//Скетч использует 2190 байт (6%) памяти устройства. Всего доступно 32256 байт.
//Глобальные переменные используют 212 байт (10%) динамической памяти, оставляя 1836 байт для локальных переменных. Максимум: 2048 байт.


// C++ code
//
#ifndef Button_h
#define Button_h
class Button
{
	public:
		Button(uint8_t pin, uint16_t debounce_ms = 100);
		void begin();
		bool read();
		bool toggled();
		bool pressed();
		bool released();
		bool has_changed();
		
		const static bool PRESSED = HIGH;
		const static bool RELEASED = LOW;
	
	private:
		uint8_t  _pin;
		uint16_t _delay;
		bool     _state;
		uint32_t _ignore_until;
		bool     _has_changed;
};

#endif

Button::Button(uint8_t pin, uint16_t debounce_ms)
:  _pin(pin)
,  _delay(debounce_ms)
,  _state(HIGH)
,  _ignore_until(0)
,  _has_changed(false)
{
}

void Button::begin()
{
	pinMode(_pin, INPUT_PULLUP);
}

bool Button::read()
{
	// ignore pin changes until after this delay time
	if (_ignore_until > millis())
	{
		// ignore any changes during this period
	}
	
	else if (digitalRead(_pin) != _state)
	{
		_ignore_until = millis() + _delay;
		_state = !_state;
		_has_changed = true;
	}
	
	return _state;
}

bool Button::toggled()
{
	read();
	return has_changed();
}

bool Button::has_changed()
{
	if (_has_changed)
	{
		_has_changed = false;
		return true;
	}
	return false;
}

bool Button::pressed()
{
	return (read() == PRESSED && has_changed());
}

bool Button::released()
{
	return (read() == RELEASED && has_changed());
}

Button button1(7);
Button button2(6);
Button button3(5);
bool flagLight = false;
 
void setup()
{
  button1.begin();
  button2.begin();
  button3.begin();
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (button1.pressed() || button2.pressed() || button3.pressed()) {
    flagLight = !flagLight;
  }
  if (flagLight) {
  	digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}