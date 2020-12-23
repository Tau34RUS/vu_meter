//Brought to life by Vlad Tau34RUS Evseev

#include <Adafruit_NeoPixel.h>
#include <FastLED.h>
#include <Wire.h>
#include <math.h>
#include "vars.h"
#include "effect_vu.h"
#include "effect_snow_sparkle.h"
#include "effect_fire.h"
#include "effect_sinelon.h"
#include "effect_rainbow.h"
#include "effect_colorful.h"
#include "effect_glitter.h"

void setup() {

  delay(2000); // power-up safety delay
  FastLED.addLeds<WS2812B, PIN, COLOR_ORDER>(leds, N_PIXELS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);
  analogReference(EXTERNAL);
  memset(vol, 0, sizeof(vol));
  LEDS.addLeds<LED_TYPE, PIN, COLOR_ORDER>(leds, N_PIXELS);
  strip.begin();
  strip.show();

  pinMode(buttonPin, INPUT);
  //initialize the buttonPin as output
  digitalWrite(buttonPin, HIGH);

  for (int i = 0 ; i < NUM_BALLS ; i++) {    // Initialize variables
    tLast[i] = millis();
    h[i] = h0;
    pos[i] = 0;                              // Balls start on the ground
    vImpact[i] = vImpact0;                   // And "pop" up at vImpact0
    tCycle[i] = 0;
    COR[i] = 0.90 - float(i) / pow(NUM_BALLS, 2);

  }
}

void loop() {

  //start mic
  uint8_t  i;
  uint16_t minLvl, maxLvl;
  int      n, height;
  //end mic

  //TODO: add bounce filter..or capasitor
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      buttonPushCounter++;
      if (buttonPushCounter == 10                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ) {
        buttonPushCounter = 1;
      }
    }
    else {
      // if the current state is LOW then the button
      // send from on to off
    }
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;

  switch (buttonPushCounter) {

    case 1:
      buttonPushCounter == 1; {

        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          vu2();
        }
        break;
      }

    case 2:
      buttonPushCounter == 2; {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          vu();
        }
        break;
      }

    case 3:
      buttonPushCounter == 3; {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else
        {
          Vu3();
        }
        break;
      }

    case 4:
      buttonPushCounter == 4; {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          fire();
        }
        break;
      }

    case 5:
      buttonPushCounter == 5;  {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          addGlitter(8);
        }
        break;
      }

    case 6:
      buttonPushCounter == 6;  {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          sinelon();
        }
        break;
      }
      

    case 7:
      buttonPushCounter == 7; {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          SnowSparkle(0, 0, 0, 40, random(200, 800));
        }
        break;
      }

    case 8:
      buttonPushCounter == 8; {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          Colorful();
        }
        break;
      }

    case 9:
      buttonPushCounter == 9; {
        if (buttonVar != buttonPushCounter) {
          buttonVar = buttonPushCounter;
        }
        else {
          rainbow(50);
        }
        break;
      }

  }

}
