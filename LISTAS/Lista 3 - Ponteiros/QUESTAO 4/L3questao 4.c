#include <stdio.h>

typedef struct {
    int x, y;
} Posicao;

void atualizarPonto(Posicao *coordenada, int novoX, int novoY) {
    coordenada->x = novoX;
    coordenada->y = novoY;
}

int main() {
    Posicao posicao = {0, 0};
    printf("Coordenadas iniciais: x = %d, y = %d\n", posicao.x, posicao.y);

    atualizarPonto(&posicao, 10, 20);

    printf("Coordenadas atualizadas: x = %d, y = %d\n", posicao.x, posicao.y);
    return 0;
}
