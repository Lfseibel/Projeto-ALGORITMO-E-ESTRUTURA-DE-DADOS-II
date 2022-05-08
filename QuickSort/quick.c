#include <stdio.h>
#include "quick.h"
#include <stdlib.h>
#include <time.h>

int geraAleatorios(char *nomeArquivo, int qtd)
{
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


void imprimeVet(int *vet, int tam)
{
  for(int i=0; i < tam; i++)
  {
    printf("%d ", vet[i]);
  }
  printf("\n");
};

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

int geraDecrescente(char *nomeArquivo, int qtd)
{
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

void quickSort(int *vet, int inicio, int fim, int *contadorTroca, int *contadorInteracao)
{
	
  if (inicio < fim) 
  {
    // Pivo do elemento
    int pi = particiona(vet, inicio, fim, contadorTroca, contadorInteracao);
    // esquerda
    quickSort(vet, inicio, pi - 1, contadorTroca, contadorInteracao);
    // direita
    quickSort(vet, pi + 1, fim, contadorTroca, contadorInteracao);
  }
	
  //printf("\n---- %d", *contadorRecursivo);
};


int particiona(int *vet, int inicio, int fim, int *contadorTroca, int *contadorInteracao)
{
  int pivo = vet[inicio]; 
  int posicaoPivo = inicio;
  int auxiliar, i;

  // Coloca os elementos menores para esquerda e incrementa a posição do pivo
	
  for(i = inicio+1; i<=fim; i++)
  {
    *contadorInteracao += 1;
    if(vet[i]<pivo)
    {
      *contadorInteracao += 1;
      posicaoPivo++;
      if(i!=posicaoPivo)
      {
        auxiliar = vet[i];
        vet[i] = vet[posicaoPivo];
        vet[posicaoPivo] = auxiliar;
        *contadorTroca +=1;
      }
    }
  }
	
  // Coloca o pivo em sua devida posição 
  *contadorInteracao += 1;
  if (posicaoPivo != inicio)
  {
    *contadorTroca +=1;
    auxiliar = vet[inicio];
    vet[inicio] = vet[posicaoPivo];
    vet[posicaoPivo] = auxiliar;
  }
	
  return posicaoPivo;
};

void resultadoQuickS (char tipo[], int trocas, int interacoes, int tam, double time_spent)
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

