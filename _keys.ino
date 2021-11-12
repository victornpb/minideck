// Pin definitions
#define BUTTON_PIN1 A0
#define BUTTON_PIN2 A1
#define BUTTON_PIN3 A2
#define BUTTON_PIN4 A3
#define BUTTON_PIN5 6
#define BUTTON_PIN6 7
#define BUTTON_PIN7 8
#define BUTTON_PIN8 9


#include "Keyboard.h"


// Button helper class for handling press/release and debouncing
class button {
  public:
    const char key;
    const uint8_t pin;

    button(uint8_t k, uint8_t p) : key(k), pin(p) {}

    void press(boolean state) {
      if (state == pressed || (millis() - lastPressed  <= debounceTime)) {
        return; // Nothing to see here, folks
      }

      lastPressed = millis();

      if (state) {
        Keyboard.press(key);
        onDown();
      }
      else {
        Keyboard.release(key);
        onUp();
      }
      pressed = state;

    }


    void update() {
      press(!digitalRead(pin));
    }

  private:
    const unsigned long debounceTime = 30;
    unsigned long lastPressed = 0;
    boolean pressed = 0;
};

button buttons[] = {
  {BUTTON_KEY1, BUTTON_PIN1},
  {BUTTON_KEY2, BUTTON_PIN2},
  {BUTTON_KEY3, BUTTON_PIN3},
  {BUTTON_KEY4, BUTTON_PIN4},
  {BUTTON_KEY5, BUTTON_PIN5},
  {BUTTON_KEY6, BUTTON_PIN6},
  {BUTTON_KEY7, BUTTON_PIN7},
  {BUTTON_KEY8, BUTTON_PIN8},
};


const uint8_t NumButtons = sizeof(buttons) / sizeof(button);

void poolKeypad(){
  for (int i = 0; i < NumButtons; i++) {
    buttons[i].update();
  }  
}



void onDown() {
  blinkOn();
}

void onUp() {
  blinkOff();
}
