#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void imprimir_data(char c[]);
int valida_data_numeros(int dia, int mes, int ano);
int eh_numero(char digito);

int main(){
    
    char data[11];
    
    int dia;
    int mes;
    int ano;
    
    char sDia[3];
    char sMes[3];
    char sAno[5];
    
    // data = "/02/2019"
    
    strcpy(data,"1/1/219");

    int i;
    //converter
    
    imprimir_data(data);
    
    //usar o atoi ou algo do tipo dia = "03" - '0';
    //iDia = atoi(sDia); //sDia - '0';
    
    
    
    //validar
    //int retorno = valida_data_numeros(dia, mes, ano);
    
    return 0;
    
}

void imprimir_data(char dt[])
{
    int i,j,ver;
    int iDia;
    int iMes,TamMes;
    int iAno,TamAno;
    
    char sDia[3];
    char sMes[3];
    char sAno[5];
    
//     Verificando o Dia
    
    for (i = 0, j=0; dt[i] != '/' && i < 2; i++,j++)
    {
        ver=eh_numero(dt[i]);
        if(ver==1)
            sDia[i]=dt[i];
        else
        {
            dt[i]=0;
            break;
        }
    }

    if(dt[i]!='/')
    {
        printf("Dia Inválido\n");
        while(dt[j]!='/')
            j++;
        j++;
    }
    else
    {
        sDia[i] = '\0';
        j++;
        printf("\n%s\n",sDia);
        printf("\n");
        iDia=atoi(sDia);
        printf("%d\n",iDia);
    }
    
//  Verificando o Mes

    for (i = 0 ; dt[j] != '/' && i < 2; i++, j++)
    {
        ver=eh_numero(dt[j]);
        if(ver==1)
            sMes[i]=dt[j];
        else
        {
            dt[j]=0;
            break;
        }
    }
    if(dt[j]!='/')
    {
        printf("Mes Inválido\n");
        while(dt[j]!='/')
            j++;
        j++;
    }
    else
    {
        sMes[i] = '\0';
        j++;
        printf("\n%s\n",sMes);
        printf("\n");
        iMes=atoi(sMes);
        printf("%d\n",iMes);
    }
    
//   Verificando o Ano
    
    for (i = 0 ; dt[j] != '\0' && i < 4; i++, j++)
    {
        ver=eh_numero(dt[j]);
        if(ver==1)
            sAno[i] = dt[j];
        else
            TamAno=1;
    }
    sAno[i] = '\0';
    
    TamAno=strlen(sAno);
    
    if(TamAno!=1 && TamAno>=5)
    {
        if(TamAno==3)
        {
            for(i=0;i<2;i++)
            {
                sAno[i]=sAno[i+1];
            }
            sAno[i]='\0';
        }
    printf("\n%s\n",sAno);
    printf("\n");
    iAno=atoi(sAno);
    printf("%d\n",iAno);
    }
    else
        printf("Ano Inválido\n");
    
    
    
}

int valida_data_numeros(int dia, int mes, int ano)
{
    
    if (dia < 1 || dia > 31)
        return 0;
    
    if (mes < 1 || mes > 12)
        return 0;
    
    if (ano <= 0)
        return 0;
    
    
}

int eh_numero(char digito)
{
    if(digito >47 && digito<58)
        return 1;
    else
        return 0;
}
