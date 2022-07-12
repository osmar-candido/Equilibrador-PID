
#define enderecoDisplay 0x22

LiquidCrystal_I2C lcd(enderecoDisplay, 16, 2);


void configuraDisplay();
void tela(int tID);

void mostraDisplay();

int Tela = 500;
int aTela = Tela;
int tID;
extern int tempoAcionamento;
extern int velocidade;

void configuraDisplay() {
  lcd.init();
  lcd.backlight();
  tela(100);
}

void tela(int tID) {
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
      default:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Tela N Existente");
        lcd.setCursor(0, 1);
        lcd.print("    Disgraca!   ");
        break;
      case 1:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Velocidade:    ");
        lcd.setCursor(0, 1);
        lcd.print(velocidade);
        break;
        case 2:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Tempo Acion.:   ");
        lcd.setCursor(0, 1);
        lcd.print(tempoAcionamento);
        break;
        // break;
    }
  }
}
void mostraDisplay() {

}
