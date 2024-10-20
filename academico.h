#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

typedef struct
{
	int ID, RA, Semestre;
	float T1, T2, P1, P2, MF, PM;
	char Disciplinas[40], Situacao[30], Turma[30];
} registro;


void CarregarDadosArquivo(registro *alunos, int *qntRegistrado, const char *nomeArquivo) {
	FILE *file = fopen(nomeArquivo, "r");
	if (file == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return;
	}

	char linha[150];
	i = 0;
	while (fgets(linha, sizeof(linha), file) != NULL && i < 100) {  // Limite de 100 alunos
		if (strstr(linha, "RA:") != NULL) {
			sscanf(linha, "RA: %d", &alunos[i].RA);

			// Ler outras informaC'C5es relacionadas ao aluno
			fgets(linha, sizeof(linha), file);
			sscanf(linha, "ID: %d", &alunos[i].ID);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "Semestre: %d", &alunos[i].Semestre);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "T1: %f", &alunos[i].T1);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "T2: %f", &alunos[i].T2);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "P1: %f", &alunos[i].P1);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "P2: %f", &alunos[i].P2);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "MF: %f", &alunos[i].MF);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "PM: %f", &alunos[i].PM);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "Disciplina: %s", alunos[i].Disciplinas);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "Situacao: %s", alunos[i].Situacao);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "Turma: %s", alunos[i].Turma);

			i++;
		}

	}
	while (fgets(linha, sizeof(linha), file) != NULL && i < 100) {  // Limite de 100 alunos
		if (strstr(linha, "RA:") != NULL) {
			sscanf(linha, "RA: %d", &alunos[i].RA);

			fgets(linha, sizeof(linha), file);
			sscanf(linha, "Disciplina: %s", alunos[i].Disciplinas);
			i++;
		}
	}
	*qntRegistrado = i;  // Atualizar a quantidade de registros
	fclose(file);
}

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
			printf("\nRegistro com RA %d nC#o encontrado.\n", busca);
		}

		fclose(file);

		printf("\n\nPressione (0) para voltar ao menu\n");
		printf("Pressione (1) para buscar outro aluno: ");
		scanf("%d", &Escolha);

	} while (Escolha != 0);

	return 0;
}

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

	fprintf(file, "\nRA: %d,\nID: %d\nSemestre: %d,\nT1: %.2f,\nT2: %.2f,\nP1: %.2f,\nP2: %.2f,\nPM: %.2f,\nMF: %.2f,\nDisciplina: %s,\nSituacao: %s,\nTurma: %s\n",
	        aluno->RA, aluno->ID, aluno->Semestre, aluno->T1, aluno->T2, aluno->P1, aluno->P2, aluno->PM, aluno->MF,aluno->Disciplinas, aluno->Situacao, aluno->Turma);
	fclose(file);
}



void AdicionarAluno(registro *aluno, int *qntRegistrado)
{
    //abro o arquivo em modo de leitura
    FILE *file = fopen("alunos.txt", "r");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    //aqui vamos adicionar o que é nessessario para inserir o cadastro do aluno
    printf("Informe a disciplina em que vai adicionar o aluno: ");
    getchar();
    fgets(aluno->Disciplinas, 40, stdin);
    aluno->Disciplinas[strcspn(aluno->Disciplinas, "\n")] = 0;

    printf("\nInforme o RA do aluno: ");
    scanf("%d", &aluno->RA);
    getchar();
    printf("\nInforme o Semestre do aluno: ");
    scanf("%d", &aluno->Semestre);
    getchar();
    printf("\nInforme a Turma do aluno: ");
    scanf("%s", aluno->Turma);
    getchar();

    //crio umas variaveis para a as condiçoes
    char linha[150];
    int RAatual, SemestreAtual, alunoExistente = 0;
    char TurmaAtual[30], DisciplinaAtual[50];

    //vou navegar entre as linhas para verificar se cada linha tem o ra 
    while (fgets(linha, sizeof(linha), file) != NULL) {  
        if (sscanf(linha, "RA: %d,", &RAatual) == 1) {
            //pego os dados do ra 
            fgets(linha, sizeof(linha), file);
            
            
            sscanf(linha, "Semestre: %d,", &SemestreAtual);
            //pego os dados do semestre
            fgets(linha, sizeof(linha), file);
            
            sscanf(linha, "Turma: %s,", TurmaAtual);
            //pego os dados da turma
            fgets(linha, sizeof(linha), file);
            //pego os dados da disciplina
            sscanf(linha, "Disciplina: %s,", DisciplinaAtual);


            //verifico se esses coletados na verificacao batem com o que o usuario digitou
            if (RAatual == aluno->RA && SemestreAtual == aluno->Semestre &&
                strcmp(TurmaAtual, aluno->Turma) == 0 && strcmp(DisciplinaAtual, aluno->Disciplinas) == 0) {
                //se sim adiciono na variavel alunoExistente e paro com o loop
                alunoExistente = 1;
                break;
            }
        }
    }
    fclose(file);
    
    //verifico se a variavel alunoExistente é true e passo a mensagem
    if (alunoExistente) {
        printf("Aluno já cadastrado!\n");
    } else {
        //se nao abro o arquivo no modo de inserir
        file = fopen("alunos.txt", "a");
        if (file == NULL) {
            printf("Erro ao abrir o arquivo para escrita.\n");
            return;
        }
        //coloco as notas como 0 apenas para inicializar
        aluno->ID = 0;
        aluno->T1 = 0;
        aluno->T2 = 0;
        aluno->P1 = 0;
        aluno->P2 = 0;
        aluno->PM = 0;
        aluno->MF = 0;

        //crio a estrutura para colocar todos os dados no arquivo
        fprintf(file, "\nRA: %d,\nID: %d,\nSemestre: %d,\nT1: %.2f,\nT2: %.2f,\nP1: %.2f,\nP2: %.2f,\nPM: %.2f,\nMF: %.2f,\nDisciplina: %s,\nSituacao: %s,\nTurma: %s\n",
                aluno->RA, aluno->ID, aluno->Semestre, aluno->T1, aluno->T2, aluno->P1, aluno->P2, aluno->PM, aluno->MF, aluno->Disciplinas, aluno->Situacao, aluno->Turma);

        printf("Aluno cadastrado com sucesso!\n");
        fclose(file);
        //por algum motivo a logica nao esta funcinando, tem a capacidade de adicioar dados identicos.
    }
}
