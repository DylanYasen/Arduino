
const int rPin = A0;
const int gPin = A1;
const int bPin = A2;

const int rOut = 9;
const int gOut = 10;
const int bOut = 11;

int rIn = 0;
int gIn = 0;
int bIn = 0;

int r = 0;
int g = 0;
int b = 0;

int output = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rIn= analogRead(rPin);
  r = map(rIn, 0, 1023, 0 ,255);

  gIn = analogRead(gPin);
  g = map(gIn,0,1023,0,255);

  bIn = analogRead(bPin);
  b = map(bIn,0,1023,0,255);
    
  //output = map(input, 0, 1023, 0, 255);

  Serial.print("r: ");
  Serial.println(r);
  Serial.print("g: ");
  Serial.println(g);  
  Serial.print("b: ");
  Serial.println(b);
  
  analogWrite(rOut,r);
  analogWrite(gOut,g);
  analogWrite(bOut,b);

}
