#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "selecao.h"


int main(void) 
{
  char nomeArquivo[30];
  int *vet;
  int tamanho = 1000000;//10000, 100000, 500000, 1000000
  double time_spent = 0.0;
  printf("Digite o nome do arquivo: \n");
  scanf("%s", nomeArquivo);
//////////////////////////////////////////////////////////////
  geraAleatorios(nomeArquivo, tamanho); 
  vet = leArquivo(nomeArquivo, tamanho);
  clock_t begin = clock();
  selecao("Aleatorio", vet, tamanho);
  clock_t end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	
  resultadoTempo(time_spent);
  free(vet);

	//////////////////////////////////////////////////////////////
  geraCrescente(nomeArquivo, tamanho);
  vet = leArquivo(nomeArquivo, tamanho);
  
  time_spent = 0.0;
  begin = clock();
  selecao("Crescente", vet, tamanho);
  end = clock();
  
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  
  resultadoTempo(time_spent);
  free(vet);

	//////////////////////////////////////////////////////////////
  geraDecrescente(nomeArquivo, tamanho);
  vet = leArquivo(nomeArquivo, tamanho);
  
  time_spent = 0.0;
  begin = clock();
  selecao("Decrescente", vet, tamanho);
  end = clock();
  time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
  
  resultadoTempo(time_spent);
  
  free(vet);
  
  return 0;
}
