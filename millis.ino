unsigned long tempoatual = millis();
unsigned long tempoanterior1 = 0;
unsigned long tempoanterior2 = 0;
int led1 = 3000;
int led2 = 5000; 
bool state1 = 0;
bool state2 = 0;
int statebtn = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempoatual = millis();
  
  if((tempoatual - tempoanterior1) > led1 && statebtn != 2){
   
      state1 = !state1;
    
      digitalWrite(10,state1);
    
      tempoanterior1 = tempoatual;
    
  }

  if((tempoatual - tempoanterior2) > led2 && statebtn != 3){
   
      state2 = !state2;
    
      digitalWrite(11,state2);
    
      tempoanterior2 =tempoatual;
    
  }
  
  if (digitalRead(12) == 0){
     if(statebtn == 1){
     
     statebtn++;
      while(digitalRead(12) == 0){
        Serial.println("a espera de soltar o botao");
      }
  }
    else if (statebtn == 2){
      statebtn++;
       while(digitalRead(12) == 0){
        Serial.println("a espera de soltar o botao");
      }
    }
    else if (statebtn == 3){
      statebtn = 1;
       while(digitalRead(12) == 0){
        Serial.println("a espera de soltar o botao");
      }
    }
  }
  if (statebtn == 2){
    state1 = LOW;
    digitalWrite(10,state1);
  }
  if(statebtn == 3){
    state2 = LOW;
    digitalWrite(11,state2);
  }
  Serial.println(digitalRead(12));


  
}
void leds (int led1, int led2){
  
  if((tempoatual - tempoanterior1) > led1){
   
      state1 = !state1;
    
      digitalWrite(10,state1);
    
      tempoanterior1 = tempoatual;
    
  }

  if((tempoatual - tempoanterior2) > led2){
   
      state2 = !state2;
    
      digitalWrite(11,state2);
    
      tempoanterior2 =tempoatual;
    
  }
  
}
