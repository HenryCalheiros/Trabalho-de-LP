#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"
#include "notas.h"
#include "disciplina.h"

int i, j;

int main()
{
  // qntRegistro e provisorio, quero mais um a cada registro existente.
  int escolha1, escolha2, escolha3, qntRegistro = 100, qntRegistrado = 0;
  registro alunos[qntRegistro];
  Disciplinas disciplina[qntRegistro];

  printf("********** MENU **********\n\n");

  do
  {
    printf("\n\nBem vindo Professor! \n\n");
    printf("Escolha uma das opcoes:\n");
    printf("(1) CADASTRAR\n");
    printf("(2) CONSULTAR\n");
    printf("(3) EDITAR\n");
    printf("(4) EXCLUIR\n");
    printf("(0) SAIR\n");
    scanf("%d", &escolha1);
    getchar();

    switch (escolha1)
    {
    case 1: // caso escolha cadastrar
      printf("********** MENU DE CADASTRO**********\n\n");
      printf("Escolha uma das opcoes:\n");
      printf("(1) CADASTRAR DISCIPLINA\n");
      printf("(2) CADASTRAR ALUNO\n");
      scanf("%d", &escolha2);
      getchar();
      switch (escolha2)
      {
      case 1: // caso escolha cadastrar uma disciplina
        criarDisciplina(&disciplina[qntRegistrado]);
      case 2:
      }
      break;

    case 2: // caso escolha visualizar os dados
      printf("********** MENU DE CONSULTAS**********\n\n");
      printf("Escolha uma das opcoes:\n");
      printf("(1) CONSULTAR DISCIPLINAS\n");
      printf("(2) CONSULTAR ALUNOS\n");
      scanf("%d", &escolha3);
      getchar();
      switch (escolha3)
      {
        case 1: // caso escolha consultar as disciplinas
          consultarDisciplinas();
          break;

        case 2:// caso escolha consultar os alunos
          break;
      }
    }
  } while (escolha1 != 0);

  return 0;
}
