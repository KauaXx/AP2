#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Funcionario{
  char nome[50];
  int idade;
  float salario;
}Funcionario;
struct ListaDeFuncionarios{
  struct Funcionario cadastro[5];
  int quantidade;
};
void AdicionarFuncionario(struct ListaDeFuncionarios *lista){
  if(lista -> quantidade < 5){
    printf("Insira o nome do funcionario: ");
    scanf("%s", lista -> cadastro[lista->quantidade].nome);
    setbuf(stdin, NULL);
    printf("Insira a idade do funcionario: ");
    scanf("%d", &lista -> cadastro[lista->quantidade].idade);
    setbuf(stdin, NULL);
    printf("Insira a salario do funcionario: ");
    scanf("%f", &lista -> cadastro[lista->quantidade].salario);
    setbuf(stdin, NULL);
    lista -> quantidade++;
  }else{
    printf("Erro: lista de funcionario cheia");
  }
}
void exibirFuncionario(struct ListaDeFuncionarios lista){
  for(int i = 0; i < lista.quantidade; i++){
    printf("Nome: %s\n", lista.cadastro[i].nome);
    printf("Idade: %d\n", lista.cadastro[i].idade);
    printf("Salario: %.2f\n", lista.cadastro[i].salario);
  }
}



int main(){
struct ListaDeFuncionarios lista;
lista.quantidade = 0;
int op;

do{
  printf("1- Adicionar funcionarios\n");
  printf("2- Exibir funcionarios\n");
  printf("0- Sair\n");
  printf("Opcao: ");
  scanf("%d", &op);
  switch(op){
    case 1:
      AdicionarFuncionario(&lista);
      break;
      case 2:
        exibirFuncionario(lista);
        break;
        case 0:
          printf("Saindo...\n");
          break;
          default:
            printf("opcao invalida\n");
  }
}while(op != 0);1;
}