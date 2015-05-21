int inByte ;      

const int LED_1_PIN = 10;
const int LED_2_PIN = 11;
const int LED_3_PIN = 12;
const int LED_4_PIN = 13;

int LEDstate[] = {1, 1, 1, 1};

void setup() {       

  Serial.begin(9600);

  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  
  digitalWrite(LED_1_PIN, HIGH);
  digitalWrite(LED_2_PIN, HIGH);
  digitalWrite(LED_3_PIN, HIGH);
  digitalWrite(LED_4_PIN, HIGH);
}

void loop() {

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




