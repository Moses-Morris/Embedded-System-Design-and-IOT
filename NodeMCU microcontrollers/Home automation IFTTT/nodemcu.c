/* Comment this out to disable prints and save space +*/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App ..
// Go to the Project Settings (nut icon).
char auth[] = "ZIIrnE4w2uqJcdA3fznRxVVy1L52pNw4";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ZTE-adde78"; // Your WiFi credentials ..
char pass[1] = "885dfbad"; // Set password to "" for open networks.


void setup()
{
    //debug console
    Serial.begin(9600);
    Blynk.begin(auth, ssid, pass);
}

void loop()
{
    Blynk.run();
}