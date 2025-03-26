#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

char jogador1[50], jogador2[50];
char j[10];
char simb = 'O';
int nj = 0, j1 = 0, j2 = 0, emp = 0, op = 0, jog = 0;
_Bool enc = false;

void inicializar() {
  for (int id = 1; id <= 9; id++) {
    j[id] = '0' + id;
  }
  nj = 0;
}

char simbolo() {
  if (simb == 'O') {
    simb = 'X';
  } else {
    simb = 'O';
  }
  nj++;
  return simb;
}

void nomear() {
  printf("Digite o nome do jogador 1: ");
  scanf("%s", jogador1);
  printf("Digite o nome do jogador 2: ");
  scanf("%s", jogador2);
}

void menu() {
  printf("***************************\n");
  printf("*       GAME VELHA        *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*   1 - INICIAR           *\n");
  printf("*   2 - ESTATISTICA       *\n");
  printf("*   3 - SAIR              *\n");
  printf("*                         *\n");
  printf("***************************\n\n");
  printf("ESCOLHA A OPCAO DESEJADA: ");
}

void game() {
  printf("        *       *       \n");
  printf("  %c    *   %c   *   %c   \n", j[1], j[2], j[3]);
  printf("        *       *       \n");
  printf("* * * * * * * * * * * * \n");
  printf("        *       *       \n");
  printf("  %c    *   %c   *   %c   \n", j[4], j[5], j[6]);
  printf("        *       *       \n");
  printf("* * * * * * * * * * * * \n");
  printf("        *       *       \n");
  printf("  %c    *   %c   *   %c   \n", j[7], j[8], j[9]);
  printf("        *       *       \n\n");
  printf("ESCOLHA A OPCAO DESEJADA: ");
}

void estatistica() {
  printf("***************************\n");
  printf("*       ESTATISTICA       *\n");
  printf("***************************\n");
  printf("*                         *\n");
  printf("*   %s = %i   *\n", jogador1, j1);
  printf("*   %s = %i   *\n", jogador2, j2);
  printf("*   Empate = %i       *\n", emp);
  printf("*                         *\n");
  printf("***************************\n");
}

void vitoria() {
  for (int i = 1; i <= 7; i += 3) {
    if (j[i] == j[i + 1] && j[i + 1] == j[i + 2]) {
      system("clear");
      printf("\n");
      printf("***************************\n");
      printf("||     VITÓRIA!      ||\n");
      printf("||                   ||\n");
      if (j[i] == 'X') {
        printf("|| %s VENCEU! ||\n", jogador1);
        j1++;
      } else {
        printf("|| %s VENCEU! ||\n", jogador2);
        j2++;
      }
      printf("||                   ||\n");
      printf("***************************\n\n");
      enc = true;
      return;
    }
  }

  for (int i = 1; i <= 3; i++) {
    if (j[i] == j[i + 3] && j[i + 3] == j[i + 6]) {
      system("clear");
      printf("\n");
      printf("***************************\n");
      printf("||     VITÓRIA!      ||\n");
      printf("||                   ||\n");
      if (j[i] == 'X') {
        printf("|| %s VENCEU! ||\n", jogador1);
        j1++;
      } else {
        printf("|| %s VENCEU! ||\n", jogador2);
        j2++;
      }
      printf("||                   ||\n");
      printf("***************************\n\n");
      enc = true;
      return;
    }
  }

  if ((j[1] == j[5] && j[5] == j[9]) || (j[3] == j[5] && j[5] == j[7])) {
    system("clear");
    printf("\n");
    printf("***************************\n");
    printf("||     VITÓRIA!      ||\n");
    printf("||                   ||\n");
    if (j[5] == 'X') {
      printf("|| %s VENCEU! ||\n", jogador1);
      j1++;
    } else {
      printf("|| %s VENCEU! ||\n", jogador2);
      j2++;
    }
    printf("||                   ||\n");
    printf("***************************\n\n");
    enc = true;
    return;
  }

  if (nj == 9) {
    system("clear");
    printf("\n");
    printf("***************************\n");
    printf("||      EMPATE!      ||\n");
    printf("||                   ||\n");
    printf("|| Jogo Empatado! ||\n");
    printf("|| %s vs %s ||\n", jogador1, jogador2);
    printf("||   Tentem de novo!   ||\n");
    printf("***************************\n\n");
    emp++;
    enc = true;
  }
}

void continuidade() {
  printf("Deseja jogar novamente? 1-Sim 2-Não\n");
  scanf("%d", &jog);
  system("clear");
  if (jog == 1) {
    inicializar();
    enc = false;  // Resetando o status de vitória para continuar o jogo
  } else {
    menu();
  }
}

int main() {
  inicializar();
  nomear();
  system("clear");
  do {
    menu();
    scanf("%d", &op);
    system("clear");
    switch (op) {
      case 1: {
        do {
          system("clear");
          game();
          do {
            scanf("%d", &jog);
            if (jog < 1 || jog > 9) {
              printf("Posição inválida! Escolha entre 1 e 9: ");
              continue;
            }
            if (j[jog] == 'X' || j[jog] == 'O') {
              printf("Posição já ocupada! Escolha outra: ");
              continue;
            }
            break;
          } while (1);
          j[jog] = simbolo();
          vitoria();
        } while (enc == false && nj < 9);
        continuidade();  // Perguntar se o jogador quer continuar após o jogo terminar
        break;
      }
      case 2: {
        estatistica();
        break;
      }
      default: {
        if (op > 3) {
          printf("Opcao invalida!\n");
        }
        break;
      }
    }
  } while (op < 3);
  system("clear");
  printf("Sistema finalizado com sucesso!");
  return 0;
}