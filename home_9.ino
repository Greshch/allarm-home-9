
#include <NanitLib.h>

#define PIN_ALLERT P3_2
#define PIN_MOVE P5_1
#define PIN_OFF P3_3
#define PIN_BUZZ  P5_4

bool on = 0;

void setup() {
  // put your setup code here, to run once:
  Nanit_Base_Start();
  Serial.begin(9600);
  pinMode(PIN_ALLERT, OUTPUT);
  pinMode(PIN_MOVE, INPUT_PULLUP);
  pinMode(PIN_OFF, INPUT_PULLUP);
  pinMode(PIN_BUZZ, OUTPUT);
  attachInterrupt(0, PirCallBack, RISING);
}

void loop() {
  if (on) { // коли спряцувала сигналізація
    tone(PIN_BUZZ, 100);
    digitalWrite(PIN_ALLERT, 1);
    delay(350);
    digitalWrite(PIN_ALLERT, 0);
    delay(200);
    if (!digitalRead(PIN_OFF)) { // вимкнути сигналізацію
      on = 0;
      noTone(PIN_BUZZ);
    }
  }
  else { // до спрацювання сигналізації
    digitalWrite(PIN_ALLERT, 1);
    delay(50);
    digitalWrite(PIN_ALLERT, 0);
    delay(950);
  }
}

void PirCallBack(void) {
  Serial.println("Motion done!");
  // digitalWrite(PIN_ALLERT, 1);
  // digitalWrite(PIN_ALLERT, 0);
  on = 1;
}