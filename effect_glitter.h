void addGlitter( fract8 chanceOfGlitter) {
  fadeToBlackBy( leds, N_PIXELS, 5);

  if ( random8() < chanceOfGlitter) {
    leds[ random16(N_PIXELS) ] += CRGB::White;
  }

  FastLED.show();
}