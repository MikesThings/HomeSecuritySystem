// set pin numbers
#include <Adafruit_NeoPixel.h> // Include the Adafruit NeoPixel library
#define LED_PIN 12 // NeoPixel LED strip
#define NUM_LEDS 8 // Number of LEDs
const int pirPin = 19;  // the number of the pir pin 
const int buzzerPin = 26;
const int buttonPin = 15;  // Button pin
// Create an instance of the Adafruit_NeoPixel class
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800); 
// variable for storing the pir status 
int pirState = 0;
int buttonState = 0;
int condition = 0;

void setup() {
  Serial.begin(115200);  
  // initialize the pir pin as an input
  pinMode(pirPin, INPUT);
  pinMode(buttonPin, INPUT);
  // initialize the LED pin as an output
 // pinMode(ledPin, OUTPUT);
  strip.begin(); // Initialize the NeoPixel strip
  strip.show();
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // read the state of the pir value
  buttonState = digitalRead(buttonPin);
  //Serial.println(buttonState);
  pirState = digitalRead(pirPin);
  Serial.println(pirState);
  if (buttonState == HIGH){
    delay(500);
    if (condition == 0) {
      condition = 1;
    }
    else {
      condition = 0; 
    }
  }
  // if the pir is pressed, the pirState is HIGH
  if (condition == 1) { 
  if (pirState == HIGH) {
    // turn LED on
   // digitalWrite(ledPin, HIGH);
    for (int i = 0; i < NUM_LEDS; i++) {
        if (i % 2 == 0) { 
        strip.setPixelColor(i, 100, 0, 0); // Set the color of even-indexed LEDs to red
    } else { 
        strip.setPixelColor(i, 0, 0, 100); // Set the color of odd-indexed LEDs to blue
    }
      strip.show(); // Update the LED strip with the new color
      for (int i = 0; i < 50; i++) // Loop 50 times and play a short tone each time
        { 
        digitalWrite(buzzerPin, HIGH); // Set to HIGH to make the buzzer sound
          delay(3); // Wait for 3 milliseconds
        digitalWrite(buzzerPin, LOW); // LOW to turn off the buzzer
        delay(3); // 
  }
      delay(10);   // Wait for 100 milliseconds
  }
  } else {
    // turn LED off
    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, 0, 0, 0); // Turn off the i-th LED
      strip.show(); // Update the LED strip
      delay(10);   // Wait for 100 milliseconds
    }
    //digitalWrite(ledPin, LOW);
  }
  }
}
