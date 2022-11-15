/* Comment this out to disable prints and save space */
#define BLYNK PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon) .
char auth[] = "hVFJVeeBQIAmjfjob-G20YhQWt.JUYyEM";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ZTE-adde78";
char pass[] = "885dfbad";
void setup()
{
    // Debug console
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
}