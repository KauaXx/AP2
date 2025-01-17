#include <stdio.h>

void trocar(int *a, int *b) {
    int troca = *a;
    *a = *b;
    *b = troca;
}

int main() {
    int x = 10, y = 20;
    printf("sem trocar: x = %d, y = %d\n", x, y);

    trocar(&x, &y);

    printf("trocado: x = %d, y = %d\n", x, y);
    return 0;
}
