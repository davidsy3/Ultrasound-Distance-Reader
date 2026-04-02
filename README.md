# Ultrasonic-Distance-Reader
My very first Arduino and embedded system project. To deepen my knowledge of robotics and take my passion further, I decided to do this simple project as a good entry point.

## Visuals

![Project Demo](assets/DistanceReader.gif)

## Installation
Go to [Arduino] (https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE) and follow the instructions to download the Arduino IDE.

Refer to the pictures below for wiring setup:

### Circut

<img width="2200" height="1700" alt="Ultrasonic-1" src="https://github.com/user-attachments/assets/30707a7b-403a-4e55-ba30-47c6499562dc" />


### TinkerCad

<img width="1710" height="855" alt="Ultrasonic Distance Reader" src="https://github.com/user-attachments/assets/48e244a3-cd20-4857-ac48-4e7d56fc28e3" />

### Requirements

<table>
    <tr>
        <td>Name</td>
        <td>Quantity</td>
        <td>Component</td>
    </tr>
    <tr>
        <td>U1</td>
        <td>1</td>
        <td> Arduino Uno R3</td>
    </tr>
    <tr>
        <td>U2</td>
        <td>1</td>
        <td> LCD 16 x 2</td>
    </tr>
    <tr>
        <td>R1, R2, R3, R4</td>
        <td>4</td>
        <td>220 Ω Resistor</td>
    </tr>
    <tr>
        <td>Rpot2</td>
        <td>1</td>
        <td>10000 Ω Potentiometer</td>
    </tr>
    <tr>
        <td>D1</td>
        <td>1</td>
        <td>Green LED</td>
    </tr>
    <tr>
        <td>D2</td>
        <td>1</td>
        <td>Yellow LED</td>
    </tr>
    <tr>
        <td>D3</td>
        <td>1</td>
        <td>Red LED</td>
    </tr>
    <tr>
        <td>DIST1</td>
        <td>1</td>
        <td> Ultrasonic Distance Sensor (4-pin)</td>
    </tr>
</table>

## Usage

```c
// Include the library code for LCD Screen
#include <LiquidCrystal.h>

// Turn off all LED's
void turnOffLEDS() {
  digitalWrite(red_LED, LOW);
  digitalWrite(yellow_LED, LOW);
  digitalWrite(green_LED, LOW);
}

// If the LED isn't set, turn off all LED's and turn it on and set to currentLED
void setLED(int led) {
  if (led != currentLED) {
    turnOffLEDS();
    digitalWrite(led, HIGH);
    currentLED = led;
  }
}

// Write to specific line and character to LCD screen
void writeToScreen(float d) {
  lcd.setCursor(0, 1);
  lcd.print(d);
  lcd.setCursor(7, 1);
  lcd.print("cm");
}

// Obtain distance from ultrasonic sensor
long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);
  return duration / 58;
}
```

## Contributing

Pull requests are welcome. Please star this repo if you found it helpful. 

If you use this in your own project update the code with the correct pins.
