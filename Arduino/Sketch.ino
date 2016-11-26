 #include <Servo.h>

Servo eins;                          
float degr = 0;
int i=0;
int stato=-1;
int ledPin = 13;

int values[] = {0,0};
float info_serial[2];
int currentValue = 0;
void setup()
{
   Serial.begin(9600);                  
   eins.attach(9);   
   pinMode(ledPin,OUTPUT);

}

void loop()
{
   if (Serial.available() > 0) 
   {        
    int incomingValue = Serial.read();
    values[currentValue] = incomingValue;
    currentValue++;
    if(currentValue > 1){
      currentValue = 0;
                 
   }

  
   }
   
   
   if(values[0]!=0){
     eins.write((180*values[0])/70);
    Serial.flush();
     }
     
   
     
    
  if(values[1]==1){
     
         if(digitalRead(ledPin)==LOW){
          
          acceso();
       
          
        }
        
           if(digitalRead(ledPin)==HIGH){   
            spento();
            
        }
          }
       
         

}
void acceso(){ 

digitalWrite(ledPin,HIGH);

Serial.flush();
return;
}
void spento(){ 

digitalWrite(ledPin,LOW);

Serial.flush();
return;
}
