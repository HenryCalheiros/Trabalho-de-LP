/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "academico.h"


int i, j;

int main()
{
    



  int Escolha, qntRegistro = 100, qntRegistrado = 99;
  registro alunos[qntRegistro];
  CarregarDadosArquivo(alunos, &qntRegistrado, "alunos.txt");
    
    
    printf("RA: %d\n", alunos[1].RA);
    printf("ID: %d\n", alunos[1].ID);
    printf("T1: %f\n", alunos[1].T1);
    printf("T2: %f\n", alunos[1].T2);
    printf("P1: %f\n", alunos[1].P1);
    printf("P2: %f\n", alunos[1].P2);
    printf("PM: %f\n", alunos[1].PM);
    printf("MF: %f\n", alunos[1].MF);
    printf("Disciplinas: %s\n", alunos[1].Disciplinas);
    printf("Semestre: %d\n", alunos[1].Semestre);
    printf("Turma: %s\n", alunos[1].Turma);
    
    
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
      for (i = 0; i < 1; i++)
      {
        AdicionarAluno(&alunos[i], &qntRegistrado);
        printf("\nO aluno %d esta na Disciplina %s\n", alunos[i].RA, alunos[i].Disciplinas);

        // aqui seria para colocar o registro la no arquivo
      }

      qntRegistrado + 1;
      break;
    case 2:
      for (i = 0; i < 1; i++)
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
