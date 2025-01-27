#ifndef buzzer_h
#define buzzer_h

#include<stdio.h>
#include"pico/stdlib.h"

int GPIO_BUZZER;

void inicializacaoBuzzer(int gpio_buzzer){
  GPIO_BUZZER = gpio_buzzer;
  gpio_init(GPIO_BUZZER);
  gpio_set_dir(GPIO_BUZZER,GPIO_OUT);
}

void tocaBuzzer(uint32_t frequencia_h,uint32_t intervalo_us){
  uint64_t periodo = 1000000/frequencia_h;
  uint32_t ciclo1 = periodo/4;
  uint32_t ciclo2 = periodo-ciclo1;
  if((frequencia_h>20)&&(frequencia_h<20000)){
    uint32_t soma=0;
    while (soma<intervalo_us){
      gpio_put(GPIO_BUZZER,true);
      sleep_us(ciclo1);
      gpio_put(GPIO_BUZZER,false);
      sleep_us(ciclo2);
      soma+=periodo;
    }
  }else{
    sleep_us(intervalo_us);
  }
}
#endif