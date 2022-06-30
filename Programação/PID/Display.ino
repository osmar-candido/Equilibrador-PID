#include <LiquidCrystal_I2C.h>
#define enderecoDisplay 0x27

LiquidCrystal_I2C lcd(enderecoDisplay, 16, 2);

// *************Adicionar Interrupt pino 2 para o teclado

void configuraDisplay();
void tela();

void ISRteclado();
void mostraDisplay();

int Tela = 100;
int aTela = Tela;


void configuraDisplay() {
  lcd.init();
  lcd.backlight();
}

void tela(){
  if (Tela != aTela) {
    lcd.clear();
    switch (Tela) {
      case 100:
        lcd.setCursor(0, 0);
        lcd.print("Equilibrador PID");
        lcd.setCursor(1, 0);
        lcd.print(" Osmar e Thomas ");
        break;
      //case 1:

       // break;
    }
  }
}
void mostraDisplay() {

}
void ISRteclado(){
 //Lê Teclado

  
}
