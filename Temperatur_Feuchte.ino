#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DHTTYPE DHT11
#define DHT11PIN 8

DHT dht(DHT11PIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Initialisierung...");
  pinMode(13,OUTPUT);

  delay(2000);
}

void loop() {
  int chk = dht.read();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Serial.print("Humidity: ");
  // Serial.print(humidity);
  // Serial.println(" %\t");
  // Serial.print("Temperature: ");
  // Serial.print(temperature);
  // Serial.println(" *C");

  // delay(2000);

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print((float)temperature, 2);
  lcd.print(" C");

  lcd.setCursor(0,1);
  lcd.print("RelF: ");
  lcd.print((float)humidity, 2);
  lcd.print(" %");

  delay(2000);
  
}
