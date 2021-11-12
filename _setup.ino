void configMode() {
  if (check()) {
    
    // Entered config mode
    leds[0] = CRGB::Blue;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Blue;
    FastLED.show();
    while(check()) {} // pause when still holding
    delay(50);

    do {
      configLoop();
    }
    while(!check()); // exit
    while(check()){} // wait for release
    
    leds[0] = CRGB::Green;
    leds[1] = CRGB::Black;
    leds[2] = CRGB::Black;
    leds[3] = CRGB::Green;
    FastLED.show();
    delay(500);
  }
}

bool check() {
    return !digitalRead(BUTTON_PIN1) && !digitalRead(BUTTON_PIN4) && !digitalRead(BUTTON_PIN5) && !digitalRead(BUTTON_PIN8);
}

void configLoop() {
  
  
}
