#include <stdio.h>

int somaArray(int *numeros, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(numeros + i);
    }
    return soma;
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int numeros[tamanho];

    printf("Digite os numeros do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Soma dos elementos: %d\n", somaArray(numeros, tamanho));
    return 0;
}
