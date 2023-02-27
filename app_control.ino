#include <ESP8266WiFi.h> 

int in1 = 15;
int in2 = 13;
int in3 = 12;
int in4 = 14;

WiFiClient client;
String  data =""; 
WiFiServer server(80);
unsigned long previousMillis = 0;
String sta_ssid = "";
String sta_password = "";
const char* ap_ssid = "WIFI CAR";

void setup(){
  Serial.begin(115200);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  WiFi.mode(WIFI_STA);
  WiFi.begin(sta_ssid,sta_password);
  Serial.println("");
  Serial.print("Connecting to: ");
  Serial.println(sta_ssid);
  Serial.print("Password: ");
  Serial.println(sta_password);

  unsigned long currentMillis = millis();
  previousMillis = currentMillis;
  while (WiFi.status() != WL_CONNECTED && currentMillis - previousMillis <= 10000) {
    delay(500);
    Serial.print(".");
    currentMillis = millis();
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("*WiFi-STA-Mode*");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
 
  } else {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ap_ssid+WiFi.softAPIP());
    IPAddress myIP = WiFi.softAPIP();
    Serial.println("");
    Serial.println("WiFi failed connected to " + sta_ssid);
    Serial.println("");
    Serial.println("*WiFi-AP-Mode*");
    Serial.print("AP IP address: ");
    Serial.println(myIP);
  }
  server.begin();                          
}

void loop() {
   client = server.available();
   if (!client) return;
   data = checkClient ();

  if (data == "maju"){Maju();}
  else if (data == "mundur"){Mundur();}
  else if (data == "kanan"){Kanan();}
  else if (data == "kiri"){Kiri();}
  else {Stop();}
}

void Maju(){ 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Mundur(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void Kanan(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void Kiri(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void Stop(){ 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

String checkClient (void) {
while(!client.available()) delay(1); 
String request = client.readStringUntil('\r');
request.remove(0, 5);
request.remove(request.length()-9,9);
return request;
}
