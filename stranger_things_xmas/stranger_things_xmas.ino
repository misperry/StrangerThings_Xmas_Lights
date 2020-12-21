/*
 * This software is free to use to anyone.
 * This will be the code for the Stranger Things Xmas lights
 * coded here on the misperry youtube channel
 * 
 * For bill of materials visit the channel at http://www.youtube.com/misperry
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 26

#define MESSAGE_CYCLE 60

#define BRIGHTNESS 100

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// set array to hold message
char message[1024] = "MERRYCHRISTMAS\0";

///build function to convert letter to address
int letterToPin(char letter)
{
  switch (letter)
  {
    case 'A':
    return 0;
    break;

    case 'B':
    return 1;
    break;

    case 'C':
    return 2;
    break;

    case 'D':
    return 3;
    break;

    case 'E':
    return 4;
    break;

    case 'F':
    return 5;
    break;

    case 'G':
    return 6;
    break;

    case 'H':
    return 7;
    break;

    case 'I':
    return 16;
    break;

    case 'J':
    return 15;
    break;

    case 'K':
    return 14;
    break;

    case 'L':
    return 13;
    break;

    case 'M':
    return 12;
    break;

    case 'N':
    return 11;
    break;

    case 'O':
    return 10;
    break;

    case 'P':
    return 9;
    break;

    case 'Q':
    return 8;
    break;

    case 'R':
    return 17;
    break;

    case 'S':
    return 18;
    break;
    
    case 'T':
    return 19;
    break;
    
    case 'U':
    return 20;
    break;
    
    case 'V':
    return 21;
    break;
    
    case 'W':
    return 22;
    break;
    
    case 'X':
    return 23;
    break;
    
    case 'Y':
    return 24;
    break;
    
    case 'Z':
    return 25;
    break;
    
  }
}

void normalXmasLights()
{
  for (int i=0; i<strip.numPixels(); i+=5)
  {
    strip.setPixelColor(i, strip.Color(0,255,0)); //set reds
    strip.setPixelColor(i+1, strip.Color(255,0,0)); //set greens
    strip.setPixelColor(i+2, strip.Color(0,0,255)); //set blues
    strip.setPixelColor(i+3, strip.Color(200,227,0)); //set yellows
    strip.setPixelColor(i+4, strip.Color(255,255,255)); //set white
    strip.show();
  }
}

void clearColors()
{
  for (int i=0; i<strip.numPixels(); i++)
  {
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.show();
  }
}

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS); // Set BRIGHTNESS to about 1/5 (max = 255)
  normalXmasLights();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<MESSAGE_CYCLE; i++)
  {
    delay(1000);
  }
  clearColors();
  displayMessage();
  delay(2000);
  normalXmasLights();

}

void displayMessage()
{
  int i;
  while (message[i]!= '\0')
  {
    strip.setPixelColor(letterToPin(message[i]),strip.Color(0,0,255));
    strip.show();
    delay(2000);
    clearColors();
    delay(200);
    i++;
  }
}
