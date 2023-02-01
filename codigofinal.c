#include <NewPing.h>

#define LONG_VIBRATION_TIME 200   //Definir vibração longa em millisegundos
#define SMALL_VIBRATION_TIME 100  // Tempo de vibração curta em milissegundos
#define DEFAULT_WAIT_TIME 150     // Tempo padrão de espera entre vibrações em milissegundos

#define MEDIAN_TIMES 1
#define MAX_DISTANCE 400

//Definir as variáveis para o sensor esquerdo
#define TRIGGERE_PIN 4  // Definir o pino trig para o sensor esquerdo
#define ECHOE_PIN 3     // Definir o pino echo para o sensor esquerdo

NewPing sonarE(TRIGGERE_PIN, ECHOE_PIN, MAX_DISTANCE);  // Configuração do NewPing, dos pinos e a max distancia para o sensor da Esq

//Definir as varáveis para o sensor frontal
#define TRIGGERF_PIN 11  // Definir o pino trig para o sensor frontal
#define ECHOF_PIN 10     // Definir o pino echo para o sensor frontal

NewPing sonarF(TRIGGERF_PIN, ECHOF_PIN, MAX_DISTANCE);  // Configuração do NewPing, dos pinos e a max distancia para o sensor da Frnt

//Definir as variéveis para o sensor direito
#define TRIGGERD_PIN 9  // Definir o pino trig para o sensor direito
#define ECHOD_PIN 12
  // Definir o pino echo para o sensor direito

NewPing sonarD(TRIGGERD_PIN, ECHOD_PIN, MAX_DISTANCE);  // Configuração do NewPing, dos pinos e a max distancia para o sensor da Dir

int sensorE;
int sensorF;
int sensorD;
int decideQuadrante();
int quadranteDecidido;

const int motorPin = 6;          // Pin do motor de vibração
unsigned long OneSTimer;         // Armazena o valor de tempo quando a primeira vibração foi iniciada
unsigned long currentOneSTimer;  // Armazena o valor de tempo atual
int counter;                     // Contador de vibrações
int delayCounter;                // Tempo de espera entre cada vibração

void vibrationDecode(int quadrante);                                  //  Função para descodificar o quadrante e inicia a vibração correspondente
void vibrate(int first, int second, int third = -1, int forth = -1);  // Função que realiza a vibração com base nos argumentos passados

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);  // Configura o pino do vibrador como saída
  OneSTimer = millis();       // Inicializa o contador de tempo com o valor atual em milissegundos
  counter = 0;                // Inicializa o contador de vibrações como 0
  delayCounter = 0;           // Inicializa o contador de espera como 0
  quadranteDecidido = 11;     // Descodifica o quadrante ... e inicia a vibração correspondente
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<INICIO DO LOOP>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void loop() {
  currentOneSTimer = millis();         // Atualiza o valor do currentOneSTimer a cada interação do loop
  vibrationDecode(quadranteDecidido);  // Descodifica o quadrante ... e inicia a vibração correspondente
  sensorE = sonarE.convert_cm(sonarE.ping_median(MEDIAN_TIMES));
  sensorF = sonarF.convert_cm(sonarF.ping_median(MEDIAN_TIMES));
  sensorD = sonarD.convert_cm(sonarD.ping_median(MEDIAN_TIMES));
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<FIM DO LOOP>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int decideQuadrante() {

  //Verificar se a leitura do sensorE é 0 e defini-lo como 400 se for
  if (sensorE == 0) {
    sensorE = 400;
  }
  
  //Verificar se a leitura do sensorD é 0 e defini-lo como 400 se for
  if (sensorD == 0) {
    sensorD = 400;
  }
  
  //Verificar se a leitura do sensorF é 0 e defini-lo como 400 se for
  if (sensorF == 0) {
    sensorF = 400;
  }
  
  //Criar variáveis para armazenar as leituras dos sensores
  int E = sensorE;
  int EF = (sensorE + sensorF) / 2;
  int DF = (sensorD + sensorF) / 2;
  int D = sensorD;
  
  //Variável para armazenar a leitura do sensor mais baixa
  int lowest = 400;
  //Variável para armazenar a fatia do quadrante
  int slice = 0;
  
  //Verificar se E é a leitura mais baixa e armazenar a fatia na variável
  if (E < lowest) {
    lowest = E;
    slice = 10;
  }
  
  //Verificar se EF é a leitura mais baixa e armazenar a fatia na variável
  if (EF < lowest) {
    lowest = EF;
    slice = 20;
  }
  
  //Verificar se DF é a leitura mais baixa e armazenar a fatia na variável
  if (DF < lowest) {
    lowest = DF;
    slice = 30;
  }
  
  //Verificar se D é a leitura mais baixa e armazenar a fatia na variável
  if (D < lowest) {
    lowest = D;
    slice = 40;
  }
  
  //Verificar o intervalo da leitura mais baixa e adicionar o número correspondente a fatia
  if (lowest < 80) {
    slice += 1;
  } else if (lowest < 120) {
    slice += 2;
  } else if (lowest < 180) {
    slice += 3;
  } else {
    slice = 44;
  }

  return slice;
}

void vibrationDecode(int quadrante) {  // Descodifica o quadrante e inicia a vibração correspondente
  switch (quadrante) {
    // Limite
    case 11:
      vibrate(1, 1);  // Vibração longa, longa
      break;
    case 21:
      vibrate(1, 0);  // Vibração longa, curta
      break;
    case 31:
      vibrate(0, 1);  // Vibração curta, longa
      break;
    case 41:
      vibrate(0, 0);  // Vibração curta, curta
      break;
    // Segurança
    case 12:
      vibrate(1, 1, 0);  // Vibração longa, longa, curta
      break;
    case 22:
      vibrate(1, 0, 0);  // Vibração longa, curta, curta
      break;
    case 32:
      vibrate(0, 0, 1);  // Vibração curta, curta, longa
      break;
    case 42:
      vibrate(0, 1, 1);  // Vibração curta, longa, longa
      break;
    // Guarda
    case 13:
      vibrate(1, 1, 1, 0);  // Vibração longa, longa, longa, curta
      break;
    case 23:
      vibrate(1, 1, 0, 0);  // Vibração longa, longa, curta, curta
      break;
    case 33:
      vibrate(0, 0, 1, 1);  // Vibração curta, curta, longa, longa
      break;
    case 43:
      vibrate(0, 1, 1, 1);  // Vibração curta, longa, longa, longa
      break;
    case 44:
      vibrate(0, -1);  // Vibração curta, longa, longa, longa
      break;
    default:  // Não Reconhecido
      break;
  }
}

void vibrate(int first, int second, int third = -1, int forth = -1) {  //Função para vibrar o motor

  if (counter == 0) { // Verifica o valor da variavel counter
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

  // Verifica se a diferença entre `currentOneSTimer` e `OneSTimer` é maior ou igual a `delayCounter`
  // e se o valor de `counter` é igual a 1
  if ((currentOneSTimer - OneSTimer >= delayCounter) && (counter == 1)) {
    switch (second) {             // Verifica o valor de `second`
      case 0:                     // Small Vibration
        smallVibration();
        break;
      case 1:                    // Long Vibration
        longVibration();
        break;
      default:                   // Não Reconhecido
        break;
    }
  }
  // Verifica se a diferença entre `currentOneSTimer` e `OneSTimer` é maior ou igual a `delayCounter`
  // e se o valor de `counter` é igual a 2
  if ((currentOneSTimer - OneSTimer >= delayCounter) && (counter == 2)) {
    switch (third) {          // Verifica o valor de `third`
      case 0:                 // Small Vibration
        smallVibration();
        break;
      case 1:                 // Long Vibration
        longVibration();
        break;
      default:                // Não Reconhecido
        counter++;
        break;
    }
  }
  // Verifica se a diferença entre `currentOneSTimer` e `OneSTimer` é maior ou igual a `delayCounter`
  // e se o valor de `counter` é igual a 3
  if ((currentOneSTimer - OneSTimer >= delayCounter) && (counter == 3)) {
    switch (forth) { // Verifica o valor de `forth`
      case 0:  // Small Vibration
        smallVibration();
        break;
      case 1:  // Long Vibration
        longVibration();
        break;
      default:  // Não Reconhecido
        counter++; //Adiciona mais 1 á variável
        break;
    }
  }
  
// Verifica se a diferença entre `currentOneSTimer` e `OneSTimer` é maior ou igual a 2000
  if (currentOneSTimer - OneSTimer >= 2000) {
    counter = 0;  // Reseta o valor de `counter` para 0
    delayCounter = 0;
    
    
    Serial.println("===============");
    Serial.println("reset");
    quadranteDecidido = decideQuadrante();
    Serial.print("Quadrante: ");
    Serial.println(quadranteDecidido);
    Serial.print("Esquerda: ");
    Serial.println(sensorE);
    Serial.print("Frente: ");
    Serial.println(sensorF);
    Serial.print("Direita: ");
    Serial.println(sensorD);
    Serial.print("Timer: ");
    Serial.println(currentOneSTimer - OneSTimer);
    OneSTimer = currentOneSTimer;
  }
}

void smallVibration() {
  
  // Toca uma frequência 1000 Hz no  motor
  tone(motorPin, 1000, SMALL_VIBRATION_TIME);
  // Acrescenta um ao contador
  counter++;
  // Acrescenta o delayCounter pela soma de SMALL_VIBRATION_TIME e DEFAULT_WAIT_TIME
  delayCounter += SMALL_VIBRATION_TIME + DEFAULT_WAIT_TIME;
}

void longVibration() {
  // Toca uma frequência 1000 Hz no  motor
  tone(motorPin, 1000, LONG_VIBRATION_TIME);
  // Acrescenta um ao contador
  counter++;
  // Acrescenta o delayCounter pela soma de LONG_VIBRATION_TIME e DEFAULT_WAIT_TIME
  delayCounter += LONG_VIBRATION_TIME + DEFAULT_WAIT_TIME;
}
