#include <stdio.h>
#include "merge.h"
#include <stdlib.h>
#include <time.h>

int geraAleatorios(char *nomeArquivo, int qtd)
{
  FILE *arq; //cria o ponteiro pra arquivo
  srand(time(0)); //faz com que os numeros aleatórios não sejam sempre os mesmo
  arq = fopen(nomeArquivo,"w"); //abre o arquivo pra inserção
  if(arq == NULL){ //se ocorrer erro ao abrir o arquivo retorna 1;
    return 1;
  }
  for(int i=0; i <= qtd-1; i++) //for pra gerar qtd de numeros aleatórios
  {
    fprintf(arq,"%d\n", rand() % 1000);//insere no arquivo um numero aleatório
  };
  fclose(arq); // fecha o arquivo 
  return 0;
};

int* leArquivo(char *nomeArquivo, int qtd)
{
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

int geraCrescente(char *nomeArquivo, int qtd)
{
  FILE *arq; //cria o ponteiro pra arquivo
  
  arq = fopen(nomeArquivo,"w"); //abre o arquivo pra inserção
  if(arq == NULL){ //se ocorrer erro ao abrir o arquivo retorna 1;
    return 1;
  }
  for(int i=0; i <= qtd-1; i++) //for pra gerar qtd de numeros aleatórios
  {
    fprintf(arq,"%d\n", i);//insere no arquivo um numero aleatório
  };
  fclose(arq); // fecha o arquivo 
  return 0;
};

int geraDecrescente(char *nomeArquivo, int qtd)
{
  FILE *arq; //cria o ponteiro pra arquivo
  
  arq = fopen(nomeArquivo,"w"); //abre o arquivo pra inserção
  if(arq == NULL){ //se ocorrer erro ao abrir o arquivo retorna 1;
    return 1;
  }
  for(int i = qtd; i>=0; i--) //for pra gerar qtd de numeros aleatórios
  {
    fprintf(arq,"%d\n", i);//insere no arquivo um numero aleatório
  };
  fclose(arq); // fecha o arquivo 
  return 0;
};

void imprimeVet(int *vet, int tam)
{
  for(int i=0; i < tam; i++)
  {
    printf("%d ", vet[i]);
  }
  printf("\n");
};

void mergeSort(int *vet, int inicio, int fim, int *contadorTroca, int *contadorInteracao)
{
  if (inicio < fim) 
  {
    
    // m é a metade do vetor
    int m = inicio + (fim - inicio) / 2;

    mergeSort(vet, inicio, m, contadorTroca, contadorInteracao);
    mergeSort(vet, m + 1, fim, contadorTroca, contadorInteracao);

    // realiza o merge
    merge(vet, inicio, m, fim, contadorTroca, contadorInteracao);
  }
};

void merge(int *vet, int inicio, int meio, int fim, int *contadorTroca, int *contadorInteracao)
{
  
  int mV1 = inicio, mV2 = meio+1, i = 0, j; //Marcador V1, marcador V2, contador do vetor auxiliar, contador de vet para cópia final
  int *vetAux = (int *) malloc(sizeof(int) * (fim-inicio)+1); // Vetor auxiliar 
  
  while(mV1 <= meio && mV2 <= fim){

		*contadorInteracao +=1;
		
    if(vet[mV1] < vet[mV2]){
			*contadorTroca +=1;
      vetAux[i] = vet[mV1];
      mV1++;
    }
    else{
			*contadorTroca+=1;
      vetAux[i] = vet[mV2];
      mV2++;
    }
    i++;
  }

  // Cópia do resto do vetor 1 ou 2 para o vetor auxiliar
  while(mV1<=meio){
    *contadorTroca+=1;
    vetAux[i] = vet[mV1];
    i++;
    mV1++;
  }

  while(mV2 <=fim){
    *contadorTroca+=1;
    vetAux[i] = vet[mV2];
    i++;
    mV2++;
  }


  // Copia o vetor auxiliar para o vetor original
  i = 0; // Reiniciando a variável contadora do vetor auxiliar
  for(j = inicio; j<=fim; j++){
    *contadorTroca+=1;
    vet[j] = vetAux[i];
    i++;
  }
  
};

void resultadoMergeS (char tipo[], int trocas, int interacoes, int tam, double time_spent)
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

