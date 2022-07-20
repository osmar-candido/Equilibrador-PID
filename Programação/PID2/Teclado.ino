//Definicao de pino e tela
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

//Funções internas e externa
void lerTeclado();
void comparaDado();
void chamaFuncao(int botao);
void ISRteclado();
extern void tela(int tID);


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
bool AbtCima = false;
bool AbtBaixo = false;
bool AbtDireita = false;
bool AbtEsquerda = false;
bool AbtCentro = false;
int tempoAcionamento = 100;
int velocidade = 0;
int bTela = 1;


//Funções
void configuraTeclado() {
  Wire.begin();
}

//Void para defir a funcao de teclado
void ISRteclado() {
  leTeclado = 1;
}

//modo de teclado local verifica se ha alguma alteração dos botoes e retorna um int referente a função detectada
void lerTeclado() { 
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

//Void para Validar alteracaoes no estado de botoes 
void comparaDado() {
  if (btRead != btLastRead) {
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
    comparaBotao();

  }
}

//Void responsavel por definicao de aperto de botao
//Compara cada estao atual dos botoes com a leitura anterior
void comparaBotao() {
  if (btCima != AbtCima) {
    if (btCima == false) {
      chamaFuncao(1);
      Serial.println("Botao UP");
    }
    AbtCima = btCima;
    
  }
  if (btBaixo != AbtBaixo) {
    if (btBaixo == false) {
      chamaFuncao(2);
    }
    AbtBaixo = btBaixo;
  }
  if (btDireita != AbtDireita) {
    if (btDireita == false) {
      chamaFuncao(3);
    }
    AbtDireita = btDireita;
  }
  if (btEsquerda != AbtEsquerda) {
    if (btEsquerda == false) {
      chamaFuncao(4);
    }
    AbtEsquerda = btEsquerda;
  }
  if (btCentro != AbtCentro) {
    if (btCentro == false) {
      chamaFuncao(5);
    }
    AbtCentro = btCentro;
  }
}

// Void para realizar a funcao especifica de cada botao 
void chamaFuncao(int botao) {
  // botao::
  // 1 = cima
  // 2 = baixo
  // 3 = esquerda
  // 4 = direita
  // 5 = centra
  
  
  // tela::
  // 1 = Tela de velocidade aberta
  // 2 = Tela de Tempo de Acionamento Aberta


  //tela(bTela) >. Atualiza a tela apos comando
  switch (botao) {
    case 1:
      switch (bTela) {
        case 1:
          //Aumenta velocidade do motor
          velocidade = velocidade + 5;
          break;
        case 2:
          //Aumenta tempo de acionamento
          tempoAcionamento = tempoAcionamento + 50;
          break;
      }
      tela(bTela);
      break;
    case 2:
      switch (bTela) {
        case 1:
          //Diminui velocidade do motor
          velocidade = velocidade - 5;
          break;
        case 2:
          //Diminui tempo de acionamento
          tempoAcionamento = tempoAcionamento - 50;
          break;
      }
      tela(bTela);
      break;
    case 4:
      //Navegacao entre as telas
      bTela = bTela - 1;
      tela(bTela);
      break;
    case 3:
      //Navegacao entre as telas
      bTela = bTela + 1;
      tela(bTela);
      break;
    case 5:
      bTela = 1;
      tela(bTela);
      break;
    default:
      tela(99);
      break;

  }
}
