#include "LedControl.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int melody2[] = {
 NOTE_A4, 0, NOTE_D5, 0, NOTE_A4, 0, NOTE_D5, 0, NOTE_A4, NOTE_D5, 0, NOTE_A4, 0, 0, NOTE_GS4, NOTE_A4, 0, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_G4, 0, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_D4, NOTE_A4, 0, NOTE_D5, 0, NOTE_A4, 0, NOTE_D5, 0, NOTE_A4, NOTE_D5, 0, NOTE_A4, 0, 0, NOTE_GS4, NOTE_A4, 0, NOTE_G4, 0, NOTE_G4, NOTE_FS4, NOTE_G4, 0, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_A4, 0, NOTE_D5, 0, NOTE_A4, 0, NOTE_D5, 0, NOTE_A4, NOTE_D5, 0, NOTE_A4, 0, 0, NOTE_GS4, NOTE_A4, 0, NOTE_C5,0, 0, NOTE_C5, NOTE_A4, NOTE_G4, 0, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_DS5, NOTE_D5, NOTE_GS4, NOTE_A4, 0, NOTE_F4, 0};

double noteDurations2[] = {
 4, 64, 4, 64, 4, 64, 4, 64, 8, 4, 64, 8, 64, 8, 8, 4, 64, 8, 8, 8, 8, 8, 8, 8, 8, 2.666, 1.99, 4, 64, 4, 64, 4, 64, 4, 64, 8, 4, 64, 8, 64, 8, 8, 4, 64, 8, 8, 2.666, 8, 4, 64, 8, 4, 4, 2.666, 4, 64, 4, 64, 4, 64, 4, 64, 8, 4, 64, 8, 64, 8, 8, 4, 64, 8, 64, 8, 2.666, 8, 4, 64, 2.666, 1.99, 2, 2, 2, 2, 4, 4, 8, 4, 64, 4, 2};

int buzzer = 3;
int ledPin =  7;  
const int buttonPin = 5;

/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to CS
 */
LedControl lc=LedControl(12,11,10,1);
unsigned long delaytime=600;
unsigned long delaytimeLong=2000;

byte F[8]={B11111100,B10000000,B10000000,B10000000,B11111100,B10000000,B10000000,B10000000};
byte I[8]={B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000,B00010000};
byte O[8]={B00111100,B01000010,B01000010,B01000010,B01000010,B01000010,B01000010,B00111100};
byte N[8]={B11000001,B11000001,B10100001,B10010001,B10001001,B10000101,B10000011,B10000011};
byte ALL[8]={B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte heart[8]={B00000000,B01100110,B11111111,B11111111,B11111111,B01111110,B00111100,B00011000};
byte face [8]={B00000000,B01100110,B01100110,B00000000,B01000010,B01000010,B01111110,B00000000};
byte creepyFace[8]={B00111100,B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};

void setup(void) {
  pinMode(ledPin, OUTPUT);  
  pinMode(buzzer, OUTPUT);
   /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);

  pinMode(buttonPin, INPUT_PULLUP);
}

void writeMatrixAll() {
 for(int i=0; i<8; i++){
  lc.setRow(0,i,0);// this is for blank
 }
 
 for (int i=0; i<8; i++){
  lc.setRow(0,i,ALL[i]);
 }
}

void writeMatrixCreepyFace() {
 for(int i=0; i<8; i++){
  lc.setRow(0,i,0);// this is for blank
 }
 
 for (int i=0; i<8; i++){
  lc.setRow(0,i,creepyFace[i]);
 }
}

void writeMatrixFace() {
 for(int i=0; i<8; i++){
  lc.setRow(0,i,0);// this is for blank
 }
 
 for (int i=0; i<8; i++){
  lc.setRow(0,i,face[i]);
 }
}

void writeMatrixHeart() {
 for(int i=0; i<8; i++){
  lc.setRow(0,i,0);// this is for blank
 }
 
 for (int i=0; i<8; i++){
  lc.setRow(0,i,heart[i]);
 }
}

void writeMatrixF() {
  for(int i=0; i<8; i++){
   lc.setRow(0,i,0);// this is for blank
  }
  
  for (int i=0; i<8; i++){
   lc.setRow(0,i,F[i]);
  }
   
}

void writeMatrixI() {
  for(int i=0; i<8; i++){
   lc.setRow(0,i,0);// this is for blank
  }
  
  for (int i=0; i<8; i++){
   lc.setRow(0,i,I[i]);
  }
}

void writeMatrixO() {
  for(int i=0; i<8; i++){
   lc.setRow(0,i,0);// this is for blank
  }
  for (int i=0; i<8; i++){
   lc.setRow(0,i,O[i]);
  }
}

void writeMatrixN() {
  for(int i=0; i<8; i++){
   lc.setRow(0,i,0);// this is for blank
  } 
  for (int i=0; i<8; i++){
   lc.setRow(0,i,N[i]);
  }
}

int state = 0;

void loop() {
 if (state == 0) {
  writeMatrixAll();
 }
 
  for (int thisNote = 0; thisNote < 91; thisNote++) {  // for 91 notes, this is what happens
    int noteDuration2 = 1000/noteDurations2[thisNote];  // defines note duration for cantina band
    tone(buzzer, melody2[thisNote],noteDuration2);  // tells the  buzzer to play the cantina band melody  
    int pauseBetweenNotes2 = noteDuration2 * 0.80; // sets the tempo
    delay(pauseBetweenNotes2);  //pauses the buzzer
    noTone(buzzer);  // stops the buzzer playing

   if (!digitalRead(buttonPin)) {
      if (state == 0) {
        writeMatrixF();
        state++;
      } else if (state == 1) {
         writeMatrixI();
         state++; 
      } else if (state == 2) {
        writeMatrixO();
        state++;  
      } else if (state == 3) {
        writeMatrixN();
        state++;
      } else if (state == 4) {
        writeMatrixHeart();
        state++;
      } else if (state == 5) {
        writeMatrixFace();
        state++;
      } else if (state == 6) {
        writeMatrixCreepyFace();
        state = 0;
      }
   } // End of button

  if (thisNote % 2 != 0) {  
   digitalWrite(ledPin, HIGH); 
  }
  else {  
   digitalWrite(ledPin, LOW);  
  }

  } // End of For loop

} // End of Main loop
