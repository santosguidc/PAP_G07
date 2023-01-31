#define LONG_VIBRATION_TIME 150 //Definir vibração longa em millisegundos
#define SMALL_VIBRATION_TIME 100 // Tempo de vibração curta em milissegundos
#define DEFAULT_WAIT_TIME 100  // Tempo padrão de espera entre vibrações em milissegundos

#define MEDIAN_TIMES 5
#define MAX_DISTANCE 400

//Definir as variáveis para o sensor esquerdo
#define TRIGGERE_PIN 4  // Definir o pino trig para o sensor esquerdo
#define ECHOE_PIN 3    // Definir o pino echo para o sensor esquerdo

NewPing sonarE(TRIGGERE_PIN, ECHOE_PIN, MAX_DISTANCE);  // Configuração do NewPing, dos pinos e a max distancia para o sensor da Esq

//Definir as varáveis para o sensor frontal
#define TRIGGERF_PIN 11  // Definir o pino trig para o sensor frontal
#define ECHOF_PIN 10     // Definir o pino echo para o sensor frontal

NewPing sonarF(TRIGGERF_PIN, ECHOF_PIN, MAX_DISTANCE);  // Configuração do NewPing, dos pinos e a max distancia para o sensor da Frnt

//Definir as variéveis para o sensor direito
#define TRIGGERD_PIN 9  // Definir o pino trig para o sensor direito
#define ECHOD_PIN 8
     // Definir o pino echo para o sensor direito

NewPing sonarD(TRIGGERD_PIN, ECHOD_PIN, MAX_DISTANCE);  // Configuração do NewPing, dos pinos e a max distancia para o sensor da Dir

int sensorE;
int sensorF;
int sensorD;
int decideQuadrante();

const int motorPin = 6;  // Pin do motor de vibração
unsigned long OneSTimer; // Armazena o valor de tempo quando a primeira vibração foi iniciada
unsigned long currentOneSTimer; // Armazena o valor de tempo atual
int counter; // Contador de vibrações
int delayCounter; // Tempo de espera entre cada vibração

void vibrationDecode(int quadrante);  //  Função para descodificar o quadrante e inicia a vibração correspondente
void vibrate(int first, int second, int third = -1, int forth = -1); // Função que realiza a vibração com base nos argumentos passados

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);  // Configura o pino do vibrador como saída
  OneSTimer = millis(); // Inicializa o contador de tempo com o valor atual em milissegundos
  counter = 0; // Inicializa o contador de vibrações como 0
  delayCounter = 0; // Inicializa o contador de espera como 0
}

void loop() {
  sensorE = sonarE.convert_cm(sonarE.ping_median(MEDIAN_TIMES));

  sensorF = sonarF.convert_cm(sonarF.ping_median(MEDIAN_TIMES));

  sensorD = sonarD.convert_cm(sonarD.ping_median(MEDIAN_TIMES));

  currentOneSTimer = millis(); // Atualiza o valor do currentOneSTimer a cada interação do loop
  vibrationDecode(43); // Descodifica o quadrante ... e inicia a vibração correspondente

}

int decideQuadrante() {
  int E = sensorE;
  int EF = (sensorE + sensorF) / 2;
  int DF = (sensorD + sensorF) / 2;
  int D = sensorD;

  int lowest = 400;
  int slice = 0;

  if (E < lowest) {
    lowest = E;
    slice = 10;
  }
  if (EF < lowest) {
    lowest = EF;
    slice = 20;
  }
  if (DF < lowest) {
    lowest = DF;
    slice = 30;
  }
  if (D < lowest) {
    lowest = D;
    slice = 40;
  }

  if (lowest < 80) {
    slice += 1;
  } else if (lowest < 120) {
    slice += 2;
  } else if (lowest < 180) {
    slice += 3;
  }

  return slice;
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
    decideQuadrante();
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
