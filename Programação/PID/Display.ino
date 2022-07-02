
#define enderecoDisplay 0x22

LiquidCrystal_I2C lcd(enderecoDisplay, 16, 2);


void configuraDisplay();
void tela();

void mostraDisplay();

int Tela = 500;
int aTela = Tela;
int tID;

void configuraDisplay() {
  lcd.init();
  lcd.backlight();
  tela(100);
}

void tela(int tID){
  Tela = tID;
  if (Tela != aTela) {
    lcd.clear();
    switch (Tela) {
      case 100:
        lcd.setCursor(0, 0);
        lcd.print("Equilibrador PID");
        lcd.setCursor(0, 1);
        lcd.print(" Osmar e Thomas ");
        break;
      //case 1:

       // break;
    }
  }
}
void mostraDisplay() {

}
