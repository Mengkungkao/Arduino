// Cathod 7 Segment with GND below

int sevensegment [7] = {2,3,4,5,6,7,8};
int numer_diplay[10][7] = {//a  b  c  d  e  f  g
                            1, 1, 1, 1, 1, 1, 0,  //0
                            0, 1, 1, 0, 0, 0, 0,  //1
                            1, 1, 0, 1, 1, 0, 1,  //2
                            1, 1, 1, 1, 0, 0, 1,  //3
                            0, 1, 1, 0, 0, 1, 1,  //4
                            1, 0, 1, 1, 0, 1, 1,  //5
                            1, 0, 1, 1, 1, 1, 1,  //6
                            1, 1, 1, 0, 0, 0, 0,  //7
                            1, 1, 1, 1, 1, 1, 1,  //8
                            1, 1, 1, 1, 0, 1, 1 //9
                            };
void setup() {
  // put your setup code here, to run once:
for(int k; k<=7;k++){
  pinMode(sevensegment [k],OUTPUT);
  Serial.begin(9600);
}
}
void loop() {
  // put your main code here, to run repeatedly:
for(int i=0; i <10; i++){
  for(int j=0; j<7;j++)
  {
    digitalWrite(sevensegment [j],numer_diplay[i][j]);
    Serial.print(sevensegment [j]);
//    Serial.print(" ");
//    Serial.println(numer_diplay[1][1]);
  }
delay(500);
}
  
}
