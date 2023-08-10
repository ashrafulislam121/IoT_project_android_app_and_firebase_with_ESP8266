// #define FIREBASE_HOST "proj-arduino2server-default-rtdb.firebaseio.com"              // the project name address from firebase id
// #define FIREBASE_AUTH "GvmqSSQEZEzCb0cmqjsF22Babx3E9uIu2ezGlz9g"       // the secret key generated from firebase                            

#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "Room539"
#define WIFI_PASSWORD "room@@539"

// Insert Firebase project API Key
#define API_KEY "AIzaSyDG3RIz7YbE-LrqJL0O04XunMlJC2iIX5M"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "proj-arduino2server-default-rtdb.firebaseio.com" 


// void removeEscapeChars(String &input);
//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

//some importent variables
String sValue, sValue2, sValue3;
bool signupOK = false;


///##### Display in dot Matrix block start###################################################################
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#define MAX_DEVICES 4
#define CLK_PIN   D5 // or SCK
#define DATA_PIN  D7 // or MOSI
#define CS_PIN    D8 // or SS
// SPI hardware interface
//MD_MAX72XX mx = MD_MAX72XX(CS_PIN, MAX_DEVICES);
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW  //edit this as per your LED matrix hardware type
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
///##### Display in dot Matrix block end###################################################################

///##### Ultrasonic and buzzer block start###################################################################
// defines pins numbers
const int trigPin = D4;  //D4
const int echoPin = D3;  //D3
const int buzz = D2;  //2
// defines variables
long duration;
int distance;
///##### Ultrasonic and buzzer block end###################################################################



void setup() {
  Serial.begin(115200);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  ///##### Display in dot Matrix block start###################################################################
  P.begin();
  P.setIntensity(5);
  P.displayClear();
  Serial.begin(9600);
  // P.displayScroll("Dept. of EEE", PA_CENTER, PA_SCROLL_LEFT, 100);
  P.print("EEE 18");
  ///##### Display in dot Matrix block end###################################################################

  ///##### Ultrasonic and buzzer block start###################################################################
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzz, OUTPUT); // Sets the buzzer in D2 as an Output
  ///##### Ultrasonic and buzzer block end###################################################################
}


void loop() {
  if (Firebase.ready() && signupOK ) {
    if (Firebase.RTDB.getString(&fbdo, "/L1")) {
      if (fbdo.dataType() == "string") {
        sValue = fbdo.stringData();
        int a = sValue.toInt();
        Serial.println(a);
        if (a == 1){
          digitalWrite(D0,HIGH);
        }else{
          digitalWrite(D0,LOW);
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }

    if (Firebase.RTDB.getString(&fbdo, "/status/enter")) {
      if (fbdo.dataType() == "string") {
        sValue = fbdo.stringData();
        int enter = sValue.toInt();
        Serial.println(enter);
        if (enter == 1){
          P.print(" Enter");
          delay(100);
          P.displayReset();
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }

    if (Firebase.RTDB.getString(&fbdo, "/status/wait")) {
      if (fbdo.dataType() == "string") {
        sValue = fbdo.stringData();
        int wait = sValue.toInt();
        Serial.println(wait);
        if (wait == 1){
          P.print("   Wait");
          delay(100);
          P.displayReset();
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }

    if (Firebase.RTDB.getString(&fbdo, "/status/close")) {
      if (fbdo.dataType() == "string") {
        sValue = fbdo.stringData();
        int close = sValue.toInt();
        Serial.println(close);
        if (close == 1){
          P.print(" Close");
          delay(100);
          P.displayReset();
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }

  }

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

  ///##### Ultrasonic and buzzer block start###################################################################
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    if(distance <= 30.0 && distance >= 1.0){
      digitalWrite(buzz, HIGH);
    }
    else{
      digitalWrite(buzz, LOW);
    }
    // delay(1000);
  ///##### Ultrasonic and buzzer block end###################################################################



}