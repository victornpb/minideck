void setup() {

  // Setup Keypad
  for (int i = 0; i < NumButtons; i++) {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }

  //Setup Leds
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 350); // limit my draw to 1A at 5v of power draw
  setDefaultLed();
}


void loop() {
  configMode();
  poolKeypad();

  //ChangePalettePeriodically();


  
  ledTick();
}
