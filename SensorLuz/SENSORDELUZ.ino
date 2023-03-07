#define LIGHT_SENSOR_PIN 0 // ESP32 pin GIOP36 (ADC0)

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog Value = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 40) {
    Serial.println(" => Deslumbrante");
  } else if (analogValue < 800) {
    Serial.println(" => Brillante");
  } else if (analogValue < 2000) {
    Serial.println(" => Luz normal");
  } else if (analogValue < 3200) {
    Serial.println(" => Poca luz");
  } else {
    Serial.println(" => Oscuro");
  }

  delay(500);
}