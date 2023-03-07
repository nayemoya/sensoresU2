void setup() {
  ledcSetup(0,15,12);
  ledcAttachPin(2,0);
}

void loop() {
  ledcWriteTone(0,800);
  delay(1000);
  uint8_t octave = 1;
  ledcWriteNote(0,NOTE_C,octave);
  delay(1000);
}
