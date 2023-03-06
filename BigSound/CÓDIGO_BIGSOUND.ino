int led = 6;
int sound_digital = 7;
int sound_analog = A0;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sound_digital, INPUT);  
}

void loop(){
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);

  Serial.print(val_analog);
  Serial.print("\t");
  Serial.println(val_digital);

  if (val_digital == HIGH)
  {
    digitalWrite (led, HIGH);
    delay(3000);
    }
  else
  {
    digitalWrite (led, LOW);
    }
}