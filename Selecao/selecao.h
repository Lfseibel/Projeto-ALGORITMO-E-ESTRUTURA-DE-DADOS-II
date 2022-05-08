#ifndef SELECAO
#define SELECAO

int geraAleatorios(char *nomeArquivo, int qtd);

int geraCrescente(char *nomeArquivo, int qtd);

int geraDecrescente(char *nomeArquivo, int qtd);

int *leArquivo(char *nomeArquivo, int qtd);

void selecao(char tipo[],int *vet, int tam);

void resultadoSelecao (char tipo[], int trocas, int interacoes, int tam);

void resultadoTempo (double time_spent);

void imprimeVet(int *vet, int tam);

#endif 