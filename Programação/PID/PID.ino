#include <Wire.h>
#include <LiquidCrystal_I2C.h>


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

}


void loop() {
  //sensor();
  if (leTeclado == 1) {
    lerTeclado();
    Serial.println("ISR");
    //leTeclado == 0;
  }
  //Serial.println(sensor);
  // PID ---------


  //
  //motor(direcao);
}
