#include <stdio.h>

int Fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: n deve ser um inteiro não negativo.\n");
    } else {
        printf("O %d numero da sequencia de Fibonacci e: %d\n", n, Fibonacci(n));
    }

    return 0;
}
