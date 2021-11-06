char i,j;
const int led_o = 2;
int st = 0;
int z;
char amplitude, repeticao;
int tempo = 1800; // tempo em microsegundos para os passos

// define números de pinos
  /**Motor de baixo**/
  const int stepPin_1 = 33 ;
  const int dirPin_1 = 27 ; 
   /**Motor de cima**/
  const int stepPin_2 = 14 ;
  const int dirPin_2 = 12 ; 

void setup() {
  Serial.begin(9600);
  pinMode(led_o, OUTPUT);
  
  // Define os dois pinos como Saídas
  pinMode ( stepPin_1, OUTPUT ) ;
  pinMode ( dirPin_1, OUTPUT ) ;
  pinMode ( stepPin_2, OUTPUT ) ;
  pinMode ( dirPin_2, OUTPUT ) ;
  
}

void loop() {
  if(Serial.available()>0){
    amplitude = Serial.read();
    repeticao = Serial.read();

    //Leds utilizados para sinalizar o start
    for(st=0;st<3;st++)
    {
         digitalWrite (led_o, HIGH);
         delay (200);
         digitalWrite (led_o, LOW);
         delay (200);
    }
    Serial.write (46);//envia um ponto pra evitar o fim da conexão serial
    
    for(j=48;j<repeticao;j++)
      {
        //1º QUARTO DE VOLTA
        digitalWrite(dirPin_1, HIGH); 
        digitalWrite(dirPin_2, LOW);
     
        for(z=0;z<35;z++)
          {
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);

            digitalWrite(stepPin_2,LOW);
             if(z>32){digitalWrite(stepPin_1,LOW);}
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
             if(z>32){ digitalWrite(stepPin_1,HIGH);}
            delayMicroseconds(tempo);
            
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);

            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
            
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
          }
          Serial.write (46);//envia um ponto pra evitar o fim da conexão serial
          
        //2º Quarto de volta
         for(z=0;z<18;z++)
          {
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
   
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
          } 

           for(z=0;z<18;z++)
          {
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
   
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
          } 
           for(z=0;z<18;z++)
          {
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
   
            digitalWrite(stepPin_1,LOW);
            if(z>10){  digitalWrite(stepPin_2,LOW);}
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            if(z>10){  digitalWrite(stepPin_2,HIGH);}
            delayMicroseconds(tempo);
          }
           
              for(z=0;z<18;z++)
          {
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
   
            digitalWrite(stepPin_1,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            delayMicroseconds(tempo);
            if(z>10){
              digitalWrite(stepPin_1,LOW);
              delayMicroseconds(tempo);
              digitalWrite(stepPin_1,HIGH);
              delayMicroseconds(tempo);
            }
          }
           digitalWrite(dirPin_2, HIGH); //mudando a direção do motor 2
           
           for(z=0;z<25;z++)
          {
            digitalWrite(stepPin_1,LOW);
          if(z>15){  digitalWrite(stepPin_2,LOW);}
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
           if(z>15){ digitalWrite(stepPin_2,HIGH);}
            delayMicroseconds(tempo);
          } 
          Serial.write (46);//envia um ponto pra evitar o fim da conexão serial
          
          //3º Quarto de volta
           for (z=0;z<16;z++)
           {
            if(z>5){
                digitalWrite(stepPin_2,LOW);
                delayMicroseconds(tempo);
                digitalWrite(stepPin_2,HIGH);
                delayMicroseconds(tempo);
    
                digitalWrite(stepPin_2,LOW);
                delayMicroseconds(tempo);
                digitalWrite(stepPin_2,HIGH);
                delayMicroseconds(tempo);
            }
            
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
           }

            digitalWrite(dirPin_1, LOW); //mudando a direção do motor 1

            for(z=0;z<15;z++)
          {
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
            
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
            
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
          }
           for(z=0;z<30;z++)
          {
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
            
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);

            digitalWrite(stepPin_1,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            delayMicroseconds(tempo);
            if(z<25){
              digitalWrite(stepPin_2,LOW);
              delayMicroseconds(tempo);
              digitalWrite(stepPin_2,HIGH);
              delayMicroseconds(tempo);
            }
          }
          Serial.write (46);//envia um ponto pra evitar o fim da conexão serial
          
          //Último Quarto de volta
          for(z=0;z<60;z++)
          {
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);

            if(z>49){
              digitalWrite(stepPin_2,LOW);
              delayMicroseconds(tempo);
              digitalWrite(stepPin_2,HIGH);
              delayMicroseconds(tempo);
            }
          }

           for(z=0;z<42;z++)
          {
            digitalWrite(stepPin_1,LOW);
            digitalWrite(stepPin_2,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            digitalWrite(stepPin_2,HIGH);
            delayMicroseconds(tempo);
          
            digitalWrite(stepPin_1,LOW);
            delayMicroseconds(tempo);
            digitalWrite(stepPin_1,HIGH);
            delayMicroseconds(tempo);
         
          }
          /*digitalWrite(stepPin_1,LOW);
          delayMicroseconds(tempo);
          digitalWrite(stepPin_1,HIGH);
          delayMicroseconds(tempo);*/
      }
        Serial.write (122);
        //int bytesSent = Serial.write(“hello”);  //envia a string “hello” e retorna o tamanho da string.
    }
}
