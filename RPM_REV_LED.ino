#include "FastLED.h"

#define PIN_SLIDE_POT_A A0 // input pin of the slide pot
#define MAX_SLIDE_POT_ANALGOG_READ_VALUE 1023 // maximum voltage as analog-to-digital converted value, depends on the voltage level of the VCC pin. Examples: 5V = 1023; 3.3V ~700


#define NUM_LEDS 17 // add number of LEDs of your RGB LED strip
#define PIN_LED 3 // digital output PIN that is connected to DIN of the RGB LED strip
#define LED_COLOR_1 CRGB::DarkBlue//see https://github.com/FastLED/FastLED/wiki/Pixel-reference for a full list, e.g. CRGB::AliceBlue, CRGB::Amethyst, CRGB::AntiqueWhite...
#define LED_COLOR_2 CRGB::DarkRed
#define LED_COLOR_3 CRGB::DarkOrange
#define LED_COLOR_4 CRGB::Gold
#define LED_COLOR_5 CRGB::DarkGreen

CRGB rgb_led[NUM_LEDS]; // color array of the LED RGB strip

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_SLIDE_POT_A, INPUT);
  FastLED.addLeds<WS2812B, PIN_LED>(rgb_led, NUM_LEDS);  
  
  Serial.println("Setup done.");

  for (int j=0;j<1;j++)
{
      rgb_led[0] = CRGB::DarkBlue; 
      FastLED.show();
      delay(180);

      rgb_led[1] = CRGB::DarkBlue; 
      FastLED.show();
      delay(170);

      rgb_led[2] = CRGB::DarkBlue; 
      FastLED.show();
      delay(160);
     
      

      rgb_led[3] = CRGB::DarkBlue; 
      FastLED.show();
      delay(150);
     
     

      rgb_led[4] = CRGB::DarkRed; 
      FastLED.show();
      delay(140);
     
      

      rgb_led[5] = CRGB::DarkRed; 
      FastLED.show();
      delay(130);
     
     

      rgb_led[6] = CRGB::DarkRed; 
      FastLED.show();
      delay(120);
     
     

      rgb_led[7] = CRGB::DarkRed; 
      FastLED.show();
      delay(110);
     
      

      rgb_led[8] = CRGB::DarkOrange; 
      FastLED.show();
      delay(100);
     
     

      rgb_led[9] = CRGB::DarkOrange; 
      FastLED.show();
      delay(90);
     
      

      rgb_led[10] = CRGB::Gold; 
      FastLED.show();
      delay(80);
     
      

      rgb_led[11] = CRGB::Gold; 
      FastLED.show();
      delay(70);
     
     
      rgb_led[12] = CRGB::DarkGreen; 
      FastLED.show();
      delay(60);
     
      

      rgb_led[13] = CRGB::DarkGreen; 
      FastLED.show();
      delay(50);
     
     

      rgb_led[14] = CRGB::DarkGreen; 
      FastLED.show();
      delay(40);
     
     

      rgb_led[15] = CRGB::DarkGreen; 
      FastLED.show();
      delay(30);
     
      

      rgb_led[16] = CRGB::DarkGreen; 
      FastLED.show();
      delay(20);
     
      

      rgb_led[17] = CRGB::DarkGreen; 
      FastLED.show();
      delay(10);
     
      
for (int k=0;k<18;k++)
{
      rgb_led[17-k] = CRGB::Black;
      FastLED.show();
      delay(100);
}     
}
}

void loop() {
  // 1) Analog value of slide pot is read
  int value_slide_pot_a = analogRead(PIN_SLIDE_POT_A);
  Serial.print("Slide Pot value: ");
  Serial.println(value_slide_pot_a);

  // 2) Analog value is mapped from slide pot range (analog input value) to led range (number of LEDs)
  int num_leds_switchedon = map(value_slide_pot_a, 0, MAX_SLIDE_POT_ANALGOG_READ_VALUE, 0, NUM_LEDS);  


  // 3) Light up the LEDs
  // Only LEDs are switched on which correspond to the area left of the slide knob



  for (int i = 0; i < 4; ++i) {
    rgb_led[i] = LED_COLOR_1;
  }  

  for (int i = 4; i < 9; ++i) {
    rgb_led[i] = LED_COLOR_2;
  }  

  for (int i = 9; i < 11; ++i) {
    rgb_led[i] = LED_COLOR_3;
  }  

  for (int i = 11; i < 13; ++i) {
    rgb_led[i] = LED_COLOR_4;
  } 

  for (int i = 13; i < 18; ++i) {
    rgb_led[i] = LED_COLOR_5;
  }  
  // LEDs are switched off which correspond to the area right of the slide knob
  for (int i = num_leds_switchedon; i < NUM_LEDS; ++i) {
    rgb_led[i] = CRGB::Black;
  }
  FastLED.show();
}
