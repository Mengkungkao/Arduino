

int L2 = 12;
int L3 = 11;
int L4 = 10;
int L5 = 9;
int L6 = 8;
int L7 = 7;  //7 LED pin

int buttonPin = 6;  //the number of the pushbutton pin

int de = 50; // delay time

int p = 0;  // variable for pattem

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {


  
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);

  pinMode(buttonPin, INPUT);

}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)

  {
    p++;
    delay(2000);
  }

  



  if (p == 2)
  {
   
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 1); //7
    delay(de);

   
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 1);
    digitalWrite(L7, 0); //6
    delay(de);

   
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 1);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //5
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 1);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //4
    delay(de);

  
    digitalWrite(L2, 0);
    digitalWrite(L3, 1);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //3
    delay(de);


   
    digitalWrite(L2, 1);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //2
    delay(de);

   
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //1
    delay(de);

  }

  if (p == 3)
  {
   
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //1
    delay(de);

   
    digitalWrite(L2, 1);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //2
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 1);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //3
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 1);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //4
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 1);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //5
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 1);
    digitalWrite(L7, 0); //6
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 1); //7
    delay(de);


    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 1);
    digitalWrite(L7, 0); //6
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 1);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //5
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 1);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //4
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 1);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //3
    delay(de);


    
    digitalWrite(L2, 1);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //2
    delay(de);
  }




  if (p == 4)
  {
    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 1); //1,7
    delay(de);

    
    digitalWrite(L2, 1);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 1);
    digitalWrite(L7, 0); //2,6
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 1);
    digitalWrite(L4, 0);
    digitalWrite(L5, 1);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //3,5
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 1);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //4
    delay(de);

  }


  if (p == 5)
  {


    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 1);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //4
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 1);
    digitalWrite(L4, 0);
    digitalWrite(L5, 1);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //3,5
    delay(de);



    
    digitalWrite(L2, 1);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 1);
    digitalWrite(L7, 0); //2,6
    delay(de);

    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 1); //1,7
    delay(de);
  }

  if (p == 6)
  {
    
    delay(de);
    digitalWrite(L2, 1);
    delay(de);
    digitalWrite(L3, 1);
    delay(de);
    digitalWrite(L4, 1);
    delay(de);
    digitalWrite(L5, 1);
    delay(de);
    digitalWrite(L6, 1);
    delay(de);
    digitalWrite(L7, 1); //1,7
    delay(de);
    digitalWrite(L7, 0); //1,7
    delay(de);
    digitalWrite(L6, 0);
    delay(de);
    digitalWrite(L5, 0);
    delay(de);
    digitalWrite(L4, 0);
    delay(de);
    digitalWrite(L3, 0);
    delay(de);
    digitalWrite(L2, 0);
    delay(de);
    
    delay(de);


  }

  if (p == 7)
  {
    
    digitalWrite(L2, 0);
    digitalWrite(L3, 0);
    digitalWrite(L4, 0);
    digitalWrite(L5, 0);
    digitalWrite(L6, 0);
    digitalWrite(L7, 0); //1,7
    p = 0;
  }

}
