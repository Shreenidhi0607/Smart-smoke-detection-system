#include <DHT.h>
#include <Servo.h>  // Servo library

// --- Pin definitions ---
#define MQ2_PIN A0      // MQ2 sensor analog pin
#define FLAME_PIN 2     // Flame sensor digital pin
#define LED_PIN 3       // LED pin
#define BUZZER_PIN 9    // Buzzer pin
#define DHTPIN 12       // DHT11 data pin
#define RELAY_PIN 7     // Relay module for fan
#define SERVO_PIN 6     // Servo pin

#define DHTTYPE DHT11   // Type of DHT sensor

DHT dht(DHTPIN, DHTTYPE);
Servo windowServo;

// --- Thresholds ---
int mq2Threshold = 115;         // Smoke level threshold
float tempThreshold = 35.0;     // Temperature threshold

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(FLAME_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // --- Initial state ---
  digitalWrite(RELAY_PIN, HIGH);  // Relay OFF (active LOW)
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  windowServo.attach(SERVO_PIN);
  windowServo.write(0); // Servo closed initially
}

void loop() {
  int hazardCount = 0;

  // --- MQ2 Sensor ---
  int mq2Value = analogRead(MQ2_PIN);
  bool mq2Hazard = mq2Value > mq2Threshold;
  if (mq2Hazard) hazardCount++;

  // --- Flame Sensor ---
  int flameValue = digitalRead(FLAME_PIN);
  bool flameHazard = (flameValue == LOW);  // LOW = flame detected
  if (flameHazard) hazardCount++;

  // --- DHT11 Sensor ---
  float temperature = dht.readTemperature(); // Celsius
  bool tempHazard = false;
  if (!isnan(temperature)) {
    tempHazard = (temperature > tempThreshold);
    if (tempHazard) hazardCount++;
  }

  // --- Print sensor values ---
  Serial.print("MQ2: "); Serial.print(mq2Value); Serial.print(mq2Hazard ? " (Hazard) | " : " (Safe) | ");
  Serial.print("Flame: "); Serial.print(flameHazard ? "Hazard | " : "Safe | ");
  Serial.print("Temp: ");
  if (!isnan(temperature)) {
    Serial.print(temperature); Serial.print("°C "); Serial.println(tempHazard ? "(Hazard)" : "(Safe)");
  } else Serial.println("Error Reading DHT11");

  // --- Overall hazard check ---
  if (hazardCount >= 2) {
    Serial.println("🚨 Multiple Hazards Detected! Activating LED, Buzzer, Fan, Servo");
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(RELAY_PIN, LOW);  // Fan ON (active LOW)
    windowServo.write(90);          // Open servo window
  } else {
    Serial.println("✅ Safe");
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(RELAY_PIN, HIGH); // Fan OFF
    windowServo.write(0);           // Close servo window
  }

  Serial.println("-----------------------------");
  delay(2000); // 2-second delay
}