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
    
        if(inByte == 0){        // se receber 0, troca o estado do LED (compilacao OK)
            if(LEDstate == 0){
               digitalWrite(LED_PIN, HIGH);
               LEDstate = 1;
            }
            else{
               digitalWrite(LED_PIN, LOW);
               LEDstate = 0;
            }
        }
        
        if(inByte > 0){        // se receber algo diferente de 0, pisca o LED (compilacao nao OK - warning ou erro)
            int count = 0;
            while(count < 10)
            {
                digitalWrite(LED_PIN, HIGH);
                LEDstate = 1;
                delay(1000);
                digitalWrite(LED_PIN, LOW);
                LEDstate = 0;
                delay(1000);
                count++;
            }
        }
        
    }
}
