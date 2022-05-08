#ifndef HEAP
#define HEAP


int geraCrescente(char *nomeArquivo, int qtd);

int geraDecrescente(char *nomeArquivo, int qtd);

int geraAleatorios(char *nomeArquivo, int qtd);

int* leArquivo(char *nomeArquivo, int qtd);

void imprimeVet(int *vet, int tam);

void swap(int *a, int *b, int *contadorTroca);

void heapify(int arr[], int n, int i, int *contadorTroca, int *contadorInteracao);

void heapSort(int arr[], int n, int *contadorTroca, int *contadorInteracao);

void printArray(int arr[], int n);

void resultadoHeapS (char tipo[], int trocas, int interacoes, int tam, double time_spent);
#endif 