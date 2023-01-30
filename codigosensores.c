#include <NewPing.h>
#include <Ultrasonic.h>

#define MAX_DISTANCE 400

//Definir as variáveis para o sensor esquerdo
#define TRIGGERE_PIN 9  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHOE_PIN 10    // Arduino pin tied to echo pin on the ultrasonic sensor.

NewPing sonarE(TRIGGERE_PIN, ECHOE_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.

//Definir as varáveis para o sensor frontal
#define TRIGGERF_PIN 7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHOF_PIN 8     // Arduino pin tied to echo pin on the ultrasonic sensor.

NewPing sonarF(TRIGGERF_PIN, ECHOF_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.

//Definir as variéveis para o sensor direito
#define TRIGGERD_PIN 2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHOD_PIN 3     // Arduino pin tied to echo pin on the ultrasonic sensor.

NewPing sonarD(TRIGGERD_PIN, ECHOD_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.

//Definir as variáveis para o motor de vibração
const int vibrationmotor = 11;

int tempvibrar = 150;  // 150ms
int tempHzvib0 = 6000;
int tempHzvib1 = 4000;
int tempHzvib2 = 2600;
int tempHzvib3 = 1800;

int nvibQ1 = 6;  //numero de vibrações do Q1
int nvibQ2 = 4;  //numero de vibrações do Q2
int nvibQ3 = 2;  //numero de vibrações do Q3
int nvibQ4 = 1;  //numero de vibraçoes do Q4

int guarda = 160;
int segura = 120;
int limite = 80;

void lerDfrnt();
void lerDesq();
void lerDdir();
long duration, distance;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>INICIO DO SETUP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void setup() {
  Serial.begin(9600);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>INICIO DO LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void loop() {

  delay(500);  // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.println("=====================");
  Serial.print("PingE: ");
  Serial.print(sonarE.ping_cm());  // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  Serial.print("PingF: ");
  Serial.print(sonarF.ping_cm());  // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  Serial.print("PingD: ");
    Serial.print(sonarD.ping_cm());  // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
