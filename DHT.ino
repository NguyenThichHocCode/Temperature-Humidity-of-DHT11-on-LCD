#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int PINDHT = 8;
const int DHTTYPE = DHT11;
DHT dht(PINDHT, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  float doam = dht.readHumidity();
  float nhietdo = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Humidity:");
  lcd.setCursor(15,0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.setCursor(10, 0);
  lcd.print(doam);
  lcd.setCursor(6, 1);
  lcd.print(nhietdo);
  lcd.setCursor(10,1);
  lcd.print(" C");
  delay(2000);
}
