/* Microsoft Teams Mute Button!
 *  MIT License
 *  
 *  Use an Adafruit Circuit Playground Express and external pushbutton to 
 *  trigger the Teams keyboard hotkey: Ctrl + Shift + M.
 *  When you want to enable, move the CPX slide switch to the left (towards button A)
 *  
 *  Wiring Info:
 *      Connect one pushbutton lead to CPX Pin A1 and the other lead to 3.3V
 *      (orientation does not matter)
 *      

*/
#include <Keyboard.h>
#include <Adafruit_CircuitPlayground.h>

// Set the pin for the pushbutton
const int muteButton = 6;

// Set up a variable to hold the control (CTRL) key
// Use this option for Windows and Linux:
char ctrlKey = KEY_LEFT_CTRL;
// Use this for OSX:
// char ctrlKey = KEY_LEFT_GUI;

// Set a variable to store the slide switch counter
int slideCounter = 0;

// Set a variable to store the button counter
int buttonCounter = 0;

void setup() {
  // Set pushbutton as an input, enable pull-down resistor
  CircuitPlayground.begin();
  pinMode(muteButton, INPUT_PULLDOWN);

  // Set up Serial Monitor for status/debugging
  Serial.begin(115200);
  // initialize keyboard control:
  Keyboard.begin();
  Serial.println("Ready to deploy! Move the CPX slide switch to the left (towards button A) to enable the mute button.");
}

void loop() {
  // While slide switch is to the left (towards Button A), allow for mute
  while(CircuitPlayground.slideSwitch()){
    // Only print status first time slide switch is moved
    if(slideCounter == 0){ 
      Serial.println("Ready to mute!");
      slideCounter += 1; 
    }
    // If pushbutton pressed, press 'Ctrl + Shift + M'
    if (digitalRead(muteButton)) {
      if (buttonCounter == 0){
        CircuitPlayground.redLED(HIGH);
        Serial.println("Pressed");
        Keyboard.press(ctrlKey);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('m');
        buttonCounter += 1;
        delay(500); // Delay to avoid multi-presses
      }
    }
    CircuitPlayground.redLED(LOW);
    buttonCounter = 0;
    Keyboard.releaseAll(); // Release all keys. Super important!!
  }
  slideCounter = 0;
  Keyboard.releaseAll();
}