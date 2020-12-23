void sinelon() {
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, N_PIXELS, thisfade);
  int pos1 = beatsin16(thisbeat, 0, N_PIXELS);
  int pos2 = beatsin16(thatbeat, 0, N_PIXELS);
  leds[(pos1 + pos2) / 2] += CHSV( myhue++ / 64, thissat, thisbri);
  FastLED.show();
  delay(40);
}