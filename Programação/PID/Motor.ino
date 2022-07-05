#define dirStep 12
#define pulStep 10
#define enableMotor 11

void configuraMotor();
void passo(int direcao);
bool configurauma = 1;
extern bool FimEsq;
extern bool FimDir;
extern bool sw1;

void configuraMotor() {
  pinMode(dirStep, OUTPUT);
  pinMode(pulStep, OUTPUT);
  pinMode(enableMotor, OUTPUT);
  digitalWrite(dirStep, LOW);
  digitalWrite(pulStep, LOW);
  digitalWrite(enableMotor, HIGH);
 
}
void desabilitaDrive(){
  digitalWrite(enableMotor, HIGH);
}
void passo(int direcao) {
  if(configurauma == 1){
    Timer1.initialize(300);
    Timer1.pwm(10,512);
    configurauma = 0;
  }
  
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
