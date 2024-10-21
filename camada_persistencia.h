#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio_ext.h>

// Constante
#define QTDREGISTRO 100

//Struct contendo os valores tabelados que compoem um boletim
typedef struct{
    int ID, RA, Semestre;
    float T1, T2, P1, P2, MF, PM;
    char Disciplinas[40], Situacao[30];
} registro;

// Função para atribuir os valores do arquivo ao Struct
void CarregarDadosArquivo(registro notas[], int *qntRegistradoNotas) {
    //Le o arquivo notas.txt
	FILE *file = fopen("notas.txt", "r");
	
	//Verificação pra caso o arquivo ainda não exista
    if (file == NULL) {
        return; // Arquivo ainda não existe
    }
    
    //Looping para Inserir todos os valores contidos no arquivo dentro do Struct
    while (fscanf(file, "%d %d %d %s %f %f %f %f %f %f %s", &notas[*qntRegistradoNotas].ID, &notas[*qntRegistradoNotas].RA,
        &notas[*qntRegistradoNotas].Semestre, notas[*qntRegistradoNotas].Disciplinas, &notas[*qntRegistradoNotas].T1, &notas[*qntRegistradoNotas].T2, &notas[*qntRegistradoNotas].P1, &notas[*qntRegistradoNotas].P2, &notas[*qntRegistradoNotas].PM, &notas[*qntRegistradoNotas].MF, notas[*qntRegistradoNotas].Situacao) != EOF) {
        (*qntRegistradoNotas)++;
    }
    
    //Fecha o acesso ao arquivo
    fclose(file);
}

//Função para salvar os dados, armazenados na Struct, no arquivo
void salvarDados(registro notas[], int qntRegistradoNotas) {
    //Sobreescreve o arquivo notas.txt (ou cria caso o arquivo nao exista)
    FILE *file = fopen("notas.txt", "w");
    
    //Verificação pra caso o arquivo ainda não exista
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    //Looping para salvar todos os valores contidos no Struct dentro do arquivo
    for (int i = 0; i < qntRegistradoNotas; i++) {
        fprintf(file, "%d %d %d %s %.1f %.1f %.1f %.1f %.1f %.2f %s\n", notas[i].ID, notas[i].RA,
        notas[i].Semestre, notas[i].Disciplinas, notas[i].T1, notas[i].T2, notas[i].P1, notas[i].P2, notas[i].PM, notas[i].MF, notas[i].Situacao);
    }
    //Fecha o acesso ao arquivo
    fclose(file);
}

// Função para buscar nota de um Aluno
int BuscarNota(registro notas[], int qntRegistradoNotas){
    //variaveis que auxiliam na função
    int aux = 0, busca, i;
    
    //Requisição do RA do aluno
    printf("Digite o RA do aluno a qual deseja ver a nota: ");
    scanf("%d", &busca); // Variavel que armazena o RA solicitado
        
    //Looping para mostrar os registros do aluno 
    for(i = 0; i < qntRegistradoNotas; i++){
        if(notas[i].RA == busca){
            printf("-----%d° Registro-----\n", notas[i].ID);
            printf("RA: %d\n", notas[i].RA);
            printf("Semestre: %d\n", notas[i].Semestre);
            printf("Disciplina: %s\n", notas[i].Disciplinas);
            printf("    -----Notas-----\n");
            printf("    T1: %.1f\n", notas[i].T1);
            printf("    P1: %.1f\n", notas[i].P1);
            printf("    T2: %.1f\n", notas[i].T2);
            printf("    P2: %.1f\n", notas[i].P2);
            printf("    PM: %.1f\n", notas[i].PM);
            printf("    Média Final: %.2f\n", notas[i].MF);
            printf("    ---------------\n");
            printf("Situação: %s\n", notas[i].Situacao);
            printf("---------------------\n\n");
                
            aux++;//incremento após encontrar um registro
        }
    }
    
    //caso nenhum registro tenha sido encontrado
    if(aux == 0){
        printf("Nenhum registro de notas encontrado!\n");
    }
    return 0;
}

// Função para adicionar um boletim de Nota
void AdicionarNotas(registro notas[], int *qntRegistradoNotas){
    //variaveis que auxiliam na função
    int i, aux = 1;
    
    //Verificando se o limite de registros foi atingido
    if (*qntRegistradoNotas < QTDREGISTRO) {
        
        //inicio do processo de cadastro
        printf("----------Cadastro de Notas----------\n\n");
        
        notas[*qntRegistradoNotas].ID = *qntRegistradoNotas + 1;
        
        printf("Digite o RA do aluno: ");
        scanf(" %d", &notas[*qntRegistradoNotas].RA);
        
        printf("Digite a semestre do aluno: ");
        scanf("%d", &notas[*qntRegistradoNotas].Semestre);
        __fpurge(stdin);
        
        printf("Digite a disciplina do aluno: ");
        scanf("%[^\n]", notas[*qntRegistradoNotas].Disciplinas);
        
        //looping de verifiçãopara caso este RA já possua um registro com o semestre e a disciplina digitados
        for(i = 0; i < *qntRegistradoNotas; i++){
            
            //Verifica se existe
            if(notas[i].RA == notas[*qntRegistradoNotas].RA && notas[i].Semestre == notas[*qntRegistradoNotas].Semestre && strcmp(notas[i].Disciplinas, notas[*qntRegistradoNotas].Disciplinas) == 0){
                printf("\nAs notas deste aluno já foram atribuidas na matéria!\n");
                aux--;
                
            } else{
                
            }
        }
    
        if(aux == 0){
            printf("-------------------------------------\n\n");
        } else{
            //Inserção das notas, após as verificações terem sido realizadas
            printf("\n-----Notas-----\n");
        
            printf("T1: ");
            scanf("%f", &notas[*qntRegistradoNotas].T1);
            
            printf("P1: ");
            scanf("%f", &notas[*qntRegistradoNotas].P1);
            
            printf("T2: ");
            scanf("%f", &notas[*qntRegistradoNotas].T2);
            
            printf("P2: ");
            scanf("%f", &notas[*qntRegistradoNotas].P2);
            
            printf("PM: ");
            scanf("%f", &notas[*qntRegistradoNotas].PM);
            
            //calculo das notas para compor a média final
            notas[*qntRegistradoNotas].MF = ((((notas[*qntRegistradoNotas].T1 * 0.4) + (notas[*qntRegistradoNotas].P1 * 0.6)) + ((notas[*qntRegistradoNotas].T2 * 0.4) + (notas[*qntRegistradoNotas].P2 * 0.6)))/2 + notas[*qntRegistradoNotas].PM);
            
            //Correção de valor caso o resultado final ultrapasse 10 (caso o usuarion já tivesse tirado 10 antes de adicionar a nota da PM)
            if(notas[*qntRegistradoNotas].MF > 10){
                notas[*qntRegistradoNotas].MF = 10;
            }
            
            //Verificação da média final para delimitar se o usuario está aprovado ou reprovado
            if(notas[*qntRegistradoNotas].MF >= 6.0){
                strcpy(notas[*qntRegistradoNotas].Situacao, "Aprovado");
            } else{
                strcpy(notas[*qntRegistradoNotas].Situacao, "Reprovado");
            }
            (*qntRegistradoNotas)++;
            
            printf("\nNota cadastrada com sucesso na ficha do Aluno: %d, na Disciplina %s\n\n", notas[*qntRegistradoNotas].RA, notas[*qntRegistradoNotas].Disciplinas);
            
            printf("-------------------------------------");
        }
    } else {
        printf("Limite de notas atingido.\n");
    }
}

//Função para listar todos os registros de notas
void ListarNotas(registro notas[], int qntRegistradoNotas){
    //Looping para listar todos os registros de boletim no sistema
    if(qntRegistradoNotas != 0){
        for (int i = 0; i < qntRegistradoNotas; i++) {
            printf("-----%d° Registro-----\n", notas[i].ID);
            printf("RA: %d\n", notas[i].RA);
            printf("Semestre: %d\n", notas[i].Semestre);
            printf("Disciplina: %s\n", notas[i].Disciplinas);
            printf("    -----Notas-----\n");
            printf("    T1: %.1f\n", notas[i].T1);
            printf("    P1: %.1f\n", notas[i].P1);
            printf("    T2: %.1f\n", notas[i].T2);
            printf("    P2: %.1f\n", notas[i].P2);
            printf("    PM: %.1f\n", notas[i].PM);
            printf("    Média Final: %.2f\n", notas[i].MF);
            printf("    ---------------\n");
            printf("Situação: %s\n", notas[i].Situacao);
            printf("---------------------\n\n");
        }
    } else{
        printf("Nenhum registro inserido até o momento!\n");
    }
    
}