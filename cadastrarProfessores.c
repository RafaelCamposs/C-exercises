#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAMANHO_LISTA 10

struct dataNascimento
{
    int dia;
    int mes;
    int ano;
};

typedef struct cadProf
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;
    char sexo;
} Lista_Prof;

//escopo de funções
int validarnome(char nm[50]);
int validardtnasc(int d, int m, int a);
int validarcpf(char c[15]);
int validarsexo(char s);
int validarmatricula(int mat);
int matricula_Professor(int qtd,Lista_Prof Professores[]);
int menu_opcoes();
void listar_Professor(Lista_Prof Professores[]);
void status_Professor(Lista_Prof Professores[]);
void retirar_Professor(int qtd,Lista_Prof Professores[]);

int main()
{
    int opcao;
    int status_matricula;
    int qtdprof=0;
    Lista_Prof Professor[TAMANHO_LISTA];
    
    //inicializando as matriculas como inativas
    status_Professor(Professor);
    
    while(opcao!=4)
    {
        opcao=menu_opcoes();
        switch(opcao)
        {
            case 1:
            {
                if(qtdprof<TAMANHO_LISTA)
                {   
                    printf("\n###CADASTRO DE PROFESSOR###\n");
                    status_matricula = matricula_Professor(qtdprof,Professor);
                    if(status_matricula==1)
                    {
                    printf("\n### MATRICULA REALIZADA COM SUCESSO###\n");
                    qtdprof++;
                    printf("\n");
                    }
                    else
                    printf("\n###FALHA NA MATRICULA###\n");
                    printf("\n");
                    break;
                } 
                else
                {
                    printf("\n###NUMERO_MAXIMO_ATINGIDO###\n");
                    break;
                }      
            
        }
            case 2:
            {
                printf("###LISTA DE Professores###\n");
                listar_Professor(Professor);
                break;
            }
            case 3:
            {
                printf("###REMOVER Professores###\n");
                retirar_Professor(qtdprof,Professor);
                if(qtdprof>0)
                    qtdprof--;
                else
                    printf("\n###NENHUM_PROFESSOR_CADASTRADO###\n");
                break;
            }
            case 4:
            {
                printf("\n###SAINDO DO CADASTRO DE PROFESSORES###\n");
                break;
            }
        
        }   
    }        
       
    return 0;   
    
}
   
            

int matricula_Professor(int qtd, Lista_Prof Professores[])
{
    int v1,v2,v3,v4,v5;
    int ver;
    
    for(ver=0;ver<TAMANHO_LISTA;ver++)
    {
        if(Professores[qtd].matricula!=-1)
            qtd++;
        else
            break;
    }
    
    
    
    printf("Informe a matricula do Professor\n");
    scanf("%d",&Professores[qtd].matricula);
    getchar();
    
    printf("Informe o nome do Professor\n");
    fgets(Professores[qtd].nome,40,stdin);
    size_t ln= strlen(Professores[qtd].nome)-1;
    if(Professores[qtd].nome[ln]=='\n')
            Professores[qtd].nome[ln]='\0';
    
    printf("Informe o dia de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.dia);
    
    printf("Informe o mes de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.mes);
    
    printf("Informe o ano de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.ano);
    getchar();
        
    printf("Informe o CPF do Professor\n");
    fgets(Professores[qtd].CPF,15,stdin);
    ln= strlen(Professores[qtd].CPF)-1;
    if(Professores[qtd].CPF[ln]=='\n')
            Professores[qtd].CPF[ln]='\0';
        
    printf("Infome o sexo do Professor(F, M ou O)\n");
    scanf("%c",&Professores[qtd].sexo);
    
    //Validação dos dados inseridos//
    v1=validarnome(Professores[qtd].nome);
    v2=validardtnasc(Professores[qtd].dtnasc.dia,Professores[qtd].dtnasc.mes,Professores[qtd].dtnasc.ano);
    v3=validarcpf(Professores[qtd].CPF);
    v4=validarsexo(Professores[qtd].sexo);
    v5=validarmatricula(Professores[qtd].matricula);
    
    if(v1==1 && v2==1 && v3==1 && v4==1 && v5==1)
    {
        return 1;
    }
    if(v1==0)
        printf("\nERRO_NOME_INVALIDO\n");
    if(v2==0)
        printf("\nERRO_DATA_INVALIDA\n");
    if(v3==0)
        printf("\nERRO_CPF_INVALIDO\n");
    if(v4==0)
        printf("\nERR0_SEXO_INVALIDO\n");
    if(v5==0)
        printf("\nERRO_MATRICULA_INVALIDA\n");
    return 0;
    
}

int validarnome(char nm[])
{
    int tam;
    tam=strlen(nm);
    if(tam>10)
        return 1;
     else
        return 0;
}

int validardtnasc(int d,int m,int a)
{
    if( d<=31 &&  d>0)
    {
        if( m<=12 &&  m>0)
        {
            if( a > 0)
                return 1;
            else 
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

int validarcpf(char c[])
{
    int len;
    len = strlen(c);
    if(len==14 || len==11)
        return 1;
    else
        return 0;
}

int validarsexo(char s)
{
    if(s=='M' || s=='m' || s=='F' || s=='f' || s=='O'  || s=='o')
        return 1;
    else
        return 0;
}

int validarmatricula(int mat)
{
    if(mat>=-1)
        return 1;
    else
        return 0;
}

int menu_opcoes()
{
    int op;
    
    printf("###MENU CADASTRO DE PROFESSOR###\n");
    printf("Informe a opcao\n");
    printf("\n");
    printf("1.Cadastro de Professores\n");
    printf("2.Relatórios de Professores\n");
    printf("3.Remover Professores\n");
    printf("4.Sair\n");
    scanf("%d",&op);
    return op;
}

void listar_Professor(Lista_Prof Professores[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
    {
        if(Professores[x].matricula!=-1)
        {
            printf("%d. Nome: %s\n",x+1,Professores[x].nome);
            printf("Matricula: %d\n",Professores[x].matricula);
            printf("Data de Nascimento : %d/%d/%d\n",Professores[x].dtnasc.dia,Professores[x].dtnasc.mes,Professores[x].dtnasc.ano);
            printf("CPF : %s\n",Professores[x].CPF);
            printf("Sexo : %c\n",Professores[x].sexo);
            printf("\n");
        }
    }
}

void status_Professor(Lista_Prof Professores[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
        Professores[x].matricula = -1;
}

void retirar_Professor(int qtd,Lista_Prof Professores[])
{
    int del;
    int cont;
    printf("Informe o número do Professor\n");
    listar_Professor(Professores);
    scanf("%d",&del);
    del--;
    for(cont=del;Professores[cont].matricula!=-1;cont++)
    {
        Professores[cont].matricula=Professores[cont+1].matricula;
        Professores[cont].sexo=Professores[cont+1].sexo;
        Professores[cont].dtnasc.dia=Professores[cont+1].dtnasc.dia;
        Professores[cont].dtnasc.mes=Professores[cont+1].dtnasc.mes;
        Professores[cont].dtnasc.ano=Professores[cont+1].dtnasc.ano;
        strcpy(Professores[cont].nome,Professores[cont+1].nome);
        strcpy(Professores[cont].CPF,Professores[cont+1].CPF);
    }
    
    listar_Professor(Professores);
    return ;
}
    
