Скетч использует 3382 байт (10%) памяти устройства. Всего доступно 32256 байт.
Глобальные переменные используют 200 байт (9%) динамической памяти, оставляя 1848 байт для локальных переменных. Максимум: 2048 байт.

// C++ code
//


#define PIN_PHOTO_SENSOR A0


void setup()
{
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  float val = analogRead(PIN_PHOTO_SENSOR);
  Serial.println(val);

  if (val > 100) {
  	digitalWrite(2, HIGH);
  } else {
  	digitalWrite(2, LOW);
  }

  if (val > 800) {
  	digitalWrite(3, HIGH);
  } else {
  	digitalWrite(3, LOW);
  }

  if (val > 900) {
  	digitalWrite(4, HIGH);
  } else {
  	digitalWrite(4, LOW);
  }


}