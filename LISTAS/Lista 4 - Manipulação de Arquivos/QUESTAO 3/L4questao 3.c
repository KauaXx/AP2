#include <stdio.h>

int main() {
    FILE *arquivo = fopen("saida.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }
    fprintf(arquivo,"A liberdade para explorar, cacar, pescar e interagir com o ambiente cria um mundo vivo e realista.\n");
    fprintf(arquivo,"Alem disso, sua trilha sonora e mecanicas de jogo elevam ainda mais a experiencia, tornando-o um marco na historia dos videogames.\n");
    fclose(arquivo);
    return 0;
}