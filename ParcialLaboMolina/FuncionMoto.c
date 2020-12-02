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
void hardcodearCliente(cCliente listC[]){
    cCliente auxlistC[] =
    {
        {1, "Alfredo",'h'},
        {2, "Roberto",'h'},
        {3, "Bianca",'m'},
        {4, "Rosa",'m'},
        {5, "Juan",'h'},
    };
    for(int i=0; i<5; i++)
    {
        listC[i] = auxlistC[i];
    }
}
int menuPrincipal(char mensaje[]){
    int opcion;
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&opcion);
    system("cls");
    return opcion;
}

int initMotos(mMotos list[], int tam){
    if(list!= NULL && tam>0){
        for(int i=0; i<tam; i++)
        {
            list[i].isEmpty=TRUE;

        }
    }
    return 0;
}
int altaMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT){
    if(addMotos(list,listC,listT,listcC,tam,tamC,tamT)==1){
        printf("No hay espacio para agregar una nueva moto\n");
    }else{
        printf("\nSe a ingresado la moto con exito!\n");
    }
    return 0;
}

int addMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT){
    int isError=1;
    int indice;
    mMotos nuevaMoto;
    if(list!= NULL && tam>0)
    {
        indice = buscarMotoLibre(list, tam);
        if(indice!= -1){

            nuevaMoto.isEmpty = FALSE;
            nuevaMoto.id=indice+1;
            do{
                printTipo(listT,tamT);
                SetInt(&nuevaMoto.idTipo,"Ingrese Tipo: ");
                system("cls");
            }while(validacionTipo(nuevaMoto.idTipo)!=0);
            do{
                printClientes(listcC);
                SetInt(&nuevaMoto.idCliente,"Ingrese Cliente: ");
                system("cls");
            }while(nuevaMoto.idCliente<0 && nuevaMoto.idCliente>5);
            SetString(nuevaMoto.marca,"Ingrese Marca de moto: ");
            system("cls");
            do{
                printColor(listC,tamC);
                SetInt(&nuevaMoto.idColor,"Ingrese Color: ");
                system("cls");
            }while(validacionColor(nuevaMoto.idColor)!=0);
            do{
                SetInt(&nuevaMoto.cilindrada,"Ingrese Cilindrada 50/125/500/600/750: ");
                system("cls");
            }while(validacionCilindrada(nuevaMoto.cilindrada)!=0);

            list[indice]= nuevaMoto;

            isError=0;
        }
    }
    return isError;
}

int buscarMotoLibre(mMotos list[], int tam){
    int aux=-1;

    for(int i=0; i<tam; i++){
        if(list[i].isEmpty == TRUE){
            aux = i;
            break;
        }
    }
    return aux;
}

int imprimirMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT, int flag){
    int opcion=0;
    if(flag!=0){
        do{
            printMoto(list,listC,listT,listcC, tam,tamC,tamT);
            opcion=3;
        }while(opcion != 3);
    }else{
        flagAlta(flag);
    }
    return 0;
}


int flagAlta(int flag){
    if(flag==0){
        printf("No se puede usar esta opcion hasta que se realize la primera ALTA de moto\n");
    }
    return 0;
}

int bajaMoto(mMotos list[], cColor listC[], tTipo listT[],tTrabajo listTrabajo[],cCliente listcC[], int tam, int tamC, int tamT, int flag){
    int aux;
    if(flag!=0){
        printMoto(list,listC,listT,listcC, tam,tamC,tamT);
        SetInt(&aux,"\nIngrese el ID de la moto a dar de baja: ");
        aux=removeMoto(list,listTrabajo,tam, aux);
        if(aux==0){
            printf("No se a encontrado la moto\n");
        }else{
            flag--;
        }
    }else{
        flagAlta(flag);
    }
    return flag;
}
int removeMoto(mMotos list[],tTrabajo listTrabajo[], int tam, int id){
    int encontrado=0;
    int aux;
    aux=findMotoById(list, tam, id);
    if(aux!=-1){
        encontrado=1;
        for(int i=0;i<tam;i++){
            if(listTrabajo[i].idMoto== list[aux].id){
                listTrabajo[i].isEmpty=TRUE;
            }
        }
        list[aux].isEmpty=TRUE;
    }
    return encontrado;
}

int findMotoById(mMotos list[], int tam, int id){
    int indice=-1;
    for(int i=0;i<tam;i++){
        if(list[i].id==id && list[i].isEmpty==FALSE){
            indice=i;
            break;
        }
    }
    return indice;
}

int printMoto(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT){
    printf("ID |Tipo  |Marca  |Cilindrada |Color  |Dueno\n");
    for(int i=0;i<tam;i++){
        if(list[i].isEmpty==FALSE){
            printf("%2d |%5s |%5s |%2d |%5s |%s\n", list[i].id, listT[devolverIdTipo(listT,tamT,list[i].idTipo)].descripcion, list[i].marca, list[i].cilindrada, listC[printColorImprimir(listC , tamC,list[i].idColor)].nombreColor,listcC[devolverIdCliente(listcC,list[i].idCliente)].nombre);
        }
    }
    return 0;
}

int modificarMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT,int flag){
    int aux;
    if(flag!=0){
        printMoto(list,listC,listT,listcC, tam,tamC,tamT);
        SetInt(&aux,"\nIngrese el ID de la moto a modificar: ");
        system("cls");
        aux=modifyMotos(list,listC, tam,tamC, aux);
        if(aux==0){
            printf("No se a encontrado la moto\n");
            system("pause");
        }
    }else{
        flagAlta(flag);
        system("pause");
    }
    return 0;
}

int modifyMotos(mMotos list[], cColor listC[], int tam, int tamC,int id){
    int aux;
    int encontrado=0;
    int menu;
    aux=findMotoById(list, tam, id);
    if(aux!=-1){
        encontrado=-1;
        do{

            SetInt(&menu,"MENU MODIFICAR MOTO\n1.COLOR\n2.CILINDRADA\n3.MENU PRINCIPAL\n");
            system("cls");
            switch(menu){

                case 1:
                    printColor(listC,tamC);
                    SetInt(&list[aux].idColor,"Ingrese nuevo color: ");
                    break;

                case 2:
                    SetInt(&list[aux].cilindrada,"Ingrese nueva cilindrada 50/125/500/600/750: ");
                    break;

                case 3:
                    encontrado=1;
                    break;
            }
            system("cls");
        }while (menu!=3);
    }
    return encontrado;
}
int sumaFecha(tTrabajo listTrabajo[], int i){

    return((listTrabajo[i].Fecha.ano*100)+listTrabajo[i].Fecha.mes)*100+listTrabajo[i].Fecha.dia;
}

int ordenamientoFecha(tTrabajo listTrabajo[], int tam){
    tTrabajo auxTrabajo;
    for(int i=0;i<tam-1;i++){
        if(listTrabajo[i].isEmpty == FALSE){
            for(int j=i+1;j<tam;j++){
                if(sumaFecha(listTrabajo,i)>sumaFecha(listTrabajo,j)){
                    auxTrabajo=listTrabajo[i];
                    listTrabajo[i]=listTrabajo[j];
                    listTrabajo[j]=auxTrabajo;
                }
            }
        }

    }
    return 0;
}
int devolverIdCliente(cCliente listC[], int aux){
    int auxId=0;
    for(int i=0;i<5;i++){
        if(aux==listC[i].id){
            auxId=i;
            break;
        }
    }
    return auxId;
}
int printClientes(cCliente listcC[]){
    printf("CLIENTES\n");
    for(int i=0;i<5;i++){
        printf("%d |%s | %c\n", listcC[i].id, listcC[i].nombre,listcC[i].sexo);
    }

    return 0;
}
