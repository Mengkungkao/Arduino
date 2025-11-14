#include "SD.h"       //Lib to read SD card
//cs10, sck13, mosi11, miso12
#define SD_ChipSelectPin 10
#include "TMRpcm.h"   //Lib to play audio
#include "SPI.h"      //SPI lib for SD card
TMRpcm tmrpcm;        //Lib object is named "tmrpcm"
int P0;
int P1;
int P2;
int P3;
int P4;
int P5;
int P6;
int P7;
int k =  200;

int sensorReading = 0;

void setup() {
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    return;
  }
  tmrpcm.setVolume(6);

}

void loop() {
  P0 = analogRead(A0);
  P1 = analogRead(A1);
  P2 = analogRead(A2);
  P3 = analogRead(A3);
  P4 = analogRead(A4);
  P5 = analogRead(A5);
  P6 = analogRead(A6);
  P7 = analogRead(A7);
  if (P0 > k) {
    tmrpcm.play("1.wav");
  }
  if (P1 > k) {
    tmrpcm.play("2.wav");
  }
  if (P2 > k) {
    tmrpcm.play("3.wav");
  }
  if (P3 > k) {
    tmrpcm.play("4.wav");
  }
}
