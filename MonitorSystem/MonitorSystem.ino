/*

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/


#include <LiquidCrystal.h>
#include <dht11.h>
#define DHT11PIN 8



const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int ledPin1 =  9, ledPin2 =  7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht11 DHT11;

void setup() {
  
  lcd.begin(16, 2);
  
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  
}

void loop() {
  
  lcd.setCursor(0, 0);
 
  
  int chk = DHT11.read(DHT11PIN);

  lcd.print("Hum(%)   : ");
   lcd.println((float)DHT11.humidity, 2);
  lcd.setCursor(0, 1);
  lcd.print("Temp(C)  : ");
   lcd.println((float)DHT11.temperature, 2);

  delay(2000);

  if ((float)DHT11.temperature > 30 || (float)DHT11.temperature < 10 ||
      (float)DHT11.humidity > 80 || (float)DHT11.humidity < 20 ){
        
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    
    lcd.noDisplay();
    delay(150);
    lcd.display();
    delay(150);
    lcd.noDisplay();
    delay(150);
    lcd.display();
    delay(150);
    
    }else{
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    }

}
