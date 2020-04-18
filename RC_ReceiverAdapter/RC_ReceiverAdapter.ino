// This little program allows an Arduino Micro or compatible board to convert the steering/throttle outputs
// from an RC receiver and turn them into synthesized joystick inputs for a USB-enabled computer.
// Phillip Merrick 2020/04

// Library routines for emulating a USB joystick
// Thanks and ref to: https://github.com/MHeironimus/ArduinoJoystickLibrary
#include "Joystick.h"

// Which pins on the micro are connected to the receiver
#define STEERING_PIN 2
#define THROTTLE_PIN 3

// This maps the pin numbers to their corresponding interrupt identifier
#define STEERING_INTERRUPT_PIN digitalPinToInterrupt(2)
#define THROTTLE_INTERRUPT_PIN digitalPinToInterrupt(3)

// These four values are updated by interrupts to capture the current steering and throttle values
volatile unsigned long start_steering;
volatile unsigned long start_throttle;
volatile int steering_value;
volatile int throttle_value;

// To make the code a little more portable, we use these to hold the register masks
// that are used for a fast read off the port
uint8_t steering_pin_mask, throttle_pin_mask;

void setup() {
  // Setup things

  // Mark the two pins as ready for input
  pinMode(STEERING_PIN,INPUT);
  pinMode(THROTTLE_PIN,INPUT);

  // Determine the bit masks for reading from the I/O port
  steering_pin_mask = digitalPinToBitMask(STEERING_PIN);
  throttle_pin_mask = digitalPinToBitMask(THROTTLE_PIN);

  // Initialise the joystick object
  Joystick.begin();

  // Attach an interrupt to each pin where the receiver is connected.
  attachInterrupt(STEERING_INTERRUPT_PIN,&changing_steering,CHANGE);
  attachInterrupt(THROTTLE_INTERRUPT_PIN,&changing_throttle,CHANGE);
}

void loop() {
  // All we do here is loop and write the current x,y values to the joystick interface
  // The steering and throttle values are updated in the background automatically by the interrupt routines

  // For safety, just make sure the values are in a reasonable range
  steering_value = constrain(steering_value,1000,2000);
  throttle_value = constrain(throttle_value,1000,2000);

  // Write the values, scaled to -127 to 127
  Joystick.setXAxis(map(steering_value,1000,2000,127,-127));
  Joystick.setYAxis(map(throttle_value,1000,2000,127,-127));

  // Arbitrary delay, in milliseconds
  delay(8);
}

void changing_steering(){
  // This routine gets called every time there's a change of state on the steering pin.
  // We inspect the value of the pin to see if we're in the on phase or off phase of the pulse

  // This does a direct read off the port register. Very fast.
  uint8_t pin_value = PIND & steering_pin_mask;

    // If it has a non-zero value, then we've started a pulse
  if(pin_value > 0){
    start_steering = micros();
  }
  else{
    // We've transitioned to off, so report how long it was on for
    steering_value = micros() - start_steering;
  }
    
}

void changing_throttle(){
  
  // This routine gets called every time there's a change of state on the throttle pin.
  // We inspect the value of the pin to see if we're in the on phase or off phase of the pulse

  // This does a direct read off the port register. Very fast. As fast as the one above!
  uint8_t pin_value = PIND & throttle_pin_mask;

  // If it has a non-zero value, then we've started a pulse
  if(pin_value > 0){
    // We capture the current microsecond timer value
    start_throttle = micros();
  }
  else{
    // We've transitioned to off, so report how long it was on for
    throttle_value = micros() - start_throttle;
  }
}

