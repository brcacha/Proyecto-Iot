#include <M5Stack.h>
const int EchoPin = 16;
const int TriggerPin = 17;

void setup() {
  
Serial.begin(9600);
pinMode(TriggerPin, OUTPUT);
pinMode(EchoPin, INPUT);
M5.begin();
}
void loop() {
  
Serial.print("Distancia: ");
M5.Lcd.print("Distancia: ");
Serial.println(distancia(TriggerPin, EchoPin));
M5.Lcd.println(distancia(TriggerPin, EchoPin));
delay(1000);

}

int distancia(int TriggerPin, int EchoPin) {
long duracion, distanciaCm;
digitalWrite(TriggerPin, LOW); 
//nos aseguramos señal baja al principio
delayMicroseconds(4);
digitalWrite(TriggerPin, HIGH); 
//generamos pulso de 10us
delayMicroseconds(10);
digitalWrite(TriggerPin, LOW);
duracion = pulseIn(EchoPin, HIGH);  
//medimos el tiempo del pulso
distanciaCm = duracion * 10 / 292 / 2;   
//convertimos a distancia
return distanciaCm;
}
