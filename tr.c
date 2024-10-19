#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "academico.h"


int i, j;

int main()
{

  int Escolha, qntRegistro = 100, qntRegistrado = 99;
  registro alunos[qntRegistro];

  printf("********** MENU **********\n\n");

  do
  {
    printf("\n\nBem vindo Professor! \n\n");
    printf("Escolha uma das opcoes:\n");
    printf("(1) Adicionar um aluno\n");
    printf("(2) Adicionar notas ao aluno\n");
    printf("(3) Editar notas de aluno\n");
    printf("(4) Visualizar notas de aluno\n");
    printf("(0) Sair\n");
    scanf("%d", &Escolha);

    switch (Escolha)
    {
    case 1:
      for (i = qntRegistrado; i < qntRegistro; i++)
      {
        AdicionarAluno(&alunos[i]);
        printf("\nO aluno %d esta na Disciplina %s\n", alunos[i].RA, alunos[i].Disciplinas);

        // aqui seria para colocar o registro la no arquivo
      }

      qntRegistrado + 1;
      break;
    case 2:
      for (i = qntRegistrado; i < qntRegistro; i++)
      {
        AdicionarNotas(&alunos[i]);
        printf("\nO aluno %d esta na Disciplina %s\n", alunos[i].RA, alunos[i].Disciplinas);

        // aqui seria para colocar o registro la no arquivo
      }

      qntRegistrado + 1;
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

