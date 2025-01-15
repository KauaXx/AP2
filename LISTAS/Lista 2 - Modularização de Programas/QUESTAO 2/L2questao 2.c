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
    Aluno cadastro[50];
    int quantidade;
};

void AdicionarAluno(struct ListaDeAlunos *lista) {
    if (lista->quantidade < 50) {
        printf("Insira o nome do aluno: ");
        scanf("%s", lista->cadastro[lista->quantidade].nome);
        printf("Insira a matricula do aluno: ");
        scanf("%d", &lista->cadastro[lista->quantidade].matricula);
        printf("Insira a nota 1 do aluno: ");
        scanf("%f", &lista->cadastro[lista->quantidade].nota1);
        printf("Insira a nota 2 do aluno: ");
        scanf("%f", &lista->cadastro[lista->quantidade].nota2);
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

void ExibirMedias(struct ListaDeAlunos lista) {
    if (lista.quantidade == 0) {
        printf("Nenhum aluno cadastrado para calcular medias.\n");
        return;
    }
    for (int i = 0; i < lista.quantidade; i++) {
        printf("Media do aluno %s: %.2f\n", lista.cadastro[i].nome, CalcularMedia(lista.cadastro[i]));
    }
}

int main() {
    struct ListaDeAlunos lista;
    lista.quantidade = 0;

    int opcao;
    do {
        printf("\n----- Menu -----\n");
        printf("1. Adicionar alunos\n");
        printf("2. Listar alunos\n");
        printf("3. exibir medias dos alunos\n");
        printf("0. Sair\n");
        printf("------------------");
        printf("\nOpcao: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                AdicionarAluno(&lista);
                break;
            case 2:
                ExibirAlunos(lista);
                break;
            case 3:
                ExibirMedias(lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
