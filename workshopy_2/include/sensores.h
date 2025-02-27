#ifndef SENSORES_H
#define SENSORES_H
#include <Arduino.h>
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

void exibirTemperatura();
void exibirGas();
void exibirUmidade();
void exibirPresenca();

#endif