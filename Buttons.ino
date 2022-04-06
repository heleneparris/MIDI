// Button/Potontiometer Functions
String whatButton;
int curPot[4] = {0, 0, 0, 0};
int prevPot[4] = {0, 0, 0, 0};
int stateOne[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevStateOne[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int stateTwo[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevStateTwo[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int stateThree[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevStateThree[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int potThreshold = 60;
int current;

// Initialize Buttons
void initButtons() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

// Check Buttons
void checkButtons() {
  for (int i = 0; i < numButtons; i++)  {
    buttons[i].update();
    if (buttons[i].rose() ) {
      buttonStates[i] = !buttonStates[i];
      if (buttons[0].rose()) {
        mode = 0;
        modeOne();
        state = "State 1";
        whatButton = "Button 1 Pressed";
        
      }
      if (buttons[1].rose()) {
        mode = 1;
        state = "State 2";
        whatButton = "Button 2 Pressed";
      }
      if (buttons[2].rose()) {
        mode = 2;
        state = "State 3";
        whatButton = "Button 3 Pressed";
      }
      Serial.print(state); Serial.print(":  "); Serial.print(whatButton); Serial.println();
    }
  }
}

// Check Pots
void checkPots() {
  for (int i = 0; i < numPots; i++) {
    potStates[i] = analogRead(potPins[i]);
    curPot[i] = potStates[i];
  }
  for (int i = 0; i < numPots; i++) {
    if (abs(curPot[i] - prevPot[i]) > potThreshold) {
      Serial.print(state); Serial.print("   ");
      Serial.print("Pot 1:  "); Serial.print(curPot[1]); Serial.print("   ");
      Serial.print("Pot 2:  "); Serial.print(curPot[2]); Serial.print("   ");
      Serial.print("Pot 3:  "); Serial.print(curPot[3]);  Serial.print("   ");
      Serial.print("Slide Pot:  "); Serial.print(curPot[0]); Serial.println();
    int outPot = map(curPot[i], 0, 1023, 0, 127);
    controlChange(0, i+100, outPot);
    prevPot[i] = curPot[i];
    }
  }
}
