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

int button1_count = 0;
int button2_count = 0;
int button3_count = 0;

void loop()
{
  button_event();
  led_event();
}

void button_event()
{
  int buttonId = -1;
  if(digitalRead(BUTTON_1_PIN) == HIGH)
  {
    buttonId
  }
  else if (digitalRead(BUTTON_2_PIN) == HIGH)
  {
    
  }
  else if (digitalRead(BUTTON_3_PIN) == HIGH)
  {
    
  }
}

void led_event()
{
  
}
