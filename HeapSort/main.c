#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "heap.h"

int main() 
{

  char nomeArquivo[30];
  int tamanho = 100;
  int *vet;
  double time_spent = 0.0;
  int contadorTroca = 0;
  int contadorInteracao = 0;

  printf("Digite o nome do arquivo: \n");
  scanf("%s", nomeArquivo);

////////////////////////////////////////////////////////////////	
  geraAleatorios(nomeArquivo, tamanho); 
  vet = leArquivo(nomeArquivo, tamanho);
		
  clock_t begin = clock();
  heapSort(vet, tamanho, &contadorTroca, &contadorInteracao);
  clock_t end = clock();	

  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		
  resultadoHeapS ("Aleatório", contadorTroca, contadorInteracao, tamanho, time_spent);
    
  free(vet);

////////////////////////////////////////////////////////////////
  contadorTroca = 0;
  contadorInteracao = 0;
  geraCrescente(nomeArquivo, tamanho); 
  vet = leArquivo(nomeArquivo, tamanho);
	
  time_spent = 0.0;	
  begin = clock();
  heapSort(vet, tamanho, &contadorTroca, &contadorInteracao);
  end = clock();

  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		
  resultadoHeapS ("Crescente", contadorTroca, contadorInteracao, tamanho, time_spent);

  free(vet);
////////////////////////////////////////////////////////////////
  contadorTroca = 0;
  contadorInteracao = 0;
  geraDecrescente(nomeArquivo, tamanho); 
  vet = leArquivo(nomeArquivo, tamanho);
	
  time_spent = 0.0;	
  begin = clock();
  heapSort(vet, tamanho, &contadorTroca, &contadorInteracao);
  end = clock();

  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
		
  resultadoHeapS ("Decrescente", contadorTroca, contadorInteracao, tamanho, time_spent);

  free(vet);
 }
