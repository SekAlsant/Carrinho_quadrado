int trigPin = 7; 
int echoPin = 4;
int sensorInfraDir = 8;

int ENA = 3;  
int ENB = 11; 

int IN1 = 5;
int IN2 = 6;
int IN3 = 9;
int IN4 = 10;

int velocidade = 220;      
int velocidadeGiro = 255;  

float tempoPara10cm = 1000; 
int distanciaLado = 20;

int tempoGiro1 = 1275; 
int tempoGiro2 = 1275;
int tempoGiro3 = 1300;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(sensorInfraDir, INPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  delay(2000); 

  andarCentimetros(distanciaLado);
  parar(); delay(500);
  girarDireita(tempoGiro1);
  parar(); delay(500);

  andarCentimetros(distanciaLado);
  parar(); delay(500);
  girarDireita(tempoGiro2);
  parar(); delay(500);

  andarCentimetros(distanciaLado);
  parar(); delay(500);
  girarDireita(tempoGiro3);
  parar(); delay(500);

  andarCentimetros(distanciaLado);
  parar();
}

void loop() {
}

void andarCentimetros(int cm) {
  long tempoNecessario = (cm / 10.0) * tempoPara10cm;
  
  analogWrite(ENA, velocidade); 
  analogWrite(ENB, velocidade);
  
  moverFrente();
  delay(tempoNecessario);
}

void moverFrente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void girarDireita(int tempoDeGiro) {
  analogWrite(ENA, velocidadeGiro); 
  analogWrite(ENB, velocidadeGiro);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  
  delay(tempoDeGiro);
}

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
