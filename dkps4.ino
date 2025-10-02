#include <PS4Controller.h>

#define motorFreq  1000      //pwm frequency
#define motorResolution   8         //pwm resolution 0- (2^8)
#define pin2   23
#define pwmmotor2   16 //pwm
#define motor2 2
#define pin1   17
#define pwmmotor1   15 //pwm
#define motor1 3
bool a = true;
int x,y;
void setup() {
  Serial.begin(115200);
  //PS4.begin("1c:4d:70:e5:05:91");
  PS4.begin("e8:61:7e:0d:66:40");
  //PS4.begin("ac:89:95;64:27:66");
  Serial.println("Ready.");
  pinMode(pin2,OUTPUT);
  ledcSetup(motor2, motorFreq, motorResolution);
  ledcAttachPin(pwmmotor2, motor2);
  digitalWrite(pin2,0);
  ledcWrite(motor2,0);

  pinMode(pin1,OUTPUT);
  ledcSetup(motor1, motorFreq, motorResolution);
  ledcAttachPin(pwmmotor1, motor1);
  digitalWrite(pin1,0);
  ledcWrite(motor1,0);
}

void loop() {
  // Below has all accessible outputs from the controller
  if (PS4.isConnected()) {
    if (PS4.R1()) a = true;
    if (PS4.L1()) a = false;
    if (a){
    dk1();
  }
  else {
    dk2();
  }

    Serial.printf("Battery Level : %d\n", PS4.Battery());

    Serial.println();
  }

}
void dk1(){
    //if (PS4.Right()) quayphai1();
    //else if (PS4.Down())lui1();
    //else if (PS4.Up()) dithang1();
    //else if (PS4.Left()) quaytrai1();
if ((PS4.LStickX()) && (PS4.LStickY())){
int x=PS4.LStickX();
int y=PS4.LStickY();
Serial.print(x);
Serial.print(" , ");
Serial.print(y);
if ((y>95)&&(-95<x<95)){
  thang();
}
else if ((y<-95)&&(-95<x<95)){
  lui();
}
else if ((x>95)&&(-95<y<95)){
  phai();
}
else if ((x<-95)&&(-95<y<95)){
  trai();
}
  else{
  dung();
}
    Serial.print(" , ");
}
}
void dk2(){
if ((PS4.LStickX()) && (PS4.LStickY())){
int x=PS4.LStickX();
int y=PS4.LStickY();
Serial.print(x);
Serial.print(" , ");
Serial.print(y);
if ((y>95)&&(-95<x<95)){
  lui();
}
else if ((y<-95)&&(-95<x<95)){
  thang();
}
else if ((x>95)&&(-95<y<95)){
  phai();
}
else if ((x<-95)&&(-95<y<95)){
  trai();
}
  else{
  dung();
}
    Serial.print(" , ");
}
}
void thang(){
  digitalWrite(pin1,0);
  ledcWrite(motor1,255);
  digitalWrite(pin2,0);
  ledcWrite(motor2,255);
}
void lui()
{
  digitalWrite(pin1,1);
  ledcWrite(motor1,255);
  digitalWrite(pin2,1);
  ledcWrite(motor2,255);
}
  void phai()
  {
  digitalWrite(pin1,1);
  ledcWrite(motor1,255);
  digitalWrite(pin2,0);
  ledcWrite(motor2,255);
  }
  void trai()
  {
  digitalWrite(pin1,0);
  ledcWrite(motor1,255);
  digitalWrite(pin2,1);
  ledcWrite(motor2,255);
  }
  void dung(){
  digitalWrite(pin1,0);
  ledcWrite(motor1,0);
  digitalWrite(pin2,0);
  ledcWrite(motor2,0);
    }
