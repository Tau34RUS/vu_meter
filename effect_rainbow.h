void rainbow(uint8_t wait) {
  uint16_t i, j;
  FastLED.setBrightness(BRIGHTNESS);
  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    // check if a button pressed
    if (digitalRead(buttonPin) != lastButtonState)  // <------------- add this
      return;         // <------------ and this
    delay(wait);
  }
}