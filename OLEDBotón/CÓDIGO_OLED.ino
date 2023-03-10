
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define el pin del botón
const int botonPin = 2;

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.display(); 
  
  // Configura el pin del botón como entrada
  pinMode(botonPin, INPUT_PULLUP);
}

void loop() {
  // Espera a que se presione el botón
  while(digitalRead(botonPin) == HIGH);

  // Muestra el mensaje en el display
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("Hola soy Nayeli Moya");
  display.display();
  
  // Espera a que se suelte el botón
  while(digitalRead(botonPin) == LOW);
}