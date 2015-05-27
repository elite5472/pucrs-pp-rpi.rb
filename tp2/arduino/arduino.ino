int inByte;

const int BUTTON_1_PIN = 9;  // PB1
const int BUTTON_2_PIN = 10; // PB2
const int BUTTON_3_PIN = 11; // PB3

const int LED_1_PIN = 5; // PD5
const int LED_2_PIN = 2; // PD2
const int LED_3_PIN = 3; // PD3
const int LED_4_PIN = 4; // PD4

int LEDstate[] = {1, 1, 1, 1};

int  button1_pressed = 0;
byte button1_count = 0;

int  button2_pressed = 0;
byte button2_count = 0;

int  button3_pressed = 0;
byte button3_count = 0;

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
  
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, HIGH);
  digitalWrite(LED_3_PIN, HIGH);
  digitalWrite(LED_4_PIN, HIGH);
}

void loop()
{
  led_event();
  //button_event();
}

void led_event()
{
     if (Serial.available()) {
  
        inByte = Serial.read();
    
        if(inByte == 1){
            if(LEDstate[0] == 0){
               digitalWrite(LED_1_PIN, HIGH);
               LEDstate[0] = 1; 
            }
            else{
               digitalWrite(LED_1_PIN, LOW);
               LEDstate[0] = 0;
            }
        }
        
        if(inByte == 2){
            if(LEDstate[1] == 0){
               digitalWrite(LED_2_PIN, HIGH);
               LEDstate[1] = 1; 
            }
            else{
               digitalWrite(LED_2_PIN, LOW);
               LEDstate[1] = 0;
            }
        }
        
        if(inByte == 3){
            if(LEDstate[2] == 0){
               digitalWrite(LED_3_PIN, HIGH);
               LEDstate[2] = 1; 
            }
            else{
               digitalWrite(LED_3_PIN, LOW);
               LEDstate[2] = 0;
            }
        }
        
        if(inByte == 4){
            if(LEDstate[3] == 0){
               digitalWrite(LED_4_PIN, HIGH);
               LEDstate[3] = 1; 
            }
            else{
               digitalWrite(LED_4_PIN, LOW);
               LEDstate[3] = 0;
            }
        }
    }
}

void button_event()
{
	int button1_read = !digitalRead(BUTTON_1_PIN);
	int button2_read = !digitalRead(BUTTON_2_PIN);
	int button3_read = !digitalRead(BUTTON_3_PIN);
	
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
		Serial.write(1);
		Serial.write(button1_count);
	}
	if(button2_pressed == 0 && button2_read == HIGH)
	{
		button2_count++;
		button2_pressed = 1;
		Serial.write(2);
		Serial.write(button2_count);
	}
	if(button3_pressed == 0 && button3_read == HIGH)
	{
		button3_count++;
		button3_pressed = 1;
		Serial.write(3);
		Serial.write(button3_count);
	}
}