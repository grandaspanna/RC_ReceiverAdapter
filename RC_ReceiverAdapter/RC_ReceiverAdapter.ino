#include "Joystick.h"

volatile unsigned long start_steering;
volatile unsigned long start_throttle;

volatile int steering_value;
volatile int throttle_value;

#define STEERING_PIN digitalPinToInterrupt(2)
#define THROTTLE_PIN digitalPinToInterrupt(7)

void setup() {
  // put your setup code here, to run once:

  Joystick.begin();
  
  attachInterrupt(STEERING_PIN,&rising_steering,RISING);
  attachInterrupt(THROTTLE_PIN,&rising_throttle,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

  steering_value = constrain(steering_value,1000,2000);
  throttle_value = constrain(throttle_value,1000,2000);

  Joystick.setXAxis(map(steering_value,1000,2000,127,-127));
  Joystick.setYAxis(map(throttle_value,1000,2000,127,-127));

  delay(10);
}

void rising_steering(){
  start_steering = micros();
  attachInterrupt(STEERING_PIN,&falling_steering,FALLING);
  //st_triggered = true;
}

void falling_steering(){
  steering_value = micros() - start_steering;
  attachInterrupt(STEERING_PIN,&rising_steering,RISING);
}

void rising_throttle(){
  start_throttle = micros();
  attachInterrupt(THROTTLE_PIN,&falling_throttle,FALLING);
}

void falling_throttle(){
  throttle_value = micros() - start_throttle;
  attachInterrupt(THROTTLE_PIN,&rising_throttle,RISING);
}

