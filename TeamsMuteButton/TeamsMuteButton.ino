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
// LIBRARIES
#include <Keyboard.h>
#include <Adafruit_CircuitPlayground.h>

// CONSTANTS
const int MUTE_BUTTON = 6; // Set the pin for the pushbutton
const int DEBOUNCE_DELAY = 50; // Set debounce time; increase if the output flickers

// Set up a variable to hold the control (CTRL) key
// Use this option for Windows and Linux:
char ctrlKey = KEY_LEFT_CTRL;
// Use this for OSX:
// char ctrlKey = KEY_LEFT_GUI;

// VARIABLES
int slideCounter = 0; // Set a variable to store the slide switch counter
int currentButtonState = 0; // Set a variable to store the button state
int lastSteadyState = 0;       // the previous steady state from the button
int lastFlickerableState = 0;  // the previous flickerable state from the button
long lastDebounceTime = 0;  // the last time the button was pressed


void setup() {
  // Set pushbutton as an input, enable pull-down resistor
  CircuitPlayground.begin();
  pinMode(MUTE_BUTTON, INPUT_PULLDOWN);

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
    
    // Read the button state
    currentButtonState = digitalRead(MUTE_BUTTON);
    
    // If the switch/button changed, due to noise or pressing:
    if(currentButtonState != lastFlickerableState){
      // reset debounce timer
      lastDebounceTime = millis(); 
      // save the last state
      lastFlickerableState = currentButtonState;
    }

    if((millis() - lastDebounceTime) > DEBOUNCE_DELAY){
      // if button state has changed (via press)
      if(lastSteadyState == 1 && currentButtonState == 0){
        CircuitPlayground.redLED(HIGH);
        Serial.println("Pressed");
        Keyboard.press(ctrlKey);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('m');
      }
      lastSteadyState = currentButtonState;
      CircuitPlayground.redLED(LOW);
      Keyboard.releaseAll(); // Release all keys. Super important!!
    }
  }
  slideCounter = 0;
  Keyboard.releaseAll();
}
