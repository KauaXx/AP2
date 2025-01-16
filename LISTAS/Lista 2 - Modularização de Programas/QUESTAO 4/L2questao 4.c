#include <stdio.h>
#include <string.h>

typedef struct Quarto {
    int numero;
    int reservado;
} Quarto;

void InicializarQuartos(Quarto quartos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        quartos[i].numero = i + 1;
        quartos[i].reservado = 0;
    }
}

void ReservarQuarto(Quarto quartos[], int tamanho) {
    int numero;
    printf("Digite o numero do quarto para reservar (1-%d): ", tamanho);
    scanf("%d", &numero);

    if (numero < 1 || numero > tamanho) {
        printf("Numero de quarto invalido.\n");
        return;
    }

    if (quartos[numero - 1].reservado) {
        printf("Erro: o quarto já está reservado.\n");
    } else {
        quartos[numero - 1].reservado = 1;
        printf("Reserva realizada com sucesso.\n");
    }
}

void ExibirQuartosDisponiveis(Quarto quartos[], int tamanho) {
    printf("Quartos disponiveis:\n");
    for (int i = 0; i < tamanho; i++) {
        if (!quartos[i].reservado) {
            printf("Quarto %d\n", quartos[i].numero);
        }
    }
}

int main() {
    int totalQuartos = 10;
    Quarto quartos[totalQuartos];
    InicializarQuartos(quartos, totalQuartos);

    int opcao;
    do {
        printf("\n----- Sistema de Reservas -----\n");
        printf("1. Reservar quarto\n");
        printf("2. Exibir quartos disponiveis\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ReservarQuarto(quartos, totalQuartos);
            break;
            case 2:
                ExibirQuartosDisponiveis(quartos, totalQuartos);
            break;
            case 0:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
