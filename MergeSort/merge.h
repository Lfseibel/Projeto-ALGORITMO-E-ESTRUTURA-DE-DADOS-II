//
// Created by Vanessa on 22/04/2022.
//

#ifndef LISTA_4_MERGEQUICK_H
#define LISTA_4_MERGEQUICK_H


int geraAleatorios(char *nomeArquivo, int qtd);

int geraCrescente(char *nomeArquivo, int qtd);

int geraDecrescente(char *nomeArquivo, int qtd);

int* leArquivo(char *nomeArquivo, int qtd);
//Esta função lê 'qtd' dados do arquivo 'nomeArquivo' e os insere em um vetor de inteiros
//A função retorna NULL caso haja algum erro no processo.

void imprimeVet(int *vet, int tam);
//Esta função recebe um vetor e o imprime na tela
//A impressão é em linha -> printf("%d ", ...);
//Antes de encerrar, a função imprime uma linha em branco

void mergeSort(int *vet, int inicio, int fim, int *contadorTroca, int *contadorInteracao);
//Função Mergesort Recursiva

void merge(int *vet, int inicio, int meio, int fim, int *contadorTroca, int *contadorInteracao);
//Função Merge, que combina dois vetores previamente ordenados

void resultadoMergeS (char tipo[], int trocas, int interacoes, int tam, double time_spent);
#endif //LISTA_4_MERGEQUICK_H