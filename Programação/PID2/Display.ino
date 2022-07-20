
#define enderecoDisplay 0x22

LiquidCrystal_I2C lcd(enderecoDisplay, 16, 2); // função de criação do elemento display colocando endereço numero de caracteres e numero de linhas

//Protótipo das funções
void configuraDisplay();
void tela(int tID);


//variáveis
int Tela = 500;
int aTela = Tela;
int tID;

//variáveis externas
extern int tempoAcionamento;
extern int velocidade;

void configuraDisplay() {
  lcd.init(); // inicia display
  lcd.backlight(); // Liga a luz de fundo
  tela(100); //executa um delay
}

void tela(int tID) { //mostra a tela conforme o id
  Tela = tID;
  if (Tela != aTela) { // verifica se a tela solicitada é diferente da atual
    lcd.clear(); // limpa o display
    switch (Tela) {
      case 100:
        lcd.setCursor(0, 0); //seta a posição do ponteiro para a primeira coluna na primeira linha
        lcd.print("Equilibrador PID"); // printa o texto
        lcd.setCursor(0, 1); //seta a posição do ponteiro para a primeira coluna na segunda linha
        lcd.print(" Osmar e Thomas "); // printa o texto
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

