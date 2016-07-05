int valorAtual, valores[32], i, cont = 0, leitura = 0, aux = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (cont >= 10) {
    Vitoria();
  }
  else {
    valorAtual = random(1, 4);
    valores[cont] = valorAtual;
    for (i = 0; i <= cont; i++) {
      acender(valores[i]);
    }
    for (i = 0; i < cont + 1; i++) {
      leitura = cor();
      Serial.print(leitura);
      Serial.print("<-Leitura e Valor->");
      Serial.println(valores[i]);
      delay(500);
      aux = 0;
      if (leitura != valores[i]) {
        Derrota();
      }
      leitura = 0;
    }
    Serial.println("---------------------");
    cont++;
  }
}

void Vitoria() {
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  for (;;) {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    delay(150);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    delay(150);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    delay(150);
  }
}
void Derrota() {
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  for (;;) {
  }
}
int cor() {
  while (aux == 0) {
    if (digitalRead(8) != 0) {
      aux = 1;
    }
    if (digitalRead(9) != 0) {
      aux = 2;
    }
    if (digitalRead(10) != 0) {
      aux = 3;
    }
  }
  return aux;
}
void acender(int led) {
  if (led == 1) {
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    delay(500);
  }
  if (led == 2) {
    digitalWrite(6, HIGH);
    delay(1000);
    digitalWrite(6, LOW);
    delay(500);
  }
  if (led == 3) {
    digitalWrite(5, HIGH);
    delay(1000);
    digitalWrite(5, LOW);
    delay(500);
  }
}

