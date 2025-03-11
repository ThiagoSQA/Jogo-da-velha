/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Função para exibir o tabuleiro
void mostrartabuleiro(char tabuleiro[]) {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
    printf("\n");
}
// Função para verificar se há uma vitória para o jogador com o símbolo mark
int checarvitória(char tabuleiro[], char marca) {
    // Linhas
    if (tabuleiro[0] == marca && tabuleiro[1] == marca && tabuleiro[2] == marca) return 1;
    if (tabuleiro[3] == marca && tabuleiro[4] == marca && tabuleiro[5] == marca) return 1;
    if (tabuleiro[6] == marca && tabuleiro[7] == marca && tabuleiro[8] == marca) return 1;
    // Colunas
    if (tabuleiro[0] == marca && tabuleiro[3] == marca && tabuleiro[6] == marca) return 1;
    if (tabuleiro[1] == marca && tabuleiro[4] == marca && tabuleiro[7] == marca) return 1;
    if (tabuleiro[2] == marca && tabuleiro[5] == marca && tabuleiro[8] == marca) return 1;
    // Diagonaistabuleiro
    if (tabuleiro[0] == marca && tabuleiro[4] == marca && tabuleiro[8] == marca) return 1;
    if (tabuleiro[2] == marca && tabuleiro[4] == marca && tabuleiro[6] == marca) return 1;

    return 0;
}

// Função para verificar se houve empate
int checarEmpate(char tabuleiro[]) {
    for (int i = 0; i < 9; i++) {
        if (tabuleiro[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char tabuleiro[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    int jogadorAtual = 1;
    char marca;
    int pos;

    while (1) {
        mostrartabuleiro(tabuleiro);
        
        marca = (jogadorAtual == 1) ? 'X' : 'O';
        printf("Jogador %d (%c), escolha uma posicao (1-9): ", jogadorAtual, marca);
        
        if (scanf("%d", &pos) != 1) {
            printf("Entrada invalida. Por favor, insira um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }
        
        pos--; // Ajusta para índices de 0 a 8
        
        if (pos < 0 || pos > 8) {
            printf("Posicao invalida. Escolha um numero entre 1 e 9.\n");
            continue;
        }
        
        if (tabuleiro[pos] != ' ') {
            printf("Posicao ja ocupada. Escolha outra.\n");
            continue;
        }
        
        // Realiza a jogada
        tabuleiro[pos] = marca;
        
        // Verifica se o jogador atual venceu
        if (checarvitória(tabuleiro, marca)) {
            mostrartabuleiro(tabuleiro);
            printf("Parabens, Jogador %d! Voce venceu!\n", jogadorAtual);
            break;
        }
        
        // Verifica se houve empate
        if (checarEmpate(tabuleiro)) {
            mostrartabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }
        
        // Alterna entre os jogadores
        jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
    }
    
    return 0;
}
