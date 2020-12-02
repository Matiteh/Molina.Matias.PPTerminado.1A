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
int menuInformes(char mensaje[]){
    int opcion;
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}
int informesMenu(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],cCliente listcC[],int tam,int tamT,int tamC,int tamS){
    int opcion=0;
    char conf='s';
    do{
            opcion=menuInformes("ABM Service Motos INFORMES\n1.MOSTRAR COLOR\n2.MOSTRAR TIPO MOTO\n3.MAYOR CILINDRADA\n4.MOSTRAR MOTO POR TIPOS\n5.MOSTRAR CANTIDAD TIPO Y COLOR\n6.MOSTRAR COLOR MAS ELEJIDO\n7.MOSTRAR TRABAJOS MOTO\n8.MOSTRAR SUMA SERVICIOS\n9.MOSTRAR MOTOS EN SERVICIOS\n10.MOSTRAR SERVICIOS POR FECHA\n11.SALIR\n");

            switch(opcion){

                case 1:/*MOSTRAR COLOR*/
                    printColorMotos(list,listT,listC,tam,tamT,tamC);
                    system("pause");
                    break;

                case 2:/*MOSTRAR TIPOS*/
                    printTipoMotos(list,listT,listC,tam,tamT,tamC);
                    system("pause");
                    break;


                case 3:/*MAYOR CILINDRADA*/
                    motoMayorCilindrada(list,listT,listC,tam,tamT,tamC);
                    system("pause");
                    break;



                case 4:/*MOSTRAR MOTOS POR TIPO*/
                    printPorTiposMotos(list,listT,listC,tam,tamT,tamC);
                    system("pause");
                    break;

                case 5:/*MOSTRAR CANT TIPO Y COLOR*/
                    printColoryTipoMoto(list,listT,listC,tam,tamT,tamC);
                    system("pause");
                    break;

                case 6:/*MOSTRAR COLOR MAS ELEJIDO*/
                    colorMayor(list,listC,tam,tamC);
                    system("pause");
                    break;

                case 7:/*MOSTRAR TRABAJOS MOTOS*/
                    printTrabajosMotos(list,listT,listC,listS,listTrabajo,listcC,tam,tamT,tamC,tamS);
                    system("pause");
                    break;

                case 8:/*SUMA SERVICIOS*/
                    printSumaServicios(list,listT,listC,listS,listTrabajo,listcC,tam,tamT,tamC,tamS);
                    system("pause");
                    break;

                case 9:/*MOSTRAR MOTOS SERVICIOS*/
                    printMotosServicios(list,listT,listC,listS,listTrabajo,tam,tamT,tamC,tamS);
                    system("pause");
                    break;
                case 10:
                    printServiciosFecha(list,listT,listC,listS,listTrabajo,tam,tamT,tamC,tamS);
                    system("pause");
                    break;
                case 11:/*ORDENAMIENTOS FECHA*/
                    conf='n';
                    break;
                default:

                    break;
                }
                system("cls");
        }while (conf!='n');
    return 0;
}


int printTipoMotos(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC){
    int tipo=0;
    printTipo(listT,tamT);
    SetInt(&tipo,"Ingrese el id del tipo de motos a mostrar: ");
    system("cls");
    printf("ID |Tipo  |Marca  |Cilindrada |Color\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE && list[i].idTipo==tipo){
            printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor);

        }
    }
    return 0;
}

int printColorMotos(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC){
    int color=0;
    printColor(listC,tamC);
    SetInt(&color,"Ingrese el id del color de motos a mostrar: ");
    system("cls");
    printf("ID |Tipo  |Marca  |Cilindrada |Color\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE && list[i].idColor==color){
            printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor);
        }
    }
    return 0;
}

int motoMayorCilindrada(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC){
    int auxMax=0;
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE){
            if(list[i].cilindrada>auxMax){
                auxMax=list[i].cilindrada;
            }
        }
    }
    printf("ID |Tipo  |Marca  |Cilindrada |Color\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE && list[i].cilindrada==auxMax){
            printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor);
        }
    }
    return 0;
}
int printPorTiposMotos(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC){
    printf("ENDURO\nID |Tipo  |Marca  |Cilindrada |Color\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE && list[i].idTipo==1000){
            printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor);
        }
    }
    printf("\nCHOPERA\nID |Tipo  |Marca  |Cilindrada |Color\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE && list[i].idTipo==1001){
            printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor);
        }
    }
    printf("\nSCOOTER\nID |Tipo  |Marca  |Cilindrada |Color\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE && list[i].idTipo==1002){
            printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor);
        }
    }
    printf("\nCICLOMOTOR\nID |Tipo  |Marca  |Cilindrada |Color\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE && list[i].idTipo==1003){
            printf("%2d |%5s |%5s |%2d |%5s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor);
        }
    }
    return 0;
}
int printColoryTipoMoto(mMotos list[],tTipo listT[],cColor listC[],int tam,int tamT,int tamC){
    int contadorColoryTipo=0;
    int color=0;
    int tipo=0;
    printColor(listC,tamC);
    SetInt(&color,"Ingrese el color: ");
    printTipo(listT,tamT);
    SetInt(&tipo,"\nIngrese el tipo: ");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE){
            if(list[i].idColor==color && list[i].idTipo==tipo){
                contadorColoryTipo++;
            }
        }
    }
    printf("\nLa cantidad de motos con el color y tipo especificados son: %d\n",contadorColoryTipo);
    return 0;
}

int colorMayor(mMotos list[],cColor listC[],int tam,int tamC){
    int contadorColorMayor;
    int auxMayorColor=0;
    int auxIdMayorColor=0;
    for(int i=0;i<tamC;i++){
        contadorColorMayor=0;
        for(int j=0;j<tam;j++){
            if(list[j].isEmpty==FALSE){
                if(list[j].idColor==listC[i].id){
                    contadorColorMayor++;
                }
            }
        }
        if(auxMayorColor<contadorColorMayor){
            auxMayorColor=contadorColorMayor;
            auxIdMayorColor=listC[i].id;
        }
    }
    printf("El color mas elejido por los clientes es el %s\n",listC[devolverIdColorInforme(listC,tamC,auxIdMayorColor)].nombreColor);
    return 0;
}
int motoMayorCantTrabajos(tTrabajo listTrabajo[],mMotos list[],int tam){
    int contadorIdMayor;
    int auxIdMayorTrabajo=0;
    int auxIdMayor=0;
    for(int i=0;i<tam;i++){
        contadorIdMayor=0;
        if(list[i].isEmpty==FALSE){
            for(int j=0;j<tam;j++){
                if(listTrabajo[j].isEmpty==FALSE){
                    if(listTrabajo[j].idMoto==list[i].id){
                        contadorIdMayor++;
                    }
                }
            }
            if(auxIdMayorTrabajo<contadorIdMayor){
                auxIdMayorTrabajo=contadorIdMayor;
                auxIdMayor=list[i].id;
            }

        }
    }
    printf("La ID de moto con mayor cantidad de trabajos es %d\nTrabajos: %d\n",auxIdMayor,auxIdMayorTrabajo);
    return 0;
}
int printTrabajosMotos(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],cCliente listcC[],int tam,int tamT,int tamC,int tamS){
    int moto=0;
    printMoto(list,listC,listT,listcC,tam,tamC,tamT);
    SetInt(&moto,"Ingrese el id de la moto a mostrar trabajos: ");
    system("cls");
    printf("ID Trabajo |ID Moto |Servicio       |Fecha\n");
    for(int i=0;i<tam;i++){
        if(listTrabajo[i].isEmpty==FALSE && listTrabajo[i].idMoto==moto){
            printf("%10d |%7d |%s%d |%d/%d/%d\n",listTrabajo[i].id, listTrabajo[i].idMoto, listS[devolverDescripcion(listS,tamS,listTrabajo[i].idServicio)].descripcion,listS[devolverDescripcion(listS,tamS,listTrabajo[i].idServicio)].precio, listTrabajo[i].Fecha.dia, listTrabajo[i].Fecha.mes, listTrabajo[i].Fecha.ano);
        }
    }
    return 0;
}
int printSumaServicios(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],cCliente listcC[],int tam,int tamT,int tamC,int tamS){
    int moto=0;
    int sumaServicios=0;
    printMoto(list,listC,listT,listcC,tam,tamC,tamT);
    SetInt(&moto,"Ingrese el id de la moto a mostrar trabajos: ");
    for(int i=0;i<tam;i++){
        if(listTrabajo[i].isEmpty==FALSE && listTrabajo[i].idMoto==moto){
           sumaServicios+=listS[devolverDescripcion(listS,tamS,listTrabajo[i].idServicio)].precio;
        }
    }
    printf("\nLa suma total de los servicios a la moto es: $%d\n",sumaServicios);
    return 0;
}
int printMotosServicios(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],int tam,int tamT,int tamC,int tamS){
    int servicio=0;
    int aux=0;
    printServicio(listS,tamS);
    SetInt(&servicio,"Ingrese el id del servicio a mostrar motos: ");
    system("cls");
    printf("ID |Tipo  |Marca  |Cilindrada |Color       |Fecha\n");
    for(int i=0;i<tam;i++){
        if(listTrabajo[i].isEmpty==FALSE && listTrabajo[i].idServicio==servicio){
            aux=devolverIdMotoInforme(list,tam,listTrabajo[i].idMoto);
            printf("%2d |%5s |%5s |%2d |%10s |%d/%d/%d\n", listTrabajo[i].idMoto, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[aux].marca, list[aux].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor, listTrabajo[i].Fecha.dia, listTrabajo[i].Fecha.mes, listTrabajo[i].Fecha.ano);
        }
    }
    return 0;
}
int devolverIdMotoInforme(mMotos list[],int tam,int idMoto){
    int aux=0;
    for(int j=0;j<tam;j++){
        if(idMoto==list[j].id){
            aux=j;
            break;
        }
    }
    return aux;
}
int printServiciosFecha(mMotos list[],tTipo listT[],cColor listC[],sServicio listS[],tTrabajo listTrabajo[],int tam,int tamT,int tamC,int tamS){
    int auxD=0;
    int auxM=0;
    int auxA=0;
    do{
        SetInt(&auxD,"Ingrese Dia: ");
        system("cls");
    }while(validacionDia(auxD)!=0);
    do{
        SetInt(&auxM,"Ingrese Mes: ");
        system("cls");
    }while(validacionMes(auxM)!=0);
    do{
        SetInt(&auxA,"Ingrese Ano: ");
        system("cls");
    }while(validacionAno(auxA)!=0);
    system("cls");
    printf("ID Trabajo |ID Moto |Servicio       |Fecha\n");
    for(int i=0;i<tam;i++){
        if(listTrabajo[i].isEmpty==FALSE && listTrabajo[i].Fecha.dia==auxD && listTrabajo[i].Fecha.mes==auxM && listTrabajo[i].Fecha.ano==auxA){
            printf("%10d |%7d |%s%d |%d/%d/%d\n",listTrabajo[i].id, listTrabajo[i].idMoto, listS[devolverDescripcion(listS,tamS,listTrabajo[i].idServicio)].descripcion,listS[devolverDescripcion(listS,tamS,listTrabajo[i].idServicio)].precio, listTrabajo[i].Fecha.dia, listTrabajo[i].Fecha.mes, listTrabajo[i].Fecha.ano);
        }
    }
    return 0;
}
