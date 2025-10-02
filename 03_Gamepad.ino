# Ngo Mau Truong Phi 25161176
#include <ESP32Servo.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
Servo myservo1;
Servo myservo2;
int goc1=0;
int goc2=90;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("1234");       //set bluetooth name of your device
  myservo1.attach(13);
  myservo2.attach(5);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.print("Up");
    quay1();
  }

  if (GamePad.isDownPressed())
  {
    Serial.print("Down");
    quay2();
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
  }

  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");
  }

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}
void quay1(){
{
  if(goc1<=90&&goc2>=0) {     
    goc1+=1;
    goc2-=1;                  
        myservo1.write(goc1);
        myservo2.write(goc2);
      delay(15);}
}
}
void quay2(){
{
  if(goc1>=0&&goc2<=90) {     
    goc1-=1;
    goc2+=1;                     
        myservo1.write(goc1);
        myservo2.write(goc2);
      delay(15);}
}
}
