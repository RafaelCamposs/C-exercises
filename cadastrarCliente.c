#include<stdio.h>
#include<stdlib.h>

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

void cadastrarCliente();

void main()
{
    cadastrarCliente();
    
    printf("......Nome do Cliente: %s......\n",Cliente.nome);
    printf(".......\n");
    printf(".......CPF do Cliente: %s......\n",Cliente.CPF);
    printf(".......\n");
    printf("......Sexo do Cliente: %c......\n",Cliente.sexo);
    printf(".......\n");
    printf("......Data de Nascimento do Cliente: %d/%d/%d......\n",Cliente.dataNascimento.dia,Cliente.dataNascimento.mes,Cliente.dataNascimento.ano);
    printf(".......\n");
}

void cadastrarCliente()
{
    
    printf("Informe o nome do Cliente\n");
    gets(Cliente.nome);
    
    printf("Informe a data de nacimento(Dia/mes/ano)\n");
    scanf("%d",&Cliente.dataNascimento.dia);
    scanf("%d",&Cliente.dataNascimento.mes);
    scanf("%d",&Cliente.dataNascimento.ano);
    
    printf("Informe o CPF do Cliente\n");
    scanf("%s",&Cliente.CPF);
    
    printf("Infome o sexo do Cliente(F, M ou O)\n");
    scanf("%s",&Cliente.sexo);
    
    return Cliente.sexo;
    return Cliente.CPF;
    return Cliente.nome;
    return Cliente.dataNascimento.dia;
    return Cliente.dataNascimento.mes;
    return Cliente.dataNascimento.ano;
}
        
    
