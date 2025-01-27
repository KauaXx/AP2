#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int codigo;
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto *produtos;
    int tamanho;
} Inventario;

void InicializarInventario(Inventario *inventario) {
    inventario->produtos = NULL;
    inventario->tamanho = 0;
}

void AdicionarProduto(Inventario *inventario) {
    inventario->tamanho++;
    inventario->produtos = realloc(inventario->produtos, inventario->tamanho * sizeof(Produto));

    if (inventario->produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    Produto *novoProduto = &inventario->produtos[inventario->tamanho - 1];

    printf("Digite o nome do produto: ");
    getchar();
    fgets(novoProduto->nome, 100, stdin);
    novoProduto->nome[strcspn(novoProduto->nome, "\n")] = 0;

    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto->codigo);

    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto->preco);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto->quantidade);

    printf("Produto adicionado com sucesso!\n");
}

void ListarProdutos(Inventario inventario) {
    if (inventario.tamanho == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < inventario.tamanho; i++) {
        printf("Nome: %s\n", inventario.produtos[i].nome);
        printf("Codigo: %d\n", inventario.produtos[i].codigo);
        printf("Preco: %.2f\n", inventario.produtos[i].preco);
        printf("Quantidade: %d\n", inventario.produtos[i].quantidade);
        printf("---------------------------\n");
    }
}

int BuscarProduto(Inventario inventario, int codigo) {
    for (int i = 0; i < inventario.tamanho; i++) {
        if (inventario.produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void BuscarProdutoPorCodigo(Inventario inventario) {
    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    int indice = BuscarProduto(inventario, codigo);

    if (indice != -1) {
        Produto produto = inventario.produtos[indice];
        printf("\nProduto encontrado:\n");
        printf("Nome: %s\n", produto.nome);
        printf("Codigo: %d\n", produto.codigo);
        printf("Preco: %.2f\n", produto.preco);
        printf("Quantidade: %d\n", produto.quantidade);
    } else {
        printf("Produto nao encontrado.\n");
    }
}

void SalvarInventario(Inventario inventario) {
    FILE *arquivo = fopen("inventario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar os dados do inventario.\n");
        return;
    }

    fprintf(arquivo, "%d\n", inventario.tamanho);
    for (int i = 0; i < inventario.tamanho; i++) {
        fprintf(arquivo, "%s\n%d\n%.2f\n%d\n", inventario.produtos[i].nome, inventario.produtos[i].codigo, inventario.produtos[i].preco, inventario.produtos[i].quantidade);
    }

    fclose(arquivo);
    printf("Dados do inventario salvos com sucesso.\n");
}

void CarregarInventario(Inventario *inventario) {
    FILE *arquivo = fopen("inventario.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de dados encontrado.\n");
        return;
    }

    fscanf(arquivo, "%d\n", &inventario->tamanho);
    inventario->produtos = malloc(inventario->tamanho * sizeof(Produto));

    if (inventario->produtos == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < inventario->tamanho; i++) {
        fgets(inventario->produtos[i].nome, 100, arquivo);
        inventario->produtos[i].nome[strcspn(inventario->produtos[i].nome, "\n")] = 0;
        fscanf(arquivo, "%d\n", &inventario->produtos[i].codigo);
        fscanf(arquivo, "%f\n", &inventario->produtos[i].preco);
        fscanf(arquivo, "%d\n", &inventario->produtos[i].quantidade);
    }

    fclose(arquivo);
    printf("Dados do inventario carregados com sucesso.\n");
}

int main() {
    Inventario inventario;
    InicializarInventario(&inventario);

    int opcao;
    do {
        printf("\n--- Sistema de Gerenciamento de Inventario ---\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto\n");
        printf("4. Salvar Inventario\n");
        printf("5. Carregar Inventario\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                AdicionarProduto(&inventario);
                break;
            case 2:
                ListarProdutos(inventario);
                break;
            case 3:
                BuscarProdutoPorCodigo(inventario);
                break;
            case 4:
                SalvarInventario(inventario);
                break;
            case 5:
                CarregarInventario(&inventario);
                break;
            case 0:
                SalvarInventario(inventario);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    free(inventario.produtos);
    return 0;
}
