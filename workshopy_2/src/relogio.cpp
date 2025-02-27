#include "Relogio.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

int seg = 0, min = 58, hora = 8, dia = 30, mes = 12, ano = 2021;

void atualizarRelogio() {
    for (int i = 0; i < 60; i++) {
        lcd.setCursor(6, 0); lcd.print(":");
        lcd.setCursor(9, 0); lcd.print(":");

        lcd.setCursor(4, 0); lcd.print(hora < 10 ? "0" : ""); lcd.print(hora);
        lcd.setCursor(7, 0); lcd.print(min < 10 ? "0" : ""); lcd.print(min);
        lcd.setCursor(10, 0); lcd.print(seg < 10 ? "0" : ""); lcd.print(seg);

        lcd.setCursor(5, 1); lcd.print("/");
        lcd.setCursor(8, 1); lcd.print("/");
        lcd.setCursor(3, 1); lcd.print(dia < 10 ? "0" : ""); lcd.print(dia);
        lcd.setCursor(6, 1); lcd.print(mes < 10 ? "0" : ""); lcd.print(mes);
        lcd.setCursor(9, 1); lcd.print(ano);

        delay(1000);
        seg++;
        if (seg == 60) { seg = 0; min++; if (min == 60) { min = 0; hora++; if (hora == 24) { hora = 0; dia++; if (dia == 32) { dia = 1; mes++; if (mes == 13) { mes = 1; ano++; } } } } }
    }
}
