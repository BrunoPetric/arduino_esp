#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.init(); // initialize the lcd
  lcd.backlight();
  pinMode(3, OUTPUT); 
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print(h);        // print message at (0, 0)
  lcd.setCursor(0, 1);         // move cursor to   (2, 1)
  lcd.print(t); // print message at (2, 1)
  delay(2000);                 // display the above for two seconds

  if(h<60){
    digitalWrite(3, HIGH);
  }
  else{
    digitalWrite(3, LOW);
  }
}