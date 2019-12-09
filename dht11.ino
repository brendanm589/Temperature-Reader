#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#define DHT11_PIN 2

void lcdPrint(float temp, float hum);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  lcdPrint(DHT.temperature, DHT.humidity);
  delay(2000);
}

void lcdPrint(float temp, float hum)
{
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(hum);
  }
