#include <LiquidCrystal.h>

const int LED = 13;
const int BOTAOV = 2;
const int BOTAOA = 12;

// Inicializar o display LCD
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

unsigned long tempoAnterior = 0;
const long interv = 1000; // tempo do intervalo

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTAOV, INPUT_PULLUP);
  pinMode(BOTAOA, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // Verificar se o botão V ou A foi pressionado para iniciar ou parar o temporizador
  if (digitalRead(BOTAOV) == LOW || digitalRead(BOTAOA) == LOW) {
    if (millis() - tempoAnterior >= interv) {
      tempoAnterior = millis();
      digitalWrite(LED, !digitalRead(LED)); // Inverter o estado do LED
    }

    unsigned long temporizador = millis();
    unsigned long segundos = temporizador / 1000;
    unsigned long minutos = segundos / 60;
    segundos = segundos % 60;

    lcd.clear(); // Limpar o display antes de atualizar o tempo
    lcd.setCursor(0, 0);
    lcd.print("Temporizador: ");
    lcd.setCursor(0, 1);

    if (minutos < 10) lcd.print("0");
    lcd.print(minutos);
    lcd.print(":");

    if (segundos < 10) lcd.print("0");
    lcd.print(segundos);
  }
}
