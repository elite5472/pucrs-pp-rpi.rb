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

byte button1_count = 0;
byte button2_count = 0;
byte button3_count = 0;

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
     Serial.write(0x72)
     Serial.write(0x01)
     Serial.write(button1_count)
     Serial.write(0xFF);
  }
  else if (digitalRead(BUTTON_2_PIN) == HIGH)
  {
     button1_count++;
     Serial.write(0x72)
     Serial.write(0x02)
     Serial.write(button2_count)
     Serial.write(0xFF);
  }
  else if (digitalRead(BUTTON_3_PIN) == HIGH)
  {
     button1_count++;
     Serial.write(0x72)
     Serial.write(0x03)
     Serial.write(button3_count)
     Serial.write(0xFF);
  }
}

void led_event()
{
     byte in0;
     byte in1;
     byte in2;
     byte in3;
     
     if(Serial.available() >= 4)
     {
         in0 = Serial.read(); 
         in1 = Serial.read(); 
         in2 = Serial.read(); 
         in3 = Serial.read();
         
         if (in0 != 0x54 && in3 != 0xFF) return;
         
           if(in == 0x01)
           {
               in = Serial.read();
               if (in == 0x00)
               {
                   digitalWrite(LED_1_PIN, LOW);
               }
               else if (in == 0x01)
               {
                   digitalWrite(LED_1_PIN, HIGH);
               }
           }
           else if (in == 0x02)
           {
               in = Serial.read();
               if (in == 0x00)
               {
                   digitalWrite(LED_2_PIN, LOW);
               }
               else if (in == 0x01)
               {
                   digitalWrite(LED_2_PIN, HIGH);
               }             
           }
           else if (in == 0x03)
           {
               in = Serial.read();
               if (in == 0x00)
               {
                   digitalWrite(LED_3_PIN, LOW);
               }
               else if (in == 0x01)
               {
                   digitalWrite(LED_3_PIN, HIGH);
               }             
           }
           else if (in == 0x04)
           {
               in = Serial.read();
               if (in == 0x00){
                   digitalWrite(LED_4_PIN, LOW);
               }
               else if (in == 0x01){
                   digitalWrite(LED_4_PIN, HIGH);
               }             
           }
     }
}
