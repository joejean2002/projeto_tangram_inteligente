const int BOTAOV = 2;
const int BOTAOA = 12;
const int LED = 13;

bool estado = 0;

void setup() {
  pinMode(BOTAOA, INPUT_PULLUP);
  pinMode(BOTAOV, INPUT_PULLUP);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);

 // Serial.begin(9600);
}

void loop() {
  if(digitalRead(BOTAOV) == LOW){
    estado = !estado;

    digitalWrite(LED, estado);
    //Serial.print("Valor de saida: ");
    //Serial.println(estado);

    while(digitalRead(BOTAOV) == LOW);
    
    delay(100);
  }

  if(digitalRead(BOTAOA) == LOW){
    estado = !estado;

    digitalWrite(LED, HIGH);
   // Serial.print("Valor de saida: ");
    //Serial.println(HIGH); 

    while(digitalRead(BOTAOA) == LOW);

    delay(100);
  }
}
