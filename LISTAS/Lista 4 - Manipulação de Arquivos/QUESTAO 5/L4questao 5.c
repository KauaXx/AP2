#include <stdio.h>

int main(){
    FILE *arquivo = fopen("saida.txt", "r");
    FILE *arquivo2 = fopen("copia.txt", "w");
    char linha[100];
    if (arquivo == NULL || arquivo2 == NULL) {
      printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
      fprintf(arquivo2, "%s", linha);
    }
    printf("Arquivo copiado com sucesso!\n");
    fclose(arquivo);
    fclose(arquivo2);
    return 0;
}
