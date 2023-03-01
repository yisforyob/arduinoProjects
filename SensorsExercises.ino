// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

int light_sensor = A0;//la photorésistance est connectée à l'analogique pin A0
int temp_sensor = 6; //le capteur de température est connecté à digital pin 6
int greenDELPin = 10; // le DEL verte est connectée à la broche numérique
int redDELPin = 11; // le DEL rouge est connectée à la broche numérique
int lightVal; //variable dans laquelle la valeur de la photorésistance sera stockée.
int temperature = 0; //variable dans laquelle la valeur de la température sera stockée
int tempLimit = 20; // variable qui représentent la limite de température
int lightLimit= 350; //variable qui représente la limite de la valeur de la photorésistance
OneWire oneWirePin(temp_sensor); //Définition de l'objet onewire
DallasTemperature sensors(&oneWirePin); //Passage de la référence de l'objet par la classe
void setup() {
Serial.begin(9600); //Activation de l'interface série
pinMode(light_sensor,INPUT); //la photorésistance est une entrée
pinMode(greenDELPin,OUTPUT); // le DEL rouge est une sortie
pinMode(redDELPin,OUTPUT); // le DEL vert est une sortie
sensors.begin(); //Amorcer le capteur pour que nous puissions demander des données
}
void loop() {
Serial.print("Requesting Temperatures from sensors: ");
sensors.requestTemperatures();
Serial.println("DONE");
temperature = sensors.getTempCByIndex(0); //Stockage des valeurs de sensor.getTempCByIndex(0)into the variable calDEL temperature (declared at the beginning)
Serial.print("Temperature is "); //Le moniteur série sort la température
Serial.print(temperature); // imprimer la valeur de la température
//Configurez les DELS pour qu'elles agissent comme des sorties
if(temperature <= 20){ //Lorsque la température est inférieure à la limite du capteur de température, la DEL verte est allumée.
Serial.println(", Green DEL is activated!");
digitalWrite(greenDELPin, HIGH);
}

else if(temperature > 20){ //Lorsque la température est supérieure à la limite du capteur de température, la DEL verte est éteinte.
digitalWrite(greenDELPin, LOW);
}
lightVal=analogRead(light_sensor); //Lire la valeur de la lumière via la variable associée à la broche
Serial.println("Light value is ");
Serial.print(lightVal); //Imprimer la valeur de la lumière sur l'interface série
delay(250); //Attendez 250 millisecondes
if (lightVal>350){ //Lorsque la valeur de la photorésistance est supérieure à la limite fixée, la DEL rouge est éteinte.
digitalWrite(redDELPin,LOW); // Éteindre le DEL rouge
}
else if (lightVal<350){ //Lorsque la valeur de la photorésistance est inférieure à la limite fixée, la DEL rouge est allumée.
Serial.print(", Red DEL is activated!");
digitalWrite(redDELPin,HIGH); //Allumez le DEL rouge
}
delay (500); //Attendez 500 millisecondes
}
