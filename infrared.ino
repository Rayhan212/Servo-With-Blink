#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "H8Jz0eeweykqfqbV9SWwNZhMF6IjqeY9";

char ssid[] = "PPO A5 2020";
char pass[] = "poiuytre";

WidgetLED led1(V1);

int sensor = 2 ;

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(sensor,INPUT);
  while(Blynk.connect() == false);
  Serial.println("tidak terdeteksi");
  
}

void loop()
{
  int sensorval = digitalRead(sensor);
  delay(1);

  if (sensorval == 1){
    led1.on();
  }

  if (sensorval == 0){
    led1.off();
  }
  
  Blynk.run();
}
