#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int *array = (int *)malloc(tamanho * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite os valores do array:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }

    printf("Elementos do array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
