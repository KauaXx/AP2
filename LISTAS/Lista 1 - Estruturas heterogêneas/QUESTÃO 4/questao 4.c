#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char nome[50];
    int codigo;
    float preco;
    int quantidade;
} Produto;

struct Estoque {
    Produto produtos[5];
    int quantidade;
};

void AdicionarProduto(struct Estoque *estoque) {
    if (estoque->quantidade < 5) {
        printf("Insira o nome do produto: ");
        scanf(" %s", estoque->produtos[estoque->quantidade].nome);
        setbuf(stdin, NULL);
        printf("Insira o codigo do produto: ");
        scanf("%d", &estoque->produtos[estoque->quantidade].codigo);
        setbuf(stdin, NULL);
        printf("Insira o preco do produto: ");
        scanf("%f", &estoque->produtos[estoque->quantidade].preco);
        setbuf(stdin, NULL);
        printf("Insira a quantidade em estoque: ");
        scanf("%d", &estoque->produtos[estoque->quantidade].quantidade);
        setbuf(stdin, NULL);
        estoque->quantidade++;
    } else {
        printf("Erro: estoque cheio\n");
    }
}

float CalcularValorTotal(Produto produto) {
    return produto.preco * produto.quantidade;
}

void ExibirProdutos(struct Estoque estoque) {
    if (estoque.quantidade == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < estoque.quantidade; i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("Nome: %s\n", estoque.produtos[i].nome);
        printf("Codigo: %d\n", estoque.produtos[i].codigo);
        printf("Preco: %.2f\n", estoque.produtos[i].preco);
        printf("Quantidade: %d\n", estoque.produtos[i].quantidade);
        printf("Valor Total em Estoque: %.2f\n", CalcularValorTotal(estoque.produtos[i]));
    }
}

int main() {
    struct Estoque estoque;
    estoque.quantidade = 0;
    int op;

    do {
        printf("\n--- Menu ---\n");
        printf("1- Adicionar produto\n");
        printf("2- Exibir produtos\n");
        printf("0- Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                AdicionarProduto(&estoque);
                break;
            case 2:
                ExibirProdutos(estoque);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while (op != 0);

    return 0;
}
