#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[50];
    int ano;
} Livro;

typedef struct {
    char nome[50];
    int id;
} Usuario;

typedef struct {
    Livro livros[100];
    Usuario usuarios[50];
    int quantidadeLivros;
    int quantidadeUsuarios;
} Biblioteca;

void AdicionarLivro(Biblioteca *biblioteca) {
    if (biblioteca->quantidadeLivros < 100) {
        printf("Insira o titulo do livro: ");
        getchar(); // Limpa o buffer
        fgets(biblioteca->livros[biblioteca->quantidadeLivros].titulo, 100, stdin);
       biblioteca->livros[biblioteca->quantidadeLivros].titulo[strcspn(biblioteca->livros[biblioteca->quantidadeLivros].titulo, "\n")] = 0;
        printf("Insira o autor do livro: ");
        fgets(biblioteca->livros[biblioteca->quantidadeLivros].autor, 50, stdin);
        biblioteca->livros[biblioteca->quantidadeLivros].autor[strcspn(biblioteca->livros[biblioteca->quantidadeLivros].autor, "\n")] = 0;
        printf("Insira o ano de publicacao: ");
        scanf("%d", &biblioteca->livros[biblioteca->quantidadeLivros].ano);

        biblioteca->quantidadeLivros++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("Erro: Capacidade maxima de livros atingida.\n");
    }
}

void AdicionarUsuario(Biblioteca *biblioteca) {
    if (biblioteca->quantidadeUsuarios < 50) {
        printf("Insira o nome do usuario: ");
        getchar();
        fgets(biblioteca->usuarios[biblioteca->quantidadeUsuarios].nome, 50, stdin);
        biblioteca->usuarios[biblioteca->quantidadeUsuarios].nome[strcspn(biblioteca->usuarios[biblioteca->quantidadeUsuarios].nome, "\n")] = 0;
        printf("Insira o ID do usuario: ");
        scanf("%d", &biblioteca->usuarios[biblioteca->quantidadeUsuarios].id);

        biblioteca->quantidadeUsuarios++;
        printf("Usuario adicionado com sucesso!\n");
    } else {
        printf("Erro: Capacidade maxima de usuarios atingida.\n");
    }
}

void ListarLivros(Biblioteca biblioteca) {
    if (biblioteca.quantidadeLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
    } else {
        printf("\n--- Lista de Livros ---\n");
        for (int i = 0; i < biblioteca.quantidadeLivros; i++) {
            printf("Titulo: %s\n", biblioteca.livros[i].titulo);
            printf("Autor: %s\n", biblioteca.livros[i].autor);
            printf("Ano: %d\n\n", biblioteca.livros[i].ano);
            printf("--------------------------------\n");
        }
    }
}

void ListarUsuarios(Biblioteca biblioteca) {
    if (biblioteca.quantidadeUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
    } else {
        printf("\n--- Lista de Usuarios ---\n");
        for (int i = 0; i < biblioteca.quantidadeUsuarios; i++) {
            printf("Nome: %s\n", biblioteca.usuarios[i].nome);
            printf("ID: %d\n\n", biblioteca.usuarios[i].id);
            printf("--------------------------------\n");
        }
    }
}

int BuscarLivroRecursivo(Livro livros[], int inicio, int fim, char *titulo) {
    if (inicio > fim) {
        return -1;
    }

    if (strcmp(livros[inicio].titulo, titulo) == 0) {
        return inicio;
    }

    return BuscarLivroRecursivo(livros, inicio + 1, fim, titulo);
}

void BuscarLivro(Biblioteca biblioteca) {
    if (biblioteca.quantidadeLivros == 0) {
        printf("Nenhum livro cadastrado para buscar.\n");
        return;
    }

    char titulo[100];
    printf("Digite o titulo do livro para buscar: ");
    getchar();
    fgets(titulo, 100, stdin);
    titulo[strcspn(titulo, "\n")] = 0;

    int indice = BuscarLivroRecursivo(biblioteca.livros, 0, biblioteca.quantidadeLivros - 1, titulo);

    if (indice != -1) {
        printf("\nLivro encontrado:\n");
        printf("Titulo: %s\n", biblioteca.livros[indice].titulo);
        printf("Autor: %s\n", biblioteca.livros[indice].autor);
        printf("Ano: %d\n", biblioteca.livros[indice].ano);
    } else {
        printf("Livro nao encontrado.\n");
    }
}

void SalvarBiblioteca(Biblioteca biblioteca) {
    FILE *arquivo = fopen("biblioteca.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar os dados da biblioteca.\n");
        return;
    }

    fprintf(arquivo, "%d\n", biblioteca.quantidadeLivros);
    for (int i = 0; i < biblioteca.quantidadeLivros; i++) {
        fprintf(arquivo, "%s\n%s\n%d\n", biblioteca.livros[i].titulo, biblioteca.livros[i].autor, biblioteca.livros[i].ano);
    }

    fprintf(arquivo, "%d\n", biblioteca.quantidadeUsuarios);
    for (int i = 0; i < biblioteca.quantidadeUsuarios; i++) {
        fprintf(arquivo, "%s\n%d\n", biblioteca.usuarios[i].nome, biblioteca.usuarios[i].id);
    }

    fclose(arquivo);
    printf("Dados da biblioteca salvos com sucesso.\n");
}

void CarregarBiblioteca(Biblioteca *biblioteca) {
    FILE *arquivo = fopen("biblioteca.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de dados encontrado.\n");
        return;
    }

    fscanf(arquivo, "%d\n", &biblioteca->quantidadeLivros);
    for (int i = 0; i < biblioteca->quantidadeLivros; i++) {
        fgets(biblioteca->livros[i].titulo, 100, arquivo);
        biblioteca->livros[i].titulo[strcspn(biblioteca->livros[i].titulo, "\n")] = 0;
        fgets(biblioteca->livros[i].autor, 50, arquivo);
        biblioteca->livros[i].autor[strcspn(biblioteca->livros[i].autor, "\n")] = 0;
        fscanf(arquivo, "%d\n", &biblioteca->livros[i].ano);
    }

    fscanf(arquivo, "%d\n", &biblioteca->quantidadeUsuarios);
    for (int i = 0; i < biblioteca->quantidadeUsuarios; i++) {
        fgets(biblioteca->usuarios[i].nome, 50, arquivo);
        biblioteca->usuarios[i].nome[strcspn(biblioteca->usuarios[i].nome, "\n")] = 0;
        fscanf(arquivo, "%d\n", &biblioteca->usuarios[i].id);
    }

    fclose(arquivo);
    printf("Dados da biblioteca carregados com sucesso.\n");
}

int main() {
    Biblioteca biblioteca;
    biblioteca.quantidadeLivros = 0;
    biblioteca.quantidadeUsuarios = 0;

    CarregarBiblioteca(&biblioteca);

    int opcao;
    do {
        printf("\n--- Sistema de Gerenciamento de Biblioteca ---\n");
        printf("1. Adicionar Livro\n");
        printf("2. Adicionar Usuario\n");
        printf("3. Listar Livros\n");
        printf("4. Listar Usuarios\n");
        printf("5. Buscar Livro\n");
        printf("6. Salvar Biblioteca\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                AdicionarLivro(&biblioteca);
                break;
            case 2:
                AdicionarUsuario(&biblioteca);
                break;
            case 3:
                ListarLivros(biblioteca);
                break;
            case 4:
                ListarUsuarios(biblioteca);
                break;
            case 5:
                BuscarLivro(biblioteca);
                break;
            case 6:
                SalvarBiblioteca(biblioteca);
                break;
            case 0:
                SalvarBiblioteca(biblioteca);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
