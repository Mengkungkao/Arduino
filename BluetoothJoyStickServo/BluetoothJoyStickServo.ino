#include<Servo.h>
#include<SoftwareSerial.h>
Servo s1;
Servo s2;
int joyX = 0;
int joyY = 1;
int v;
signed int x;
signed int y;
signed int z;
signed int btna;
signed int btnb;
float a;
float m;

boolean fast = true;
int ML = 4;         
int MR = 7;         

int EL = 5;         
int ER = 6;
String str;
char dir = 0;
int el = 0;         
int er = 0;         

int elp = 0;        
int erp = 0;


void setup() {
  s1.attach(9);
  s2.attach(10);
  Serial.begin(9600);
  Serial.println("Start");

  

}

void loop() {
  while(Serial.available())             //as long as incoming serial signal is available
    {
      
      char getData = Serial.read();       //read a byte
      
  

        if (getData == 'x')               //similar to *** (for Button X)
        {  
          delay(5);        
          if (Serial.read() == '#') 
          {
            processx();
          }
        }      
       
        if (getData == 'y')               //similar to *** (for Button Y)
        {    
          delay(5);
          if (Serial.read() == '#') 
          {
            processy();
          }
        }   

        if (getData == 'z')               //similar to *** (for Button Z)
        {     
          delay(5);
          if (Serial.read() == '#') 
          {
            processz();
          }
        } 
        
        
        if (getData == '~') {                       //here is where we try to parse string sent by analog joystick - find '~' first
        
          x = Serial.parseInt();                    //if '~' has been successfully found, parse the following numbers and keep it in variable x (x is the speed of motor left)
        
            if (Serial.read() == '*') {             //next, find '*'
        
              y = Serial.parseInt();                //if '*' is found, parse the numbers that follow it (y is the speed of motor right)
        
                if (Serial.read() == '@') {         //find '@'
                
                  z = Serial.parseInt();            //parse the following numbers
                  
                    if (Serial.read() == '#') {     //finally is the string is ended with '#'?
                    
                      process();                    //process all the parsed string if '#' is found
                  }                
              } 
           }
        }
        
          
        
    }
    
}

void processx(){                                                                        //set to fast mode
  Serial.println("Button x! "); 
  Serial.flush(); 
  fast = true;
}

void processy(){
  Serial.println("Button y! ");                                                         //do nothing except print something on serial monitor
  Serial.flush(); 
}

void processz(){                                                                        //set to slow mode
  Serial.println("Button z! "); 
  Serial.flush(); 
  fast = false;
}
void process(){
           
  if (fast == false) { er = map(y, 0, 500, 0, 255); }                //if slow mode was set, convert maximum value for y from 500 to 255 (y is motor right's speed)                  
  else { er = y; }                                                   //if fast mode was set, proceed with current maximum value           

  erp = abs(er);                                                     //take the absolute value of motor right's speed and keep it to erp (processed motor right's speed)


  if (fast == false) { el = map(x, 0, 500, 0, 255); }                //if slow mode was set, convert maximum value for x from 500 to 255 (x is motor left's speed)   
  else { el = x; }                                                   //if fast mode was set, proceed with current maximum value     
  
  elp = abs(el);                                                     //take the absolute value of motor left's speed and keep it to elp (processed motor left's speed)

  //erp= map(er,0,1023,0,180);
  //elp= map(el,0,1023,0,180);
                                                   
  v= map(v,0,1023,0,180);
  s1.write(elp);
  s1.write(v);
  v=analogRead(joyY);
  v= map(v,0,1023,0,180);
  s2.write(erp);
  s2.write(v);
  Serial.flush(); 
}
