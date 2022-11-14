const int buttonpin1 = D0; //
const int buttonpin2 = D1;
const int buttonpin3 = D2;
const int ledpin1 = D3;
const int ledpin2 = D4;
const int ledpin3 = D5;


//button status
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


    buttonstate2 = digitalRead(buttonpin2);
    if (buttonstate2 == HIGH)
    {
    digitalWrite(ledpin2, HIGH);
    }
    else
    {
    digitalWrite(ledpin2, LOW);
    }


buttonstate3 = digitalRead(buttonpin3);
if (buttonstate3 == HIGH)
{
digitalWrite(ledpin3, HIGH);
}
else
{
digitalWrite(ledpin3, LOW);
}



}