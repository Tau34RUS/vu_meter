  void setAll(byte red, byte green, byte blue) {

  for (int i = 0; i < N_PIXELS; i++ ) {

    strip.setPixelColor(i, red, green, blue);

  }

  strip.show();

}