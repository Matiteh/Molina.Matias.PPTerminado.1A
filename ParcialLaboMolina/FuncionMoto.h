#ifndef FuncionMoto_h
#define FuncionMoto_h




typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int idCliente;
    int cilindrada;
    int isEmpty;
}mMotos;
typedef struct
{
    int id;
    char nombre[50];
    char sexo;
}cCliente;
#include "Color.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Informes.h"
void hardcodearCliente(cCliente listC[]);

int initMotos(mMotos list[], int tam);

int altaMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT);

int addMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT);

int buscarMotoLibre(mMotos list[], int tam);

int menuPrincipal(char mensaje[]);

int imprimirMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT, int flag);

int printMoto(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT);

int flagAlta(int flag);

int bajaMoto(mMotos list[], cColor listC[], tTipo listT[],tTrabajo listTrabajo[],cCliente listcC[], int tam, int tamC, int tamT, int flag);

int removeMoto(mMotos list[],tTrabajo listTrabajo[], int tam, int id);

int findMotoById(mMotos list[], int tam, int id);

int modifyMotos(mMotos list[], cColor listC[], int tam, int tamC,int id);

int modificarMotos(mMotos list[], cColor listC[], tTipo listT[],cCliente listcC[], int tam, int tamC, int tamT,int flag);

int ordenamientoFecha(tTrabajo listTrabajo[], int tam);

int sumaFecha(tTrabajo listTrabajo[], int i);

int devolverIdCliente(cCliente listC[], int aux);

int printClientes(cCliente listcC[]);

#endif // FuncionMoto_h
