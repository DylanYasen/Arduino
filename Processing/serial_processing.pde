import processing.serial.*;

Serial port;
int r, g, b;
int[] serialInput = new int[3];
int serialCount = 0;
int xpos, ypos, size;
boolean contact = false;

void setup(){
  size(400,400);
  noStroke();
  xpos = 200;
  ypos = 200;
  size = 100;
  String arduino = Serial.list()[1];
  println(arduino);
  port = new Serial(this, arduino, 9600);

}

void draw() { 
  background(255,255,255); 
  fill(r,g,b);
  ellipse(xpos, ypos, size, size);
}

void serialEvent(Serial port) {
  int incoming = port.read(); 
  if (contact == false) {
    if (incoming == 'X') { 
      port.clear(); 
      contact = true; 
      port.write('X');
    }
  } 
  else {
    serialInput[serialCount] = incoming;
    serialCount++;
    //println(serialCount);
    if (serialCount > 2) {
      r = serialInput[0];
      g = serialInput[1];
      b = serialInput[2];
     
      println("r " + r);
      println("g " + g);
      println("b " + b);
      
      port.write('X');
      serialCount = 0;
    }   
  }
}