//Definir pinos do speaker e do acelerometro
const int speakerPin = 8; 
const int xPin = A0; 
const int yPin = A1; 
const int zPin = A2; 

const int unwantedAngle = 45; // Definir o angulo indesejado, em graus
const int beepDuration = 100; // Definir a duração dos bips em milisegundos
const int beepPause = 50; // Definir a pausa entre bips em milisegundos
const int beepCount = 5; // o numero de bips que da

void setup() {
  // iniciar o pino do speaker como output
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // ler o valor de x,y,z do acelerometro 
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int z = analogRead(zPin);

  // calcular o angulo a partir dos valores x,y e z
  float angle = atan2(y, x) * 180 / PI;

  // ver se o angulo é indesejado
  if (abs(angle) > unwantedAngle) {
    // dar uns bips para alertar o utilizador
    for (int i = 0; i < beepCount; i++) {
      digitalWrite(speakerPin, HIGH);
      delay(beepDuration);
      digitalWrite(speakerPin, LOW);
      delay(beepPause);
    }
  }
}
