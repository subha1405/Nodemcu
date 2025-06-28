
#include <ESP8266WiFi.h>
const char* ssid="motog85";
const char* pass="Motog855g";

WiFiServer server(80); 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(ssid,pass);
Serial.print("Connecting to");
Serial.print(ssid);
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.print(".");
  delay(1000);
}
Serial.println();
Serial.println("Connected Successfully");
server.begin();
Serial.print("IP ADDRESS of the ESP is ");
Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
 WiFiClient client = server.available();
if(!client)
{
  return;
}
Serial.println("NEw Client");
while(!client.available())
{

}
String req=client.readString();
Serial.println(req);
String resp="HTTP/1.1 200 OK\r\n Content-Type: text/plain\r\n\r\n<!DOCTYPE HTML><HTML><BODY>Hi from ESP</BODY></HTML>";
client.print(resp);
delay(100);
client.stop();
}
