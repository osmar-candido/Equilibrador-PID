
#define pinTrig 12 // pino usado para disparar os pulsos do sensor
#define pinEcho 13    // pino usado para ler a saida do sensor
#define alimentacaoSensor 11

/*----------Protótipo Funções----------*/
void configuraSensor();
void sensor();
void gatilhoSensor();
float calculaDistancia(float tempoMicrossegundos);

/*----------Variaveis----------*/
// Obs. Velocidade do som = 340,29 m/s = 0.00034029 m/us
const float velocidadeSom = 0.00034029; // em metros por microsegundo
float tempoEcho = 0;

void configuraSensor() {
  // Configura pinos Trig e Echo
  pinMode(pinTrig, OUTPUT); // configura pino TRIG como saída
  pinMode(pinEcho, INPUT); // configura pino ECHO como entrada
  pinMode(alimentacaoSensor, OUTPUT);
  digitalWrite(alimentacaoSensor, HIGH);
  digitalWrite(pinTrig, LOW);
}

void sensor() {
  gatilhoSensor(); // envia pulso trigger (gatilho) para disparar o sensor
  tempoEcho = pulseIn(pinEcho, HIGH); // mede o tempo de duração do sinal no pino de leitura em us
  // exibe no monitor serial
  Serial.print("Distancia em metros: ");
  Serial.println(calculaDistancia(tempoEcho), 4);
  Serial.print("Distancia em centimetros: ");
  Serial.println(calculaDistancia(tempoEcho) * 100);
  Serial.println("------------------------------------");
}

// Funçao para enviar o pulso de trigger
void  gatilhoSensor() {
  // Para fazer o HC-SR04 enviar um pulso ultrassonico, nos temos
  // que enviar para o pino de trigger um sinal de nivel alto
  // com pelo menos 10us de duraçao
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
}

// Função para calcular a distancia em metros
float calculaDistancia(float tempoMicrossegundos) {
  return ((tempoMicrossegundos * velocidadeSom) / 2); // velocidade do som em m/microssegundo
}
