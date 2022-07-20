//inclusão das biblitecas
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TimerOne.h>
/*

  pin | cabo8 | função
  13  -   8   - driver laranja
  12  -   3   - driver marrom
  11  -   4   - driver vermelho
   7  -   2   - fim de curso
   6  -   1   - echo
   5  -   7   - trigger
   4  -   6   - fim de curso lado sensor
  GND -   5  - gnd
*/
//chama a funções de outras abas
extern void configuraSensor();
extern void configuraMotor();
extern void sensor();
extern void configuraDisplay();
extern void configuraTeclado();
extern void desabilitaDrive();
extern void passo(int direcao);
extern void lerTeclado();
extern int tempoAcionamento;
extern int velocidade;
extern void sensorDebug();

//declaração das variaveis de uso
bool direcao = false;
int debugMode = 1;
bool switch1 = false;
bool switch2 = false;
bool switch3 = false;
float setpoint = 38.0;
int long tempoAnterior = millis();
bool executa1 = false;
bool executa2 = false;
int contador = 1;

//chamada das variaveis externas
extern int leTeclado;
extern bool sw2;
extern bool sw3;
extern bool sw1;
extern float centimetros;

void setup() {
  Serial.begin(9600);//inicializa a serial
  //chama todas as funções de configuração
  configuraSensor();
  configuraMotor();
  configuraDisplay();
  configuraTeclado();
  setupPinos();
}
void loop() {
  atuadores();//verifica o sw2 para selecionar o modo debug
  sensor(); //efetua a leitura do sensor
  lerTeclado(); //efetua a verificação do teclado
  testes(); //chama a função a qual esta sendo utilizada para a geração das tabelas para o controle
}

void testes() {
  if(sw1 == 0){
    sensorDebug();//chama o valor do sensor na serial
    Serial.print(","); //printa uma virgula
  }
  if (sw3 == 1) {
    if(sw1 == 0){
      Serial.println(map(velocidade, 0, 100, 50, 0)); //exibe o valor enviado na função passo
    }
    if (executa1 == false) { //executa as funções abaixo apenas uma vez quando entrado neste modo, resetando caso seja alterada para o executa2
      executa2 = false;
      passo(map(velocidade, 0, 100, 50, 0));
      executa1 = true;
    }
  }
  if (sw3 == 0) {
    if(sw1 == 0){
      Serial.println(map(velocidade, 0, 100, 50, 100)); //exibe o valor enviado na função passo
    }
    if (executa2 == false) { //executa as funções abaixo apenas uma vez quando entrado neste modo, resetando caso seja alterada para o executa2
      executa1 = false;
      passo(map(velocidade, 0, 100, 50, 100));
      executa2 = true;
    }
  }
}

void atuadores() {
  if (sw2 == 0) { //verifica o status do switch de alavanca 2 e seta o debug para visualização com label ou modo plotter
    debugMode = 1;
  } else {
    debugMode = 0;
  }
}

void setupPinos() { //setup de todos os pinos em uso
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
}
