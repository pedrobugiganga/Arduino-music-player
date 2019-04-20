
/*
 * Push Button on pin 2 and 3
 * Audio Out - pin 9
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 

 */
 

#include <LiquidCrystal.h>

LiquidCrystal lcd ( A5, A4, A3, A2, A1, A0);

 
#include "SD.h" //Lib to read SD card
#include "TMRpcm.h" //Lib to play audio
#include "SPI.h" //SPI lib for SD card



#define SD_ChipSelectPin 4 //Chip select is pin number 4
TMRpcm music; //Lib object is named "music"

int song_number=0;
int select;
int play_pause;
int count =0;
int simbol =0;


void setup(){

lcd.begin(16,2);

  // apresentacao inicial no display
  lcd.setCursor(0,0); lcd.print("  MUSIC PLAYER  ");
  lcd.setCursor(0,1); lcd.print(">"); delay(125); lcd.setCursor(1,1); lcd.print(">"); delay(125);
  lcd.setCursor(2,1); lcd.print(">"); delay(125); lcd.setCursor(3,1); lcd.print(">"); delay(125);
  lcd.setCursor(4,1); lcd.print(">"); delay(125); lcd.setCursor(5,1); lcd.print(">"); delay(125);
  lcd.setCursor(6,1); lcd.print(">"); delay(125); lcd.setCursor(7,1); lcd.print(">"); delay(125);
  lcd.setCursor(8,1); lcd.print(">"); delay(125); lcd.setCursor(9,1); lcd.print(">"); delay(125);
  lcd.setCursor(10,1); lcd.print(">"); delay(125); lcd.setCursor(11,1); lcd.print(">"); delay(125);
  lcd.setCursor(12,1); lcd.print(">"); delay(125); lcd.setCursor(13,1); lcd.print(">"); delay(125);
  lcd.setCursor(14,1); lcd.print(">"); delay(125); lcd.setCursor(15,1); lcd.print(">"); delay(125);lcd.clear();
  lcd.setCursor(0,0); lcd.print("tap to play!");
  // apresentacao inicial no display
  
music.speakerPin = 9; //Auido out on pin 9
Serial.begin(9600); //Serial Com for debugging 
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}

pinMode(2,INPUT); //Button 1 chage track
pinMode(3,INPUT); //Button 2  play/pause


music.setVolume(4);    //   0 to 7. Set volume level
music.quality(1);        //  Set 1 for 2x oversampling Set 0 for normal
//music.volume(0);        //   1(up) or 0(down) to control volume
//music.play("filename",30); plays a file starting at 30 seconds into the track    
}

void loop()
{ 
   select = digitalRead(2);
   play_pause = digitalRead(3);

   

   if(select == LOW && count == 0){
   music.play("1.wav",10);
   lcd.setCursor(14,1); lcd.print("  ");
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("INCUBUS - talk ");
   lcd.setCursor(0,1); lcd.print("shows on mute >");
   delay(1000);
   count ++;
   select = digitalRead(2);}

   if(select == LOW && count == 1){
   music.play("2.wav");
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("KHAKI SCOUTS - ");
   lcd.setCursor(0,1); lcd.print("campfires     >");
   delay(1000);
   count ++;
   select = digitalRead(2);}
      
   if(select == LOW && count == 2){
   music.play("3.wav");
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("THE KILLERS - ");
   lcd.setCursor(0,1); lcd.print("on top        >");
   delay(1000);
   count ++;
   select = digitalRead(2);}
   
      if(select == LOW && count == 3){
   music.play("4.wav");
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("MALU MAGALHAES - ");
   lcd.setCursor(0,1); lcd.print("sambinha bom  >");
   delay(1000);
   count = 0;
   select = digitalRead(2);}
   
     if (play_pause == LOW){
      music.pause();
      lcd.setCursor(14,1); lcd.print("  ");
      lcd.setCursor(14,1); lcd.print("||");
      simbol++;
     if ( simbol == 2 ){
      lcd.setCursor(14,1); lcd.print("  ");
      lcd.setCursor(14,1); lcd.print("> ");
      simbol = 0;
     }
      




      
      delay(1000);
     }


    
   }
