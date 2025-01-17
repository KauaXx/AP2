#include <stdio.h>

int main(){
  FILE *arquivo = fopen("saida.txt", "w");
  if(arquivo == NULL){
    printf("Erro ao abrir o arquivo");
  }
    fprintf(arquivo,"Red Dead Redemption 2 e uma obra-prima dos jogos de mundo aberto, oferecendo uma experiencia imersiva e emocional.\n");
    fprintf(arquivo,"Com graficos deslumbrantes, narrativa profunda e personagens cativantes, ele transporta os jogadores para o Velho Oeste.");
    fprintf(arquivo,"Cada detalhe, desde a ambientacao ate as interacoes, contribui para uma jornada inesquecivel.\n");

  fclose(arquivo);
    return 0;
}