#include"teclado_lib.h"
#include<stdio.h>
#include"pico/stdlib.h"



void setColunasTeclado(uint c1,uint c2, uint c3, uint c4){
  columns[0] = c1;
  columns[1] = c2;
  columns[2] = c3;
  columns[3] = c4;
}

void setLinhasTeclado(uint r1, uint r2, uint r3, uint r4){
  rows[0] = r1;
  rows[1] = r2;
  rows[2] = r3;
  rows[3] = r4;
}

void inicializacaoTeclado(){
  for(int i=0;i<4;i++){
    gpio_init(columns[i]);
    gpio_init(rows[i]);
    gpio_set_dir(columns[i],GPIO_IN);
    gpio_set_dir(rows[i],GPIO_OUT);
    gpio_put(rows[i], true);
  }
}
int lerTeclado(){
  int col=-1;
  for(int i=0;i<4;i++){
    if(gpio_get(columns[i])){
      col=i;
    }
  }
  int row=-1;
  if(col!=-1){
    for(int i=0;i<4;i++){
      gpio_put(rows[i],false);
    }
    
    for(row=0;row<4;row++){
      gpio_put(rows[row],true);
      if(gpio_get(columns[col])){
        break;
      }
    }
    for(int i=row+1;i<4;i++){
      gpio_put(rows[i],true);
    }
  }
  
  return row*4+col;
}
