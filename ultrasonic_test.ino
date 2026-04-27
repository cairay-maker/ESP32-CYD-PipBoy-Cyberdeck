#include <Arduino.h>
#include <Ultrasonic.h>

#define TRIG_PIN 21
#define ECHO_PIN 22

Ultrasonic sonar(TRIG_PIN, ECHO_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  Serial.println("HC-SR04 library test started");
  Serial.printf("TRIG=%d ECHO=%d\n", TRIG_PIN, ECHO_PIN);
}

void loop() {
  unsigned int distance = sonar.read(CM);
  if (distance == 0) {
    Serial.println("Ultrasonic: NO ECHO / timeout");
  } else {
    Serial.printf("Ultrasonic distance=%.1f cm\n", float(distance));
  }

  delay(500);
}
