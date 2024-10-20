#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int ID, RA, Semestre;
    float T1, T2, P1, P2, MF, PM;
    char Disciplinas[40], Situacao[30], Turma[30];
} registro;

typedef struct
{
    int ID;
    char nome[40];
} Disciplinas;

// Função para buscar nota de um Aluno
int VisualizarNotas()
{

    int busca, Escolha, registroEncontrado = 0;
    char linha[256];
    do
    {
        registroEncontrado = 0;
        FILE *file = fopen("alunos.txt", "r");

        printf("Qual o RA do aluno que esta buscando? ");
        scanf("%d", &busca);
        getchar();

        while (fgets(linha, sizeof(linha), file) != NULL)
        {

            if (strstr(linha, "RA:") != NULL)
            {
                int RAatual;

                sscanf(linha, "RA: %d", &RAatual);

                if (RAatual == busca)
                {
                    printf("\nRegistro encontrado:\n%s", linha);
                    while (fgets(linha, sizeof(linha), file) != NULL && strlen(linha) > 1)
                    {
                        printf("%s", linha);
                        registroEncontrado = 1;
                    }
                }
            }
        }
        if (registroEncontrado == 0)
        {
            printf("\nRegistro com RA %d não encontrado.\n", busca);
        }

        fclose(file);

        printf("\n\nPressione (0) para voltar ao menu\n");
        printf("Pressione (1) para buscar outro aluno: ");
        scanf("%d", &Escolha);

    } while (Escolha != 0);

    return 0;
}

// Função para adicionar nota de um Aluno
void AdicionarNotas(registro *aluno)
{

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

    fprintf(file, "\nRA: %d,\n Disciplina: %s,\n T1: %.2f,\n T2: %.2f,\n P1: %.2f,\n P2: %.2f,\n PM: %.2f,\n MF: %.2f\n",
            aluno->RA, aluno->Disciplinas, aluno->T1, aluno->T2, aluno->P1, aluno->P2, aluno->PM, aluno->MF);
    fclose(file);
}

// Função para adicionar um Aluno
void AdicionarAluno(registro *aluno)
{
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

// Função para verificar a existência de uma disciplina digitada
bool DisciplinaExiste(char nomeDigitado[40])
{
    Disciplinas *disciplina;

    FILE *file = fopen("disciplinas.txt", "r");
   
    bool existe = false;

    // loop para percorrer todos os registros no arquivo
    while (fscanf(file, "\nID: %d,\nNome: %[^\n]", &disciplina->ID, disciplina->nome) == 2) 
    {
        
       if(strcmp(disciplina->nome, nomeDigitado) == 0) // se o nome digitado, já estiver nos arquivos
       {
         existe = true; // disciplina existente encontrada
         break;
       }
    }

    fclose(file);
    return existe;
}

// Função para gerar um id auto-increment para os registros
int gerarId()
{
    Disciplinas *disciplina;

    int maior = 0;
    FILE *file = fopen("disciplinas.txt", "r");

    while (fscanf(file, "\nID: %d,\nNome: %[^\n]", &disciplina->ID, disciplina->nome) == 2) 
    {
       
        if(disciplina->ID > maior)
        {
            maior = disciplina->ID;
        }
    }

    fclose(file);
    return maior;
}

// Função para adicionar uma disciplina
void AdicionarDisciplina(Disciplinas *disciplina)
{
    
    FILE *file = fopen("disciplinas.txt", "a"); // a, para abrir somente para gravação e manter o que já está escrito

    printf("Informe o nome da disciplina que deseja adicionar: ");
    scanf("%s",disciplina->nome);

    // passa o nome digitado pelo usuário como parametro
    if(DisciplinaExiste(disciplina->nome) == false) // se a função retornar false o registro não existe
    {
        disciplina->ID = gerarId() + 1;
        fprintf(file, "\nID: %d,\nNome: %s", disciplina->ID, disciplina->nome);
        printf("\nDisciplina cadastrada com sucesso! \n");
    }
    else
    {
        printf("Disciplina já registrada!! \n");
    }

    
    fclose(file);

}

// Função para exibir disciplinas
void ConsultarDisciplina(Disciplinas *disciplina)
{
    FILE *file = fopen("disciplinas.txt", "r"); // r, para abrir somente para leitura e manter o que já está escrito
    printf(" _______________________________________\n");
    printf("|---------TABELA DE DISCIPLINAS---------|\n");
    printf("|          I D             DISCIPLINA   |\n");

    //loop para acessar os registros no arquivo
    while (fscanf(file, "\nID: %d,\nNome: %[^\n]", &disciplina->ID, disciplina->nome) == 2) 
    {
        printf("|  %10d   %18s      | \n", disciplina->ID, disciplina->nome);
    }
    printf(" _______________________________________\n");


}

