/* Comment this out to disable prints and save space */
#define BLYNK PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon) .
char auth[] = "qwertyu"; //token from blynk app

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ZTE-adde78"; //wifi name
char pass[] = "885dfbad"; //wifi password
void setup()
{
    // Debug console
    Serial.begin(9600); //baud rate
    Blynk.begin(auth, ssid, pass);
}