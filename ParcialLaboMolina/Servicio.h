#ifndef SERVICIO_H
#define SERVICIO_H

typedef struct
{
    int id;
    char descripcion[21];
    int precio;
}sServicio;

#include "Trabajo.h"

int printServicio(sServicio listS[], int tamS);

void hardcodearServicios(sServicio listS[], int tamS);

int devolverDescripcion(sServicio listS[],int tamS,int aux);

#endif // SERVICIO_H
