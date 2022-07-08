#define pinTrig 5 // pino usado para disparar os pulsos do sensor
#define pinEcho 6    // pino usado para ler a saida do sensor
#define pinFim1 7
#define pinFim2 4

#define numeroLeitura 5 //quantas leituras a fazer para o filtro
#define tempoLeitura 1 //tempo entre leitura em millis
/*----------Protótipo Funções----------*/
void configuraSensor();                             //vai no setup, configura os pinos e seta a forma inicial
void sensor();                                      //efetua a leitura do sensor
void gatilhoSensor();                               //faz o pulso no sensor ultrassonico
float calculaDistancia(float tempoMicrossegundos);  //converte o tempo para a distancia
void sensorDebug();
void fimCurso();

/*----------Variaveis----------*/
// Obs. Velocidade do som = 340,29 m/s = 0.00034029 m/us
const float velocidadeSom = 0.00034029; // em metros por microsegundo
float tempoEcho = 0;
extern int debugMode;
long somador = 0;
float centimetros = 0;
float medidas[5] = {0, 0, 0, 0, 0};
int long contadorErro = 0;
bool FimEsq = false;
bool FimDir = false;
int long TimingSensor = 0;
/*----------Funções----------*/

void configuraSensor() { //função inserida no setup onde configura todas as entradas e saidas
  pinMode(pinTrig, OUTPUT); // configura pino TRIG do sensor ultrassonico como saída
  pinMode(pinEcho, INPUT); // configura pino ECHO do sensor ultrassonico como entrada
  pinMode(pinFim1, INPUT);
  pinMode(pinFim2, INPUT);
  digitalWrite(pinTrig, LOW);
  TimingSensor = millis();
}

/*
  const float velocidadeSom = 0.00034029; // em metros por microsegundo
  float tempoEcho = 0;
  extern int debugMode;
  long somador = 0;
  float centimetros = 0;
  float medidas[5];
*/

void sensor() {
  fimCurso();
  if (TimingSensor + 60 <= millis()) {
    gatilhoSensor(); // envia pulso trigger (gatilho) para disparar o sensor
    tempoEcho = pulseInLong(pinEcho, HIGH, 2900);
    if (tempoEcho < 2500) {
      atualizaMedia((calculaDistancia(tempoEcho) * 100));
      sensorDebug();
    }
    TimingSensor = millis();
  }
}

bool atualizaMedidas = false;

void atualizaMedia(float medida) {
  filtro(medida);
  if (atualizaMedidas == true && medida > 3.0 && medida < 50.0) {
    medidas[0] = medidas[1];
    medidas[1] = medidas[2];
    medidas[2] = medidas[3];
    medidas[3] = medidas[4];
    medidas[4] = medida;
    centimetros = (medidas[4] * 0.4) + (medidas[4] * 0.25) + (medidas[4] * 0.20) + (medidas[4] * 0.10) + (medidas[4] * 0.5);
    atualizaMedidas = false;
  }
}

void filtro(float amedida) {
  if ( (amedida / medidas[4]) > 0.9 || amedida / medidas[4] < 1.1) {
    if (amedida < 48.0) {
      atualizaMedidas = true;
    }
  } else {
    contadorErro = contadorErro + 1;
    lcd.setCursor(0, 0);
    lcd.print("vish! ");
    lcd.print(contadorErro);
  }

}


void  gatilhoSensor() { // Funçao para enviar o pulso de trigger
  // Para fazer o HC-SR04 enviar um pulso ultrassonico, nos temos que enviar para o pino de trigger um sinal de nivel alto com pelo menos 10us de duraçao
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
}

// Função para calcular a distancia em metros
float calculaDistancia(float tempoMicrossegundos) {
  return ((tempoMicrossegundos * velocidadeSom) / 2); // velocidade do som em m/microssegundo
}
void sensorDebug() {
  if (debugMode == 0) { //mostra os dados na serial de forma mais intuitiva
    Serial.print("tempo: ");
    Serial.println(tempoEcho);
    Serial.print("Distancia em metros: ");
    Serial.println(calculaDistancia(tempoEcho), 4);
    Serial.print("Distancia em centimetros: ");
    Serial.println(centimetros, 1);
    Serial.println("------------------------------------");
  }
  if (debugMode == 1 && centimetros < 57.0) { //mostra os dados em grafico via serial
    Serial.println(centimetros, 1);
  }
}
void fimCurso() {
  if (digitalRead(pinFim1) == HIGH) { //sensor do lado do driver
    FimEsq = false;
  } else {
    //Serial.println("Sensor 1");
    FimEsq = true;
  }
  if (digitalRead(pinFim2) == HIGH) { //sensor do lado do ultrassonico
    FimDir = false;
  } else {
    //Serial.println("Sensor 2");
    FimDir = true;
  }

}
