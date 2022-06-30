
extern void configuraSensor();
extern void sensor();
extern void configuraMotor();
extern void motor(bool direcao);
extern void configuraDisplay();
extern void lerTeclado();

bool direcao=false;
int debugMode = 0;
int leTeclado = 0;
bool switch1 = false;
bool switch2 = false;
bool switch3 = false;


void setup() {
  Serial.begin(9600);
  configuraSensor();
  configuraMotor();
  configuraDisplay();
  
}


void loop() {
  sensor();
  if(leTeclado == 1){
    lerTeclado();
  }
  //Serial.println(sensor);
  // PID ---------
  
  
  //
  //motor(direcao);
}
