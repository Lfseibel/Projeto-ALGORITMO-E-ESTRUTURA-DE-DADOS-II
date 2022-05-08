#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "heap.h"

int geraCrescente(char *nomeArquivo, int qtd)
{
  FILE *arq; //cria o ponteiro pra arquivo
  
  arq = fopen(nomeArquivo,"w"); //abre o arquivo pra inserção
  if(arq == NULL)
  { //se ocorrer erro ao abrir o arquivo retorna 1;
    return 1;
  }
  for(int i=0; i <= qtd-1; i++) //for pra gerar qtd de numeros aleatórios
  {
    fprintf(arq,"%d\n", i);//insere no arquivo um numero aleatório
  };
  fclose(arq); // fecha o arquivo 
  return 0;
};

int geraDecrescente(char *nomeArquivo, int qtd){
  FILE *arq; //cria o ponteiro pra arquivo
  
  arq = fopen(nomeArquivo,"w"); //abre o arquivo pra inserção
  if(arq == NULL)
  { //se ocorrer erro ao abrir o arquivo retorna 1;
    return 1;
  }
  for(int i = qtd; i>=0; i--) //for pra gerar qtd de numeros aleatórios
  {
    fprintf(arq,"%d\n", i);//insere no arquivo um numero aleatório
  };
  fclose(arq); // fecha o arquivo 
  return 0;
};

int geraAleatorios(char *nomeArquivo, int qtd){
  FILE *arq; //cria o ponteiro pra arquivo
  srand(time(0)); //faz com que os numeros aleatórios não sejam sempre os mesmo
  arq = fopen(nomeArquivo,"w"); //abre o arquivo pra inserção
  if(arq == NULL)
  { //se ocorrer erro ao abrir o arquivo retorna 1;
    return 1;
  }
  for(int i=0; i <= qtd-1; i++) //for pra gerar qtd de numeros aleatórios
  {
    fprintf(arq,"%d\n", rand() % 1000);//insere no arquivo um numero aleatório
  };
  fclose(arq); // fecha o arquivo 
  return 0;
};

int* leArquivo(char *nomeArquivo, int qtd){
  FILE *arq; //cria o ponteiro pra arquivo
  arq = fopen(nomeArquivo,"r"); //abre o arquivo no modo leitura
  if(arq == NULL)
  {
    return NULL;
  }
  int *vetor = NULL; //cria o vetor
  vetor = (int*)malloc((qtd-1)*sizeof(int)); //aloca o vetor

  for(int i=0; i < qtd; i++)
  {
    fscanf(arq, "%d/n", &vetor[i]);//preenche o vetor
  };
  fclose(arq);//fecha o arquivo
  return vetor;//retorna o vetor
};

void imprimeVet(int *vet, int tam){
  for(int i=0; i < tam; i++)
  {
    printf("%d ", vet[i]);
  }
  printf("\n");
};

void swap(int *a, int *b, int *contadorTroca) 
{
  *contadorTroca += 1;
  int temp = *a;
  *a = *b;
  *b = temp;
}
  
void heapify(int *arr, int n, int i, int *contadorTroca, int *contadorInteracao) 
{
 
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  *contadorInteracao += 1;
  if (left < n && arr[left] > arr[largest])
  {
    *contadorTroca += 1;
    largest = left;
  }
  *contadorInteracao += 1;
  if (right < n && arr[right] > arr[largest])
  {
    *contadorTroca += 1;
    largest = right;
  }
  
  *contadorInteracao += 1;
  if (largest != i) 
  {
    swap(&arr[i], &arr[largest], contadorTroca);
    heapify(arr, n, largest, contadorTroca, contadorInteracao);
  }
}

void heapSort(int *arr, int n, int *contadorTroca, int *contadorInteracao) 
{  
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i, contadorTroca, contadorInteracao);
  }
     
  // Heap sort
  for (int i = n - 1; i >= 0; i--) 
  {
    swap(&arr[0], &arr[i], contadorTroca);
    
    heapify(arr, i, 0, contadorTroca, contadorInteracao);
  }
}

void printArray(int *arr, int n) 
{
  for (int i = 0; i < n; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void resultadoHeapS (char tipo[], int trocas, int interacoes, int tam, double time_spent)
{
  FILE *arq; //cria o ponteiro pra arquivo
  arq = fopen("Resultado","a"); //abre o arquivo no modo leitura
  fprintf(arq,"Número de dados: %d\n", tam);
  fprintf(arq,"Tipo de ordem: %s\n", tipo);
  fprintf(arq,"Número de interações: %d\n", interacoes);
  fprintf(arq,"Número de trocas: %d\n", trocas);
  fprintf(arq,"Tempo de execução: %lf\n", time_spent);
  fprintf(arq,"-------------\n");
  fclose(arq);
};
