#define analogMQ7 A0      // Signal 
 
#include "DHT.h"
#define DHTPIN 4 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 dht.begin();
 pinMode (analogMQ7, INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  //dht
  int h = dht.readHumidity(); //Leemos la Humedad //uso int por el tema de la pesicion
  int t = dht.readTemperature();
  
  //COMPOROBACION DE LECTURA
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
}


    
int sensorValue = analogRead(analogMQ7);
int v= (sensorValue*2000)/(3000); //para imprimir valor real
 Serial.print("MQ-7 PPM: "); 
 Serial.print(v);
Serial.print("          ");
  Serial.print("Humedad:");
  Serial.print(h);
  Serial.print(" %          ");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" ºc");
 delay(1500);
}
