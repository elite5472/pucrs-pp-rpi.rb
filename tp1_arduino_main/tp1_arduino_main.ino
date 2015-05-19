const int BUTTON_1_PIN = 9;
const int BUTTON_2_PIN = 10;
const int BUTTON_3_PIN = 11;

const int LED_1_PIN = 1;
const int LED_2_PIN = 2;
const int LED_3_PIN = 3;
const int LED_4_PIN = 4;

void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(BUTTON_3_PIN, INPUT);
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
}

int  button1_pressed = 0;
byte button1_count = 0;

int  button2_pressed = 0;
byte button2_count = 0;

int  button3_pressed = 0;
byte button3_count = 0;

void loop()
{
  led_event();
  button_event();
  
}

void button_event()
{
	int button1_read = digitalRead(BUTTON_1_PIN);
	int button2_read = digitalRead(BUTTON_2_PIN);
	int button3_read = digitalRead(BUTTON_3_PIN);
	
	if(button1_pressed == 1 && button1_read == LOW)
		button1_pressed == 0;
		
	if(button2_pressed == 1 && button1_read == LOW)
		button2_pressed == 0;
		
	if(button3_pressed == 1 && button1_read == LOW)
		button3_pressed == 0;
		
	if(button1_pressed == 0 && button1_read == HIGH)
	{
		button1_count++;
		button1_pressed = 1;
		Serial.write(0x72);
		Serial.write(0x01);
		Serial.write(button1_count);
		Serial.write(0xFF);
	}
	if(button2_pressed == 0 && button2_read == HIGH)
	{
		button2_count++;
		button2_pressed = 1;
		Serial.write(0x72);
		Serial.write(0x01);
		Serial.write(button2_count);
		Serial.write(0xFF);
	}
	if(button3_pressed == 0 && button3_read == HIGH)
	{
		button3_count++;
		button3_pressed = 1;
		Serial.write(0x72);
		Serial.write(0x01);
		Serial.write(button3_count);
		Serial.write(0xFF);
	}
}

void led_event()
{
	while(Serial.available() > 0)
	{
		byte in0 = Serial.read()
		if (in0 == 0x54)
		{
			while(Serial.available() < 3)
			{
				delay(1);
			}
			
			byte in1 = Serial.read();
			byte in2 = Serial.read();
			byte in3 = Serial.read();

			if (in3 != 0xFF)
				return;

			int pin = 0;
			if (in1 == 0x01)
				pin = LED_1_PIN;
			else if (in1 == 0x02)
				pin = LED_2_PIN;
			else if (in1 == 0x03)
				pin = LED_3_PIN;
			else if  (in1 == 0x04)
				pin = LED_4_PIN;
	
			if (pin != 0)
			{
				if (in2 == 0x00)
					digitalWrite(pin, LOW);
				else if (in2 == 0x01)
					digitalWrite(pin, HIGH);
			}
		}
	}
}
