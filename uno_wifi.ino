//BetterWeather-BetterHealth Project 
//Computer Programing 2018,IT KMITL
/*Json*/
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(3, 2); //RX, TX
/*include LCD 20x4 libary*/
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int show;

/*DHT11 Sensor*/
#include "dht.h" // include libary of DHT11
#define DHTTYPE DHT11 // using DHT 11 
#define dhtPin 8 // Digital Pin sensor is connected to
dht DHT; // Creats a DHT object

/*Dust sensor*/
int measurePin = A0; // Analog Pin sensor is connected to
int ledPower = 6; // Digital Pin sensor is connected to

float rawSignal = 0;
float voltage = 0;
float dustDensity = 0;

String quality;

void setup() {
  // put your setup code here, to run once:
  s.begin(9600);
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
  Serial.println("==== BWBH project ====\n\n");
  // lcd
  lcd.setBacklight(255);
  lcd.begin(20, 4);
  lcd.setCursor(0, 1);
  lcd.print("++ Weather & Dust ++");
  delay(1000);

}

StaticJsonBuffer<256> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();
void loop() {
  // put your main code here, to run repeatedly:
  /*DHT code*/
  lcd.clear();
  if (show == 0) {
    DHT.read11(dhtPin);

    Serial.print("humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature);
    Serial.println("C  ");

    lcd.setCursor(0, 0);
    lcd.print("Humidity = ");
    lcd.print(DHT.humidity);
    lcd.print("%  ");
    lcd.setCursor(0, 2);
    lcd.print("Temperature = ");
    lcd.print(DHT.temperature);
    lcd.print("C  ");

  }
  /*Dust Code*/
  else if (show == 1) {
    digitalWrite(ledPower, LOW); // power on the LED
    delayMicroseconds(280); //samplingTime from datadheet

    rawSignal = analogRead(measurePin); // read the dust value

    delayMicroseconds(40);
    digitalWrite(ledPower, HIGH); // turn the LED off
    delayMicroseconds(9680); // sleeptime

    voltage = rawSignal * (3.3 / 1024); // convert to voltage

    // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/

    dustDensity = (0.17 * voltage - 0.1) * 1000; // *1000 convert  ug/m3

    Serial.print("Raw (0-1023): ");
    Serial.print(rawSignal);

    Serial.print(" Voltage: ");
    Serial.print(voltage);

    Serial.print(" Dust Density [ug/m3]: "); //microgram per m3
    Serial.println(dustDensity);
    /* Air Quality Chart - Small Count Reading (0.5 micron)+
      300-1050   = POOR
      150-300    = GOOD
      75-150     = VERY GOOD
      0-75       = EXCELLENT*/

    lcd.setCursor(0, 0);
    lcd.print("Dust = ");
    if (dustDensity < 0){
      dustDensity = 0;
      }
    lcd.print(dustDensity);
    lcd.print("[ug/m3]");
    lcd.setCursor(0, 2);
    lcd.print("Quality = ");

    if (dustDensity <= 75) {
      quality = "EXCELLENT *O*";
      lcd.print("EXCELLENT");
      lcd.setCursor(8,3);
      lcd.print("*O*");
      
    }
    else if (dustDensity <= 150) {
      quality = "VERY GOOD ^O^";
      lcd.print("VERY GOOD");
      lcd.setCursor(8,3);
      lcd.print("^O^");
    }
    else if (dustDensity <= 300) {
      quality = "GOOD ^ ^";
      lcd.print("GOOD");
      lcd.setCursor(8,3);
      lcd.print("^ ^");
    }
    else if (dustDensity <= 1050) {
      quality = "POOR - -*";
      lcd.print("POOR");
      lcd.setCursor(8,3);
      lcd.print("- -*");
    }
    
  }
  /*Json*/
  root["temp"] = DHT.temperature;
  root["hum"] = DHT.humidity;
  root["dust"] = dustDensity;
  root["qua"] = quality;

  if (show == 1) {
    root.printTo(s);
  }

  show = (show + 1) % 2; // to select case to show on lcd
  delay(5000);

}
