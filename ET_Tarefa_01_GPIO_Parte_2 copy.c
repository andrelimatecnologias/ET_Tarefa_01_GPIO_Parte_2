#include <stdio.h>
#include "pico/stdlib.h"
#include "teclado.h"
#include "buzzer.h"
#include "matriz_led.h"

uint32_t vermelho,verde,azul,ciano,amarelo,roxo,branco;

void inicializacao(){
  // teclado
  setLinhasTeclado(8,9,6,5);
  setColunasTeclado(4,3,2,28);
  inicializacaoTeclado();

  // buzzer
  inicializacaoBuzzer(21);

  // matriz de leds
  inicializacaoMatrizLed(7);

    vermelho = getCorRGB(1.0,0.0,0.0);
    verde = getCorRGB(0.0,1.0,0.0);
    azul = getCorRGB(0.0,0.0,1.0);
    ciano = getCorRGB(0.0,1.0,1.0);
    amarelo = getCorRGB(1.0,1.0,0.0);
    roxo = getCorRGB(1.0,0.0,1.0);
    branco = getCorRGB(1.0,1.0,1.0);
  
}

void play_animacao1(){

}

void play_animacao2(){
    
}

void play_animacao3(){
    
}

void play_animacao4(){
    
}

void play_animacao5(){
    
}

void play_animacao6(){
    
}

void emitirSomPersonalizado(uint32_t frequencia){
    tocaBuzzer(frequencia,20000);
    sleep_ms(50);
}



void play_animacao7(){
    
    int numero0[13] = {1,2,3,8,13,18,23,22,21,16,11,6,1};
    int numero1[5] = {3,8,13,18,23};
    int numero2[11] = {1,2,3,8,13,12,11,16,21,22,23};
    int numero3[11] = {1,2,3,8,13,12,11,18,23,22,21};
    int numero4[9] = {1,6,11,12,13,8,3,18,23};
    int numero5[11] = {3,2,1,6,11,12,13,18,23,22,21};
    int numero6[12] = {3,2,1,6,11,16,21,22,23,18,13,12};
    int numero7[7] = {1,2,3,8,13,18,23};
    int numero8[13] = {1,2,3,8,13,18,23,22,21,16,11,6,12};
    int numero9[12] = {12,11,6,1,2,3,8,13,18,23,22,21};

    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero9,12,vermelho,20,emitirSomPersonalizado,100);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero8,13,verde,20,emitirSomPersonalizado,200);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero7,7,azul,20,emitirSomPersonalizado,300);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero6,12,amarelo,20,emitirSomPersonalizado,400);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero5,11,roxo,20,emitirSomPersonalizado,500);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero4,9,ciano,20,emitirSomPersonalizado,600);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero3,11,vermelho,20,emitirSomPersonalizado,700);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero2,11,verde,20,emitirSomPersonalizado,800);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero1,5,azul,20,emitirSomPersonalizado,900);
    sleep_ms(500);
    desligaTodosLEDs();
    ligaLEDsNaCorComIntervalo(numero0,13,branco,20,emitirSomPersonalizado,1000);
    sleep_ms(500);
    desligaTodosLEDs();
    pintaFrame(120);
}

void analisaTeclaPressionada(int tecla){
    if(tecla>=0){
        if(TECLADO[tecla]==1){
            play_animacao1();
        }
        if(TECLADO[tecla]==2){
            play_animacao2();
        }
        if(TECLADO[tecla]==3){
            play_animacao3();
        }
        if(TECLADO[tecla]==4){
            play_animacao4();
        }
        if(TECLADO[tecla]==5){
            play_animacao5();
        }
        if(TECLADO[tecla]==6){
            play_animacao6();
        }
        if(TECLADO[tecla]==7){
            play_animacao7();
        }
        if(TECLADO[tecla]==ASTERISTICO){
          printf("tecla asteristico pressionada!\n");
        }
        if(TECLADO[tecla]==JOGO_DA_VELHA){
          printf("tecla jogo da velha pressionada!\n");
        }
        if(TECLADO[tecla]==TECLA_A){
          desligaTodosLEDs();
          pintaFrame(0);
        }
        if(TECLADO[tecla]==TECLA_B){
          ligaTodosLEDsNaCor(getCorRGB(0.0,0.0,1.0));
          pintaFrame(0);
        }
        if(TECLADO[tecla]==TECLA_C){
          ligaTodosLEDsNaCor(getCorRGB(0.8,0.0,0.0));
          pintaFrame(0);
        }
        if(TECLADO[tecla]==TECLA_D){
          ligaTodosLEDsNaCor(getCorRGB(0.0,0.5,0.0));
          pintaFrame(0);
        }
    }
}

int main() {
  stdio_init_all();
  inicializacao();
  
  
  //imprimeLEDs();
  
  while (true) {
    int tecla = lerTeclado();
    busy_wait_us(100000);
    analisaTeclaPressionada(tecla);
  }
  
} 