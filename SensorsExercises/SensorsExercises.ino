// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

int light_sensor = A0, temp_sensor = 6, greenDELPin = 10, redDELPin = 11, lightVal, temperature = 0, tempLimit = 20, lightLimit= 350; 
OneWire oneWirePin(temp_sensor); 
DallasTemperature sensors(&oneWirePin); 


void setup() {
  
Serial.begin(9600);
pinMode(light_sensor,INPUT); 
pinMode(greenDELPin,OUTPUT); 
pinMode(redDELPin,OUTPUT);
sensors.begin(); 

}


void loop() {

  
Serial.print("Requesting Temperatures from sensors: ");
sensors.requestTemperatures();
Serial.println("DONE");

temperature = sensors.getTempCByIndex(0); 
Serial.print("Temperature is "); 
Serial.print(temperature); 

if(temperature <= 20){ 
Serial.println(", Green DEL is activated!");
digitalWrite(greenDELPin, HIGH);
}
else if(temperature > 20){ 
digitalWrite(greenDELPin, LOW);
 }
 
lightVal=analogRead(light_sensor); 
Serial.println("Light value is ");
Serial.print(lightVal); 
delay(250); 

if (lightVal>350){ 
digitalWrite(redDELPin,LOW); 
}
else if (lightVal<350){ 
Serial.print(", Red DEL is activated!");
digitalWrite(redDELPin,HIGH); 
}
delay (500); 
}
