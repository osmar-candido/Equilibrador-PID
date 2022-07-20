//definições dos pinos de conexão com o driver
#define dirStep 12
#define pulStep 10
#define enableMotor 11

//funções
void configuraMotor();
void passo(int direcao);
void motorDebug();

//variaveis locais
bool configurauma = 1;
int tempo = 300;
float frequencia = 300;
int motorFeedback;
int dir;

//variaveis externas
extern bool FimEsq;
extern bool FimDir;
extern bool sw1;
extern int debugMode;

void configuraMotor() { // efetua o setup das entradas e configuração dos estados iniciais dos pinos
  pinMode(dirStep, OUTPUT);
  pinMode(pulStep, OUTPUT);
  pinMode(enableMotor, OUTPUT);
  digitalWrite(dirStep, LOW);
  digitalWrite(pulStep, LOW);
  digitalWrite(enableMotor, HIGH);
}
void desabilitaDrive() { // função para desligar o drive deixando o motor livre
  digitalWrite(enableMotor, HIGH);
}
void motorDebug() { //função para efetuar o print Serial do motor
  if (debugMode == 1) { //mostra os dados em grafico via serial
    frequencia = 1.0 / (float(tempo) / 1000000.0);
    frequencia = map(frequencia, 0.0, 3500, 0.0, 50.0);
    if (sw1 == false) {
      Serial.print(",");
      Serial.print(frequencia, 1);
    }
  }
}
/*
 função de acionamento do motor onde o sinal de entrada varia de 0-100
 sendo:
   0 velocidade maxima em um sentido
 100 velocidade maxima no outro sentido
  50 motor parado e/ou desabilitado
*/
void passo(int direcao) { // função de acionamento do motor onde o sinal de entrada varia de 0-100
  if (configurauma == 1) {//função para executar a instrução apenas uma vez
    Timer1.initialize(tempo);//inicializa o timer
    Timer1.pwm(10, 512);//seta um pwm no pino 10 com 50% de dutycicle
    configurauma = 0; 
  }
  if (direcao == 50) { // direçao = 50 então desabilita drive
    desabilitaDrive(); 
    motorFeedback = 0; 
  } else if (direcao > 50) { // verifica o sentido desejado
    direcao = direcao - 50; // efetua a subtração para facilitar o map
    direcao = map(direcao, 0, 50, 0, 100); // executa o map para obter um 0 a 100%
    Timer1.setPeriod(map(direcao, 0, 100, 15000, 300)); //efetua o map novamente para obter o novo periodo de timer1
    digitalWrite(dirStep, HIGH); //seta a direção
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
  if (sw1 == 0) { //primeiro switch alavanca, serve para desabilitar o movimento do drive
    if (dir == 0) {
      //Serial.println("Esquerda");
      if (FimDir == HIGH) { //caso o sensor da esquerda seja acionado ele permite apenas que o motor possa se movimentar novamente para a direita
        //Serial.println("Sensor Esquerda");
        desabilitaDrive();
      } else {
        digitalWrite(enableMotor, LOW);
      }
    }
    if (dir == 1) {
      //Serial.println("Direta");
      if (FimEsq == HIGH) { //caso o sensor da direita seja acionado ele permite apenas que o motor possa se movimentar novamente para a esquerda
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
