#include <Arduino.h>
#include <Bounce2.h> // mussten wir herunterladen

// Buttons an den Pins 2 und 3
const int BTN_YELLOW = 2;
const int BTN_BLUE = 3;
// Leds
const int LED_GREEN = 6;
const int LED_PINK = 7;

Bounce2::Button btnYellow = Bounce2::Button();
Bounce2::Button btnBlue = Bounce2::Button();

void setup() {
  Serial.begin(9600);  

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_PINK, OUTPUT);

  btnYellow.attach(BTN_YELLOW, INPUT_PULLUP);
  btnYellow.setPressedState(LOW); // auf active low setzen

  btnBlue.attach(BTN_BLUE, INPUT_PULLUP);
  btnBlue.setPressedState(LOW); 
  

}

void loop() {
  btnYellow.update();
  btnBlue.update();

  if (btnYellow.pressed())
  {
    digitalWrite(LED_GREEN, HIGH);
    delay(2000);
    digitalWrite(LED_GREEN, LOW);
  }
  else if (btnBlue.pressed())
  {
    Serial.println("Blau gedrückt");
  }
}