#define  SW_VERSION "Thinkspeak.com"
#include <ESP8266WiFi.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN D1 //port connection in DHT11

WiFiClient client;
WiFiServer server(80);

//Configure custom configuration
const char *MY_SSID = "wifiname" //the wifi name
const char *MY_PWD = "pwd" //the wifi password
const char *TS_SERVER = "api.thinkspeak.com" //The connection to thinkspeak api
String TS_API_KEY = "ApiKey" //The api keey provided for your project demo

void connectWifi()
{
    WiFi.begin(MY_SSID, MY_PWD);
    while(WiFi.status() != WL_CONNECTED)
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
        postStr+="&field1=";
        postStr+=String(DHT.Humidity,1);
        postStr+="&field2=";
        postStr+=String(DHT.temperature,1);
        postStr+="\r\n\r\n";

        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thinksspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINKSPEAKAPIKEY: "+TS_API_KEY+"\n");
        client.print(postStr.length());
        client.print(postStr);
        delay(100);
    }
    client.stop();
}

void setup()
{
    //The setup code that will run once
    Serial.begin(9600);
    delay(10);
    connectWifi();
}
void loop()
{
    //The code executes repeatedly
    sendDataTS();
    delay(10000);
}
