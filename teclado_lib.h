#ifndef teclado_lib_h
#define teclado_lib_h

#include<stdio.h>
#include"pico/stdlib.h"


#define ASTERISTICO 13
#define JOGO_DA_VELHA 14
#define TECLA_A 10
#define TECLA_B 11
#define TECLA_C 12
#define TECLA_D 15

static uint columns[4]; 
static uint rows[4];


static const int TECLADO[16] = {
    1, 2 , 3, 10,
    4, 5 , 6, 11,
    7, 8 , 9, 12,
    13, 0 , 14, 15
};

void setColunasTeclado(uint c1,uint c2, uint c3, uint c4);

void setLinhasTeclado(uint r1, uint r2, uint r3, uint r4);

void inicializacaoTeclado();
int lerTeclado();

#endif