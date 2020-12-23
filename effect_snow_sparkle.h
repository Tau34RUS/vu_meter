#include "helper_setall.h"

void SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) {

  setAll(red, green, blue);

  int Pixel1 = random(N_PIXELS);
  int Pixel2 = random(N_PIXELS);
  int Pixel3 = random(N_PIXELS);

  strip.setPixelColor(Pixel1, 0xff, 0xff, 0xff);
  strip.setPixelColor(Pixel2, 0xff, 0xff, 0xff);
  strip.setPixelColor(Pixel3, 0xff, 0xff, 0xff);

  strip.show();

  delay(SparkleDelay);

  strip.setPixelColor(Pixel1, red, green, blue);
  strip.setPixelColor(Pixel2, red, green, blue);
  strip.setPixelColor(Pixel3, red, green, blue);

  strip.show();

  delay(SpeedDelay);

}
