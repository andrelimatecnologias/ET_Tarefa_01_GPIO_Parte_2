#ifndef buzzer_h
#define buzzer_h

#include<stdio.h>
#include"pico/stdlib.h"

static int GPIO_BUZZER;

void inicializacaoBuzzer(int gpio_buzzer);

void tocaBuzzer(uint32_t frequencia_h,uint32_t intervalo_us);

#endif