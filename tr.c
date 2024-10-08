#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j;

typedef struct {
  int ID, RA, Semestre;
  float T1, T2, P1, P2, MF, PM;
  char Disciplinas[40], Situacao[30], Turma[30];
} registro;

int VisualizarNotas() {

  int busca, Escolha, registroEncontrado = 0;
  char linha[256];
  do {
    registroEncontrado = 0;
    FILE *file = fopen("alunos.txt", "r");

    printf("Qual o RA do aluno que esta buscando? ");
    scanf("%d", &busca);
    getchar();

    while (fgets(linha, sizeof(linha), file) != NULL) {

      if (strstr(linha, "RA:") != NULL) {
        int RAatual;

        sscanf(linha, "RA: %d", &RAatual);

        if (RAatual == busca) {
          printf("\nRegistro encontrado:\n%s", linha);
          while (fgets(linha, sizeof(linha), file) != NULL &&
                 strlen(linha) > 1) {
            printf("%s", linha);
            registroEncontrado = 1;
          }
        }
      }
    }
    if (registroEncontrado == 0) {
      printf("\nRegistro com RA %d não encontrado.\n", busca);
    }

    fclose(file);

    printf("\n\nPressione (0) para voltar ao menu\n");
    printf("Pressione (1) para buscar outro aluno: ");
    scanf("%d", &Escolha);

  } while (Escolha != 0);

  return 0;
}
void AdicionarAluno(registro *aluno) {
  // aqui vai AdicionarAluno no arquivo

  FILE *file = fopen("alunos.txt", "a");

  printf("Informe a disciplina em que vai adicionar adicionar o aluno: ");
  getchar();
  fgets(aluno->Disciplinas, 40, stdin);

  printf("\nInforme o RA do aluno?");
  scanf("%d", &aluno->RA);

  getchar();

  fprintf(file, "\nRA: %d,\n Disciplina: %s\n", aluno->RA, aluno->Disciplinas);
  fclose(file);
}

void AdicionarNotas(registro *aluno) {

  // aqui vai AdicionarNotas ao aluno no arquivo

  FILE *file = fopen("alunos.txt", "a");

  printf("Informe o RA do aluno: ");
  scanf("%d", &aluno->RA);
  getchar();

  printf("Informe a disciplina em que vai adicionar a nota: ");
  fgets(aluno->Disciplinas, sizeof(aluno->Disciplinas), stdin);
  aluno->Disciplinas[strcspn(aluno->Disciplinas, "\n")] = '\0';

  printf("Informe a nota T1: ");
  scanf("%f", &aluno->T1);
  getchar();

  printf("Informe a nota T2: ");
  scanf("%f", &aluno->T2);
  getchar();

  printf("Informe a nota P1: ");
  scanf("%f", &aluno->P1);
  getchar();

  printf("Informe a nota P2: ");
  scanf("%f", &aluno->P2);
  getchar();

  printf("Informe a nota PM: ");
  scanf("%f", &aluno->PM);
  getchar();

  printf("Informe a nota MF: ");
  scanf("%f", &aluno->MF);
  getchar();

  fprintf(file,
          "\nRA: %d,\n Disciplina: %s,\n T1: %.2f,\n T2: %.2f,\n P1: %.2f,\n "
          "P2: %.2f,\n PM: %.2f,\n MF: %.2f\n",
          aluno->RA, aluno->Disciplinas, aluno->T1, aluno->T2, aluno->P1,
          aluno->P2, aluno->PM, aluno->MF);
  fclose(file);
}

int main() {
  //qntRegistro e provisorio, quero mais um a cada registro existente.
  int Escolha, qntRegistro = 100, qntRegistrado = 99;
  registro alunos[qntRegistro];

  printf("********** MENU **********\n\n");

  do {
    printf("\n\nBem vindo Professor! \n\n");
    printf("Escolha uma das opcoes:\n");
    printf("(1) Adicionar um aluno\n");
    printf("(2) Adicionar notas ao aluno\n");
    printf("(3) Editar notas de aluno\n");
    printf("(4) Visualizar notas de aluno\n");
    printf("(0) Sair\n");
    scanf("%d", &Escolha);

    switch (Escolha) {
    case 1:
      for (i = qntRegistrado; i < qntRegistro; i++) {
        AdicionarAluno(&alunos[i]);
        printf("\nO aluno %d esta na Disciplina %s\n", alunos[i].RA,
               alunos[i].Disciplinas);

        // aqui seria para colocar o registro la no arquivo
      }

      qntRegistrado++;
      break;
    case 2:
      for (i = qntRegistrado; i < qntRegistro; i++) {
        AdicionarNotas(&alunos[i]);
        printf("\nO aluno %d esta na Disciplina %s\n", alunos[i].RA,
               alunos[i].Disciplinas);

        // aqui seria para colocar o registro la no arquivo
      }

      qntRegistrado++;
      break;
    case 3:
      //
      break;
    case 4:
      VisualizarNotas();
      break;

      // fclose(file);
    }

  } while (Escolha != 0);

  return 0;
}

int EditarNotas() {

  // aqui vai EditarNotas do aluno no arquivo

  return 0;
}
