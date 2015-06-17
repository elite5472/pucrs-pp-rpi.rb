int inByte;

const int LED_1_PIN = 10;  // PB2

int LEDstate = 1;

void setup() 
{
	Serial.begin(9600);

	pinMode(LED_PIN, OUTPUT);

	digitalWrite(LED_PIN, HIGH);
}

void loop()
{
	if (Serial.available()) 
	{
		inByte = Serial.read();
	}
	
	if(inByte == 0)
	{
		on();
	}
	else
	{
		blink();
	}
}

void on()
{
	digitalWrite(LED_PIN, HIGH);
}

void blink()
{
	if (LEDstate == 1)
	{
		digitalWrite(LED_PIN, LOW);
		LEDstate = 0;
	}
	else
	{
		digitalWrite(LED_PIN, HIGH);
		LEDstate = 1;
	}
	delay(1000);
}
