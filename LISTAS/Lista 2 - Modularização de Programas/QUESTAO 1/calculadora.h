#ifndef CALCULADORA_H
#define CALCULADORA_H
float soma(float a, float b){
  return a + b;
}

float subtracao(float a, float b){
  return a - b;
}

float multiplicacao(float a, float b){
  return a * b;
}
float divisao(float a, float b){
  return a / b;
}
void menu(float *a, float *b){
  printf("digite o primeiro numero: ");
  scanf("%f", a);
  printf("digite o segundo numero: ");
  scanf("%f", b);
}
#endif
