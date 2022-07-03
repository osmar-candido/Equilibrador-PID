#define dirStep 13
#define pulStep 12
#define enableMotor 11

void configuraMotor();
void passo(int direcao);

extern bool FimEsq;
extern bool FimDir;

void configuraMotor() {
  pinMode(dirStep, OUTPUT);
  pinMode(pulStep, OUTPUT);
  pinMode(enableMotor, OUTPUT);
  digitalWrite(dirStep, LOW);
  digitalWrite(pulStep, LOW);
  digitalWrite(enableMotor, LOW);
}
void passo(int direcao) {
  if (FimEsq == HIGH && FimDir == LOW) {

    
    
    
    switch (direcao) {
      case 0:
        digitalWrite(dirStep, LOW);
        break;
      case 1:
        digitalWrite(dirStep, HIGH);
        break;
    }
    digitalWrite(pulStep, HIGH);
    delayMicroseconds(10);
    digitalWrite(pulStep, LOW);
    delayMicroseconds(10);
  }
}
