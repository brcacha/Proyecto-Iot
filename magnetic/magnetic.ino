#include <M5Stack.h>

const int inputPin = 2;
 
int value = 0;
 
void setup() {
  Serial.begin(9600);
  M5.begin();
  pinMode(inputPin, INPUT_PULLUP);
}
 
void loop(){
  value = digitalRead(inputPin);  //lectura digital de pin
 
  //mandar mensaje a puerto serie en función del valor leido
  if (value == HIGH) {
      M5.Lcd.printf("Encendido");
  }
  else {
      M5.Lcd.printf("Apagado");
  }
  delay(1000);
}
