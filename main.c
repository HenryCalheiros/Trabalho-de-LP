/******************************************************************************

Disciplina: Linguagem de Programação;

Integrantes: Augusto Andrade, Henry Calheiros, Matheus Ferreira, Otavio Rodrigues;

Descrição do problema: Este programa cuida da inserção, manipulação e consulta de notas alunos;

Descrição do Algoritmo: Oferece ao usuario um menu, onde ele seleciona a opção desejada. Ao seleciona-la, será chamada uma função referente a opção escolhida.

Identificação das variáveis de entrada e saída do algoritmo:
    escolhaOperacao
    escolhaConsulta
    buscar
    registro alunos[]
    
    

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "academico.h"



// Declaração de variáves globais
int i, escolhaOperacao, escolhaConsulta;

// Iniciando a variavel de contagem de registros
int qntRegistradoNotas = 0;  

//Atribuindo apelido a Struct
registro notas[QTDREGISTRO];

//Funções de Menu
void menuPrincipal();
void menuCadastro();
void menuConsulta();

int main(){
    
    // Insere os dados, que estão armazenado no arquivo, na Struct
    CarregarDadosArquivo(notas, &qntRegistradoNotas);
    
    // Looping do Menu principal
    do{
        printf("********** MENU **********");
        printf("\nBem vindo Professor! \n\n");
        printf("Escolha uma das opcoes:\n");
        printf("(1) Cadastrar Notas\n");
        printf("(2) Consultar\n");
        printf("(0) Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolhaOperacao);
        printf("**************************\n\n");
        

        switch (escolhaOperacao){
            case 0: // usuário escolheu encerrar o código
                salvarDados(notas, qntRegistradoNotas); // chamando a função para salvar os valores do struct no arquivo antes de encerrar o programa
            break;
            
            case 1: // usuário escolheu cadastrar
                AdicionarNotas(notas, &qntRegistradoNotas); // função para cadastrar um novo usuário
            break;
    
          case 2: // usuário escolheu consultar
            menuConsulta(); 
            break;
        }

    } while (escolhaOperacao != 0);

    return 0;
}

void menuConsulta(){
        printf("********** MENU DE CONSULTA**********");
        printf("\nBem vindo Professor! \n\n");
        printf("Escolha uma das opções:\n");
        printf("(1) Listar todas as notas\n");
        printf("(2) listar notas de um Aluno\n");
        printf("Escolha: ");
        scanf("%d", &escolhaConsulta); 
        printf("*************************************\n\n");

        switch (escolhaConsulta){
        
          case 1: // usuário escolheu consultar todos os notas
          ListarNotas(notas, qntRegistradoNotas);
          break;

          case 2: // usuário escolheu buscar um aluno
          BuscarNota(notas, qntRegistradoNotas);
          break;
        }  
}