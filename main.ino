#include <EncoderButton.h>
#include <ESP8266WiFi.h>

//Connection
const char* ssid     = "";  // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "";  // The password of the Wi-Fi network
const char* lampIP = "";    // IP of the light
const int lampPort = 55443;

//IO
const int ledPin = D4;
EncoderButton eb1(D7, D6, D5);

//Variables
int brightness=100; //default brightness
int temp=3000;      //default temp
bool mode=true;     //default mode true=brightness false=temp
char buffer[70];    //char to store the command

//Commands
const char* toggle="{\"id\":1,\"method\":\"toggle\",\"params\":[]}";
const char* brighttext= "{\"id\":1,\"method\":\"set_bright\",\"params\":[%d, \"sudden\", 10]}";
const char* temptext= "{\"id\":1,\"method\":\"set_ct_abx\",\"params\":[%d, \"sudden\", 10]}";


void sendLightCommand(const String& command) {
  WiFiClient client;
  if (!client.connect(lampIP, lampPort)) {
    delay(500);
    return;
  }
  if (client.connected()) {
    client.println(command);
  }
}

void onEb1Encoder(EncoderButton& eb) {
  if(mode){
    brightness = constrain(brightness+eb.increment()*10, 1, 100);
    sprintf(buffer, brighttext, brightness);}
  else{
    temp = constrain(temp+eb.increment()*100, 1700, 6500);
    sprintf(buffer, temptext, temp);}
  sendLightCommand(buffer);
}

void onEb1Click(EncoderButton& eb){
  sendLightCommand(toggle);
}

void onEb1LongPress(EncoderButton& eb){
  mode = !mode;
  digitalWrite(ledPin, mode);
}

void setup() {
  //Prep IO
  pinMode(ledPin, OUTPUT);
  eb1.setRateLimit(100);
  eb1.setEncoderHandler(onEb1Encoder);
  eb1.setClickHandler(onEb1Click);
  eb1.setLongPressHandler(onEb1LongPress);

  //Connect to wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {delay(1000);}
  digitalWrite(ledPin, HIGH);
}

void loop() {
  eb1.update();
}