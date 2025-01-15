#include <stdio.h>
#include "calculadora.h"

int main(){
  int opcao;
  float a,b;
  do{
    printf("\n--- calculadora ---\n");
    printf("1- Soma\n");
    printf("2- Subtracao\n");
    printf("3- Multiplicacao\n");
    printf("4- Divisao\n");
    printf("0- Sair\n");
    printf("---------------------\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    switch(opcao){
      case 1:
        menu(&a,&b);
      printf("o resultado da Soma e: %.2f\n", soma(a,b));
      break;

      case 2:
        menu(&a,&b);
      printf("o resultado da subtracao e: %.2f", subtracao(a,b));
      break;

      case 3:
        menu(&a,&b);
      printf("o resultado da multiplicacao e: %.2f", multiplicacao(a,b));
      break;

      case 4:
        menu(&a,&b);
      printf("o resultado da divisao e: %.2f", divisao(a,b));
      break;

      case 0:
        printf("Saindo...\n");
      break;

      default:
        printf("Opcao invalida\n");
      break;
    }
  }while (opcao != 0);

}