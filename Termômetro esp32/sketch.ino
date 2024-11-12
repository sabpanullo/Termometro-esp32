#define LED_BLUE 13    // Pino do LED azul
#define LED_GREEN 12   // Pino do LED verde
#define LED_RED 14     // Pino do LED vermelho

void setup() {
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  
  Serial.begin(115200);
  randomSeed(analogRead(0));  // Inicializa o gerador de números aleatórios
}

void loop() {
  float temperature = random(-10, 41);  // Gera uma "temperatura" aleatória entre -10 e 40°C
  
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature < 0) {
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
  } else if (temperature < 30) {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  } else {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
  }

  delay(2000);  // Espera 2 segundos para a próxima leitura
}

