#define LONG_VIBRATION_TIME 150 //Definir vibração longa em millisegundos
#define SMALL_VIBRATION_TIME 100 // Tempo de vibração curta em milissegundos
#define DEFAULT_WAIT_TIME 100  // Tempo padrão de espera entre vibrações em milissegundos

const int motorPin = 11;  // Pin do motor de vibração
unsigned long OneSTimer; // Armazena o valor de tempo quando a primeira vibração foi iniciada
unsigned long currentOneSTimer; // Armazena o valor de tempo atual
int counter; // Contador de vibrações
int delayCounter; // Tempo de espera entre cada vibração


void vibrationDecode(int quadrante); );   //  Função para descodificar o quadrante e inicia a vibração correspondente
void vibrate(int first, int second, int third = -1, int forth = -1); // Função que realiza a vibração com base nos argumentos passados

void setup() {
  pinMode(motorPin, OUTPUT);  // Configura o pino do vibrador como saída
  OneSTimer = millis(); // Inicializa o contador de tempo com o valor atual em milissegundos
  counter = 0; // Inicializa o contador de vibrações como 0
  delayCounter = 0; // Inicializa o contador de espera como 0
  Serial.begin(9600); // Inicializa a comunicação serial com baud rate de 9600
}

void loop() {
  currentOneSTimer = millis(); // Atualiza o valor do currentOneSTimer a cada interação do loop
  vibrationDecode(43); // Descodifica o quadrante ... e inicia a vibração correspondente
  //ping();
}

void vibrationDecode(int quadrante) { // Descodifica o quadrante e inicia a vibração correspondente
  switch (quadrante) {
    // Limite
    case 11:
      vibrate(1, 1); // Vibração longa, longa
      break;
    case 21:
      vibrate(1, 0); // Vibração longa, curta
      break;
    case 31:
      vibrate(0, 1); // Vibração curta, longa
      break;
    case 41:
      vibrate(0, 0); // Vibração curta, curta
      break;
    // Segurança
    case 12:
      vibrate(1, 1, 0); // Vibração longa, longa, curta
      break;
    case 22:
      vibrate(1, 0, 0); // Vibração longa, curta, curta
      break;
    case 32:
      vibrate(0, 0, 1); // Vibração curta, curta, longa
      break;
    case 42:
      vibrate(0, 1, 1); // Vibração curta, longa, longa
      break;
    // Guarda
    case 13:
      vibrate(1, 1, 1, 0); // Vibração longa, longa, longa, curta
      break;
    case 23:
      vibrate(1, 1, 0, 0); // Vibração longa, longa, curta, curta
      break;
    case 33:
      vibrate(0, 0, 1, 1); // Vibração curta, curta, longa, longa
      break;
    case 43:
      vibrate(0, 1, 1, 1); // Vibração curta, longa, longa, longa
      break;
    default:  // Não Reconhecido
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

    // Imprimir para o serial monitor
    Serial.println("===============");
    Serial.println("vibrate First");
    Serial.println(counter);
    Serial.println(delayCounter);
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
    Serial.println("===============");
    Serial.println("vibrate Second");
    Serial.println(counter);
    Serial.println(delayCounter);
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
        counter++;
        break;
    }
    Serial.println("===============");
    Serial.println("vibrate third");
    Serial.println(counter);
    Serial.println(delayCounter);
  }

  if ((currentOneSTimer - OneSTimer >= delayCounter) && (counter == 3)) {
    switch (forth) {
      case 0:  // Small Vibration
        smallVibration();
        break;
      case 1:  // Long Vibration
        longVibration();
        break;
      default:  // Não Reconhecido
        counter++;
        break;
    }
    Serial.println("===============");
    Serial.println("vibrate Forth");
    Serial.println(counter);
    Serial.println(delayCounter);
  }

  if (currentOneSTimer - OneSTimer >= 1000) {
    counter = 0;
    delayCounter = 0;
    Serial.println("===============");
    Serial.println("reset");
    Serial.println(currentOneSTimer);
    OneSTimer = currentOneSTimer;
    //decideQuadrante();
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
