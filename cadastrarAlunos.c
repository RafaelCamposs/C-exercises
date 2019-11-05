#include<stdio.h>
#include<stdlib.h>

struct dataNascimento
{
    int dia;
    int mes;
    int ano;
};

struct cadAluno
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;//ano depois numero, ex: 201901,201902
    char sexo;
};

struct cadAluno Aluno[15];
void cadastroAluno()
{
    int doagain;
    int numAlunos;
    printf("...Cadastro de Aluno...\n");
    
    
    numAlunos=0;
    doagain=1;
    for(;doagain==1;numAlunos++)
    {
        printf("Informe o nome do Aluno\n");
        fgets(Aluno[numAlunos].nome,50,stdin);
        printf("Informe o dia do nascimento\n");
        scanf("%d",&Aluno[numAlunos].dtnasc.dia);
        printf("Informe o mes do nascimento\n");
        scanf("%d",&Aluno[numAlunos].dtnasc.mes);
        printf("Informe o ano do nascimento\n");
        scanf("%d",&Aluno[numAlunos].dtnasc.ano);
        printf("Informe o Numero da matricula\n");
        scanf("%d",&Aluno[numAlunos].matricula);
        printf("Informe o CPF\n");
        scanf("%s",&Aluno[numAlunos].CPF);
        printf("Informe o sexo do Aluno\n");
        scanf("%s",&Aluno[numAlunos].sexo);
        printf("Aluno cadastrado com sucesso!\n");
        printf("Para continuar digite 1, para sair digite 2\n");
        scanf("%d",&doagain);
    }
            
    return;
}
   
void main()
{
    cadastroAluno();
    printf("Cadastros Feitos com sucesso\n");
    printf("Lista de alunos\n");
    printf(" Nome do aluno 1:%s",Aluno[0].nome);
    printf("Data de nascimento :%d/%d/%d",Aluno[0].dtnasc.dia,Aluno[0].dtnasc.mes,Aluno[0].dtnasc.ano);
    printf("Matricula : %d",Aluno[0].matricula);
    printf("CPF ; %s",Aluno[0].CPF);
    printf("Sexo : %s",Aluno[0].sexo);
    return;
}
