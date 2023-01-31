const int motorPin = 11;  // Pin do motor de vibração
unsigned long OneSTimer;
unsigned long currentOneSTimer;
unsigned long firstTimer;
unsigned long firstCurrentTimer;
unsigned long secondTimer;
unsigned long secondCurrentTimer;
unsigned long thirdTimer;
unsigned long thirdCurrentTimer;
unsigned long fourthTimer;
unsigned long fourthCurrentTimer;
int counter;

void setup() {
  pinMode(motorPin, OUTPUT);  // Configura o pino como saída
  OneSTimer = millis();
  counter = 0;
  Serial.begin(9600);
}

void loop() {
  currentOneSTimer = millis();
  //quadrante11();
  //quadrante12();
  //quadrante13();
  //quadrante21();
  //quadrante22();
  //quadrante23();
  //quadrante31();
  //quadrante32();
  //quadrante33();
  //quadrante41();
  //quadrante42();
  //quadrante43();
}

void quadrante11() {
  if (counter == 0) {
    longVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 250) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante12() {
  if (counter == 0) {
    longVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 250) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 500) && (counter == 2)) {
    smallVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }


  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante13() {
  if (counter == 0) {
    longVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 250) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 500) && (counter == 2)) {
    longVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 750) && (counter == 3)) {
    smallVibration();
    counter = 4;
    Serial.println("4");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante21() {
  if (counter == 0) {
    longVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 250) && (counter == 1)) {
    smallVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante22() {
  if (counter == 0) {
    longVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 250) && (counter == 1)) {
    smallVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 450) && (counter == 2)) {
    smallVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante23() {
  if (counter == 0) {
    longVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 250) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 500) && (counter == 2)) {
    smallVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 700) && (counter == 3)) {
    smallVibration();
    counter = 4;
    Serial.println("4");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante31() {
  if (counter == 0) {
    smallVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 200) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante32() {
  if (counter == 0) {
    smallVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 200) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 450) && (counter == 2)) {
    longVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante33() {
  if (counter == 0) {
    smallVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 200) && (counter == 1)) {
    smallVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 400) && (counter == 2)) {
    longVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 650) && (counter == 3)) {
    longVibration();
    counter = 4;
    Serial.println("4");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante41() {
  if (counter == 0) {
    smallVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 200) && (counter == 1)) {
    smallVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante42() {
  if (counter == 0) {
    smallVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 200) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 450) && (counter == 2)) {
    longVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void quadrante43() {
  if (counter == 0) {
    smallVibration();
    counter = 1;
    Serial.println("1");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 200) && (counter == 1)) {
    longVibration();
    counter = 2;
    Serial.println("2");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 450) && (counter == 2)) {
    longVibration();
    counter = 3;
    Serial.println("3");
    Serial.println(currentOneSTimer);
  }

  if ((currentOneSTimer - OneSTimer >= 700) && (counter == 3)) {
    longVibration();
    counter = 4;
    Serial.println("4");
    Serial.println(currentOneSTimer);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void smallVibration() {
  tone(motorPin, 1000, 100);
}

void longVibration() {
  tone(motorPin, 1000, 150);
}
