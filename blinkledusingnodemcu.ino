#define BLYNK_TEMPLATE_ID "TMPL3pjRiE8N2"
#define BLYNK_TEMPLATE_NAME "LED CONTROL"
#define BLYNK_AUTH_TOKEN "c2hW6f3eaBGrFSuhU79-I_zj_-r9Gc19"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "";  // Enter your Wifi Username
char pass[] = "";  // Enter your Wifi password

int ledpin = D2;
void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  Blynk.run(); 
}
