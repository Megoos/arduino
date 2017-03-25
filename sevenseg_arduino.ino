void setup() {
  Serial.begin(9600);
  for (int i = 3; i < 13; i++){
    pinMode(i,OUTPUT);
    }     
}

void none(){
  for(int i = 6; i < 13; i++)
    if(i!=12){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }

void zero(){
  for(int i = 6; i < 13; i++)
    if(i==12){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }
  
void one(){
  for(int i = 6; i < 13; i++)
    if(i!=7 && i!=8){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }

void two(){
  for(int i = 6; i < 13; i++)
    if(i==8 || i==11){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }

void three(){
  for(int i = 6; i < 13; i++)
    if(i==10 || i==11){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }  
    
void four(){
  for(int i = 6; i < 13; i++)
    if(i==6 || i==9 || i==10){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }

void five(){
  for(int i = 6; i < 13; i++)
    if(i==7 || i==10){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }

void six(){
  for(int i = 6; i < 13; i++)
    if(i==7){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }  

void seven(){
  for(int i = 6; i < 13; i++)
    if(i!=7 && i!=8 && i!=6){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }

void eight(){
  for(int i = 6; i < 13; i++)    
       digitalWrite(i,HIGH);      
  }

void nine(){
  for(int i = 6; i < 13; i++)
    if(i==10){
    digitalWrite(i,LOW);
    }else{
       digitalWrite(i,HIGH);
      }
  }  
  
void digit(int d, int c){
  switch (d){
    case 1:
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    break;
    case 2:
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);
    break;
    case 3:
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    break;
    default: 
    break;
    } 

   switch (c){
    case 0: zero();
            break;
    case 1: one();
            break;
    case 2: two();
            break;        
    case 3: three();
            break;
    case 4: four();
            break;
    case 5: five();
            break; 
    case 6: six();
            break;  
    case 7: seven();
            break;
    case 8: eight();
            break;
    case 9: nine();
            break;       
    case 11: none();
            break; 
    default : none(); break;              
    }  
      delay(5);
  }  

void vivod (int mun){

int del = 100;
int st = 0;
int i=1;
if(mun<100){
  digit(i,11);  
  del=del/10;
  i=2;   
}
if(mun<10){
  digit(i,11);
  del=del/10;
  i=3;
  }
  for (i; i < 4; i++){       
       st = mun/del;
       mun = mun-st*del; 
       digit(i,st);       
       del=del/10;
     }
  }

int i = 25;
unsigned long prev_ms = 0;
void loop() {  
 if ((millis() - prev_ms) >  500) { //вывод данных каждые 1500мс
        prev_ms = millis();        
        i++;
    }
vivod(i);
}
