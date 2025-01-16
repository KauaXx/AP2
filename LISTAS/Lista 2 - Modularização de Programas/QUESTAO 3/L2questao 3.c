#include <stdio.h>
#include <string.h>

typedef struct Usuario {
    char nome[50];
    char senha[50];
} Usuario;

typedef struct SistemaLogin {
    Usuario usuario[50];
    int quantidade;
    int maxUsuarios;
} SistemaLogin;

void CadastrarUsuario(SistemaLogin *sistema) {
    if (sistema->quantidade < sistema->maxUsuarios) {
        printf("Digite o nome de usuario: ");
        scanf("%s", sistema->usuario[sistema->quantidade].nome);
        printf("Digite a senha: ");
        scanf("%s", sistema->usuario[sistema->quantidade].senha);
        sistema->quantidade++;
        printf("Usuario cadastrado com sucesso!\n");
    } else {
        printf("Erro: limite de usuarios alcançado.\n");
    }
}

int AutenticarUsuario(SistemaLogin sistema) {
    char nome[50], senha[50];
    printf("Digite o nome de usuario: ");
    scanf("%s", nome);
    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < sistema.quantidade; i++) {
        if (strcmp(sistema.usuario[i].nome, nome) == 0 &&
            strcmp(sistema.usuario[i].senha, senha) == 0) {
            printf("Login bem-sucedido!\n");
            return 1;
            }
    }
    printf("Usuario ou senha invalidos.\n");
    return 0;
}

int main() {
    SistemaLogin sistema = {.quantidade = 0, .maxUsuarios = 50};
    int opcao;

    do {
        printf("\n----- Menu de Login -----\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Fazer login\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                CadastrarUsuario(&sistema);
            break;
            case 2:
                AutenticarUsuario(sistema);
            break;
            case 0:
                printf("Saindo...\n");
            break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
