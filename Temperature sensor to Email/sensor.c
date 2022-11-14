#define  SW_VERSION "Thinkspeak.com"
#include <ESP8266Wifi.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN D1 //port connection in DHT11

WiFiClient client;
WiFiServer server(80);

const char *MY_SSID = "wifiname" //the wifi name
const char *MY_PWD = "pwd" //the wifi password
const char *TS_SERVER = "api.thinkspeak.com" //The connection to thinkspeak api
String TS_API_KEY = "ApiKey" //The api keey provided for your project demo

void connectWifi()
{
    Wifi.begin(MY_SSID, MY_PWD);
    while(Wifi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print(".");
    }
    Serial.print("Wifi Connected");
    server.begin();
    Serial.print("Server Started");
    Serial.print("Use this url to connect");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.print("/");
}

void sendDataTS(void)
{
    int chk = DHT.read11(DHT11_PIN);
    Serial.print("Humidity:");
    Serial.print(DHT.Humidity);
    Serial.print("Temperature:");
    Serial.print("DHT.Temperature");
    delay(2000);
    if(client.connect(TS_SERVER, 80))
    {
        String postStr = TS_API_KEY;
        postStr+="&field1="
        postStr+=String(DHT.Humidity,1);
        postStr+="&field2="
        postStr+=String(DHT.temperature,1);
        postStr+="\r\n\r\n";

        client.print("POST /update ")
        


    }
}

void setup()
{

}
void loop()
{

}