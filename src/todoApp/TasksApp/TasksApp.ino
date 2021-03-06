#include <FirebaseCloudMessaging.h>
#include <Firebase.h>
#include <FirebaseHttpClient.h>
#include <FirebaseArduino.h>
#include <FirebaseError.h>
#include <FirebaseObject.h>
#include <ESP8266WiFi.h>
// writing display code. 
// will do firebase integration

//#include <WiFiClientSecure.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(D0,D1,D5, D4, D3, D2);


const char* WIFI_SSID = "mycci9E";
const char* WIFI_PASSWORD = "clevergadfly385";
const char* FIREBASE_HOST = "reacttasks-116cc.firebaseio.com";
const char* FIREBASE_AUTH = "dMBkRtDxQzajUlZ2DyTo4E7029ZkLds04zltLkT0";
int i = 1000; // hard coded itterator value for deugging 
String tempNote ;
String tempPriority ; 
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(i ; i>1; i--){ // trying to itterate through firebase list of things to do. 
    tempNote = Firebase.getString("notes/-LaHQk1LTCAGmCZHCsSR/noteContent");
    tempPriority = Firebase.getString("notes/-LaHQk1LTCAGmCZHCsSR/priority");
  disp(tempNote,tempPriority );
    delay(100000); 
  }
}

void disp(String dispString, String priority){
  lcd.print(dispString); 
  lcd.setCursor(0,1);
  lcd.print(priority); 
  }
