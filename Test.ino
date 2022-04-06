// Test Program

long testTimer = 0;
long testInterval = 1000;
int testColor = 0;

int buttonState = false;
int prevPotStates;
int prevButtonState = false;

void startUp() {
  delay(500);
  for (int i = 0; i < numLED; i++) {
    strip.setPixelColor(i, Wheel(random(0, 255))); strip.show(); delay(25);
    strip.setPixelColor(i, Wheel(random(0, 255))); strip.show(); delay(25);
    strip.setPixelColor(i, Wheel(random(0, 255))); strip.show(); delay(25);
    strip.setPixelColor(i, Wheel(random(0, 255))); strip.show(); delay(25);
    strip.setPixelColor(i, Wheel(random(0, 255))); strip.show(); delay(25);
    strip.setPixelColor(i, Wheel(random(0, 255))); strip.show(); delay(25);
    strip.setPixelColor(i, Wheel(random(0, 255))); strip.show();
  }
}
