

#include <SoftwareSerial.h>

#define rxPin 1
#define txPin 2

int luz_1 = A4;
int luz_2 = A5;
int reading_1;
int reading_2;
float diferencia;
int duracion;
float inicio;
float fin;

SoftwareSerial BTSerial (rxPin, txPin);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  
reading_1 = analogRead(luz_1);
reading_2 = analogRead(luz_2);
//Serial.println(reading_2);

if(reading_1 < 9){   //COMPROBAR SIEMPRE EL LÍMITE (20)
  inicio = millis();
}

if(reading_2 < 9){
  fin = millis();
}

diferencia = (fin - inicio)/1000;

if (diferencia>0){
duracion = int(diferencia*100);  //para no enviar decimales multiplico x100
}
else{
duracion = 0;
}
Serial.println(duracion);

delay(100);
}


