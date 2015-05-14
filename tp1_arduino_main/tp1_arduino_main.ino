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
  led_event();
  button_event();
  
}

void button_event()
{
  if(digitalRead(BUTTON_1_PIN) == HIGH)
  {
     button1_count++;
     if(Serial.available){
         Serial.write(9);
         Serial.write(-1);
         Serial.write(2);
         Serial.write(-1);
         Serial.write(button1_count);
         Serial.write(-1);
         Serial.write(-1);
         Serial.write(8);
     }
  }
  else if (digitalRead(BUTTON_2_PIN) == HIGH)
  {
     button2_count++;
     if(Serial.available){
         Serial.write(9);
         Serial.write(-1);
         Serial.write(2);
         Serial.write(-1);
         Serial.write(-1);
         Serial.write(button2_count);
         Serial.write(-1);
         Serial.write(8);
     }
  }
  else if (digitalRead(BUTTON_3_PIN) == HIGH)
  {
     button3_count++;
     if(Serial.available){
         Serial.write(9);
         Serial.write(-1);
         Serial.write(2);
         Serial.write(-1);
         Serial.write(-1);
         Serial.write(-1);
         Serial.write(button3_count);
         Serial.write(8);
     }
  }
}

void led_event()
{
     int in;
     
     if(Serial.available)
     {
         in = Serial.read(); // 9
         
         in = Serial.read(); // -1
         
         in = Serial.read(); // 1
         if (in != 1){
             for(;;);
         }  
         
         in = Serial.read(); // led1
         if (in == 0){
             digitalWrite(LED_1_PIN, LOW);
         }
         else if (in == 1){
             digitalWrite(LED_1_PIN, HIGH);
         }
         
         in = Serial.read(); // led2
         if (in == 0){
             digitalWrite(LED_2_PIN, LOW);
         }
         else if (in == 1){
             digitalWrite(LED_2_PIN, HIGH);
         }
         
         in = Serial.read(); // led3
         if (in == 0){
             digitalWrite(LED_3_PIN, LOW);
         }
         else if (in == 1){
             digitalWrite(LED_3_PIN, HIGH);
         }
         
         in = Serial.read(); // led4
         if (in == 0){
             digitalWrite(LED_4_PIN, LOW);
         }
         else if (in == 1){
             digitalWrite(LED_4_PIN, HIGH);
         }
         
         in = Serial.read(); // 8
     }
}
