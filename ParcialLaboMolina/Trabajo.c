#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionMoto.h"
#include "Color.h"
#include "Tipo.h"
#include "Validaciones.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"
#include "InputGenerico.h"
#define TRUE 1
#define FALSE 0
int initTrabajos(tTrabajo listTrabajo[], int tam){
    if(listTrabajo!= NULL && tam>0){
        for(int i=0; i<tam; i++)
        {
            listTrabajo[i].isEmpty=TRUE;

        }
    }
    return 0;
}
int altaTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], cColor listC[],tTipo listT[],cCliente listcC[], int tam, int tamS, int tamC, int tamT, int flag,int* id){
    int flagTrabajo=0;
    if(flag!=0){
        if(addTrabajo(listTrabajo,list, listS,listC,listT,listcC,tam, tamS,tamC,tamT,&id)==1){
            printf("No hay espacio para agregar un nuevo trabajo\n");
        }else{
            printf("\nSe a ingresado el trabajo con exito!\n");
        }
    }else{
        flagAlta(flag);
    }

    return flagTrabajo;
}

int addTrabajo(tTrabajo listTrabajo[],mMotos list[], sServicio listS[], cColor listC[],tTipo listT[],cCliente listcC[], int tam, int tamS, int tamC, int tamT,int** id){
    int isError=1;
    int indice;
    int auxA=1;
    tTrabajo auxTrabajo;
    if(listTrabajo!= NULL && tam>0){
        indice = buscarTrabajoLibre(listTrabajo, tam);
        if(indice!= -1){
            (**id)++;
            auxTrabajo.id=**id;
            auxTrabajo.isEmpty = FALSE;
            do{
                printMoto(list,listC,listT,listcC,tam,tamC,tamT);
                SetInt(&auxTrabajo.idMoto,"Ingrese ID Moto: ");
                system("cls");
                auxA=findMotoById(list, tam, auxTrabajo.idMoto);
                if(auxA==-1){
                    printf("No se encontro la moto\n");
                }
            }while(auxA==-1);
            do{
                printServicio(listS,tamS);
                SetInt(&auxTrabajo.idServicio,"Ingrese ID Servicio: ");
                system("cls");
            }while(validacionServicio(auxTrabajo.idServicio)!=0);
            do{
                SetInt(&auxTrabajo.Fecha.dia,"Ingrese Dia: ");
                system("cls");
            }while(validacionDia(auxTrabajo.Fecha.dia)!=0);
            do{
                SetInt(&auxTrabajo.Fecha.mes,"Ingrese Mes: ");
                system("cls");
            }while(validacionMes(auxTrabajo.Fecha.mes)!=0);
            do{
                SetInt(&auxTrabajo.Fecha.ano,"Ingrese Ano: ");
                system("cls");
            }while(validacionAno(auxTrabajo.Fecha.ano)!=0);

            listTrabajo[indice]= auxTrabajo;

            isError=0;
        }
    }
    return isError;
}
int buscarTrabajoLibre(tTrabajo listTrabajo[], int tam){
    int aux=-1;

    for(int i=0; i<tam; i++){
        if(listTrabajo[i].isEmpty == TRUE){
            aux = i;
            break;
        }
    }
    return aux;
}
int printTrabajos(tTrabajo listTrabajo[], sServicio listS[], int tam, int tamS, int flag, int flagTrabajo){
    int opcion=0;
    if(flag!=0 && flagTrabajo!=0){
        do{
                printf("ID Trabajo |ID Moto |Servicio       |Fecha\n");
                for(int i=0;i<tam;i++){
                    if(listTrabajo[i].isEmpty==FALSE){
                        printf("%10d |%7d |%s%d |%d/%d/%d\n",listTrabajo[i].id, listTrabajo[i].idMoto, listS[devolverDescripcion(listS,tamS,listTrabajo[i].idServicio)].descripcion,listS[devolverDescripcion(listS,tamS,listTrabajo[i].idServicio)].precio, listTrabajo[i].Fecha.dia, listTrabajo[i].Fecha.mes, listTrabajo[i].Fecha.ano);
                    }
                }
                opcion=3;
        }while(opcion != 3);
    }else{
        flagAltaTrabajo(flagTrabajo);
    }
    return 0;
}
int flagAltaTrabajo(int flag){
    if(flag==0){
        printf("No se puede usar esta opcion hasta que se realize la primera ALTA de Trabajos\n");
    }
    return 0;
}

