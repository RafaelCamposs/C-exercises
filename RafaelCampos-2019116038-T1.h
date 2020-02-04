 // #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Rafael Campos da Paixão
//  email:rafa.campos.200.rc@gmail.com
//  Matrícula:2019116038
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int validadata(int d,int m,int a);
int bissexto(int a);
int ehNumero(char c);
int q1(char data[]);
int transforma_dias(int d,int m,int a);
int transforma_data(char data[],int dma[]);
int switch_specialChar(int v);
void remove_specialcaracter(char vet[], int tam);
void preenche_vetor(int v1[], int v2[], int tam);

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 */
int q1(char data[]){
    
    int iDia;
    int iMes;
    int iAno;
    
    int bis;
    
    char sDia[3];
    char sMes[3];
    char sAno[5];;
    
    int validacao;
    int i,j;

    for(i=0;data[i]!='/';i++)
    {
        if(ehNumero(data[i])!=0)
            sDia[i]=data[i];
        else
            return 0;
        if(i>1)
            return 0;
    }
    
    sDia[i]='\0';
    i++;
    iDia = atoi(sDia);
    
    for(j=0;data[i]!='/';i++,j++)
    {
        if(ehNumero(data[i])!=0)
            sMes[j]=data[i];
        else
            return 0;
        if(j>1)
            return 0;
    }

    sMes[j]='\0';
    i++;
    iMes = atoi(sMes);
    
    
    for(j=0;data[i]!='\0';i++,j++)
    {
        if(ehNumero(data[i])!=0)
            sAno[j]=data[i];
        else
            return 0;
    }
    
    if(j==5 || j==1 || j==3)
        return 0;
    else
    {
        j++;
        iAno=atoi(sAno);
    }
 
    bis=bissexto(iAno);
    if(bis==1){
        if(iDia<=29 && iMes==2)
            return 1;
        else if(iMes!=2){
            validacao=validadata(iDia,iMes,iAno);
            if(validacao==1)
                return 1;
            else
                return 0;
        }
    }
    else{
        validacao =validadata(iDia,iMes,iAno);
        if(validacao==1)
            return 1;
        else
            return 0;
    }
}
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){
    
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias=0, nMeses=0, nAnos=0;
    
    int diaI=0,mesI=0,anoI=0;
    int diaF=0,mesF=0,anoF=0;
    int mes=0,dia=0;
    int totalI=0,totalF=0,difIF=0;
    int dma[3];
    int ano[12],retorno;
    
    dma[0]=-1;
    dma[1]=-1;
    dma[2]=-1;
    
    ano[0]=31;
    ano[1]=28;
    ano[2]=31;
    ano[3]=30;
    ano[4]=31;
    ano[5]=30;
    ano[6]=31;
    ano[7]=31;
    ano[8]=30;
    ano[9]=31;
    ano[10]=30;
    ano[11]=31;
    
    if (q1(datainicial) == 0)
        return 2;
    if (q1(datafinal) == 0)
        return 3;
    
    retorno=transforma_data(datainicial,dma);
    
    if(retorno == 1){
        diaI=dma[0];
        mesI=dma[1];
        anoI=dma[2];
    } 
    totalI=transforma_dias(diaI,mesI,anoI);
    
    retorno=transforma_data(datafinal,dma);
    if(retorno == 1){
        diaF=dma[0];
        mesF=dma[1];
        anoF=dma[2];
    }
    totalF=transforma_dias(diaF,mesF,anoF);
    
    if(totalI>totalF)
        return 4;
    
    difIF=totalF-totalI;
    mes=mesI-1;
    while(anoI!=anoF)
    {
        if(bissexto(anoI)== 1){
            difIF=difIF-366;
            nAnos++;
        }
        else{
            difIF=difIF-365;
            nAnos++;
        }
    anoI++;    
    }
    
    if(difIF-ano[mes]>=0){
        while(mesI!=mesF){
            diaI++;
            difIF--;
            dia++;
            if(dia == ano[mes]){
                nMeses++;
                mes++;
                dia=0;
                mesI++;
            }
        }
    }

    nDias= difIF;
    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;

}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = 0;
    int i;
    int asciivalue = c;
    int textsize;
 
    textsize = strlen(texto);
    
    remove_specialcaracter(texto, textsize);
    
    if(isCaseSensitive == 1){
        for(i=0;i<=textsize;i++){
            if(asciivalue == texto[i])
                qtdOcorrencias++;
        }
    }
    if(isCaseSensitive!=1){
        for(i=0;i<=textsize;i++){
            if(asciivalue == texto[i] || (asciivalue==texto[i]-32 || asciivalue == texto[i]+32))
                qtdOcorrencias++;
        }
    }
    
    
    return qtdOcorrencias;

}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;
    int tamTexto, tamBusca;
    int i,j,k,count,comp;
    int x=0;
    
    tamTexto=strlen(strTexto);
    tamBusca=strlen(strBusca);
    
    char compStr[tamBusca+1];
    
    remove_specialcaracter(strTexto,tamTexto);
    remove_specialcaracter(strBusca,tamBusca);
    
    for(i=0;i<tamTexto;i++){
        count=0;
        if(strBusca[0] == strTexto[i]){
           for(j=0,k=i;count!=tamBusca;j++,count++,k++)
               compStr[j]=strTexto[k];
            comp=strcmp(strBusca,compStr);
            if(comp==0){
                posicoes[x]=i+1;
                x++;
                posicoes[x]=i+count;
                x++;
                qtdOcorrencias++;
            }
        }        
    }
    
    
    
    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
    
    int baseNum = 10,baseTroca=10,inv=0;
    int resto,div=-1;
    
    if(num>=10){
        while(div!=0){     
            baseNum = baseNum*10;
            div = num/baseNum;
        }
        while(num>0){
            baseNum=baseNum/10;
            resto=num%10;
            inv=inv+(resto*baseNum);
            num=num-resto;
            num=num/10;
        }
        num=inv;
        return  num;
    }
    if(num<10 && num>=0)
        return num;
    
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0;
    int div=-1;
    int baseNum=10,count,TamBusca,qtdocorrencias=0;
    int x,y,z;
    int vet1[50],vet2[50];
    
    if(numerobase>=10){
        count=0;
        while(div!=0){
        baseNum = baseNum*10;
        div = numerobase/baseNum;
        count++;
        }
        count++;
        int vetBase[count+1];
        for(x=0;x<count;x++){
            baseNum=baseNum/10;
            div=numerobase / baseNum;
            vetBase[x]=div;
            numerobase=numerobase - (div*baseNum);
        }
        count++;
        numerobase=-1;
        vetBase[count-1]=-1;
        preenche_vetor(vet1,vetBase,count);
    }
    if(numerobase<10 && numerobase>=0){
        int vetBase[2];
        vetBase[0]=numerobase;
        vetBase[1]=-1;
        preenche_vetor(vet1,vetBase,2);
    }
    
    baseNum=10;
    
    if(numerobusca>=10){
        TamBusca=0;
        while(div!=0){
        baseNum = baseNum*10;
        div = numerobusca/baseNum;
        TamBusca++;
        }
        TamBusca++;
        int vetBusca[TamBusca+1];
        for(x=0;x<TamBusca;x++){
            baseNum=baseNum/10;
            div=numerobusca / baseNum;
            vetBusca[x]=div;
            numerobusca=numerobusca - (div*baseNum);
        }
        TamBusca++;
        numerobusca=-1;
        vetBusca[TamBusca-1]=-1;
        preenche_vetor(vet2,vetBusca,TamBusca);
    }
    if(numerobusca<10 && numerobusca>=0){
        int vetBusca[2];
        TamBusca=1;
        vetBusca[0]= numerobusca;
        vetBusca[1]= -1;
        preenche_vetor(vet2,vetBusca,2);
    }
    
    
    if(numerobusca<10 && numerobusca>=0){
        for(x=0;vet1[x]!=-1;x++){
            if(vet1[x]==vet2[0])
               qtdOcorrencias++;
        }
    }
    else{
        for(x=0;vet1[x]!=-1;x++){
            count=0;
            if(vet1[x]=vet2[0]){
                for(y=0,z=x;vet2[y]!=-1;y++,z++){
                    if(vet1[z]==vet2[y])
                        count++;
                    }
                    if(count==TamBusca-1)
                        qtdOcorrencias++;
            }
            
        }   
    }
        

    return qtdOcorrencias;
}


//Funções auxiliares
int validadata(int d,int m,int a)
{
    if(m==2){
        if(d<=28)
            return 1;
        else
            return 0;
    }
    else if(d <= 31 && d > 0)
        if(m <= 12 &&  m > 0)
            if(a > 0)
                return 1;
            else
                return 0;
        else
            return 0;
    else
        return 0;
                
}

int ehNumero(char c)
{
    if (c >= 48 && c <= 57)
        return 1;
    else 
        return 0;
}

int bissexto(int a)
{
    if( (a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
        return 1;
    else
        return 0;
            
}
            
int transforma_data(char data[],int dma[])
{

    int iDia;
    int iMes;
    int iAno;
    
    char sDia[3];
    char sMes[3];
    char sAno[5];;
    
    int i,j;

    dma[0]=0;
    dma[1]=0;
    dma[2]=0;
    
    for(i=0;data[i]!='/';i++)
    {
        if(ehNumero(data[i])!=0)
            sDia[i]=data[i];
        else
            return 0;
        if(i>1)
            return 0;
    }
    sDia[i]='\0';
    i++;
    iDia = atoi(sDia);
    dma[0]=iDia;
    
    for(j=0;data[i]!='/';i++,j++)
    {
        if(ehNumero(data[i])!=0)
            sMes[j]=data[i];
        else
            return 0;
        if(j>1)
            return 0;
    }
    
    sMes[j]='\0';
    i++;
    iMes = atoi(sMes);
    dma[1]=iMes;
    
    for(j=0;data[i]!='\0';i++,j++)
    {
        if(ehNumero(data[i])!=0)
            sAno[j]=data[i];
        else
            return 0;
    }

    if(j==5 || j==1 || j==3)
        return 0;
    else
    {
        j++;
        iAno=atoi(sAno);
        dma[2]=iAno;
    }    
    
    return 1;
}

int transforma_dias(int d,int m,int a)
{
    int ano[12];
    int contador=0;
    int x;
    ano[0]=31;
    ano[1]=28;
    ano[2]=31;
    ano[3]=30;
    ano[4]=31;
    ano[5]=30;
    ano[6]=31;
    ano[7]=31;
    ano[8]=30;
    ano[9]=31;
    ano[10]=30;
    ano[11]=31;

    for(x=1;x<a;x++)
    {
        if(bissexto(x)==1)
            contador=contador + 366;
        else
            contador=contador + 365;
    }
    
    if(m!=1)
    {
        for(x=0;x < m-1;x++)
        {
            if(bissexto(a)==1 && x==1)
                contador=contador+ano[x]+1;
            else
                contador=contador+ano[x];
        }
    }
    
    contador=contador + d;
    
    return contador;
}
void remove_specialcaracter(char vet[], int tam){
    int i,j, count;
    
    for(i=0;i < tam;i++){
        count =0;
        if(vet[i]==-61){
            for(j=i;j<tam;j++){
                vet[j]=vet[j+1];
            }
        vet[i]= switch_specialChar(vet[i]);
        }
        if(vet[i] == -31){
            while(count !=2){
                for(j=i;j<tam;j++)
                    vet[j]=vet[j+1];
                count++;
            }
            if(vet[i]==-67) vet[i] = 101;        
            if(vet[i]==-68) vet[i] = 69;
        }
    }
        
        
}

int switch_specialChar(int v){
    
    
    if(v >= -96 && v <= -93)// substitiu o "a" acentuado por a
        v= 97;
    if(v >= -128 && v <= -125)// substitiu o "A" acentuado por A
        v= 65;
    if(v >= -88 && v <= -86 )
        v = 101;
    if(v >=-120 && v <= -118 )
        v = 69;
    if(v >= -78 && v <= -75)
        v = 111;
    if(v >= -110 && v <= -108 || v== -107)
        v = 79;
    if(v >= -84 && v <= -82 )
        v = 105;
    if(v >= -116 && v <= -114 )
        v = 73;
    if(v >= -71 && v <= -69 )
        v = 117;
    if(v >= -103 && v <= -101)
        v = 85;
    if(v == -89)
        v = 99;
    
    return v;
    
}

void preenche_vetor(int v1[],int v2[],int tam){
    int x;
    
    for(x=0;x<tam;x++)
        v1[x] = v2[x];
}
