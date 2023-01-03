#define echoPin 2 
#define trigPin 3 



// definir as variáveis para os sensor e motor esquerdo
const int trigSLPin = 12;
const int echoSLPin = 13;
const int VLPin = 11;

// definir variáveis para os sensor e motor da frente

const int trigSFPin = 7;
const int echoSFPin = 8;
const int VFPin = 10;

// definir variáveis para o sensor e motor direito

const int trigSRPin = 2;
const int echoSRPin = 4;
const int VRPin = 9;

long durationSL;
long durationSF;
long durationSR;
float distanceCmSL;
float distanceCmSF; 
float distanceCmSR; 

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>SETUP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void setup()
{
  pinMode(trigSLPin, OUTPUT); 
  pinMode(echoSLPin, INPUT);
  pinMode(VLPin, OUTPUT);
  digitalWrite(VLPin, LOW);
  
  pinMode(trigSFPin, OUTPUT);
  pinMode(echoSFPin, INPUT);
  pinMode(VFPin, OUTPUT);
  digitalWrite(VFPin, LOW);
  
  pinMode(trigSRPin, OUTPUT);
  pinMode(echoSRPin, INPUT);
  pinMode(VRPin, OUTPUT);
  digitalWrite(VRPin, LOW);
  
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LOOP<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void loop() 
{
  
  digitalWrite(trigSLPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigSLPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigSLPin, LOW);
  durationSL = pulseIn(echoSLPin, HIGH);
  
  distanceCmSL = durationSL * 0.034 / 2;
  
  digitalWrite(trigSFPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigSFPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigSFPin, LOW);
  durationSF = pulseIn(echoSFPin, HIGH);
  
  distanceCmSF = durationSF * 0.034 / 2;

  digitalWrite(trigSRPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigSRPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigSRPin, LOW);
  durationSR = pulseIn(echoSRPin, HIGH);
   
  distanceCmSR = durationSR * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distanceCmSL);
  Serial.println(distanceCmSF);
  Serial.println(distanceCmSR);
  Serial.println(" cm");
  
//>>>>>>>>>>>>>>>ESQUERDA<<<<<<<<<<<<<<<
  
  if ( distanceCmSL < 300)
  {
    digitalWrite(VLPin, HIGH);
        digitalWrite(3,HIGH);

  }
  
  else
  {
    digitalWrite(VLPin, LOW);
        digitalWrite(3,LOW);

  }
  
//>>>>>>>>>>>>>>>FRENTE<<<<<<<<<<<<<<<
  
  if ( distanceCmSF < 300)
  {
    digitalWrite(VFPin, HIGH);
    digitalWrite(5,HIGH);
  }
  
  else
  {
    digitalWrite(VFPin, LOW);
        digitalWrite(5,LOW);

  }
    
//>>>>>>>>>>>>>>>DIREITA<<<<<<<<<<<<<<<
  
  if ( distanceCmSR < 300)
  {
    digitalWrite(VRPin, HIGH);
        digitalWrite(6,HIGH);
  }
  
  else
  {
    digitalWrite(VRPin, LOW);
    digitalWrite(6,LOW);
  }
  
}



