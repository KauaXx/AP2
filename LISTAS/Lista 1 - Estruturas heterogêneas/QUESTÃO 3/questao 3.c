#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    char titulo[100];
    char autor[50];
    int ano_publicacao;
} Livro;

struct Biblioteca {
    Livro livros[5];
    int quantidade;
};

void AdicionarLivro(struct Biblioteca *biblioteca) {
    if (biblioteca->quantidade < 5) {
        printf("Insira o titulo do livro: ");
        scanf(" %s", biblioteca->livros[biblioteca->quantidade].titulo);
        setbuf(stdin, NULL);
        printf("Insira o autor do livro: ");
        scanf(" %s", biblioteca->livros[biblioteca->quantidade].autor);
        setbuf(stdin, NULL);
        printf("Insira o ano de publicacao do livro: ");
        scanf("%d", &biblioteca->livros[biblioteca->quantidade].ano_publicacao);
        setbuf(stdin, NULL);
        biblioteca->quantidade++;
    } else {
        printf("Erro: biblioteca cheia\n");
    }
}

void ExibirLivros(struct Biblioteca biblioteca) {
    if (biblioteca.quantidade == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    for (int i = 0; i < biblioteca.quantidade; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Titulo: %s\n", biblioteca.livros[i].titulo);
        printf("Autor: %s\n", biblioteca.livros[i].autor);
        printf("Ano de Publicacao: %d\n", biblioteca.livros[i].ano_publicacao);
    }
}

int main() {
    struct Biblioteca biblioteca;
    biblioteca.quantidade = 0;
    int op;

    do {
        printf("\n--- Menu ---\n");
        printf("1- Adicionar livro\n");
        printf("2- Exibir livros\n");
        printf("0- Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                AdicionarLivro(&biblioteca);
                break;
            case 2:
                ExibirLivros(biblioteca);
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
