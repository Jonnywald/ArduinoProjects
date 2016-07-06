int valorAtual, valores[32], i, cont = 0, leitura = 0, aux = 0;

void setup() {
  // Entrada (botoes)
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  // Saida (LEDs)
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  // Semente da sequecia aleatoria utiliza o ruido na porta A0 (note que nao a nada conectado nela)
  randomSeed(analogRead(0));
  // inicia o monitor serial com baud rate 9600
  Serial.begin(9600);
}

void loop() {
  // checagem de vitoria
  if (cont >= 10) {
    Vitoria();
  }
  else {
    // obtem um valor para o led aleatorio
    valorAtual = random(1, 4);
    // amazena no vetor de ocorrencias
    valores[cont] = valorAtual;
    // acende as ocorrencias
    for (i = 0; i <= cont; i++) {
      acender(valores[i]);
    }
    // recebe a entrada do usuario
    for (i = 0; i < cont + 1; i++) {
      leitura = cor();
      // auxilio de debug
      Serial.print(leitura);
      Serial.print("<-Leitura e Valor->");
      Serial.println(valores[i]);
      delay(500);
      aux = 0;
      // caso entrada x de usuario nao seja igual a ocorrencia x o usuario perde
      if (leitura != valores[i]) {
        Derrota();
      }
      leitura = 0;
    }
    Serial.println("---------------------");
    cont++;
  }
}
// leds "correndo" (estado de vitoria)
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
  // Leds "travados" (estado de derrota)
}
void Derrota() {
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  for (;;) {
  }
}
// computaçao de escolha do usuario
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
// exibiçao de occorencias
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

