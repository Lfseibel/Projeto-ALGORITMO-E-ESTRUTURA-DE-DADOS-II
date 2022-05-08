#include <stdio.h>
#include "merge.h"
#include <time.h>
#include <stdlib.h>

int main(void) 
{
  char nomeArquivo[30];
  int tamanho = 100;
  int *vet;
  double time_spent = 0.0;
  int contadorTroca = 0;
  int contadorInteracao = 0;
	
  printf("Digite o nome do arquivo: \n");
  scanf("%s", nomeArquivo);

//////////////////////////////////////////////////////////////
  geraAleatorios(nomeArquivo, tamanho); 
  vet = leArquivo(nomeArquivo, tamanho);
  
  clock_t begin = clock();
  mergeSort(vet, 0, tamanho-1, &contadorTroca, &contadorInteracao); 
  clock_t end = clock();
  
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  
  resultadoMergeS ("Aleatório", contadorTroca, contadorInteracao, tamanho, time_spent);
  
  free(vet);
////////////////////////////////////////////////////////////// 
  contadorTroca = 0;
  contadorInteracao = 0;
  geraCrescente(nomeArquivo, tamanho);
  vet = leArquivo(nomeArquivo, tamanho);
  
  time_spent = 0.0;
  
  begin = clock();
  mergeSort(vet, 0, tamanho-1, &contadorTroca, &contadorInteracao);
  end = clock();
  
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  resultadoMergeS ("Crescente", contadorTroca, contadorInteracao, tamanho, time_spent);
  
  free(vet);

//////////////////////////////////////////////////////////////
  contadorTroca = 0;
  contadorInteracao = 0;
  geraDecrescente(nomeArquivo, tamanho);
  vet = leArquivo(nomeArquivo, tamanho);
  
  time_spent = 0.0;
  
  begin = clock();
  mergeSort(vet, 0, tamanho-1, &contadorTroca, &contadorInteracao);
  end = clock();
  
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  
  resultadoMergeS ("Decrescente", contadorTroca, contadorInteracao, tamanho, time_spent);
  
  free(vet);

 
  return 0;
}
