#include<stdio.h>
#include<stdlib.h>
#include "CadastroDisciplinas.h"
#define TAM_LISTA 10

int menu_principal();

int main()
{
    int opcao;
    int qtdaluno=0,qtdprofessor=0,qtddisciplina=0;
    Lista_aluno Aluno[TAM_LISTA];
    Lista_Prof Professor[TAM_LISTA];
    Disciplina lista_disciplinas[TAM_DISCIPLINAS];
    
    //inicializando as matriculas como inativas e zerando o contador de alunos nas Disciplinas
    status_aluno(Aluno);
    status_Professor(Professor);
    zerando_contador(lista_disciplinas);
    
    while(opcao!=4)
    {
        opcao=menu_principal();
        switch(opcao)
        {
            case 1:
            {
                qtdaluno=menu_alunos(qtdaluno,Aluno);
                break;
            }
            case 2:
            {
                qtdprofessor=menu_professor(qtdprofessor,Professor);
                break;
            }
            case 3:
            {
                qtddisciplina=menu_disciplinas(qtdaluno,qtddisciplina,qtdprofessor,Aluno,Professor,lista_disciplinas);
                break;
            }
            
        }  
    }
    return 0;
}

int menu_principal()
{
    int op;
    
    printf("\n###MENU PRINCIPAL###\n");
    printf("\n");
    printf("Informe a opcão\n");
    printf("\n");
    printf("1.Menu de Alunos\n");
    printf("2.Menu de Professores\n");
    printf("3.Menu de Disciplinas\n");
    printf("4.Sair\n");
    scanf("%d",&op);
    
    return op;
    
}
