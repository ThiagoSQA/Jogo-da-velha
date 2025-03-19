#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char caminho[9];
char tabuleiro[3][3];
char jogador1[10], jogador2[10];
char j[10];
char simb = 'O';
int nj = 0, ju = 0, jd = 0, emp = 0, op = 0, jog = 0;
_Bool enc = false;

void inicializar() {
  for (int id = 0; id < 9; id++) {
    caminho[id] = "";
  }
  j[1] = '1';
  j[2] = '2';
  j[3] = '3';
  j[4] = '4';
  j[5] = '5';
  j[6] = '6';
  j[7] = '7';
  j[8] = '8';
  j[9] = '9';
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
  printf("*   %c = %i   *\n", jogador1, ju);
  printf("*   %c = %i   *\n", jogador2, jd);
  printf("*   Empate = %i       *\n", emp);
  printf("*                         *\n");
  printf("***************************\n");
}

void armazenarjogada(int jog) {
  switch (jog) {
  case 1:
    caminho[1] += simb;
    caminho[6] += simb;
    caminho[8] += simb;
    break;
  case 2:
    caminho[1] += simb;
    caminho[5] += simb;
    break;
  case 3:
    caminho[1] += simb;
    caminho[4] += simb;
    caminho[7] += simb;
    break;
  case 4:
    caminho[2] += simb;
    caminho[6] += simb;
    break;
  case 5:
    caminho[2] += simb;
    caminho[5] += simb;
    caminho[7] += simb;
    caminho[8] += simb;
    break;
  case 6:
    caminho[2] += simb;
    caminho[4] += simb;
    break;
  case 7:
    caminho[3] += simb;
    caminho[6] += simb;
    caminho[7] += simb;
    break;
  case 8:
    caminho[3] += simb;
    caminho[5] += simb;
    break;
  case 9:
    caminho[3] += simb;
    caminho[4] += simb;
    caminho[8] += simb;
    break;
  }
}

void continuidade() {
  system("clear");
  printf("Deseja continuar? 1-Sim 2-Não\n");
  scanf("%d", &jog);
   system("clear");
  if (jog == 1){
    inicializar();
  } else {
    menu();
  }
}

void triunfo() {
  for (int x = 1; x < 9; x++) {
    if (strlen(&caminho[x]) == 3) {
      if (strcmp(caminho[x], "XXX") == 0)
        system("clear");
      printf("Jogador %s venceu!", jogador1);
      ju++;
      enc = true;
      continuidade();
    } else if (caminho[x] == "OOO") {
      system("clear");
      printf("Jogador %s venceu!", jogador2);
      jd++;
      enc = true;
      continuidade();
    } else if ((enc == false) && (nj == 9)) {
      system("clear");
      printf("Empate!");
      emp++;
      continuidade();
    }
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
          if(j[jog] == 'X' || j[jog] == 'O') {
            printf("Posição já ocupada! Escolha outra: ");
          }
        } while(j[jog] == 'X' || j[jog] == 'O');
        j[jog] = simbolo();
        armazenarjogada(jog);
        if (nj >=9 )
          triunfo();
      } while (enc == false && nj < 9);
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
}