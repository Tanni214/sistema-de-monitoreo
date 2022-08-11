#include <Wire.h>

void setup() {
 Serial.begin(9600); /* begin serial for debug */
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
}

void loop() {

 Wire.requestFrom(8, 1); /* request & read data of size 13 from slave */
 while(Wire.available()){
    int h = Wire.read();
    //Serial.print("Humedad:  ");
    Serial.print(h);
    //Serial.println(" %t");
 
  }/* request & read data of size 13 from slave */
    Wire.requestFrom(8, 1);
    while(Wire.available()){
    int t = Wire.read();
    //Serial.print("Temperatura: ");
    Serial.print(t);
    //Serial.println(" *C ");
  
   }/* request & read data of size 13 from slave */
    Wire.requestFrom(8, 1);
   while(Wire.available()){
    int v = Wire.read();
  Serial.print(v);
  
 }
 Serial.println();
 delay(1000);

 
}
