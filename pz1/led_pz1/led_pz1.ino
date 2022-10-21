// Скетч использует 1016 байт (3%) памяти устройства. Всего доступно 32256 байт.
// Глобальные переменные используют 9 байт (0%) динамической памяти, оставляя 2039 байт для локальных переменных. Максимум: 2048 байт.

const int led = 13;
const int S = 400;
const int P = 100;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(S);
  digitalWrite(led, LOW);
  delay(P);
  digitalWrite(led, HIGH);
  delay(S);
  digitalWrite(led, LOW);
  delay(P);
  digitalWrite(led, HIGH);
  delay(S);
  digitalWrite(led, LOW);
  delay(P);
  delay(1000);
}

