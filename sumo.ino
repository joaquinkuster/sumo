// || VARIABLES ||
// MOTOR 1
int IN1 = 8;
int IN2 = 7;
int ENA = 9;
// MOTOR 2
int IN3 = 6;
int IN4 = 4;
int ENB = 5;
// MOTOR 3
int IN5 = A1;
int IN6 = A2;
int ENC = 10;
// MOTOR 4
int IN7 = A3;
int IN8 = A4;
int END = 11;

// INFRAROJOS
int SENSOR1 = 2;
int SENSOR2 = 3;

// SENSOR ULTRASONICO 
int ECO = 12;
int TRIG = 13;  
// OBSTACULO
boolean ACTUAL=HIGH;
//_____________________


// || SETUP ||
void setup() {
  // ESPERAR 3 SEG.
  delay(2500);

  // MOTORES (RUEDAS)
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(END, OUTPUT);

  // INFRAROJOS
  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);

  // SENSOR ULTRASONICO
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);

  Serial.begin(9600);
}
//_____________________


// || LOOP ||
void loop() {
  Serial.println(digitalRead(SENSOR2));
}
//_____________________


// || FUNCIONES ||
  
// || DETECCION ||
boolean  deteccion(){
  // VARIABLES
  long duracion = 0;
  int distancia = 0;

  int suma = 0;
  int divisor = 0;

  // DETECTAMOS SI HAY ALGUIEN CERCA
  for (int i = 0; i < 5; i = i + 1) {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(4);
    digitalWrite(TRIG, HIGH);
    
    delay(1);
    
    digitalWrite(TRIG, LOW);
    
    duracion = pulseIn(ECO, HIGH);
    distancia = duracion / 58.2;

    // CALCULAMOS DISTANCIA
    if(distancia > 0 && distancia < 350){
      suma = suma + distancia;
      divisor++;
    }
  }

  // RETORNAMOS SI DETECTO ALGO O NO
  if((suma /divisor) < 95 && (suma /divisor)> 0 ){
    return HIGH;
  }else{
    return LOW;
  }
}
//_____________________


// || AVANZAR || 
void avanzar(int VELOC){
  // ASIGNAMOS VELOCIDAD A C/ MOTOR
  motorDerechoDelanteroAvanzar(VELOC);
  motorIzquierdoDelanteroAvanzar(VELOC);
  motorDerechoTraseroAvanzar(VELOC);
  motorIzquierdoTraseroAvanzar(VELOC);
}
//_____________________


// || RETROCEDER || 
void retroceder(int VELOC){
  // ASIGNAMOS VELOCIDAD A C/ MOTOR
  motorDerechoDelanteroRetroceder(VELOC);
  motorIzquierdoDelanteroRetroceder(VELOC);
  motorDerechoTraseroRetroceder(VELOC);
  motorIzquierdoTraseroRetroceder(VELOC);
}
//_____________________


// || GIRAR DERECHA || 
void girarDerecha(int VELOC){
  // ASIGNAMOS VELOCIDAD A C/ MOTOR
  motorDerechoDelanteroRetroceder(VELOC);
  motorDerechoTraseroRetroceder(VELOC);
  motorIzquierdoDelanteroAvanzar(VELOC);
  motorIzquierdoTraseroAvanzar(VELOC);  
}
//_____________________


// || GIRAR IZQUIERDA || 
void girarIzquierda(int VELOC){
  // ASIGNAMOS VELOCIDAD A C/ MOTOR
  motorDerechoDelanteroAvanzar(VELOC);
  motorDerechoTraseroAvanzar(VELOC);
  motorIzquierdoDelanteroRetroceder(VELOC);
  motorIzquierdoTraseroRetroceder(VELOC);
}
//_____________________


// || MOTOR DELANTERO DERECHO (AVANZAR) || 
void motorDerechoDelanteroAvanzar(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(ENA, VELOC);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
//_____________________
// || MOTOR DELANTERO DERECHO (RETROCEDER) || 
void motorDerechoDelanteroRetroceder(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(ENA, VELOC);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}
//_____________________


// || MOTOR DELANTERO IZQUIERDO (AVANZAR) || 
void motorIzquierdoDelanteroAvanzar(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(ENB, VELOC);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
//_____________________
// || MOTOR DELANTERO IZQUIERDO (RETROCEDER) || 
void motorIzquierdoDelanteroRetroceder(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(ENB, VELOC);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
//_____________________


// || MOTOR TRASERO DERECHO (AVANZAR) || 
void motorDerechoTraseroAvanzar(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(END, VELOC);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}
//_____________________
// || MOTOR TRASERO DERECHO (RETROCEDER) || 
void motorDerechoTraseroRetroceder(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(END, VELOC);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}
//_____________________


// || MOTOR TRASERO IZQUIERDO (AVANZAR) || 
void motorIzquierdoTraseroAvanzar(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(ENC, VELOC);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
}
//_____________________
// || MOTOR TRASERO IZQUIERDO (RETROCEDER) || 
void motorIzquierdoTraseroRetroceder(int VELOC){
  // ASIGNAMOS VELOCIDAD AL MOTOR
  analogWrite(ENC, VELOC);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
}
