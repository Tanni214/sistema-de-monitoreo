#include <Wire.h>
#define analogMQ7 A0 
#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


int h;
int t;
char flag=0;
int sensorValue = analogRead(analogMQ7);
int v= (sensorValue*2000)/(3000); //para imprimir valor real
 
void setup() {
 Wire.begin(8);                /* join i2c bus with address 8 */
 Wire.onReceive(receiveEvent); /* register receive event */
 Wire.onRequest(requestEvent); /* register request event */
 Serial.begin(9600);    
 /* start serial for debug */
}

void loop() {
 delay(100);

   h = dht.readHumidity(); //Leemos la Humedad //uso int por el tema de la pesicion
   t = dht.readTemperature();

   sensorValue = analogRead(analogMQ7);
   v= (sensorValue*2000)/(3000); //para imprimir valor real

delay(1500);
  
}

// function that executes whenever data is received from master
void receiveEvent(int howMany) {
 while (0 <Wire.available()) {
    char c = Wire.read();      /* receive byte as a character */
    Serial.print(c);           /* print the character */
  }
 Serial.println();             /* to newline */
}

// function that executes whenever data is requested from master
void requestEvent() {
  if(flag == 0) {

      Wire.write(h);  /*send string on request */
      flag =1;
      
      }

     else if (flag ==1)  {

      Wire.write(t);  /*send string on request */
      flag =2;
      
      }

     else if (flag ==2)  {

      Wire.write(v);  /*send string on request */
      flag =0;
      
      }

      
}
