
/ Smart Street Light (4-lamp version)
// Arduino Nano + LDR + IR Sensors + LEDs
// ---------------- PIN MAPPING ----------------
const int LDR_PIN = A0; // LDR analog pin
const int IR_SENSOR_PINS[4] = {2, 3, 4, 5}; // IR sensor digital pins
const int LED_PINS[4] = {3, 5, 6, 9}; // PWM pins for LEDs
// ------------- LDR THRESHOLDS ----------------
const int LDR_THRESHOLD_NIGHT = 400; // below this = night
// ------------- LED BRIGHTNESS ----------------
const int LED_DIM = 60; // dim light (0–255)
const int LED_FULL = 255; // full brightness
void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(IR_SENSOR_PINS[i], INPUT_PULLUP); // IR sensors are ACTIVE-LOW
    pinMode(LED_PINS[i], OUTPUT);
    analogWrite(LED_PINS[i], 0); // turn off initially
  }
}
void loop() {
  int ldrValue = analogRead(LDR_PIN);
  bool isNight = (ldrValue < LDR_THRESHOLD_NIGHT);
  // Debug (optional)
  // Serial.println(ldrValue);
  if (!isNight) {
    // DAY TIME → lights OFF
    for (int i = 0; i < 4; i++) {
      analogWrite(LED_PINS[i], 0);
    }
  } else {
    // NIGHT → dim lights
    for (int i = 0; i < 4; i++) {
      analogWrite(LED_PINS[i], LED_DIM);
    }
    // Check IR sensors
    for (int i = 0; i < 4; i++) {
      if (digitalRead(IR_SENSOR_PINS[i]) == LOW) { // object detected
        analogWrite(LED_PINS[i], LED_FULL);
      }
    }
  }
  delay(100);
}
