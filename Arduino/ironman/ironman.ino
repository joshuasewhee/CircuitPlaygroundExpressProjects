/*
 * Name: Joshua Sew-Hee
 * Date: 6/9/19
 * Desc: Iron Man Arc Reactor
 * Lib : Adafruit_CircuitPlayground.h
 * Ref :https://adafruit.github.io/Adafruit_CircuitPlayground/html/class_adafruit___circuit_playground.html
 * This program emulates the arc reactor from the Iron Man movie
 * 
 */

// System libraries
#include "Adafruit_CircuitPlayground.h"

// System defines 
#define numPixels 12

// Declare variables
bool button_pressed = false; // Determines whether button is pressed or not
int pixelValue;          // Current value of the pixels
int dir = 1;             // Direction of the pixels... 1 = getting brighter, 0 = getting dimmer
int flip;                // Randomly flip the direction every once in a while
int minPixelValue = 20;  // Min value of brightness
int maxPixelValue = 255; // Max value of brightness
int pixelValueDelta = 5; // Delta of brightness between times through the loop
//String color = "Cyan";   // Color of Neopixels

int ledState = 1;        // the current state of the output pin
int buttonState;         // the current reading from the input pin
int lastButtonState = 1; // the previous reading from the input pin

// Keep track of time in milliseconds
unsigned long lastDebounceTime = 0; // Last time push button toggled
unsigned long debounceDelay = 50;   // Debounce time; increase if output flickers

// Enumerate colors to be displayed on Arc Reactor
enum Colors{
  CYAN,
  RED,
  YELLOW,
  GREEN
};

Colors color = CYAN;

// The setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);                      // Allow serial communication
  CircuitPlayground.begin();
}

// The loop function runs over and over again forever
void loop() {
  // Randomly flip the direction of the pixel increase/decrease
  flip = random(32);
  if(flip > 20) {
    dir = 1 - dir;
  }
  // Pixels -> Brighter
  if (dir == 1) {
    pixelValue += pixelValueDelta;
  }
  // Pixels -> Dimmer
  if (dir == 0) {
    pixelValue -= pixelValueDelta;
  }
  // Set min threshold of pixels
  if (pixelValue < minPixelValue) {
    pixelValue = minPixelValue;
    dir = 1;
  }
  // Set max threshold of pixels
  if (pixelValue > maxPixelValue) {
    pixelValue = maxPixelValue;
    dir = 0;
  }
  
  // If slide switch is to the left
  if (CircuitPlayground.slideSwitch()){
     CircuitPlayground.clearPixels();
     color = CYAN;
  }
  // If slide switch is to the right
  else {
    if (color == CYAN) {
      for(int i=0; i<numPixels; i++) {
      // CircuitPlayground.setPixelColor(pixelNumber, R, G, B); // Color
      CircuitPlayground.setPixelColor(i, 0, pixelValue, pixelValue); // Cyan
      }
    }
    else if (color == RED) {
       for(int i=0; i<numPixels; i++) {
      // CircuitPlayground.setPixelColor(pixelNumber, R, G, B); // Color
      CircuitPlayground.setPixelColor(i, pixelValue, 0, 0); // Red
      }
    }
    else if (color == YELLOW) {
      for(int i=0; i<numPixels; i++) {
      // CircuitPlayground.setPixelColor(pixelNumber, R, G, B); // Color
      CircuitPlayground.setPixelColor(i, pixelValue, pixelValue, 0); // Red
      }
    }
    else if (color == GREEN) {
      for(int i=0; i<numPixels; i++) {
      // CircuitPlayground.setPixelColor(pixelNumber, R, G, B); // Color
      CircuitPlayground.setPixelColor(i, 0, pixelValue, 0); // Yellow
      }
    }    
  }
  
  if (CircuitPlayground.leftButton()) {
    switch (color){
      case CYAN:
        color = RED;
        break;
      case RED:
        color = YELLOW;
        break;
      case YELLOW:
        color = GREEN;
        break;
      case GREEN:
        color = CYAN; // Reset color to CYAN
        break;
    }
  }
  
//  // The left button will toggle actions between button presses
//  if (button_pressed == false and CircuitPlayground.leftButton()) {
//    button_pressed = true;
//  }
//  else if (button_pressed == true and CircuitPlayground.leftButton()){
//    button_pressed = false;
//  }
//
//  if (button_pressed){
//    CircuitPlayground.redLED(HIGH); // LED on
//  }
//  else{
//    CircuitPlayground.redLED(LOW); // LED off
//  }
}
