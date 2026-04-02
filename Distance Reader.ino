// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const byte trigPin = 6;
const byte echoPin = 5;
const byte green_LED = 4;
const byte yellow_LED = 3;
const byte red_LED = 2;

float duration, distance;

const byte rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int currentLED = -1;

void turnOffLEDS() {
  digitalWrite(red_LED, LOW);
  digitalWrite(yellow_LED, LOW);
  digitalWrite(green_LED, LOW);
}

void setLED(int led) {
  if (led != currentLED) {
    turnOffLEDS();
    digitalWrite(led, HIGH);
    currentLED = led;
  }
}

void writeToScreen(float d) {
  lcd.setCursor(0, 1);
  lcd.print(d);
  lcd.setCursor(7, 1);
  lcd.print("cm");
}

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);
  return duration / 58;
}

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Distance of Object:");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(green_LED, OUTPUT);
  pinMode(yellow_LED, OUTPUT);
  pinMode(red_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance = (distance + getDistance()) / 2;
  writeToScreen(distance);
  
  if (distance < 10) {
    // Turn off all LED's then turn on only Red LED when object is 
    // 10 cm away.
    setLED(red_LED);
  } else if (distance < 20) {
    // Turn yellow light on when between 20-10 cm
    setLED(yellow_LED);
  } else {
    // If object is more than 20 cm away, turn green light on.
    setLED(green_LED);
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  delay(50);
}
