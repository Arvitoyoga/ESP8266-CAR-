#include <ESP8266WiFi.h>

WiFiClient client;

WiFiServer server(80);
const char* ssid = "ESAGA";

const char* password = "";

String  data =""; 

void setup(){
  Serial.begin(115200); 

connectWiFi();

  server.begin();
  pinMode(LED_BUILTIN, OUTPUT);

  server.begin();

}
void loop()

{

  client = server.available();

  if (!client) return;

  data = checkClient ();

  if (data == "on"){ON();}

  else {OFF();}
} 

void ON(){
   digitalWrite(LED_BUILTIN, HIGH);  
}

void OFF (){
   digitalWrite(LED_BUILTIN, LOW);  
}

void connectWiFi()

{

  Serial.println("Connecting to WIFI");

  WiFi.begin(ssid, password);

  while ((!(WiFi.status() == WL_CONNECTED)))

  {

    delay(300);

   Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

  Serial.println("NodeMCU Local IP: ");

  Serial.print((WiFi.localIP()));

}

String checkClient (void)

{

while(!client.available()) delay(1); 

String request = client.readStringUntil('\r');

request.remove(0, 5);

request.remove(request.length()-9,9);

return request;

}
