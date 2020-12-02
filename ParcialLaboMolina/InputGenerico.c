#include <stdio.h>
#include <stdlib.h>
#include "InputGenerico.h"
void SetInt(int* num, char* mensaje){
    printf(mensaje);
    scanf("%d",num);
}

void SetFloat(float* num, char* mensaje){
    printf(mensaje);
    scanf("%f",num);
}

void SetString(char* palabra, char* mensaje){
    printf(mensaje);
    fflush(stdin);
    scanf("%s",palabra);
}
void SetChar(char* letra, char* mensaje){
    printf(mensaje);
    fflush(stdin);
    scanf("%c",letra);
}
