#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char jogador1[50], jogador2[50];
int vitoriasJogador1 = 0;
int vitoriasJogador2 = 0;
int empates = 0;

void mostrarTabuleiro(char tabuleiro[]) {
    system("clear");
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
    printf("\n");
}

int vitoria(char tabuleiro[], char marca) {
    for (int i = 0; i < 9; i += 3) {
        if (tabuleiro[i] == marca && tabuleiro[i + 1] == marca && tabuleiro[i + 2] == marca) return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i] == marca && tabuleiro[i + 3] == marca && tabuleiro[i + 6] == marca) return 1;
    }
    if ((tabuleiro[0] == marca && tabuleiro[4] == marca && tabuleiro[8] == marca) ||
        (tabuleiro[2] == marca && tabuleiro[4] == marca && tabuleiro[6] == marca)) {
        return 1;
    }
    return 0;
}

void game() {
    char tabuleiro[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    int jogadorAtual = 1;
    char marca;
    int pos;

    while (1) {
        mostrarTabuleiro(tabuleiro);
        char* nomeJogador = (jogadorAtual == 1) ? jogador1 : jogador2;
        marca = (jogadorAtual == 1) ? 'X' : 'O';
        printf("%s (%c), escolha uma posição (1-9): ", nomeJogador, marca);

        if (scanf("%d", &pos) != 1) {
            printf("Entrada inválida. Digite um número entre 1 e 9.\n");
            while (getchar() != '\n');
            continue;
        }

        pos--;
        if (pos < 0 || pos > 8 || tabuleiro[pos] != ' ') {
            printf("Posição inválida ou já ocupada. Tente novamente.\n");
            continue;
        }

        tabuleiro[pos] = marca;

        if (vitoria(tabuleiro, marca)) {
            mostrarTabuleiro(tabuleiro);
            printf("Parabéns, %s! Você venceu!\n", nomeJogador);
            if (jogadorAtual == 1) vitoriasJogador1++;
            else vitoriasJogador2++;                  
            break;
        }

        int empate = 1;
        for (int i = 0; i < 9; i++) {
            if (tabuleiro[i] == ' ') {
                empate = 0;
                break;
            }
        }
        if (empate) {
            mostrarTabuleiro(tabuleiro);
            printf("Empate!\n");
            empates++;
            break;
        }

        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
    }
    printf("Pressione Enter para voltar ao menu...");
    getchar();
    getchar();
}

void estatisticas() {
    system("clear");
    printf("\n********** ESTATÍSTICAS **********\n");
    printf("Vitórias de %s: %d\n", jogador1, vitoriasJogador1);
    printf("Vitórias de %s: %d\n", jogador2, vitoriasJogador2);
    printf("Empates: %d\n", empates);
    printf("**********************************\n");
    printf("Pressione Enter para voltar ao menu...");
    getchar();
    getchar();
}

void menu() {
    printf("\n***********************************\n");
    printf("*         JOGO DA VELHA           *\n");
    printf("***********************************\n");
    printf("*  1 - JOGAR                      *\n");
    printf("*  2 - ESTATÍSTICAS               *\n");
    printf("*  3 - SAIR                       *\n");
    printf("***********************************\n");
    printf("Digite a opção desejada: ");
}

int main() {
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogador1);
    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogador2);

    int op;
    do {
        system("clear");
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                game();
                break;
            case 2:
                estatisticas();
                break;
            case 3:
                printf("Jogo finalizado com sucesso!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != 3);

    return 0;
}
