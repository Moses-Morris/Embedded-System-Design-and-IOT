int LED1 = D3;
int LED2 = D4;
int LED3 = D5;
void setup() 
{
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    pinMode(LED3,OUTPUT);
}
void loop()
(
    digitalWrite(LED1,HIGH) ;
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    delay(1000);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    delay(1000);
}