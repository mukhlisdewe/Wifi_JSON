#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <parse_merge.h>
#define DEBUG false //untuk mengaktifkan serial print

ESP8266WebServer server(80);  //Define server object
const char* ssid = "realme 3"; //Setting SSID sik Slur
const char* password  = "qwerty321"; //Setting Password e Slur


void handleRoot() {
  String webPage;
  
 
  StaticJsonBuffer <500> jsonBuffer;
 
  // Create the root object
  JsonObject& root = jsonBuffer.createObject();

 
  // root["battery"] = random(20,100); //Tinggal ganti DATA_STR()  
  // root["current"] = random(0,5); 
  root["Check Point"] = DATA_STR(0);
  root["X Position"]  = DATA_STR(1);
  root["Y Position"]  = DATA_STR(2);
 
  root.printTo(webPage);  
  server.send(200, "text/html", webPage);
}
   
// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    debug_msg(".");
  }

  debug_msg("");
  debug_msg("WiFi connected");
  debug_msg(WiFi.localIP().toString()); 
  server.on("/", handleRoot);      //Associate handler function to web requests
    
  server.begin(); //Start web server
  debug_msg("HTTP server started OK");
}

void debug_msg(String str){
  if (DEBUG)
    Serial.println(str); 
}

void loop() {
  //Handle Clinet requests
  if(Serial.available() > 0){
		data = Serial.readString();
		parse_string();
		// debug_msg(DATA_STR(0));
		// Serial.println("Total Data [" + String(get_data_total()) + "] --> [0] " + DATA_STR(0) + "; [1] " + DATA_STR(1));
		clear_str();
  }
  server.handleClient();
}