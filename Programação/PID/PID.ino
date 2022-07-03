#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*

  pin | cabo8 | função
  13  -   8   - driver laranja
  12  -   3   - driver marrom
  11  -   4   - driver vermelho
   7  -   2   - fim de curso
   6  -   1   - echo
   5  -   7   - trigger
   4  -   6   - fim de curso lado sensor
  GND  -   5   - gnd
*/

extern void configuraSensor();
extern void configuraMotor();
extern void sensor();
extern void configuraDisplay();
extern void configuraTeclado();

extern void motor(bool direcao);
extern void lerTeclado();


bool direcao = false;
int debugMode = 0;
bool switch1 = false;
bool switch2 = false;
bool switch3 = false;

extern int leTeclado;

void setup() {
  Serial.begin(9600);
  configuraSensor();
  configuraMotor();
  configuraDisplay();
  configuraTeclado();
  setupPinos();
}


void loop() {
  sensor();
  if (leTeclado == 1) {
  lerTeclado();
  leTeclado == 0;
  }
  //Serial.println(sensor);
  // PID ---------


  //
  //motor(direcao);
}

int comandoSerial;

void setupPinos() {
  /*
    pin | cabo8 | função
    13  -   8   - driver laranja
    12  -   3   - driver marrom
    11  -   4   - driver vermelho
    7  -   2   - fim de curso
    6  -   1   - echo
    5  -   7   - trigger
    4  -   6   - fim de curso lado sensor
    GND  -   5   - GND
  */
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
}
