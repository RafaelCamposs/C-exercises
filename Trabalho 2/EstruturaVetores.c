#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"


void dobrar(int *x){

    *x = *x * 2;


}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){
    
    int retorno = 0;
  
    if(posicao<1 ||posicao>10)
      retorno = POSICAO_INVALIDA;
    else if(tamanho<1)
      retorno = TAMANHO_INVALIDO;  
    else if(vetor[posicao-1].EstAux==NULL){
      vetor[posicao-1].EstAux=(int *) malloc(tamanho*sizeof(int));
      vetor[posicao-1].count=0;
      vetor[posicao-1].tam = tamanho-1;
      if(vetor[posicao-1].EstAux==NULL)
        retorno = SEM_ESPACO_DE_MEMORIA;
      else  
        retorno = SUCESSO;
    }
    else if(vetor[posicao-1].EstAux!=NULL){
      retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }

    return retorno;

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if(posicao<1 || posicao>10){
        posicao_invalida=1;
    }
    else if(vetor[posicao-1].EstAux != NULL)
        existeEstruturaAuxiliar = 1;
        if(vetor[posicao-1].count <= vetor[posicao-1].tam)
            temEspaco=1;


    if(posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else{
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar){
          if (temEspaco){
              //insere
              vetor[posicao-1].EstAux[vetor[posicao-1].count]= valor;
              vetor[posicao-1].count++;
              retorno = SUCESSO;
          }else{
              retorno = SEM_ESPACO;
          }
        }else{
          retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    int retorno;
    if(posicao < 1 || posicao > 10)
        retorno = POSICAO_INVALIDA;
    else if (vetor[posicao-1].EstAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(vetor[posicao-1].count == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{ 
        vetor[posicao-1].count--;
        retorno = SUCESSO;
    }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
    int retorno = SUCESSO;
    int x,y, GotHim=0;
    if(posicao<1 || posicao >10)
        retorno = POSICAO_INVALIDA;
    if(vetor[posicao-1].EstAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    if(vetor[posicao-1].count == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{
        for(x=0;x <= vetor[posicao-1].count;x++){
            if(valor == vetor[posicao-1].EstAux[x]){
                GotHim=1;
                retorno = SUCESSO;
                for(y=x;y <= vetor[posicao-1].count;y++)
                    vetor[posicao-1].EstAux[y]= vetor[posicao-1].EstAux[y+1];
            }
        }
        if(GotHim != 1)
            retorno = NUMERO_INEXISTENTE; 
    }
  
  return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;

}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;
    int x;
    if(ehPosicaoValida(posicao) != SUCESSO)
            retorno =  POSICAO_INVALIDA;
    else if(vetor[posicao-1].EstAux == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;
    else{
        for(x=0;x < vetor[posicao-1].count;x++)
            vetorAux[x]=vetor[posicao-1].EstAux[x];
    
        retorno = SUCESSO;
    }
    
    return retorno;

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;
    int x;
        
    if(ehPosicaoValida(posicao) != SUCESSO)
            retorno =  POSICAO_INVALIDA;
    else if(vetor[posicao-1].EstAux == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;
    else{
        for(x=0;x < vetor[posicao-1].count;x++)
            vetorAux[x]=vetor[posicao-1].EstAux[x];
        ordena(vetorAux,vetor[posicao-1].tam);
        retorno = SUCESSO;
    }
    

    return retorno;

}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0,i,j=0;
    int x;
    for(i=0;i<10;i++){    
        if(vetor[i].count == 0)
            j++;
    }
    if(j==10)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        for(x=0,i=0;i<10;i++){
            for(j=0;j < vetor[i].count;x++,j++)
                vetorAux[x]=vetor[i].EstAux[j];
        }
        retorno = SUCESSO;
    }
    
    return retorno;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0,i,j=0,tamtotal=0;
    int x;
    for(i=0;i<10;i++)
        tamtotal = vetor[i].count+tamtotal;
    
    for(i=0;i<10;i++){    
        if(vetor[i].count == 0)
            j++;
    }
    if(j==10)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        for(x=0,i=0;i<10;i++){
            for(j=0;j < vetor[i].count;x++,j++)
                vetorAux[x]=vetor[i].EstAux[j];
        }
        ordena(vetorAux,tamtotal);
        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno;
    if(ehPosicaoValida(posicao) != SUCESSO)
            retorno =  POSICAO_INVALIDA;
    else if(vetor[posicao-1].EstAux == NULL)
            retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(vetor[posicao-1].tam+1+novoTamanho <= 0)
            retorno = NOVO_TAMANHO_INVALIDO;
    else{
        novoTamanho = novoTamanho + vetor[posicao-1].tam+1;
        vetor[posicao-1].EstAux=(int *) realloc(vetor[posicao-1].EstAux,novoTamanho);
        if(vetor[posicao-1].tam+ 1 > novoTamanho)
            vetor[posicao-1].count = vetor[posicao-1].tam+1-novoTamanho-1;    
        vetor[posicao-1].tam=novoTamanho-1;
        if(vetor[posicao-1].EstAux == NULL)
            retorno = SEM_ESPACO_DE_MEMORIA;
        else
            retorno = SUCESSO;
    }
    
    return retorno;

}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorno = 0;

    if(posicao<1 || posicao >10)
        retorno = POSICAO_INVALIDA;
    if(vetor[posicao-1].EstAux == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    if(vetor[posicao-1].count == 0)
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
        retorno = vetor[posicao-1].count ;

    return retorno;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No* montarListaEncadeadaComCabecote(){
    
    int i,tam = 0,vazio = 0;
    
    tam = verificacontadores();
    vazio = verificarestruturas();
    
    if(vazio == 10)
        return NULL;

    
    int vetorAuxiliar[tam];
    getDadosDeTodasEstruturasAuxiliares(vetorAuxiliar);

   
    No *inicio;
    No *busca = NULL;
    No *novo;
    No *cabecote = (No *) malloc(sizeof(No));
    cabecote->prox = NULL;

    inicio = cabecote;
    
    for(i = 0;i < tam; i++){
        if(inicio ==  cabecote){
            novo = (No*) malloc(sizeof(No));
            cabecote->prox = novo;
            novo->conteudo = vetorAuxiliar[i];
            novo->prox = NULL;
            inicio = novo;
        }
        else{
            busca = inicio;
            while (busca->prox != NULL){
                busca = busca->prox;
            }
            novo = (No*) malloc(sizeof(No));
            busca->prox = novo;
            novo->prox = NULL;
            novo ->conteudo = vetorAuxiliar[i];
        }
                
    }
    return cabecote;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){
    int x=0;
    No *busca = inicio->prox;

    while(busca != NULL){
        vetorAux[x] = busca->conteudo;
        busca = busca->prox;
        x++;
    }
 
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio){
    No *busca;
    No *tmp;
    busca = *inicio;
    while(busca != NULL){
        tmp = busca;
        busca = busca ->prox;
        free(tmp);
    }
    *inicio = busca;

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar(){
    int x;

    for(x=0;x<10;x++)
        vetor[x].EstAux=NULL;
    
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    int x;
    for(x=0;x<10;x++)
        free(vetor[x].EstAux); 
    
}

void ordena(int vetor[], int n){
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int verificarestruturas(){
    int x, count;

    for(x=0;x<10;x++){
        if(vetor[x].count == 0)
            count ++;
    }

    return count;

}

int verificacontadores(){
   int x, count = 0;

    for(x=0;x<10;x++)
        count = count + vetor[x].count;
    
    return count;

}
