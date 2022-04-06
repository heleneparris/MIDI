
void modeOne() {
  for (int i = 0; i < numLED; i++) {
    strip.setPixelColor(i, Wheel(254));
  }
  state = "State 1";

  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      stateOne[i] = !stateOne[i];
      if (stateOne[i] != prevStateOne[i]) {
        if (stateOne[i]) {
          controlChange(0, i, 127);
          Serial.println("yuh");
        } else {
          controlChange(0, i, 0);
          Serial.println("Nuh");
        }
      }
      prevStateOne[i] = stateOne[i];
    }
  }
}

void modeTwo() {
  for (int i = 0; i < numLED; i++) {
    strip.setPixelColor(i, Wheel(65));
  }
  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      stateTwo[i] = !stateTwo[i];
      if (stateTwo[i] != prevStateTwo[i]) {
        if (stateTwo[i]) {
          controlChange(0, i, 127);
          Serial.println("yuh");
        } else {
          controlChange(0, i, 0);
          Serial.println("Nuh");
        }
      }
      prevStateTwo[i] = stateTwo[i];
    }
  }
}
void modeThree() {
  for (int i = 0; i < numLED; i++) {
    strip.setPixelColor(i, Wheel(160));
  }
  for (int i = 0; i < numButtons; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      stateThree[i] = !stateThree[i];
      if (stateThree[i] != prevStateThree[i]) {
        if (stateThree[i]) {
          controlChange(0, i, 127);
          Serial.println("yuh");
        } else {
          controlChange(0, i, 0);
          Serial.println("Nuh");
        }
      }
      prevStateThree[i] = stateThree[i];
    }
  }
}
