
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int id;
    char nome[40];
} Disciplinas;

// Função para adicionar disciplinas da instituição
void criarDisciplina(Disciplinas *disciplina)
{

    int Escolha;
    char linha[256];
    int disciplinaExistente;

    FILE *file = fopen("disciplinas.txt", "r+"); // r+, para ler e escrever no arquivo

    // loop para continuar adicionando matéria
    do
    {
        disciplinaExistente = 0;

        printf("Informe o nome da matéria que deseja adicionar: ");
        fgets(disciplina->nome, 40, stdin);

        rewind(file); // retorna para o inicio do arquivo para verificar se já há registros

        while (fgets(linha, sizeof(linha), file) != NULL) // loop para ler as linhas do arquivo
        {
            int idExistente;
            char nomeExistente[40];

            // Tenta ler o ID e o nome da linha
            if (sscanf(linha, "ID:%d, Nome:%39[^\n]", &idExistente, nomeExistente) == 2) // Verifica se leu corretamente
            {
                if (strcmp(nomeExistente, disciplina->nome) == 0) // Compara o nome lido com o nome da disciplina
                {
                    disciplinaExistente = 1; // Disciplina já cadastrada
                    break;                   // Sai do loop se a disciplina já existe
                }
            }
        }

        if (!disciplinaExistente) // não está registrada
        {
            srand(time(0));
            disciplina->id = rand() % 100; // gera um id aleatório entre 0 e 100
            fprintf(file, "ID:%d, Nome:%s\n", disciplina->id, disciplina->nome);
            printf("Disciplina adicionada com sucesso!\n");
        }
        else
        {
            printf(" Disciplina já cadastrada!! \n");
        }

        printf("Pressione (0) para voltar ao menu\n");
        printf("Pressione (1) para adicionar outra matéria: \n");

        scanf("%d", &Escolha);
        getchar(); // limpa o buffer

    } while (Escolha != 0); // condição de parada

    fclose(file); // fecha o arquivo
}

// função para exibir todas as disciplinas
void consultarDisciplinas()
{
    char linha[256];
    FILE *file = fopen("disciplinas.txt", "r"); // r, para somente ler o arquivo

    printf("-----------------------------------------\n");
    printf("%-5s | %-40s\n", "ID", "Nome da Disciplina");
    printf("-----------------------------------------\n");
    while (fgets(linha, sizeof(linha), file) != NULL) // loop para ler as linhas do arquivo
    {
        int id;
        char nome[40];

        if (sscanf(linha, "ID:%d, Nome:%39[^\n]", &id, nome) == 2)
        {
            printf("%-5d | %-40s\n", id, nome);
        }
    }
}