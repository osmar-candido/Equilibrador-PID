#define dirStep 4
#define pulStep 5

void configuraMotor();
void passo(int direcao);




void configuraMotor() {
  pinMode(dirStep, OUTPUT);
  pinMode(pulStep, OUTPUT);
  digitalWrite(dirStep, LOW);
  digitalWrite(pulStep, LOW);
}
void passo(int direcao) {
  switch (direcao) {
    case 0:
      digitalWrite(dirStep, LOW);
      //DDRD = DDRD & ~ (1 << PD5);
      break;
    case 1:
      digitalWrite(dirStep, HIGH);
      //DDRD = DDRD | (1 << PD5); // Nível HIGH
      break;
    default:
      digitalWrite(dirStep, LOW);
      //DDRD = DDRD & ~ (1 << PD5);
      break;
  }
  digitalWrite(pulStep, HIGH);
  //DDRD = DDRD | (1 << PD5); // Nível HIGH
  delayMicroseconds(10);
  digitalWrite(pulStep, LOW);
  //DDRD = DDRD & ~ (1 << PD5);
  delayMicroseconds(10);
}
