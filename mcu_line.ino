//BetterWeather-BetterHealth Project 
//Computer Programing 2018,IT KMITL
/*JSON library*/
#include <SoftwareSerial.h>
SoftwareSerial s(D2, D3); //RX, TX
#include <ArduinoJson.h>

/*Line notification*/
void Line_Notify(String message) ;

#include <ESP8266WiFi.h>
#include <WiFiClientSecureAxTLS.h> // กรณีขึ้น Error ให้เอาบรรทัดนี้ออก

// Config connect WiFi
#define WIFI_SSID "net"
#define WIFI_PASSWORD "123456788"

// Line config
#define LINE_TOKEN "UVkU4cUHXPOvSpYF7y13GbEfd3d1mk6RQEqIt0Ledju" 

void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  s.begin(9600);
  while (!Serial) continue;
}

void loop() {
  delay(5000);
  StaticJsonBuffer<256> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);

  //Print the data in the serial monitor
  Serial.println("JSON received and parsed");
  Serial.println("");
  Serial.print("Temperature : ");
  float data1 = root["temp"];
  Serial.println(data1);
  Serial.print("Humidity    : ");
  float data2 = root["hum"];
  Serial.println(data2);
  Serial.print("Dust        : ");
  float data3 = root["dust"];
  Serial.println(data3);
  Serial.print("Quality     : ");
  String data4 = root["qua"];
  Serial.println(data4);
  Serial.println("---------------------xxxxx--------------------");

  /*send*/
  Line_Notify("Temp = " + String(data1) + "C\n" + "Humi = " + String(data2) + " percent" + "\n" + "Dust = " + String(data3) + "[ug/m3]\n" + "Quaility = " + String(data4));
}

void Line_Notify(String message) {
  axTLS::WiFiClientSecure client; // กรณีขึ้น Error ให้ลบ axTLS:: ข้างหน้าทิ้ง

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  // Serial.println(req);
  client.print(req);

  delay(20);

  // Serial.println("-------------");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
    //Serial.println(line);
  }
  // Serial.println("-------------");
}
