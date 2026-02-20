#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// LED Pins
#define greenLED 2
#define yellowLED 3
#define redLED 4

// Ultrasonic Pins
#define trigPin 6
#define echoPin 7

// Buzzer
#define buzzer 8

long duration;
float distance;

void setup() {

  Serial.begin(9600);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);

  // OLED Initialization
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  display.clearDisplay();
  display.display();
}

float getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

void showMessage(String msg) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println(msg);
  display.display();
}

void loop() {

  // GREEN LED 
  digitalWrite(greenLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);
  noTone(buzzer);
  delay(10000);

  // YELLOW LED 
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(redLED, LOW);
  noTone(buzzer);
  delay(10000);

  // RED LED 
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  showMessage("RED");

  unsigned long startTime = millis();

  while (millis() - startTime < 10000) {

    float d = getDistance();
    Serial.print("Distance: ");
    Serial.println(d);

    if (d > 0 && d < 10) {

      // Sound buzzer
      tone(buzzer, 1000);

      // OLED Warning
      showMessage("Red Light\nCrossed");

    } else {

      noTone(buzzer);
      showMessage("RED");
    }

    delay(200);
  }

  digitalWrite(redLED, LOW);
}
