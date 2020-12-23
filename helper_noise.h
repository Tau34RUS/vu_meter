void fillnoise8() {
  for (int i = 0; i < N_PIXELS; i++) {
    uint8_t index = inoise8(i * scale, dist + i * scale) % 255;
    leds[i] = ColorFromPalette(currentPalette, index, 255, LINEARBLEND);
  }
  dist += beatsin8(10, 1, 4);
}