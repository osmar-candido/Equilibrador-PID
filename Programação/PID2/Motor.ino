#define dirStep 12
#define pulStep 10
#define enableMotor 11

void configuraMotor();
void passo(int direcao);
void motorDebug();
bool configurauma = 1;
extern bool FimEsq;
extern bool FimDir;
extern bool sw1;
extern int debugMode;
int tempo = 10000;
float frequencia = 300;

void configuraMotor() {
  pinMode(dirStep, OUTPUT);
  pinMode(pulStep, OUTPUT);
  pinMode(enableMotor, OUTPUT);
  digitalWrite(dirStep, LOW);
  digitalWrite(pulStep, LOW);
  digitalWrite(enableMotor, HIGH);
}
void desabilitaDrive() {
  digitalWrite(enableMotor, HIGH);
}
void motorDebug() {
  if (debugMode == 1) { //mostra os dados em grafico via serial
    frequencia = 1.0 / (float(tempo) / 1000000.0);
    frequencia = map(frequencia,0.0,3500,0.0,50.0);
    Serial.print(",");
    Serial.print(frequencia, 1);
  }
}
void passo(int direcao) {
  if (configurauma == 1) {
    Timer1.initialize(tempo);
    Timer1.pwm(10, 512);
    configurauma = 0;
  }
  motorDebug();
  switch (direcao) {
    case 0:
      digitalWrite(dirStep, LOW);
      break;
    case 1:
      digitalWrite(dirStep, HIGH);
      break;
  }
  if (sw1 == 0) {
    digitalWrite(enableMotor, LOW);
    if (FimEsq == HIGH && direcao == 1) {
      desabilitaDrive();
    }
    if (FimDir == HIGH && direcao == 0) {
      desabilitaDrive();
    }
  } else {
    desabilitaDrive();
  }
}
