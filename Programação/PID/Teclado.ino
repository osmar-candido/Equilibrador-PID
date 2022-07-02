#define enderecoTeclado 0x20
#define intTeclado 2

//Protótipo Funções
void lerTeclado();
void comparaDado();
void chamaFuncao(int botao);
void ISRteclado();

//Variaveis
byte x = 0;
byte y = 0;
int leTeclado = 1;
//Funções


void configuraTeclado() {
  Wire.begin();
  //attachInterrupt(digitalPinToInterrupt(intTeclado), ISRteclado, FALLING);
}

void ISRteclado(){
  leTeclado = 1;
}

void lerTeclado()
{
  Wire.requestFrom(enderecoTeclado, 1);      //Se PCF8574A - mude de 33 para 57
  if (Wire.available())    //If the request is available
  {
    x = Wire.read();     //Receive the data
  }
  //Serial.println(x);                                               //Se PCF8574A mude 32 para 56
}
void comparaDado() {
  
}
void chamaFuncao(int botao) {

}
