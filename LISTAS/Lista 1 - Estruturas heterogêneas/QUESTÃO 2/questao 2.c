#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
} Aluno;

struct ListaDeAlunos {
    Aluno cadastro[5];
    int quantidade;
};

void AdicionarAluno(struct ListaDeAlunos *lista) {
    if (lista->quantidade < 5) {
        printf("Insira o nome do aluno: ");
        scanf("%s", lista->cadastro[lista->quantidade].nome);
        setbuf(stdin, NULL);
        printf("Insira a matricula do aluno: ");
        scanf("%d", &lista->cadastro[lista->quantidade].matricula);
        setbuf(stdin, NULL);
        printf("Insira a nota 1 do aluno: ");
        scanf("%f", &lista->cadastro[lista->quantidade].nota1);
        setbuf(stdin, NULL);
        printf("Insira a nota 2 do aluno: ");
        scanf("%f", &lista->cadastro[lista->quantidade].nota2);
        setbuf(stdin, NULL);
        lista->quantidade++;
    } else {
        printf("Erro: lista de alunos cheia\n");
    }
}

float CalcularMedia(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}

void ExibirAlunos(struct ListaDeAlunos lista) {
    if (lista.quantidade == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < lista.quantidade; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", lista.cadastro[i].nome);
        printf("Matricula: %d\n", lista.cadastro[i].matricula);
        printf("Nota 1: %.2f\n", lista.cadastro[i].nota1);
        printf("Nota 2: %.2f\n", lista.cadastro[i].nota2);
        printf("Media: %.2f\n", CalcularMedia(lista.cadastro[i]));
    }
}

int main() {
    struct ListaDeAlunos lista;
    lista.quantidade = 0;
    int op;

    do {
        printf("\n--- Menu ---\n");
        printf("1- Adicionar aluno\n");
        printf("2- Exibir alunos\n");
        printf("0- Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                AdicionarAluno(&lista);
                break;
            case 2:
                ExibirAlunos(lista);
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
