#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrarProfessores.h"
#define TAM_DISCIPLINAS 10
#define TAM_ALUNOS 10
#define TAM_PROFESSOR 10
#define LIMITE_ALUNOS 10

#define SUCESSO_CADASTRO 1
#define SUCESSO_EXCLUSAO 7
#define CODIGO_EXISTENTE 2
#define CODIGO_INVALIDO 3
#define SEMESTRE_INVALIDO 4
#define ERRO_LIMITE_DISCIPLINAS 6
#define ERRO_LIMITE_ALUNOS 10

#define NAO_LOCALIZADO -1


typedef struct ficha_disciplina
{
     int codigo;
     char nome[30];
     int semestre;
     int alunos_matriculados[LIMITE_ALUNOS];
     char professor_Disciplina[30];
     int contador;
} Disciplina;

//CABEÇALHO**************************************************************************************************
int opcaoMenuDisciplinas();
int cadastra_disciplina(int qtde_Disciplinas, Disciplina lista_disciplinas[], Lista_Prof Professores[]);
void imprime_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas);
int excluir_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas);
int localizar_Disciplinas(int loc_codigo, Disciplina lista_disciplinas[], int qtde_Disciplinas);
int incluir_aluno(Disciplina lista_disciplinas[], int qtde_Disciplinas, Lista_aluno Alunos[]);
int localizar_Alunos(int loc_matricula,  Lista_aluno Alunos[]);
void zerando_contador(Disciplina lista_disciplinas[]);
void imprime_disciplina_com_aluno(Disciplina lista_disciplinas[], int qtde_Disciplinas,  Lista_aluno Alunos[]);
int excluir_aluno_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas);
int localizar_Alunos_Disciplina(int loc_matricula , Disciplina lista_disciplinas[], int posicao_disciplina);
int localizar_Professores(int loc_matricula,  Lista_Prof Professores[]);
void alterar_cadastro_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas, Lista_Prof Professores[]);
int valida_codigo(int codigo_disciplina, Disciplina lista_disciplinas[], int qtde_Disciplinas);
int valida_semestre(int semestre_disciplina, Disciplina lista_disciplinas[], int qtde_Disciplinas);
int menu_disciplinas(int qtd_alunos,int qtd_disciplinas,int qtdprofessor,Lista_aluno Alunos[],Lista_Prof Professores[],Disciplina lista_disciplinas[]);
//**********************************************************************************************************

int menu_disciplinas(int qtd_alunos,int qtd_disciplinas,int qtdprofessor,Lista_aluno Alunos[],Lista_Prof Professores[],Disciplina lista_disciplinas[]) {

    int i;
    int sair=0;
    int retorno=0;
    int op;
     

    while (!sair){
    op = opcaoMenuDisciplinas();
    switch(op){
      case 0:{
        printf("###VOLTANDO###\n");
        sair = 1;
        break;
      }
      case 1: {
        retorno = cadastra_disciplina(qtd_disciplinas, lista_disciplinas, Professores);
        if (retorno == SUCESSO_CADASTRO){
            printf("\n\n##Cadastro realizado com sucesso##\n\n");
            qtd_disciplinas++;
        }
        break;
      }
      case 6: {
        imprime_disciplina(lista_disciplinas, qtd_disciplinas);
        break;
      }
      case 3:{
        retorno = excluir_disciplina(lista_disciplinas, qtd_disciplinas);
        if(retorno == SUCESSO_EXCLUSAO){
            qtd_disciplinas--;
            printf("\n\n##Exclusão realizada com sucesso##\n\n");  
        }
        break;  
    }
    case 4:{
        retorno=incluir_aluno(lista_disciplinas, qtd_disciplinas, Alunos);
        if (retorno == SUCESSO_CADASTRO)
            printf("\n\n##Cadastro realizado com sucesso##\n\n");
        else if(retorno == ERRO_LIMITE_ALUNOS)
             printf("\n\n##O LIMITE DE ALUNOS NA DISCIPLINA FOI ATINGIDO##\n\n");
        break;  
    }
    case 7: {
        imprime_disciplina_com_aluno(lista_disciplinas, qtd_disciplinas,Alunos);
        break;
      }
      case 5:{
        retorno = excluir_aluno_disciplina(lista_disciplinas, qtd_disciplinas);
        if(retorno == SUCESSO_EXCLUSAO){
            printf("\n\n##Exclusão realizada com sucesso##\n\n");  
        }
        break;  
    }
      case 2:{
          alterar_cadastro_disciplina(lista_disciplinas, qtd_disciplinas, Professores);
          break;
        }
      default:{
        printf("##Opção Inválida##\n");

      }
    }
  }
	return qtd_disciplinas;
}

//MODULO MENU DE DISCIPLINAS
int opcaoMenuDisciplinas(){
    int opcao;
    printf("\n######### MENU DE DISCIPLINAS #########\n");
    printf("Digite a opção:\n");
    printf("0 - Voltar a Menu Principal\n");
    printf("1 - Inserir Disciplina\n");
    printf("2 - Alterar Cadastro de Disciplinas\n");
    printf("3 - Excluir Disciplinas\n");
    printf("4 - Incluir Aluno nas Disciplinas\n");
    printf("5 - Excluir Aluno nas Disciplinas\n");
    printf("6 - Listar apenas Disciplinas\n");
    printf("7 - Listar Disciplinas com Alunos\n");
    scanf("%d", &opcao);
    return opcao;
}

//FUNÇÃO PARA CADASTRAR A DISCIPLINA
int cadastra_disciplina(int qtde_Disciplinas, Disciplina lista_disciplinas[], Lista_Prof Professores[]){
    
    int verificador;
    int matricula_professor;
    int code_disciplina;
    int sem_disciplina;
    
	if(qtde_Disciplinas >= TAM_DISCIPLINAS)
        return ERRO_LIMITE_DISCIPLINAS; 

    printf("\n######### Cadastro de Disciplina #########\n");
    
    do{
        printf("Digite o codigo da Disciplina :\n");
        scanf("%d", &code_disciplina);
        getchar();
        verificador= valida_codigo(code_disciplina, lista_disciplinas, qtde_Disciplinas);
        if(verificador==CODIGO_INVALIDO)
            printf("O codigo digitado não eh valido\n");
        else if(verificador== CODIGO_EXISTENTE)
            printf("A matricula digitada já existe\n");
        else if(verificador == SUCESSO_CADASTRO)
            lista_disciplinas[qtde_Disciplinas].codigo = code_disciplina;
    }while(verificador != SUCESSO_CADASTRO);

    printf("Nome da Disciplina: ");
    fgets(lista_disciplinas[qtde_Disciplinas].nome, 30, stdin);
    size_t ln = strlen(lista_disciplinas[qtde_Disciplinas].nome) - 1; 
        if (lista_disciplinas[qtde_Disciplinas].nome[ln] == '\n')
          lista_disciplinas[qtde_Disciplinas].nome[ln] = '\0';

    do{
        printf("Digite o Semestre da Disciplina :\n");
        scanf("%d", &sem_disciplina);
        getchar();
        verificador= valida_semestre(sem_disciplina, lista_disciplinas, qtde_Disciplinas);
        if(verificador==SEMESTRE_INVALIDO)
            printf("O semestre digitado não eh valido\n");
        else if(verificador == SUCESSO_CADASTRO)
            lista_disciplinas[qtde_Disciplinas].semestre = sem_disciplina;
    }while(verificador != SUCESSO_CADASTRO);

    
    do{
        printf("Digite a matricula do professor da disciplina: ");
        scanf("%d", &matricula_professor);
        getchar();
        verificador = localizar_Professores(matricula_professor, Professores);
        if(verificador== NAO_LOCALIZADO)
            printf("##PROFESSOR NÃO LOCALIZADO. DIGITE NOVAMENTE##\n");
        else
            strcpy(lista_disciplinas[qtde_Disciplinas].professor_Disciplina, Professores[verificador].nome);
    
    }while(verificador == NAO_LOCALIZADO);
    
    return SUCESSO_CADASTRO;
}

//FUNÇÃO PARA GERAR RELATORIOS DE DISCIPLINAS CADASTRADAS 
void imprime_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas){

    int k;
    printf("---------------------- RELATORIO DE CADASTRO DE DISCIPLINA ----------------------\n\n ");
    for (k = 0; k < qtde_Disciplinas; k++){
            printf("Disciplina: %s\t Codigo: %d\t Semestre: %d\t Professor: %s\n",lista_disciplinas[k].nome,lista_disciplinas[k].codigo,lista_disciplinas[k].semestre, lista_disciplinas[k].professor_Disciplina);
            printf("-----------------------------------------------------------\n ");
    }

}
//FUNÇÃO PARA GERAR RELATORIOS DE DISCIPLINAS CADASTRADAS COM ALUNOS
void imprime_disciplina_com_aluno(Disciplina lista_disciplinas[], int qtde_Disciplinas,  Lista_aluno Alunos[]){

    int iCont;
    int pos_aluno;
    int jCont;
    
    printf("---------------------------- RELATORIO DE CADASTRO DE DISCIPLINA ---------------------------\n\n ");

    for (iCont = 0; iCont < qtde_Disciplinas; iCont++){
        
        printf("Disciplina: %s\n Codigo: %d\n ",lista_disciplinas[iCont].nome, lista_disciplinas[iCont].codigo);
        printf("----Alunos Matriculados----\n");
        for(jCont = 0; jCont < lista_disciplinas[iCont].contador; jCont++){
				pos_aluno= localizar_Alunos(lista_disciplinas[iCont].alunos_matriculados[jCont], Alunos);
				printf("\t\tMatricula: %d\tNome: %s\n", Alunos[pos_aluno].matricula, Alunos[pos_aluno].nome);
			}
        printf("--------------------------------------------------\n");
	}
            

}

//FUNÇÃO PARA EXCLUSÃO DE UMA DISCIPLINA
int excluir_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas){

    int code;
    int posicao_disciplina;
    int i;
    do{
        printf("Informe o codigo da disciplina que deseja excluir: ");
        scanf("%d", &code);

        posicao_disciplina= localizar_Disciplinas(code, lista_disciplinas, qtde_Disciplinas);
        
        if(posicao_disciplina == NAO_LOCALIZADO)
            printf("DISCIPLINA NAO LOCALIZADA. DIGITE NOVAMENTE!!!!\n");
        
    }while(posicao_disciplina == NAO_LOCALIZADO);
    
    for (i = posicao_disciplina; i < qtde_Disciplinas; i++)
                lista_disciplinas[i]= lista_disciplinas[i+1];
    
    return SUCESSO_EXCLUSAO;
            
}

// FUNÇÃO PARA INCLUSÃO DE UM ALUNO NUMA DISCIPLINA
int incluir_aluno(Disciplina lista_disciplinas[], int qtde_Disciplinas, Lista_aluno Alunos[]){
    int codigo_disciplina;
    int matricula_aluno;
    int posicao_disciplina;
    int posicao_aluno;
    int verificacao;

    do{
        printf("Informe o codigo da disciplina que deseja incluir o aluno: ");
        scanf("%d", &codigo_disciplina);
    
        posicao_disciplina = localizar_Disciplinas(codigo_disciplina, lista_disciplinas, qtde_Disciplinas);

        if(posicao_disciplina == NAO_LOCALIZADO)
            printf("DISCIPLINA NAO LOCALIZADA. DIGITE NOVAMENTE!!!!\n");
    }while(posicao_disciplina == NAO_LOCALIZADO);
    
    if(lista_disciplinas[posicao_disciplina].contador >= LIMITE_ALUNOS)
        return ERRO_LIMITE_ALUNOS; 
    
    do{
        printf("Informe a matricula do aluno a ser incluso: ");
        scanf("%d", &matricula_aluno);
    
        posicao_aluno= localizar_Alunos(matricula_aluno, Alunos);
        
        if(posicao_aluno == NAO_LOCALIZADO)
            printf("ALUNO NAO LOCALIZADO. DIGITE NOVAMENTE!!!!\n");
        
        verificacao= localizar_Alunos_Disciplina(matricula_aluno, lista_disciplinas, posicao_disciplina);
        
        if(verificacao != NAO_LOCALIZADO)
            printf("ALUNO JÁ ESTA CADASTRADO NESTA DISCIPLINA.DIGITE NOVAMENTE!!!! \n");
    
        
    }while(posicao_aluno == NAO_LOCALIZADO || verificacao != NAO_LOCALIZADO );

    lista_disciplinas[posicao_disciplina].alunos_matriculados[lista_disciplinas[posicao_disciplina].contador] = Alunos[posicao_aluno].matricula; 
    lista_disciplinas[posicao_disciplina].contador++; // INCREMENTANDO O CONTADOR DE ALUNOS NESTA DISCIPLINA
    
    return SUCESSO_CADASTRO;
}

// FUNÇÃO PARA EXCLUSÃO DE UM ALUNO NUMA DISCIPLINA
int excluir_aluno_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas){

    int code;
    int matricula;
    int posicao_disciplina;
    int posicao_aluno;
    int i;

   do{
    printf("Informe o codigo da disciplina que deseja excluir o aluno: ");
    scanf("%d", &code);

    posicao_disciplina= localizar_Disciplinas(code, lista_disciplinas, qtde_Disciplinas);
    
    if(posicao_disciplina == NAO_LOCALIZADO)
        printf("DISCIPLINA NAO LOCALIZADA. DIGITE NOVAMENTE!!!!\n");
    
   }while (posicao_disciplina == NAO_LOCALIZADO);
   
   do{
    printf("Informe a matricula do aluno que deseja excluir desta disciplina: ");
    scanf("%d", &matricula);
    
    posicao_aluno= localizar_Alunos_Disciplina(matricula, lista_disciplinas, posicao_disciplina);
    
    if(posicao_aluno == NAO_LOCALIZADO)
        printf("ALUNO NAO LOCALIZADO NESTA DISCIPLINA. DIGITE NOVAMENTE!!!!\n");
    
   }while(posicao_aluno == NAO_LOCALIZADO);
   
    for (i = posicao_aluno; i < lista_disciplinas[posicao_disciplina].contador; i++)
                lista_disciplinas[posicao_disciplina].alunos_matriculados[i]= lista_disciplinas[posicao_disciplina].alunos_matriculados[i+1];
    lista_disciplinas[posicao_disciplina].contador--;
    
    return SUCESSO_EXCLUSAO;
            
}

//FUNÇÃO PARA LOCALIZAR DISCIPLINAS PELO CODIGO
int localizar_Disciplinas(int loc_codigo, Disciplina lista_disciplinas[], int qtde_Disciplinas){
    int posicao;
    for (posicao = 0; posicao< qtde_Disciplinas; posicao++) {
        if (lista_disciplinas[posicao].codigo == loc_codigo) {
            return posicao;
        }
    }
    return NAO_LOCALIZADO;
}

//FUNÇÃO PARA LOCALIZAR ALUNOS PELO NUMERO DE MATRICULA
int localizar_Alunos(int loc_matricula,  Lista_aluno Alunos[]){
	int X;
    for (X = 0; X < TAM_ALUNOS ; X++) {
        if (Alunos[X].matricula == loc_matricula) {
            return X;
        }
    }
    return NAO_LOCALIZADO;
} 

//FUNÇÃO PARA LOCALIZAR PROFESSORES PELO NUMERO DE MATRICULA
int localizar_Professores(int loc_matricula,  Lista_Prof Professores[]){
	int X;
    for (X = 0; X < TAM_PROFESSOR ; X++) {
        if (Professores[X].matricula == loc_matricula) {
            return X;
        }
    }
    return NAO_LOCALIZADO;
} 

//FUNÇÃO PARA LOCALIZAR ALUNOS JÁ CADASTRADOS EM ALGUMA DISCIPLINA
int localizar_Alunos_Disciplina(int loc_matricula , Disciplina lista_disciplinas[], int posicao_disciplina){
    int X;
    for (X = 0; X < lista_disciplinas[posicao_disciplina].contador; X++) {
        if (lista_disciplinas[posicao_disciplina].alunos_matriculados[X] == loc_matricula) {
            return X;
        }
    }
    return NAO_LOCALIZADO;
}

// FUNÇÃO PARA ZERAR O CONTADOR DE ALUNOS DENTRO DE CADA DISCIPLINA
void zerando_contador(Disciplina lista_disciplinas[]){
    int k;
    for (k = 0; k < TAM_DISCIPLINAS; k++){
        lista_disciplinas[k].contador = 0;
    }
}

//FUNÇÃO PARA ALTERAR O CADASTRO DAS DISCIPLINAS
void alterar_cadastro_disciplina(Disciplina lista_disciplinas[], int qtde_Disciplinas, Lista_Prof Professores[]){
    
    int code;
    int posicao_disciplina;
    int opcao;
    int verificador;
    int alt_code;
    char alt_name[30];
    int alt_professor;
    int alt_sem;
    
    printf("Informe o codigo da Disciplina que você deseja alterar\n");
    scanf("%d",&code);
    
    posicao_disciplina = localizar_Disciplinas(code, lista_disciplinas, qtde_Disciplinas);
    
    
    printf("###Informe que dado a ser alterado###\n");
    printf("1.Codigo\n");
    printf("2.Nome\n");
    printf("3.Semestre\n");
    printf("4.Professor\n");
    
    scanf("%d",&opcao);
    getchar();
    
    switch(opcao)
    {
        case 1:
        {
            do{
            printf("Informe o novo codigo:\n");
            scanf("%d",&alt_code);
            verificador= valida_codigo(alt_code, lista_disciplinas, qtde_Disciplinas);
            
            if(verificador== SUCESSO_CADASTRO){
                lista_disciplinas[posicao_disciplina].codigo = alt_code;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
            }
            else
                printf("\n###CODIGO INVALIDO###\n");
                
            }while(verificador != SUCESSO_CADASTRO);
                break;
        }
        case 2:
        {
            printf("Informe o novo nome:\n");
            fgets(alt_name, 30, stdin);
            size_t ln = strlen(alt_name) - 1; 
            if (alt_name[ln] == '\n')
                alt_name[ln] = '\0';
    
            strcpy(lista_disciplinas[posicao_disciplina].nome, alt_name);
            printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            
        }
        case 3:
        {
            do{
            printf("Informe o novo semestre:\n");
            scanf("%d",&alt_sem);
            
            verificador= valida_semestre(alt_sem, lista_disciplinas, qtde_Disciplinas);
            
            if(verificador== SUCESSO_CADASTRO){
                lista_disciplinas[posicao_disciplina].semestre = alt_sem;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
            }
            else
                printf("\n###SEMESTRE INVALIDO###\n");
            }while(verificador != SUCESSO_CADASTRO);
                break;
        }
        case 4:
        {
        
            do{
                printf("Digite a nova matricula do professor da disciplina: ");
                scanf("%d", &alt_professor);
                getchar();
                verificador = localizar_Professores(alt_professor, Professores);
                if(verificador== NAO_LOCALIZADO)
                    printf("PROFESSOR NÃO LOCALIZADO. DIGITE NOVAMENTE!!\n");
                else{
                    strcpy(lista_disciplinas[posicao_disciplina].professor_Disciplina, Professores[verificador].nome);
                    printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                }
            }while(verificador == NAO_LOCALIZADO);

        } 
        
    }
    
}

//FUNÇÃO PARA VALIDAR O CODIGO DA DSICIPLINA
int valida_codigo(int codigo_disciplina, Disciplina lista_disciplinas[], int qtde_Disciplinas){
    
    int verificador;
    
    if (codigo_disciplina <= 0) {
        return CODIGO_INVALIDO;
    }
    verificador= localizar_Disciplinas(codigo_disciplina, lista_disciplinas, qtde_Disciplinas);
    if(verificador!= NAO_LOCALIZADO)
        return CODIGO_EXISTENTE;

    return SUCESSO_CADASTRO;
}

//FUNÇÃO PARA VALIDAR O SEMESTRE DA DSICIPLINA
int valida_semestre(int semestre_disciplina, Disciplina lista_disciplinas[], int qtde_Disciplinas){
    int verificador;
    
    if (semestre_disciplina >= 11) {
        return SEMESTRE_INVALIDO;
    }

    return SUCESSO_CADASTRO;
}
