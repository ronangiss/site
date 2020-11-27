/*
 * Title: Electromechanical Game
 * Author: Rónán Gissler
 * Date: 11/2/20
*/

// include servo library used to control servo motors
#include <Servo.h>

// generate a servo object for each servo
Servo servo1;
Servo servo2;

// Define necessary Arduino pins
const int servo1pin = 6;
const int servo2pin = 7;
const int pot1pin = 20;
const int pot2pin = 21;
const int button1pin = 3;
const int button2pin = 2;

// create a variable for button state (true means button push moves arms up and
// false means button push moves arms down)
int button1State = true;
int button2State = true;

// create a variable to store the value of the potentiometer
int pot1val;
int pot1valOld = 0; // used to determine when the potentiometer value is changing
int pot2val;
int pot2valOld = 0; // used to determine when the potentiometer value is changing

void setup() {
  // attach the servo objects to specific pins on the
  // Arduino through which control signals will be sent
 servo1.attach(servo1pin);
 servo2.attach(servo2pin);
 
 pinMode(pot1pin, INPUT);
 pinMode(pot2pin, INPUT);
 pinMode(button1pin, INPUT);
 pinMode(button2pin, INPUT);

}

void loop() {
 pot1val = analogRead(pot1pin); // reads the value of the potentiometer (value between 0 and 1023)
 pot1val = map(pot1val, 0, 1023, 0, 80); // scales potentiometer value to servo scale (value between 0 and 80)
 pot2val = analogRead(pot2pin); // reads the value of the potentiometer (value between 0 and 1023)
 pot2val = map(pot2val, 0, 1023, 0, 80); // scales potentiometer value to servo scale (value between 0 and 80)

 // read button states
 int button1 = digitalRead(button1pin);
 int button2 = digitalRead(button2pin);

 // adjusts servo 1 based on potentiometer 1 reading
 if (pot1val > pot1valOld + 4 || pot1val < pot1valOld - 4) {
  servo1.write(pot1val);
  pot1valOld = pot1val;
  delay(15);
 }
 // adjusts servo 1 based on button 1 reading
 if (button1 == HIGH) {
  if (button1State) {
    servo1.write(80);
    button1State = false;
    delay(500);
  }
  else {
    servo1.write(0);
    button1State = true;
    delay(500);
  }
 }
 // adjusts servo 2 based on potentiometer 2 reading
  if (pot2val > pot2valOld + 4 || pot2val < pot2valOld - 4) {
  servo2.write(pot2val);
  pot2valOld = pot2val;
  delay(15);
 }
 // adjusts servo 2 based on button 2 reading
 if (button2 == HIGH) {
  if (button2State) {
    servo2.write(80);
    button2State = false;
    delay(500);
  }
  else {
    servo2.write(0);
    button2State = true;
    delay(500);
  }
 }
}
