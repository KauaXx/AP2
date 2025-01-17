#include <stdio.h>
#include <string.h>

int main(){
    FILE *arquivo = fopen("saida.txt", "r");
    char linha[100];
    int contador = 0;

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador += strlen(linha);
        }


    printf("Numero de caracteres: %d\n", contador);

    fclose(arquivo);
    return 0;


}