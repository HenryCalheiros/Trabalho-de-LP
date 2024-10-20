#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "academico.h"

// Constante
#define QTDREGISTRO 100

// Declaração de variáves globais
int i, j;
int escolhaOperacao, escolhaCadastro, escolhaConsulta;
int qntRegistradoAlunos = 0, qntRegistradoDisciplinas = 0;  
registro alunos[QTDREGISTRO]; 
Disciplinas disciplina[QTDREGISTRO];

//Funções de Menu
void menuPrincipal();
void menuCadastro();
void menuConsulta();

int main()
{

  do
  {

    menuPrincipal();

    switch (escolhaOperacao)
    {
      case 1: // usuário escolheu cadastrar
        menuCadastro();
        break;

      case 2: // usuário escolheu consultar
        menuConsulta();
        break;

      case 3: // usuário escolheu excluir
        break;
      case 4: // usuário escoheu atualizar
        break;
    }

  } while (escolhaOperacao != 0);

  return 0;
}

void menuPrincipal()
{
    printf("********** MENU **********");
    printf("\n\nBem vindo Professor! \n\n");
    printf("Escolha uma das opcoes:\n");
    printf("(1) Cadastrar\n");
    printf("(2) Consultar\n");
    printf("(3) Excluir\n");
    printf("(4) Atualizar\n");
    printf("(0) Sair\n");
    scanf("%d", &escolhaOperacao);
}

void menuCadastro()
{
    printf("********** MENU **********");
    printf("\n\nBem vindo Professor! \n\n");
    printf("Escolha uma das opcoes:\n");
    printf("(1) Cadastrar Aluno\n");
    printf("(2) Cadastrar Disciplina\n");
    printf("(3) Cadastrar Notas\n");
    scanf("%d", &escolhaCadastro);

    switch (escolhaCadastro)

    {
        case 1: // usuário escolheu cadastrar aluno
            if(qntRegistradoAlunos < QTDREGISTRO) // verifica se a quantidade registrada é menor do que a quantidade MAX
            {
                AdicionarAluno(&alunos[i]);
                printf("\nO aluno %d esta na Disciplina %s\n", alunos[i].RA, alunos[i].Disciplinas);

                // aqui seria para colocar o registro la no arquivo
                qntRegistradoAlunos += 1;
            }

            
            break;

        case 2: // usuário escolheu cadastrar disciplina
          if(qntRegistradoDisciplinas < QTDREGISTRO)
          {
            AdicionarDisciplina(&disciplina[QTDREGISTRO]);
            break;
          }
          

        case 3: // usuário escolheu cadastrar notas
          if(qntRegistradoAlunos < QTDREGISTRO)
          {
            AdicionarNotas(&alunos[i]);
            printf("\nO aluno %d esta na Disciplina %s\n", alunos[i].RA, alunos[i].Disciplinas);

            // aqui seria para colocar o registro la no arquivo
            
            qntRegistradoAlunos += 1;
          }

            break;
    }
}

void menuConsulta()
{
        printf("********** MENU DE CONSULTA**********");
        printf("\n\nBem vindo Professor! \n\n");
        printf("Escolha uma das opcoes:\n");
        printf("(1) Consultar Alunos\n");
        printf("(2) Buscar Aluno\n");
        printf("(3) Consultar Disciplinas\n");
        scanf("%d", &escolhaConsulta); 

        switch (escolhaConsulta)
        {
        
          case 1: // usuário escolheu consultar todos os alunos
          break;

          case 2: // usuário escolheu buscar um aluno
          VisualizarNotas();
          break;

          case 3: // usuário escolheu consultar todas as disciplinas
          ConsultarDisciplina(&disciplina[QTDREGISTRO]);
          break;
        }  
}