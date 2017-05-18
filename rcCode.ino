// motor one
int enA = 10;
int in1 = 12;//pwm case
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;
//RC channel
int pinver = 3;
int pinrot = 11;
int pinspd;
int spd;
int ver;
int rot;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ver, INPUT);
  pinMode(rot, INPUT);
  
  Serial.begin(9600);
}

void loop(){
  ver = pulseIn(3, HIGH, 25000); // Read the pulse width of
  rot = pulseIn(9, HIGH, 25000); // Read the pulse width of 
  Serial.print("Channel 1: "); // Print the value of 
  Serial.println(rot);        // each channel
   // Serial.print("Channel 2: "); // Print the value of 
  //Serial.println(rot);        // each channel
  //forward function

if(rot<1200){
rotaionalLeftTurn();
}
else if(rot>1800){
  roationalRightTurn();
}
else if(ver<1200){
    verticalMotionBackwards();
}
else if(ver>1600) {
  verticalMotionFoward();
}
else{
motoroff();
}

delay(100);  
}


void motoroff(){
    // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void verticalMotionBackwards(){
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
}

void verticalMotionFoward(){
    // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);//speed adjustments

  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 255);  
}

void rotaionalLeftTurn(){
    // now change motor directions
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
  }
 void roationalRightTurn(){
    // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
  }