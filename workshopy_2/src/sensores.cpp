#include "sensores.h"
#include <Arduino.h>



#define red 0
#define green 1
#define sensorpir 9
#define buzzer 8

void exibirTemperatura() {
    int PinoAnalog = analogRead(A0);
    int NewPinoAnalog = map(PinoAnalog, 20, 358, -40, 125);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura de:");
    lcd.setCursor(0, 1);
    lcd.print(NewPinoAnalog);
    lcd.print(" C");
    delay(7000);
    lcd.clear();
}

void exibirGas() {
    int MQ2pin = A1;
    pinMode(buzzer, OUTPUT);
    float sensorValue = analogRead(MQ2pin);

    if (sensorValue >= 450) {
        digitalWrite(buzzer, HIGH);
        digitalWrite(red, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Perigo de gas:");
        lcd.setCursor(0, 1);
        lcd.print(sensorValue);
        delay(7000);
        digitalWrite(buzzer, LOW);
        digitalWrite(red, LOW);
    } else {
        digitalWrite(buzzer, LOW);
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sem perigo:");
        lcd.setCursor(0, 1);
        lcd.print(sensorValue);
        delay(7000);
        digitalWrite(green, LOW);
    }
    lcd.clear();
}