#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.c"

int main(){
    
    clock_t inicio, fim; // Variáveis para a contagem do tempo do algoritmo
    double tempo_execucao; // Variável para guardar o tempo de execução do algoritmo
    
    FILE *arch = fopen("ListaDeAlunos.txt", "w+"); // Abre e cria um arquivo no modo "write" (escrita)
    if(arch==NULL){
        printf("Erro ao abrir arquivo!");
        exit(1);
    }
    int n, i; /* Declaração de uma variável que armazena e define a quantidade de pessoas
    que serão cadastradas "n" e uma variavel de contagem "i" */

    // Criaçao de ponteiro do tipo da struct Aluno. Chamada da função que será usada para alocar um vetor de Aluno
    // Atribuição do valor que será retornado da função que aloca um vetor para o ponteiro da struct do tipo Aluno
    Aluno* p= AlocaAlunos(arch);
    Documento* d= AlocaDocumento();

    ordenaAlunos(n, p);
    ImprimeAluno(n, p);
    for (i = 0; i < n; i++){
        fprintf(arch, "%s\n%i\n%i\n\n", p[i].nome, p[i].mat, p[i].d.CPF);
    }

    fclose(arch);
    free(p); // Liberando espaço alocado dinamicamente da struct "Aluno"
    free(d); // Liberando espaço alocado dinamicamente da union "Documento"
    printf("\nPrograma finalizado!\n");
    system("pause");
    printf("\n\n");
    
    fim = clock(); // "fim" recebe o tempo de execução
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC; // "tempo_execucao" recebe o resultado da divisão entre tempo "inicio" e tempo "fim"
    printf("Tempo de execução: %f segundos\n", tempo_execucao) // Amostragem do tempo de execução
        
    return 0;
}
