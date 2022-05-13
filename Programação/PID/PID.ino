
//tecnica por cancelamento


extern void configuraSensor();
extern void sensor();
extern void configuraMotor();
extern void motor(bool direcao);

bool direcao=false;

void setup() {
  configuraSensor();
  configuraMotor();
}

void loop() {
  sensor();
  // PID ---------
  
  
  //
  motor(direcao);
}
