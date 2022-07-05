#define enderecoTeclado 0x20
#define intTeclado 2

//   botoes em relação aos bits
//  bit 0 = F1
//  bit 1 = F2
//  bit 2 = F3
//  bit 3 = F4
//  bit 4 = ESC
//  bit 5 = OK
//  bit 6 = A encoder
//  bit 7 = B encoder

//Protótipo Funções
void lerTeclado();
void comparaDado();
void chamaFuncao(int botao);
void ISRteclado();

//Variaveis
byte btRead;
byte btLastRead;
int leTeclado = 1;
bool btCima = false;
bool btBaixo = false;
bool btDireita = false;
bool btEsquerda = false;
bool btCentro = false;
bool sw1 = false;
bool sw2 = false;
bool sw3  = false;

//Funções
void configuraTeclado() {
  Wire.begin();
  //attachInterrupt(digitalPinToInterrupt(intTeclado), ISRteclado, FALLING);
}

void ISRteclado() {
  leTeclado = 1;
}

void lerTeclado() { //modo de teclado local verifica se ha alguma alteração dos botoes e retorna um int referente a função detectada
  //   botoes em relação aos bits
  //  bit 0 = sw1
  //  bit 1 = sw3
  //  bit 2 = botão direita
  //  bit 3 = botão baixo
  //  bit 4 = sw1
  //  bit 5 = botão centro
  //  bit 6 = botão cima
  //  bit 7 = botão esquerda
  Wire.requestFrom(enderecoTeclado, 1);
  if (Wire.available()) {
    btRead = Wire.read();
    comparaDado();
  }
}

void comparaDado() {
  if (btRead != btLastRead) {
    /*for (int cont = 0; cont < 8; cont++) {
      Serial.print(bitRead(btRead, cont));
    }*/
    Serial.println("");
    btCima      = bitRead(btRead, 6);
    btBaixo     = bitRead(btRead, 3);
    btDireita   = bitRead(btRead, 2);
    btEsquerda  = bitRead(btRead, 7);
    btCentro    = bitRead(btRead, 5);
    sw1         = bitRead(btRead, 4);
    sw2         = bitRead(btRead, 0);
    sw3         = bitRead(btRead, 1);

    btLastRead  = btRead;
  }
}
void chamaFuncao(int botao) {

}
