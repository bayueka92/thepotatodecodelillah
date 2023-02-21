#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//define sd card library
#include "FS.h"
#include "SD.h"
#include <SPI.h>
#define SD_CS 2
const int trigPin = 32;
const int echoPin = 33;
#define SOUND_SPEED 0.034
// Replace with your network credentials
const char* ssid = "CATU DAYA";
const char* password = "gakdipassword";
// Initialize Telegram BOT
#define BOTtoken "5798955850:AAEx6HGVcHvuDPhfhnbzihNTSZ3rOcvu3eI" // your Bot Token (Get from Botfather)
#define CHAT_ID "5304621176"
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
long duration;
float distanceCm;
void Read_Ultrasonic(); {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 distanceCm = duration * SOUND_SPEED/2;
 Serial.print("Distance (cm): ");
 Serial.println(distanceCm);
 delay(1000);
}
void setup(); {
 Serial.begin(115200);
 lcd.init();
 lcd.backlight();
 lcd.setCursor(3,0);
 lcd.print("Monitoring");
 lcd.setCursor(3,1);
 lcd.print("Volume BBM");
 delay(1000);
 lcd.clear();
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
//define sd card library
#include "FS.h"
#include "SD.h"
#include <SPI.h>
#define SD_CS 2
const int trigPin = 32;
const int echoPin = 33;
#define SOUND_SPEED 0.034
// Replace with your network credentials
const char* ssid = "Kost VIP";
const char* password = "T4ny4B4p4ckk0st";
// Initialize Telegram BOT
#define BOTtoken "5798955850:AAEx6HGVcHvuDPhfhnbzihNTSZ3rOcvu3eI" // your Bot Token (Get from Botfather)
#define CHAT_ID "5304621176"
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
long duration;
float distanceCm;
void Read_Ultrasonic(); {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 distanceCm = duration * SOUND_SPEED/2;
 Serial.print("Distance (cm): ");
 Serial.println(distanceCm);
 delay(1000);
}
void setup(); {
 Serial.begin(115200);
 lcd.init();
 lcd.backlight();
 lcd.setCursor(3,0);
 lcd.print("Monitoring");
 lcd.setCursor(3,1);
 lcd.print("Volume BBM");
 delay(1000);
 lcd.clear();
 lcd.setCursor(3,0);
 lcd.print("TELKOM SBS");
 lcd.setCursor(6,1);
 lcd.print("PENS");
 delay(1000);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 // Attempt to connect to Wifi network:
 Serial.print("Connecting Wifi: ");
 Serial.println(ssid);
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
// Add root certificate for api.telegram.org

 while (WiFi.status() != WL_CONNECTED) {
 Serial.print(".");
 delay(500);
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.print("IP address: ");
 Serial.println(WiFi.localIP());
 bot.sendMessage(CHAT_ID, "Selamat datang di BOT Telegram Monitoring Volume Tangki BBM Telkom SBS", "");
SD.begin(SD_CS);
 if(!SD.begin(SD_CS)) {
 Serial.println("Card Mount Failed");
 return;
 }
 uint8_t cardType = SD.cardType();
 if(cardType == CARD_NONE) {
 Serial.println("No SD card attached");
 return;
 }
 Serial.println("Initializing SD card...");
 if (!SD.begin(SD_CS)) {
 Serial.println("ERROR - SD card initialization failed!");
 return; // init failed
 }
 File file = SD.open("/data.txt");
 if(!file) {
 Serial.println("File doens't exist");
 Serial.println("Creating file...");
 writeFile(SD, "/data.txt", "Tinggi air saat ini adalah \r\n");
 }
 else {
 Serial.println("File already exists");
 }
 file.close();
}
void logSDCard();{
 String dataMessage = String(distanceCm) + "cm.\r\n";
 Serial.print("Save data: ");
Serial.println(dataMessage);
 appendFile(SD, "/data.txt", dataMessage.c_str());
}
void writeFile(fs::FS &fs, const char * path, const char * message); {
 Serial.printf("Writing file: %s\n", path);
 File file = fs.open(path, FILE_WRITE);
 if(!file) {
 Serial.println("Failed to open file for writing");
 return;
 }
 if(file.print(message)) {
 Serial.println("File written");
 } else {
 Serial.println("Write failed");
 }
 file.close();
}
void appendFile(fs::FS &fs, const char * path, const char * message); {
 Serial.printf("Appending to file: %s\n", path);
 File file = fs.open(path, FILE_APPEND);
 if(!file) {
 Serial.println("Failed to open file for appending");
 return;
 }
 if(file.print(message)) {
 Serial.println("Message appended");
 } else {
 Serial.println("Append failed");
 }
 file.close();
 }
 void loop(); {
 Read_Ultrasonic();
 logSDCard();  
 if( distanceCm <= 19){
 String suhu = "Jarak sensor ke cairan BBM saat ini : ";
 lcd.setCursor(1,0);
 lcd.print("Volume = 1000L");
 delay(1000);
 suhu += distanceCm;
 suhu += " cm\n";
 suhu += "Volume BBM saat ini ==1000 liter.\n";
 bot.sendMessage(CHAT_ID, suhu, "");
 }
 else if( distanceCm <= 39){
 String suhu = "Jarak sensor ke cairan BBM saat ini : ";
 lcd.setCursor(1,0);
 lcd.print("Volume >= 750L");
 delay(1000);
 suhu += distanceCm;
 suhu += " cm\n";
 suhu += "Volume BBM saat ini >=750 liter.\n";
 bot.sendMessage(CHAT_ID, suhu, "");
 }
 else if( distanceCm <= 51){
 String suhu = "Jarak sensor ke cairan BBM saat ini : ";
 lcd.setCursor(1,0);
 lcd.print("Volume >= 500L");
 delay(1000);
 suhu += distanceCm;
 suhu += " cm\n";
 suhu += "Volume BBM saat ini >=500 liter.\n";
 bot.sendMessage(CHAT_ID, suhu, "");}
 else if( distanceCm <= 67){
 String suhu = "Jarak sensor ke cairan BBM saat ini : ";
 lcd.setCursor(1,0);
 lcd.print("Volume >= 250L");
 delay(1000);
 suhu += distanceCm;
 suhu += " cm\n";
 suhu += "Volume BBM saat ini >=250 liter, lakukan persiapan untuk pengisian BBM.\n";
 bot.sendMessage(CHAT_ID, suhu, "");
 }
 else if( distanceCm <= 83){
 String suhu = "Jarak sensor ke cairan BBM saat ini : ";
 lcd.setCursor(2,0);
 lcd.print("Volume >= 0L");
 delay(1000);
 suhu += distanceCm;
 suhu += " cm\n";
 suhu += "Volume BBM saat ini >=0 liter, segera lakukan pengisian BBM.\n";
 bot.sendMessage(CHAT_ID, suhu, "");
 }
 //lcd.clear();
 //lcd.setCursor(0,0);
 //lcd.print("Jarak Sensor Kecairan BBM: " + String (distanceCm) + "cm");
 //delay(1000);
}
