#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Sensores.h"
#include "Relogio.h"


LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    attachInterrupt(0, muda, RISING);/* A funçao "attachInterrupt serve para 
    executar automaticamente quando ocorre algo em um pino específico no arduíno
    sem necessidade de executar várias vezes no loop().
    Resumindo: -Quando o botão conectado ao pino 2 for pressionado, a função muda()
    será chamada imediatamente, -Quando o botão conectado ao pino 3 for pressionado,
    a função escolheOpcao() será chamada imediatamente."*/ 
    attachInterrupt(1, escolheOpcao, RISING);
    lcd.begin(16, 2);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    Serial.begin(9600);
}

void loop() {
    atualizarRelogio();
    exibirTemperatura();
    exibirGas();
    exibirUmidade();
    exibirPresenca();
}
