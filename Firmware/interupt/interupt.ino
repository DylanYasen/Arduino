const int buttonPin = 2;
const int ledPin = 3;

volatile int state = 0;

void setup() {

  //Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
 
  attachInterrupt(digitalPinToInterrupt(buttonPin),blink, FALLING);
}

void loop() {
  digitalWrite(ledPin,state);
}

void blink(){
  digitalWrite(ledPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(ledPin,LOW);
}

