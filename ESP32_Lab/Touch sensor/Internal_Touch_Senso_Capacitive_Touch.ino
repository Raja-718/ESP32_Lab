// Experiment 1 Final: Touch-to-Light
const int TOUCH_PIN = 4;    // Pin D4
const int LED_PIN = 2;      // The built-in Blue LED
const int THRESHOLD = 1200; // Adjusted for your specific board

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT); // Set the blue LED as an output
  Serial.println("Touch D4 to light up the Blue LED!");
}

void loop() {
  int val = touchRead(TOUCH_PIN);
  
  if (val < THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // Turn LED ON
    Serial.print("TOUCHED! Value: ");
    Serial.println(val);
  } else {
    digitalWrite(LED_PIN, LOW);  // Turn LED OFF
  }
  
  delay(100);
}