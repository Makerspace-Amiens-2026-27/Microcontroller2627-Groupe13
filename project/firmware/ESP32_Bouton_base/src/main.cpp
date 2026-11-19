#include "config.h"

void setup() {
    Serial.begin(115200);
    pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
    Serial.println(digitalRead(PIN_BUTTON) == HIGH ? "HIGH" : "LOW");
    delay(200);  // programme de test : on ralentit l'affichage
}

//HIGH pour bouton relache
//LOW pour bouton appuye