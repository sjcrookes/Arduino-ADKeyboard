#include <ADKeyboard.h>

int ADKeyboard_PIN = A0;

ADKeyboard kb(ADKeyboard_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Print what button is being pressed
  Serial.print("pressing:");
  Serial.println(kb.pressed());

  // Check if button 1 is specifically being pressed
  if ( kb.pressed(1) )
    Serial.println("button 1 pressed");

  delay(200);
}