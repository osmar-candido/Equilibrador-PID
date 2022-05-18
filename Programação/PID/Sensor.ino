
#define pinTrig 12 // pino usado para disparar os pulsos do sensor
#define pinEcho 13    // pino usado para ler a saida do sensor
#define pinFim1 9
#define pinFim2 8
#define alimentacaoSensor 11 // para fins de facilidade será usado durantes os testes iniciais a porta 11 como alimentação do HSR04
#define numeroLeitura 30 //quantas leituras a fazer para o filtro
#define tempoLeitura 5 //tempo entre leitura em millis
/*----------Protótipo Funções----------*/
void configuraSensor();
void sensor();
void gatilhoSensor();
float calculaDistancia(float tempoMicrossegundos);
int calibraFim();

/*----------Variaveis----------*/
// Obs. Velocidade do som = 340,29 m/s = 0.00034029 m/us
const float velocidadeSom = 0.00034029; // em metros por microsegundo
float tempoEcho = 0;
int debugMode = 1;
long somador = 0;
float centimetros = 0;
int fimEsq = 0;
int fimDir = 0;

/*----------Funções----------*/
void configuraSensor() { //função inserida no setup onde configura todas as entradas e saidas
  pinMode(pinTrig, OUTPUT); // configura pino TRIG do sensor ultrassonico como saída
  pinMode(pinEcho, INPUT); // configura pino ECHO do sensor ultrassonico como entrada
  pinMode(alimentacaoSensor, OUTPUT); // configura pino Vcc do sensor ultrassonico como saida (para Testes apenas após isso sera ligado diretamente no VCC)
  pinMode(pinFim1,INPUT);
  pinMode(pinFim2,INPUT);
  digitalWrite(alimentacaoSensor, HIGH);
  digitalWrite(pinTrig, LOW);
}
int calibraFim(){ //função para calibrar a primeira posição a fim de deixar mais proximo do centro possível
  
  
}
void sensor() { //efetua a leitura do sensor ultrassonico aplicando filtro retornando a variavel centimetros com a distancia medida
  somador = 0; //reset da variavel onde será armazenado a soma das leituras
  for(int cont = 0;cont <= numeroLeitura; cont = cont+1){ //efetua varias leituras a fim de reduzir ruido
    gatilhoSensor(); // envia pulso trigger (gatilho) para disparar o sensor
    tempoEcho = pulseInLong(pinEcho, HIGH); // mede o tempo de duração do sinal no pino de leitura em us
    somador = somador + tempoEcho;
    delay(tempoLeitura);
  }
  tempoEcho = somador/numeroLeitura; //efetua média das leituras
  centimetros = calculaDistancia(tempoEcho) * 100; //calcula a distancia em centimetros
  // exibe no monitor serial
  if (debugMode == 0) { //mostra os dados na serial de forma mais intuitiva
    Serial.print("tempo: ");
    Serial.println(tempoEcho);
    Serial.print("Distancia em metros: ");
    Serial.println(calculaDistancia(tempoEcho), 4);
    Serial.print("Distancia em centimetros: ");
    Serial.println(centimetros,1);
    Serial.println("------------------------------------");
  }
  if (debugMode == 1 && (calculaDistancia(tempoEcho) * 100)<40.0) { //mostra os dados em grafico via serial
    Serial.print(calculaDistancia(tempoEcho) * 100);
    Serial.print(",");
    Serial.print(40.0);
    Serial.print(",");
    Serial.println(0.0);
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
