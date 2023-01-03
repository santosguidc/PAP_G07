const int speakerPin = 8; // pin for the speaker
const int xPin = A0; // pin for the x-axis of the accelerometer
const int yPin = A1; // pin for the y-axis of the accelerometer
const int zPin = A2; // pin for the z-axis of the accelerometer

const int unwantedAngle = 45; // the unwanted angle threshold, in degrees
const int beepDuration = 100; // the duration of each beep, in milliseconds
const int beepPause = 50; // the pause between each beep, in milliseconds
const int beepCount = 3; // the number of beeps to give

void setup() {
  // initialize the speaker pin as an output
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // read the x, y, and z values from the accelerometer
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int z = analogRead(zPin);

  // calculate the angle from the x, y, and z values
  float angle = atan2(y, x) * 180 / PI;

  // check if the angle is unwanted
  if (abs(angle) > unwantedAngle) {
    // give a few beeps to alert the user
    for (int i = 0; i < beepCount; i++) {
      digitalWrite(speakerPin, HIGH);
      delay(beepDuration);
      digitalWrite(speakerPin, LOW);
      delay(beepPause);
    }
  }
}
