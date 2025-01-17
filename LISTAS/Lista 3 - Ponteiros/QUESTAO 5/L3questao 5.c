#include <stdio.h>

int contarCaracteres(char *quantidade) {
    int contador = 0;
    while (*quantidade != '\0') {
        contador++;
        quantidade++;
    }
    return contador;
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    scanf("%s", string);

    printf("Numero de caracteres: %d\n", contarCaracteres(string));
    return 0;
}
