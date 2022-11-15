#define BLYNK PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

#define DHTPIN D1 //connect pin to DHT11
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
// You should get Auth Token in the Blynk App.
char auth[] = "";
char ssid[] = "";//wifi
char pass[] = ""; //wifi


void setup()
{
    // Debug console
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
    dht.begin();

}


void dht11()
{
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if(isnan(t) || isnan(h)) //if it is not a number
    {
        Serial.println("failed Ito read dht");
    }
    else
    {
        Serial.print("temp-");
        Serial.print(t);
        Serial.print("*c");
        Serial.print("Humidity-");
        Serial.print(h);
        Serial.println(" %");
        Blynk.virtualWrite(V0,t); //make the virtual ports
        Blynk.virtualWrite(V1,h);
        delay(500);
    }
}
void loop()
{
    dht11();
    Blynk.run();
}

