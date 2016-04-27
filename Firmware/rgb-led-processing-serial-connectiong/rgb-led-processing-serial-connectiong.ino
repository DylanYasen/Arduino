const int rPin = A0;
const int gPin = A1;
const int bPin = A2;

int rIn = 0;
int gIn = 0;
int bIn = 0;

int r = 0;
int g = 0;
int b = 0;

int incoming = 0;

void setup() {

  Serial.begin(9600);

  while (!Serial){  
  }

  establishContact();
}

void loop() {

  
  rIn= analogRead(rPin);
  r = map(rIn, 0, 1023, 0 ,255);

  gIn = analogRead(gPin);
  g = map(gIn,0,1023,0,255);

  bIn = analogRead(bPin);
  b = map(bIn,0,1023,0,255);

  delay(500);

  // pass via serial
  if(Serial.available() > 0){
    incoming = Serial.read();
    Serial.write(r);
    Serial.write(g);
    Serial.write(b);
  }
}

void establishContact(){
  while(Serial.available() <= 0){
    Serial.print('X');
    delay(300);
  }
}

