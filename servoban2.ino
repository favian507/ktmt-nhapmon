#Bui Van Quoc Khanh 25161143
#include<ESP32Servo.h>
int pos = 0;
//servo nâng cần bắn
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;


void setup() {
  Serial.begin(115200);

  Serial.println("Ready.");
  //servo nâng cần gắp
  myservo1.attach(5);
  // servo quay cần gắp


}

void loop() {
myservo1.write(0);

}

//code nâng servo cần bắn
  void nanglen1 (){
  {
     {                           
        myservo1.write(65);
        }
    for(pos = 15; pos<80; pos+=1) {                           
        myservo2.write(pos);
        delay(15);}
  }
}

