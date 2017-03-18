// project: IoT Weather Station, EAFIT University, Systems Engineering, 20171
// Adaptation done by: Edwin Montoya Munera - emontoya@eafit.edu.co and David Velasquez - dvelas25@eafit.edu.co
// github: https://github.com/edwinmontoya/iotweatherstation.git

// Description: This program test the connection to the server "iotweatherstation" in order to obtain the Date (day+hour) in format: yyyy:mm:dd:hh:mm:ss
// the connection is done throught Wifi network and HTTP Connection. It uses GET Method.

// Libraries

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

// Wifi module from Chipset
ESP8266WiFiMulti WiFiMulti;

//Constants
const unsigned long SEND_Timer = 5000;  //Delay between SEND variables, 5000 milliseconds - 5 seconds
const char* SSIDR = "wifi-name"; //WiFi SSID, change wifi-name by your own
const char* PASSWORD = "wifi-password"; //WiFi Pass, change wifi-password by your own
const char* HOST = "http://iotserver1.dis.eafit.edu.co";  // Server on DIS-EAFIT

String appName = "/weather";
String serviceGetTime = "/getTime";
unsigned long lastConnectionTime = 0; //Last time you connected to the server, in milliseconds


String webGetTime() {
  // variables:
  HTTPClient http;
  String url;
  int httpCode;
  String payload;

  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    url = appName;
    url += serviceGetTime;
    http.begin(HOST + url);
    Serial.print(HOST + url);
    httpCode = http.GET();
    if (httpCode > 0) {
      if (httpCode == HTTP_CODE_OK) {
        payload = http.getString();
        Serial.println(payload);
      }
    }
    http.end();
    return payload;
  }
}

void setup() {

  Serial.begin(115200);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFiMulti.addAP(SSIDR, PASSWORD);

}

void loop() {

  if (millis() - lastConnectionTime > SEND_Timer) {
    String dh = webGetTime();
    Serial.println("day+hour="+dh);
    lastConnectionTime = millis();
  }
}
