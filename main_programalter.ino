#include<Servo.h>
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SD.h>



Servo motor1, motor2,motor3;
int p;
int infa = A0;
#define LED 2  // The pin the LED is connected to
#define SD_ChipSelectPin 4
 TMRpcm tmrpcm;
 


void setup(){  
  
 Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;

}
};



  void loop(){
  int n=0;
    Serial.begin(9600);
  int infa = analogRead(A0);
  Serial.println( infa);
  delay(60);
 
  
  
  if (infa < 100)
  {
  tmrpcm.speakerPin = 10; 
    motor1.attach(7);
    motor2.attach(8);
    motor3.attach(9);
    
 for (p = 70; p<=120; p++)
    {
      motor1.write(p);
      delay(60);
    };

   for (p=45; p>=30; p--)
   {
    motor2.write(p);
    delay(60);
   };
   
   
   
  //for sound 
   tmrpcm.setVolume(5);
   tmrpcm.play("Voyage.wav"); 
   delay(7000);
    
    
    for (p=30; p<=45; p++)
   {
    motor2.write(p);
    delay(60);
   };
   
   for (p = 120; p >= 70; p--)
    {
      motor1.write(p);
      delay(60);
    };
     while(n%2==0)
    {
     for (p=70; p>=25; p--)
    {
      motor3.write(p);
      delay(60);
    };
    };
  
    //completes one rotation
    while(n%2!=0)
    {
      for (p = 25; p<=70; p++)
    {
      motor3.write(p);
      delay(60);
    };
    };
  };
   
  };

    
   
