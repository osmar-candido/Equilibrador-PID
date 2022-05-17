

//tecnica por cancelamento


extern void configuraSensor();
extern void sensor();
extern void configuraMotor();
extern void motor(bool direcao);

bool direcao=false;

void setup() {
  Serial.begin(9600);
  configuraSensor();
  configuraMotor();
}

void loop() {
  sensor();
  
  //Serial.println(sensor);
  // PID ---------
  
  
  //
  //motor(direcao);
}
