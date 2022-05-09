#ifndef LISTA_4_MERGEQUICK_H
#define LISTA_4_MERGEQUICK_H


int geraAleatorios(char *nomeArquivo, int qtd);

int geraCrescente(char *nomeArquivo, int qtd);

int geraDecrescente(char *nomeArquivo, int qtd);

int* leArquivo(char *nomeArquivo, int qtd);

void imprimeVet(int *vet, int tam);

void quickSort(int *vet, int inicio, int fim, int *contadorTroca, int *contadorInteracao);

int particiona(int *vet, int inicio, int fim, int *contadorTroca, int *contadorInteracao);

void resultadoQuickS (char tipo[], int trocas, int interacoes, int tam, double time_spent);

#endif
