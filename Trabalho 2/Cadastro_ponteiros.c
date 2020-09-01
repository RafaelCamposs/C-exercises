#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int cadastra_idade(int *p[]);
int cadastra_salario(float *p[]);
int cadastra_sexo(char *p[]);
int cadastra_nome(char *p[]);

int menu();

int main(){
    
    int idade[5],*P_idade[5];
    float salario[5],*P_salario[5];
    char sexo[5],*P_sexo[5];
    char nome[5][50],*P_nome[5];
    int op=0,retorno,x;
    
    for(x=0;x<5;x++)
        P_idade[x] = &idade[x];
    for(x=0;x<5;x++)
        P_nome[x] = &nome[x];
    for(x=0;x<5;x++)
        P_salario[x] = &salario[x];
    for(x=0;x<5;x++)
        P_sexo[x] = &sexo[x];
    
    while(op != 5){
        op=menu();
        switch(op){
            case 1:{
                printf("\nCadastro de idade\n");
                retorno=cadastra_idade(P_idade);
                if(retorno==1){
                    printf("Sucesso!!\n");
                    for(x=0;x<5;x++)
                        printf("\nIdades Registradas: %da %d\n",x+1,idade[x]);
                }
                else
                    printf("ERRO_IDADE\n");
                break;
            }
            case 2:{
                printf("\nCadastro do Salario\n");
                retorno=cadastra_salario(P_salario);
                if(retorno==1){
                    printf("Sucesso!!\n");
                    for(x=0;x<5;x++)
                        printf("\nSalario Registrado: %do %.2f\n",x+1,salario[x]);
                }
                else
                    printf("ERRO_SALARIO\n");
                break;
            }
            case 3:{
                printf("\nCadastro do Sexo\n");
                retorno=cadastra_sexo(P_sexo);
                if(retorno==1){
                    printf("Sucesso!!\n");
                    for(x=0;x<5;x++)
                        printf("\nSexo Registrado: %do %c\n",x+1,sexo[x]);
                }
                else
                    printf("ERRO_SEXO\n");
                break;
            }
            case 4:{
                printf("\nCadastro de Nome\n");
                retorno=cadastra_nome(P_nome);
                if(retorno==1){
                    printf("Sucesso!!\n");
                    for(x=0;x<5;x++)
                        printf("\nNome Registrado: %do %s\n",x+1,nome[x]);
                }
                else
                    printf("ERRO_NOME\n");
                break;
            }
            case 5:{
                printf("\nSaindo do Programa\n"); 
            }
            
            
        }
        
    }
    
    
}

int cadastra_idade(int *p[]){
    
    int count = 0,x;
    for(x=0;x<5;x++){
        printf("\nInforme a Idade\n");
        scanf("%d",p[x]);
        if(*p[x]>0)
            count ++;
    }
    
    if(count==5)
        return 1;
    else
        return 0;
}

int cadastra_salario(float *p[]){
    
    int count = 0,x;
    for(x=0;x<5;x++){
        printf("\nInforme o Salario\n");
        scanf("%f",p[x]);
        if(*p[x]>0)
            count++;
    }
    
    if(count==5)
        return 1;
    else
        return 0;
}

int cadastra_sexo(char *p[]){
   
    int count = 0,x;
    for(x=0;x<5;x++){
        printf("\nInforme o sexo(M ou F ou O)\n");
        getchar();
        scanf("%c",p[x]);
        if(*p[x]>=96)
            *p[x]=*p[x]-32;
        if((*p[x]=='M') ||(*p[x]=='F') || (*p[x]=='O'))
            count++;
    }
    if(count==5)
        return 1;
    else
        return 0;
}

int cadastra_nome(char *p[]){
    
    int tam,x,count=0;
    for(x=0;x<5;x++){
        printf("Informe o Nome\n");
        getchar();
        fgets(p[x],50,stdin);
        tam=strlen(p[x]);
        size_t ln= strlen(p[x])-1;
        if(p[x][ln] =='\n')
            p[x][ln]='\0';
        if(tam<=50)
            count++;
    }
    if(count == 5)
        return 1;
    else
        return 0;
    
}


int menu(){
    
    int v;
    
    printf("\nMENU DE OPCOES\n");
    printf("1.Cadastro de Idade\n");
    printf("2.Cadastro de Salario\n");    
    printf("3.Cadastro de Sexo\n");
    printf("4.Cadastro de Nome\n");
    printf("5.Sair do Programa\n");
    
    scanf("%d",&v);
    return v;
    
}
