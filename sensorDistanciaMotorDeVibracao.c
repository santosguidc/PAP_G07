//Definir os pinos dos sensores
#define TRIG_LEFT 8
#define ECHO_LEFT 9
#define TRIG_FRONT 10
#define ECHO_FRONT 11
#define TRIG_RIGHT 12
#define ECHO_RIGHT 13

//Definir o pino do motor de vibração
#define VIBRATION_MOTOR 7

//Definir a distância máxima
#define MAX_DISTANCE 200

//Definir as distâncias
#define DISTANCE_80CM 80
#define DISTANCE_1_2M 120
#define DISTANCE_1_6M 160

//Definir as vibrações
#define VIBRATION_COUNT6 6
#define VIBRATION_COUNT4 4
#define VIBRATION_COUNT2 2
#define VIBRATION_COUNT1 1

//Definir as frequências
#define FREQ_3HZ 3
#define FREQ_2HZ 2
#define FREQ_1HZ 1

void setup() {
  //Definir os input e output
  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);
  pinMode(VIBRATION_MOTOR, OUTPUT);
}

//Função para calcular a distância
long measure_distance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  long distance = (duration / 2) / 29.1;

  return distance;
}

//Função para vibrar caso a distancia seja menor que G/S/L
void vibrate(int freq, int count) {
  for (int i = 0; i < count; i++) {
    tone(VIBRATION_MOTOR, freq);
    delay(500);
    noTone(VIBRATION_MOTOR);
    delay(500);
  }
}

void loop() {
  
  
  // 1 Situação
  int left_distance = measure_distance(TRIG_LEFT, ECHO_LEFT);
  int front_distance = measure_distance(TRIG_FRONT, ECHO_FRONT);
  if (left_distance < DISTANCE_80CM && front_distance < DISTANCE_80CM) {
    vibrate(FREQ_3HZ, VIBRATION_COUNT6);
  }
  else if (left_distance < DISTANCE_1_2M && front_distance < DISTANCE_1_2M) {
    vibrate(FREQ_2HZ, VIBRATION_COUNT6);
  }
  else if (left_distance < DISTANCE_1_6M && front_distance < DISTANCE_1_6M) {
    vibrate(FREQ_1HZ, VIBRATION_COUNT6);
  }

}
