#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Sensores.h"
#include "Relogio.h"


LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    attachInterrupt(0, muda, RISING);
    attachInterrupt(1, escolheOpcao, RISING);
    lcd.begin(16, 2);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    Serial.begin(115200);
}

void loop() {
    atualizarRelogio();
    exibirTemperatura();
    exibirGas();
    exibirUmidade();
    exibirPresenca();
}
