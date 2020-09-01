#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct dtnasc
{
    int dia;
    int mes;
    int ano;
};

struct cadastro
{
    char nome[50];
    struct dtnasc dataNascimento;
    char CPF[15];
    char sexo;//M ou m para masculino e F ou f para Feminino
};

struct cadastro Cliente;

int v1,v2,v3,v4;

int validarnome(char nm[50]);
int validardtnasc(int d, int m, int a);
int validarcpf(char c[15]);
int validarsexo(char s);
void cadastrarCliente();

void main()
{
    
    cadastrarCliente();
    
    if(v1==1 && v2==1 && v3==1 && v4==1)
    {
        printf("###CADASTRO REALIZADO COM SUCESSO###\n");
        printf("###DADOS DO CLIENTE###\n");
        printf("......Nome do Cliente: %s",Cliente.nome);
        printf("......Data de Nascimento do Cliente: %d/%d/%d\n",Cliente.dataNascimento.dia,Cliente.dataNascimento.mes,Cliente.dataNascimento.ano);
        printf("......CPF do Cliente: %s\n",Cliente.CPF);
        printf("......Sexo do Cliente: %c\n",Cliente.sexo);
    }
    if(v1==0)
        printf("ERRO_NOME_INVALIDO\n");
    if(v2==0)
        printf("ERRO_DATA_INVALIDA\n");
    if(v3==0)
        printf("ERRO_CPF_INVALIDO\n");
    if(v4==0)
        printf("ERR0_SEXO_INVALIDO\n");
        
}

void cadastrarCliente()
{
    
    printf("Informe o nome do Cliente\n");
    fgets(Cliente.nome,50,stdin);
    
    printf("Informe a dia do Nascimento\n");
    scanf("%d",&Cliente.dataNascimento.dia);
    printf("Informe a mes do Nascimento\n");
    scanf("%d",&Cliente.dataNascimento.mes);
    printf("Informe a ano do Nascimento\n");
    scanf("%d",&Cliente.dataNascimento.ano);
    
    printf("Informe o CPF do Cliente\n");
    scanf("%s",&Cliente.CPF);
    
    printf("Infome o sexo do Cliente(F, M ou O)\n");
    scanf("%s",&Cliente.sexo);
    
    v1=validarnome(Cliente.nome);
    v2=validardtnasc(Cliente.dataNascimento.dia,Cliente.dataNascimento.mes,Cliente.dataNascimento.ano);
    v3=validarcpf(Cliente.CPF);
    v4=validarsexo(Cliente.sexo);
    
    return Cliente.sexo;
    return Cliente.CPF;
    return Cliente.nome;
    return Cliente.dataNascimento.dia;
    return Cliente.dataNascimento.mes;
    return Cliente.dataNascimento.ano;
}

int validarnome(char nm[50])
{
    int tam;
    tam=strlen(nm);
    if(tam>21)
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

int validarcpf(char c[15])
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
