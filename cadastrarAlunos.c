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

typedef struct cadAluno
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;
    char sexo;
} Lista_aluno;

//escopo de funções
int validarnome(char nm[50]);
int validardtnasc(int d, int m, int a);
int validarcpf(char c[15]);
int validarsexo(char s);
int validarmatricula(int mat);
int matricula_Aluno(int qtd,Lista_aluno Alunos[]);
int menu_opcoes();
void listar_aluno(Lista_aluno Alunos[]);
void status_aluno(Lista_aluno Alunos[]);
void retirar_aluno(Lista_aluno Alunos[]);

int main()
{
    int x;
    int opcao;
    int status_matricula;
    int qtdaluno=0;
    Lista_aluno Aluno[TAMANHO_LISTA];
    
    //inicializando as matriculas como inativas
    status_aluno(Aluno);
    
    while(opcao!=4)
    {
        opcao=menu_opcoes();
        switch(opcao)
        {
            case 1:
            {
                printf("\n###CADASTRO DE ALUNO###\n");
                status_matricula = matricula_Aluno(qtdaluno, Aluno);
                if(status_matricula==1)
                {
                printf("\n### MATRICULA REALIZADA COM SUCESSO###\n");
                qtdaluno++;
                printf("\n");
                }
                else
                printf("\n###FALHA NA MATRICULA###\n");
                printf("\n");
                break;
            }
            case 2:
            {
                printf("###LISTA DE ALUNOS###\n");
                listar_aluno(Aluno);
                break;
            }
            case 3:
            {
                printf("###REMOVER ALUNOS###\n");
                retirar_aluno(Aluno);
                break;
            }
            case 4:
            {
                printf("\n###SAINDO DO CADASTRO DE ALUNOS###\n");
                break;
            }
        
        }   
    }        
       
    return 0;   
    
}
   
            

int matricula_Aluno(int qtd, Lista_aluno Alunos[])
{
    int v1,v2,v3,v4,v5;
    
    printf("Informe a matricula do aluno\n");
    scanf("%d",&Alunos[qtd].matricula);
    getchar();
    
    printf("Informe o nome do Aluno\n");
    fgets(Alunos[qtd].nome,40,stdin);
    size_t ln= strlen(Alunos[qtd].nome)-1;
    if(Alunos[qtd].nome[ln]=='\n')
            Alunos[qtd].nome[ln]='\0';
    
    printf("Informe a dia do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.dia);
    
    printf("Informe a mes do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.mes);
    
    printf("Informe a ano do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.ano);
    getchar();
        
    printf("Informe o CPF do Aluno\n");
    fgets(Alunos[qtd].CPF,15,stdin);
    ln= strlen(Alunos[qtd].CPF)-1;
    if(Alunos[qtd].CPF[ln]=='\n')
            Alunos[qtd].CPF[ln]='\0';
        
    printf("Infome o sexo do Aluno(F, M ou O)\n");
    scanf("%s",&Alunos[qtd].sexo);
    
    //Validação dos dados inseridos//
    v1=validarnome(Alunos[qtd].nome);
    v2=validardtnasc(Alunos[qtd].dtnasc.dia,Alunos[qtd].dtnasc.mes,Alunos[qtd].dtnasc.ano);
    v3=validarcpf(Alunos[qtd].CPF);
    v4=validarsexo(Alunos[qtd].sexo);
    v5=validarmatricula(Alunos[qtd].matricula);
    
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
    if(tam>20)
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
    
    printf("###MENU ESCOLA###\n");
    printf("Informe a opcao\n");
    printf("\n");
    printf("1.Cadastro de Alunos\n");
    printf("2.Relatórios de Alunos\n");
    printf("3.Remover Alunos\n");
    printf("4.Sair\n");
    scanf("%d",&op);
    return op;
}

void listar_aluno(Lista_aluno Alunos[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].matricula!=-1)
        printf("%d. %s\n",x+1,Alunos[x].nome);
    }
}

void status_aluno(Lista_aluno Alunos[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
        Alunos[x].matricula = -1;
}

void retirar_aluno(Lista_aluno Alunos[])
{
    int del;
    
    printf("Informe o número do Aluno\n");
    listar_aluno(Alunos);
    scanf("%d",&del);
    Alunos[del-1].matricula=-1;
    listar_aluno(Alunos);
}
    
