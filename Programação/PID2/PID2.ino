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
extern int leTeclado;
extern bool sw2;
extern bool sw3;

extern float centimetros;

void setup() {
  Serial.begin(9600);
  configuraSensor();
  configuraMotor();
  configuraDisplay();
  configuraTeclado();
  setupPinos();
}
void loop() {
  atuadores();
  sensor();
  lerTeclado();
  testes();
  /*if(setpoint < centimetros){
    passo(0);
    }else{
    passo(1);
    }*/
  //debugCortaLinha();
  //delay(1);
}

void testes() {
  /*if(setpoint < centimetros){
    passo(0);
    }else{
    passo(100);
    }*/
  Serial.print(millis());
  Serial.print("  ");
  Serial.println(tempoAnterior);

  if (millis() > (tempoAnterior + tempoAcionamento)) {
    contador = contador + 1;
    tempoAnterior = millis();
  }
  if (contador == 3) {
    executa1 = false;
    executa2 = false;
    contador = 1;
  }
  if (contador == 1) {
    if (executa1 == false) {
      passo(map(velocidade, 0, 100, 50, 0));
      executa1 = true;
      Serial.println("lado 1");
    }
  }
  if (contador == 2) {
    if (executa2 == false) {
      passo(map(velocidade, 0, 100, 50, 100));
      executa2 = true;
      Serial.println("lado 2");
    }
  }
}

void atuadores() {
  if (sw2 == 0) {
    debugMode = 1;
  } else {
    debugMode = 0;
  }
}

void setupPinos() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
}
void debugCortaLinha() {
  Serial.println("");
}
