#include <stdio.h>
#include "selecao.h"
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
    fprintf(arq,"%d\n", rand() % 100000);//insere no arquivo um numero aleatório
  };
  fclose(arq); // fecha o arquivo 
  return 0;
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

int *leArquivo(char *nomeArquivo, int qtd)
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
//Esta função lê 'qtd' dados do arquivo 'nomeArquivo' e os insere em um vetor de inteiros
//A função retorna NULL caso haja algum erro no processo.

void selecao(char tipo[], int *vet, int tam )
{
  int interacoes = 0;
  int trocas = 0;
  int position, aux; //cria as variaves de posicao e a auxiliar

  for(int i = 0; i < tam - 1; i++)
  {
    position=i; //define a posicao como o valor de i
    for(int j = i + 1; j < tam; j++)
    {
      if(vet[position] > vet[j])//caso o vetor em posicao for maior que o vetor em J, a posicao passa a ser J
      {
        interacoes++;
        position=j; 
      } 
    }
    if(position != i)//se a posicao for diferente de i troca os valores do vetor
    {
      trocas++;
      aux=vet[i];
      vet[i]=vet[position];
      vet[position]=aux;
    }
  }

  resultadoSelecao(tipo, trocas, interacoes, tam);
};
//Esta função recebe um vetor de inteiros de tamanho 'tam' e o ordena (ordem crescente) utilizando o método seleção
void resultadoSelecao (char tipo[], int trocas, int interacoes, int tam)
{
  FILE *arq; //cria o ponteiro pra arquivo
  arq = fopen("Resultado","a"); //abre o arquivo no modo leitura
  fprintf(arq,"Número de dados: %d\n", tam);
  fprintf(arq,"Tipo de ordem: %s\n", tipo);
  fprintf(arq,"Número de interações: %d\n", interacoes);
  fprintf(arq,"Número de trocas: %d\n", trocas);
  fclose(arq);
};

void resultadoTempo (double time_spent)
{
  FILE *arq; //cria o ponteiro pra arquivo
  arq = fopen("Resultado","a"); //abre o arquivo no modo leitura
  fprintf(arq,"Tempo de execução: %lf\n", time_spent);
  fprintf(arq,"-------------\n");
  fclose(arq);
};

void imprimeVet(int *vet, int tam)
{
  for(int i=0; i < tam; i++)
  {
    printf("%d ", vet[i]);
  }
  printf("\n");
};
//Esta função recebe um vetor e o imprime na tela
//A impressão é em linha -> printf("%d ", vet[i]);
//Antes de encerrar, a função imprime uma linha em branco
