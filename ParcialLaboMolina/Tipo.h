#ifndef TIPO_H
#define TIPO_H

typedef struct
{
    int id;
    char descripcion[21];
}tTipo;

int printTipo(tTipo listT[], int tamT);

void hardcodearTipos(tTipo listT[], int tamT);

int devolverIdTipo(tTipo listT[],int tamT, int aux);

int devolverIdTipoInforme(tTipo listT[],int tamT,int tipo);

#endif // TIPO_H
