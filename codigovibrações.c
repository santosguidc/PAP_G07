#define LONG_VIBRATION_TIME 150
#define SMALL_VIBRATION_TIME 100
#define DEFAULT_WAIT_TIME 100

const int motorPin = 11;  // Pin do motor de vibração
unsigned long OneSTimer;
unsigned long currentOneSTimer;
int counter;
int delayCounter;

void setup() {
  pinMode(motorPin, OUTPUT);  // Configura o pino do vibrador como saída
  OneSTimer = millis();
  counter = 0;
  delayCounter = 0;
  Serial.begin(9600);
}

void loop() {
  currentOneSTimer = millis();
  vibrationDecode(13);
}

void vibrationDecode(int quadrante) {
  switch (quadrante) {
    //Limite
    case 11:
      vibrate(1, 1);
      break;
    case 21:
      vibrate(1, 0);
      break;
    case 31:
      vibrate(0, 1);
      break;
    case 41:
      vibrate(0, 0);
      break;
    //Segurança
    case 12:
      vibrate(1, 1, 0);
      break;
    case 22:
      vibrate(1, 0, 0);
      break;
    case 32:
      vibrate(0, 0, 1);
      break;
    case 42:
      vibrate(0, 1, 1);
      break;
    //Guarda
    case 13:
      vibrate(1, 1, 1, 0);
      break;
    case 23:
      vibrate(1, 1, 0, 0);
      break;
    case 33:
      vibrate(0, 0, 1, 1);
      break;
    case 43:
      vibrate(0, 1, 1, 1);
      break;
    default:  //Não Reconhecido
      break;
  }
}

void vibrate(int first, int second, int third = -1, int forth = -1) {

  if (counter == 0) {
    switch (first) {
      case 0:  // Small Vibration
        smallVibration();
        break;
      case 1:  // Long Vibration
        longVibration();
        break;
      default:  // Não Reconhecido
        break;
    }
  }

  if ((currentOneSTimer - OneSTimer >= delayCounter) && (counter == 1)) {
    switch (second) {
      case 0:  // Small Vibration
        smallVibration();
        break;
      case 1:  // Long Vibration
        longVibration();
        break;
      default:  // Não Reconhecido
        break;
    }
  }

  if ((currentOneSTimer - OneSTimer >= delayCounter) && (counter == 2)) {
    switch (third) {
      case 0:  // Small Vibration
        smallVibration();
        break;
      case 1:  // Long Vibration
        longVibration();
        break;
      default:  // Não Reconhecido
        break;
    }
  }

  switch ((currentOneSTimer - OneSTimer >= delayCounter) && (counter == 3)) {
    case 0:  // Small Vibration
      smallVibration();
      break;
    case 1:  // Long Vibration
      longVibration();
      break;
    default:  // Não Reconhecido
      break;
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void smallVibration() {
  tone(motorPin, 1000, SMALL_VIBRATION_TIME);
  counter++;
  delayCounter += SMALL_VIBRATION_TIME + DEFAULT_WAIT_TIME;
}

void longVibration() {
  tone(motorPin, 1000, LONG_VIBRATION_TIME);
  counter++;
  delayCounter += LONG_VIBRATION_TIME + DEFAULT_WAIT_TIME;
}
