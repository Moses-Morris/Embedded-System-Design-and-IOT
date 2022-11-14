const int buttonpin1 = DO;
const int buttonpin2 = D1;
const int buttonpin3 = D2;
const int ledpin1 = D3;
const int ledpin2 = D4;
const int ledpin3 = D5;

int buttonstate1=0;
int buttonstate2=0;
int buttonstate3=0;
void setup() {
    // put your setup code here, to run once:
    pinMode(ledpin1, OUTPUT);
    pinMode(ledpin2, OUTPUT);
    pinMode(ledpin3, OUTPUT);
    pinMode(buttonpin1, INPUT);
    pinMode(buttonpin2, INPUT);
    pinMode(buttonpin3, INPUT);
}
void loop() 
{
    // put your main code here, to run repeatedly:
    buttonstate1 = digitalRead(buttonpin1);
    if (buttonstate1 == HIGH)
    {
    digitalWrite(ledpin1, HIGH);
    }
    else
    {
    digitalWrite(ledpin1, LOW);
    }


}