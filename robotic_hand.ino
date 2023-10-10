
/*
  Rotation Servo Sample.
  Sample of controle FS90R(FEETECH RC Model Co.,Ltd.)
*/

#define bottom 0 // 85-500
#define platform 1 //85-500
#define shoulder 2 //85-500
#define elbow 3
#define palm 4

void set_angle(int pin, int angle);

// range 85-500
#include "FaBoPWM_PCA9685.h"

FaBoPWM faboPWM;
int pos = 0;
int STOP = 0;
int FORWARD = 400;
int BACK = 250;

void setup() {
  Serial.begin(115200);
  if(faboPWM.begin()) {
    Serial.println("Find PCA9685");
    faboPWM.init(STOP);
  }
  faboPWM.set_hz(50);


  faboPWM.set_channel_value(shoulder, STOP); 
  faboPWM.set_channel_value(bottom, STOP); 
  faboPWM.set_channel_value(platform, STOP);
  faboPWM.set_channel_value(elbow, STOP);
  delay(500);
}

void loop() {
  set_angle(palm, 180);
  
}

void set_angle(int pin, int angle) {
  angle = map(angle, 0, 180, 85, 500);
  faboPWM.set_channel_value(pin, angle); 
}

