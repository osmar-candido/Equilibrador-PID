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
int tempo = 300;
float frequencia = 300;
int motorFeedback;
int dir;

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
    frequencia = map(frequencia, 0.0, 3500, 0.0, 50.0);
    if (sw1 == false) {
      Serial.print(",");
      Serial.print(frequencia, 1);
    }
  }
}
void passo(int direcao) {
  if (configurauma == 1) {
    Timer1.initialize(tempo);
    Timer1.pwm(10, 512);
    configurauma = 0;
  }
  if (direcao == 50) {
    desabilitaDrive();
    motorFeedback = 0;
  } else if (direcao > 50) {
    direcao = direcao - 50;
    direcao = map(direcao, 0, 50, 0, 100);
    Timer1.setPeriod(map(direcao, 0, 100, 15000, 300));
    digitalWrite(dirStep, HIGH);
    motorFeedback = direcao;
    dir = 1;

  } else if (direcao < 50) {
    direcao = map(direcao, 50, 0, 0, 100);
    digitalWrite(dirStep, LOW);
    Timer1.setPeriod(map(direcao, 0, 100, 15000, 300));
    motorFeedback = direcao * -1;
    dir = 0;
  }

  /*
    switch (direcao) {
    case 0:
      digitalWrite(dirStep, LOW);
      break;
    case 1:
      digitalWrite(dirStep, HIGH);
      break;
    }*/
  if (sw1 == 0) {
    if (dir == 0) {
      //Serial.println("Esquerda");
      if (FimDir == HIGH) {
        //Serial.println("Sensor Esquerda");
        desabilitaDrive();
      } else {
        digitalWrite(enableMotor, LOW);
      }
    }
    if (dir == 1) {
      //Serial.println("Direta");
      if (FimEsq == HIGH) {
        //Serial.println("Sensor Direita");
        desabilitaDrive();
      } else {
        digitalWrite(enableMotor, LOW);
      }
    }
  } else {
    desabilitaDrive();
  }
}
