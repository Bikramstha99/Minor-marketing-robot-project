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
 TMRpcm tmrpcm,audi;
 int n=0;


void setup(){  
  
 Serial.begin(9600);
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;

}
};



  void loop(){
  
    Serial.begin(9600);
  int infa = analogRead(A0);
  Serial.println( infa);
  delay(1000);
 
  
  
  if (infa < 100)
  {
  tmrpcm.speakerPin = 9; 
    motor1.attach(7);
    motor2.attach(8);
    motor3.attach(9);
    
 for (p = 70; p<=110; p++)
    {
      motor1.write(p);
      delay(60);
    };

   for (p=45; p>=35; p--)
   {
    motor2.write(p);
    delay(60);
   };
   
   delay(1000);
   
  //for sound 
   tmrpcm.setVolume(6);
   tmrpcm.play("apple.wav"); 
   delay(7000);
    
    
    for (p=35; p<=45; p++)
   {
    motor2.write(p);
    delay(60);
   };
   
   for (p = 110; p >= 70; p--)
    {
      motor1.write(p);
      delay(60);
    };
     
     for (p=0; p>=90; p--)
    {
      motor3.write(p);
      delay(60);
    };
    
  for (p = 70; p<=110; p++)
    {
      motor1.write(p);
      delay(60);
    };

   for (p=45; p>=35; p--)
   {
    motor2.write(p);
    delay(60);
   };
   
   
   delay(5000);
  //for sound 
   audi.setVolume(6);
   audi.play("choco.wav"); 
   delay(7000);
    
    
    for (p=35; p<=45; p++)
   {
    motor2.write(p);
    delay(60);
   };
   
   for (p = 110; p >= 70; p--)
    {
      motor1.write(p);
      delay(60);
    };
    //completes one rotation
  
      for (p = 90; p<=0; p++)
    {
      motor3.write(p);
      delay(60);
    
   // };
  };
  };
  };

    
   
