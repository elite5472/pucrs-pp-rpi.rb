const int BUTTON_1_PIN = 2;
const int BUTTON_2_PIN = 3;
const int BUTTON_3_PIN = 4;

void setup() 
{
  Serial.begin(9600);
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(BUTTON_3_PIN, INPUT);
  
  digitalWrite(BUTTON_1_PIN, HIGH);
  digitalWrite(BUTTON_2_PIN, HIGH);
  digitalWrite(BUTTON_3_PIN, HIGH);
}

int bt1_state;
int bt2_state;
int bt3_state;

void loop()
{
  bt1_state = !digitalRead(BUTTON_1_PIN);
  bt2_state = !digitalRead(BUTTON_2_PIN);
  bt3_state = !digitalRead(BUTTON_3_PIN);
  
  if(bt1_state == HIGH)
  {
    Serial.print("Hello bt1\n");
    Serial.write(13);
  }
  
  if(bt2_state == HIGH)
  {
    Serial.print("Hello bt2\n");
    Serial.write(13);
  }
  
  if(bt3_state == HIGH)
  {
    Serial.print("Hello bt3\n");
    Serial.write(13);
  }

}
