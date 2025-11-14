signed int x;
signed int y;
signed int z;
signed int btna;
signed int btnb;
float a;
float m;


String str;
char dir = 0;

int ML = 4;         //ML is direction control pin of Motor Left - we connect it to pin 4 (depend to the motor driver module configuration - please refer to manufacturer's datasheet)
int MR = 7;         //MR is direction control pin of Motor Right - we connect it to pin 7 (depend to the motor driver module configuration - please refer to manufacturer's datasheet)

int EL = 5;         //EL is speed control pin of Motor Left - we connect it to pin 5 (depend to the motor driver module configuration - please refer to manufacturer's datasheet)
int ER = 6;         //ER is speed control pin of Motor Right - we connect it to pin 6 (depend to the motor driver module configuration - please refer to manufacturer's datasheet)

int el = 0;         //variable to hold motor left's raw speed
int er = 0;         //variable to hold motor right's raw speed

int elp = 0;        //variable to hold motor left's processed speed
int erp = 0;        //variable to hold motor right's processed speed


boolean fast = true;          //to switch between slow/fast mode (optional)
boolean StateA0 = false;      //to hold the toggle state of button A (optional; and you can use any name you like such as "PlanetJupiter" or "ButtonA_State" or "MyHouse")
boolean StateA1 = false;      //to hold the toggle state of button B (optional; and you can use any name you like such as "Boat" or "ButtonB_State" or "HisHouse")
boolean State11 = false;      //to hold the toggle state of button C (optional; and you can use any name you like such as "Parachute" or "ButtonC_State" or "TheirHouse")


void setup() {
  
pinMode(MR, OUTPUT);          //set MR pin to be output
pinMode(ML, OUTPUT);          //set ML pin to be output
pinMode(ER, OUTPUT);          //set ER pin to be output
pinMode(EL, OUTPUT);          //set EL pin to be output

pinMode(11, OUTPUT);          //set 11 pin to be output - this pin is only used with button A (optional; can be changed to other pins or not used at all)
pinMode(A0, OUTPUT);          //set A0 pin to be output - this pin is only used with button B (optional; can be changed to other pins or not used at all)
pinMode(A1, OUTPUT);          //set A1 pin to be output - this pin is only used with button C (optional; can be changed to other pins or not used at all)

Serial.begin(9600);           //set baud rate to 9600
Serial.println("Start");      //print something that can indicate that we have successfully started our program
}


void loop() 
{
    while(Serial.available())             //as long as incoming serial signal is available
    {
      
      char getData = Serial.read();       //read a byte
      
        if (getData == 'M')               //compare it to 'M' (this function reads Magnitude value sent by the Arduino Robot Joystick app when you press the Magnitude button; this function...
        //...is actually not used for building 4WD robot that you see in the YouTube video)    (***)
        
        {
          m = Serial.parseFloat();        //if the received byte was 'M', parse the following bytes and keep it in variable m...
          
          if (Serial.read() == '#')       //...until '#' is received
          {
            processM();                   //send the parsed float (m) to processM() function
          }
        }
        
        if (getData == 'A')               //similar to *** (this function reads Magnitude value sent by the Arduino Robot Joystick app when you press the Angle button; this function...
        //...is actually not used for building 4WD robot that you see in the YouTube video) 
        
        {
          a = Serial.parseFloat();
          
          if (Serial.read() == '#') 
          {
            processA();
          }
        }
       
        if (getData == 'a')               //similar to *** (for Button A)
        {  
          delay(5);                       //since no numbers are sent after letter 'a', we give a little delay as a dummy
          if (Serial.read() == '#')   
          {
            processa();
          }
        }      
       
        if (getData == 'b')               //similar to *** (for Button B)
        {    
          delay(5);
          if (Serial.read() == '#') 
          {
            processb();
          }
        }   

        if (getData == 'c')               //similar to *** (for Button C)
        {     
          delay(5);
          if (Serial.read() == '#') 
          {
            processc();
          }
        } 

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

void processa(){
  Serial.println("Button a! ");                                                         //print on screen when button A is pressed
  StateA0 = !StateA0;                                                                   //toggle the current state
  if (StateA0 == true) { digitalWrite(A0, HIGH); } else { digitalWrite(A0, LOW); }      //if state is true then set A0 to high, otherwise, set it to low
  Serial.flush();                                                                       //clear the serial memory if any
}

void processb(){                                                                        //similar to processa() 
  Serial.println("Button b! "); 
  State11 = !State11;
  if (State11 == true) { digitalWrite(11, HIGH); } else { digitalWrite(11, LOW); }
  Serial.flush(); 
}

void processc(){                                                                        //also similar to processa() 
  Serial.println("Button c! ");
  StateA1 = !StateA1;
  if (StateA1 == true) { digitalWrite(A1, HIGH); } else { digitalWrite(A1, LOW); }
  Serial.flush();  
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

void processM(){
  m1 = map(m, 0, 500, 0, 255);                                                          //convert the minimum value of m from 0 to 0 and maximum from 500 to 255 (mapping function)
  Serial.print("Received Magnitude: ");
  Serial.println(m1); 
  Serial.flush();   
}

void processA(){
  Serial.print("Received Angle: ");
  Serial.println(a);                                                                    //print parsed string for angle
  Serial.flush();   
}

void process(){
           
  if (fast == false) { er = map(y, 0, 500, 0, 255); }                //if slow mode was set, convert maximum value for y from 500 to 255 (y is motor right's speed)                  
  else { er = y; }                                                   //if fast mode was set, proceed with current maximum value           

  if (er < 0) {                                                      //if motor right's speed that received from the Arduino Joystick app is negative,...
    digitalWrite(MR, HIGH);                                          //...set direction control pin to make motor right reverses
  } 
  else if (er >= 0) {                                                //else if motor right's speed that received from the Arduino Joystick app is positive,...
    digitalWrite(MR, LOW);                                           //...set direction control pin to make motor right turns the other way
  } 
  erp = abs(er);                                                     //take the absolute value of motor right's speed and keep it to erp (processed motor right's speed)


  if (fast == false) { el = map(x, 0, 500, 0, 255); }                //if slow mode was set, convert maximum value for x from 500 to 255 (x is motor left's speed)   
  else { el = x; }                                                   //if fast mode was set, proceed with current maximum value     
  
  if (el < 0) {                                                      //if motor left's speed that received from the Arduino Joystick app is negative,...
    digitalWrite(ML, HIGH);                                          //...set direction control pin to make motor left reverses
  } 
  else if (el >= 0)  {                                               //else if motor left's speed that received from the Arduino Joystick app is positive,...
    digitalWrite(ML, LOW);                                           //...set direction control pin to make motor left turns the other way
  } 
  elp = abs(el);                                                     //take the absolute value of motor left's speed and keep it to elp (processed motor left's speed)
                                                 
  analogWrite(EL, elp);                                              //supply speed control pin for motor left with processed motor left's speed value
  analogWrite(ER, erp);                                              //supply speed control pin for motor right with processed motor right's speed value
  
  
  Serial.flush();                                                    //clear the serial trash if any
}  
