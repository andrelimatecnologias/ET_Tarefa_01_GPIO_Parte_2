
#include "matriz_led.h"
#include<stdio.h>
#include"pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "pico/bootrom.h"
#include "ET_Tarefa_01_GPIO_Parte_2.pio.h"



uint32_t getCorRGB(double r, double g, double b)
{
  unsigned char R, G, B;
  R = r * 255;
  G = g * 255;
  B = b * 255;
  return (G << 24) | (R << 16) | (B << 8);
}

void pintaFrame(uint32_t intervalo){
    
    for (int16_t i = 0; i < NUM_PIXELS; i++) {
        pio_sm_put_blocking(pio, sm, cores[mapeamento[i]]);
    }
    sleep_ms(intervalo);
    
}


void pintaLED(int led, uint32_t cor){
   cores[led] = cor;
}

void ligaLEDNaCor(int led,uint32_t cor){
    cores[led] = cor;
}

void desligaLED(int led){
    cores[led] = 0;
}

void ligaLEDsNaCor(int *leds, int quant, uint32_t cor){
  for(int i=0;i<quant;i++){
    pintaLED(leds[i],cor);
  }
}


void ligaLEDsNaCorComIntervalo(int *leds, int quant, uint32_t cor,uint32_t intervalo,Funcao funcao,uint32_t frequencia){
  for(int i=0;i<quant;i++){
    pintaLED(leds[i],cor);
    pintaFrame(intervalo);
    funcao(frequencia);
  }
}
void ligaLEDsNasCores(int *leds, int quant, uint32_t *cores_esc){
  for(int i=0;i<quant;i++){
    pintaLED(leds[i],cores_esc[i]);
  }
}
void ligaLEDsNasCoresComIntervalo(int *leds, int quant, uint32_t *cores_esc,uint32_t intervalo){
  for(int i=0;i<quant;i++){
    pintaLED(leds[i],cores_esc[i]);
    pintaFrame(intervalo);
  }
}

void ligaTodosLEDsNaCor(uint32_t cor){
    for(int i=0;i<NUM_PIXELS;i++){
        cores[i] = cor;
    }
}

void ligaTodosLEDsNasCores(uint32_t *cores_esc){
    for(int i=0;i<NUM_PIXELS;i++){
        cores[i] = cores_esc[i];
    }
}

void desligaTodosLEDs(){
    for(int i=0;i<NUM_PIXELS;i++){
        cores[i] = 0;
    }
}

void imprimeLEDs(){

  for(int j=0;j<5;j++){
    for(int i=0;i<5;i++){
      printf("[%d]",cores[j*5+i]);
    }
    printf("\n");
  }
}



void inicializacaoMatrizLed(int gpio_matriz){
  stdio_init_all();
  
  GPIO_MATRIZ_LED = gpio_matriz;
  pio = pio0; 
  //coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
  set_sys_clock_khz(128000, false);
  //configurações da PIO
  uint offset = pio_add_program(pio, &ET_Tarefa_01_GPIO_Parte_2_program);
  sm = pio_claim_unused_sm(pio, true);
  ET_Tarefa_01_GPIO_Parte_2_program_init(pio, sm, offset, GPIO_MATRIZ_LED);
  //pio_matrix_program_init();
  
}
