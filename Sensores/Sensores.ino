//Portas do sensores
int LM35 = A0;//Sensor de Temperatura
int LDR = A1;//Sensor de Luminosidade
//Função de leitura da temperatura
void Temperatura(int sensor){
	float temp;
	//Conversão do valor para graus celcius
	temp = (float(analogRead(sensor))*5/(1023))/0.01;
	Serial.print("Temperatura: ");
	Serial.print(temp);
	Serial.println(" ºC");
	delay(10);
}
//Função da leitura do LDR
void Luminosidade(int sensor){
	float luz;
	Serial.print("Luminosidade: ");
	Serial.print(luz);
	Serial.println(" (0-1023)");
	delay(10);
}
//Setup do Serial
void setup(){
	Serial.begin(9600);
}

void loop(){
	Serial.println("||Temperatura e Luminosidade||");
	Temperatura(LM35);
	Luminosidade(LDR);
  delay(1000);
}
