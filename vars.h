#ifndef VARS_H
#define VARS_H

#define PIN 6             //LED Data Pin
#define N_PIXELS  100     //Number of Pixels
#define BG 0
#define COLOR_ORDER GRB  // Try mixing up the letters (RGB, GBR, BRG, etc) for a whole new world of color combinations
#define BRIGHTNESS 220   // 0-255, higher number is brighter.
#define LED_TYPE WS2812B
#define MIC_PIN   A3  // Microphone is attached to this analog pin
#define DC_OFFSET  0  // DC offset in mic signal - if unusure, leave 0
const int buttonPin = 12;     // the number of the pushbutton pin

#define SAMPLES   50  // Length of buffer for dynamic level adjustment
#define TOP       (N_PIXELS + 2) // Allow dot to go slightly off scale
#define PEAK_FALL 30  // Rate of peak falling dot
#define N_PIXELS_HALF (N_PIXELS/2)
#define GRAVITY           -9.81              // Downward (negative) acceleration of gravity in m/s^2
#define h0                1                  // Starting height, in meters, of the ball (strip length)
#define NUM_BALLS         4                  // Number of bouncing balls you want (recommend < 7, but 20 is fun in its own way)
#define SPEED .20       // Amount to increment RGB color by each cycle

int NOISE = 20; // Noise/hum/interference in mic signal
//config for balls
float h[NUM_BALLS] ;                         // An array of heights
float vImpact0 = sqrt( -2 * GRAVITY * h0 );  // Impact velocity of the ball when it hits the ground if "dropped" from the top of the strip
float vImpact[NUM_BALLS] ;                   // As time goes on the impact velocity will change, so make an array to store those values
float tCycle[NUM_BALLS] ;                    // The time since the last time the ball struck the ground
int   pos[NUM_BALLS] ;                       // The integer position of the dot on the strip (LED index)
long  tLast[NUM_BALLS] ;                     // The clock time of the last ground strike
float COR[NUM_BALLS] ;                       // Coefficient of Restitution (bounce damping)

int lead_dot = 0;

float
greenOffset = 30,
blueOffset = 150;

byte
peak      = 0,      // Used for falling dot
dotCount  = 0,      // Frame counter for delaying dot-falling speed
volCount  = 0;      // Frame counter for storing past volume data
int
vol[SAMPLES],       // Collection of prior volume samples
    lvl       = 10,      // Current "dampened" audio level
    minLvlAvg = 0,      // For dynamic adjustment of graph low & high
    maxLvlAvg = 512;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

CRGBPalette16 currentPalette(CRGB::Black);
CRGBPalette16 targetPalette(OceanColors_p);

// FOR SYLON ETC
uint8_t thisbeat =  23;
uint8_t thatbeat =  28;
uint8_t thisfade =  20;                                     // How quickly does it fade? Lower = slower fade rate.
uint8_t thissat = 255;                                     // The saturation, where 255 = brilliant colours.
uint8_t thisbri = 255;

CRGB leds[N_PIXELS];

//Ripple variables
int color;
int center = 0;
int step = -1;
int maxSteps = 16;
uint8_t maxChanges = 48;      // Value for blending between palettes.
static uint16_t dist;         // A random number for noise generator.
uint16_t scale = 30;          // Wouldn't recommend changing this on the fly, or the animation will be really blocky.
float fadeRate = 0.80;
int diff;
int myhue = 0;

// Variables will change:

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonVar = 0;
int buttonState = 0;         // current state of the button
int lastButtonState = 0;

//background color
uint32_t currentBg = random(256);
uint32_t nextBg = currentBg;

#endif
