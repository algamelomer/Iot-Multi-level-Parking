#include "DRV8825.h"
#include <Stepper.h>
#include "BluetoothSerial.h"

DRV8825 stepper;
const int stepsPerRevolution = 200;  
Stepper mystepper(stepsPerRevolution, 18, 19);

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

BluetoothSerial Serialtest;

void setup()
{
  Serial.begin(9600);
  stepper.begin(22, 23); 
  mystepper.setSpeed(550);
  Serialtest.begin("Rawan_Magdy");
}

void loop()
{
    if (Serialtest.available()) {
    int cmd = Serialtest.parseInt();
    Serial.println(cmd);
  //  slow in one direction
  
  if (cmd>=10&&cmd<=25600){
    stepper.setDirection(DRV8825_CLOCK_WISE);
  for (int i = 50; i < cmd; i++)
  {
    stepper.step();
    
    delay(1);
  }}
else if (cmd==5){
  slot_12();
  Serial.println("slot_5");
}
else if (cmd==-5){
  slot_12_remove();
  Serial.println("slot_5");
}
else if (cmd==4){
  slot_11();
  Serial.println("slot_4");
}
else if (cmd==-4){
  slot_11_remove();
  Serial.println("slot_4");
}

else if(cmd==1){
  slot_1();
  Serial.println("slot_1");
}
else if(cmd==-1){
  slot_1_remove();
}

else if(cmd==2){
  slot_2();
}

else if(cmd==-2){
  slot_2_remove();
}

else if(cmd>=-25600&&cmd<=-10){
  stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = -50; i < -cmd; i++)
  {
    stepper.step();
    
    delay(1);
  }}
else if(cmd>=100000&&cmd<=104000){
  mystepper.step(map(cmd,100000,104000,0,4000));
}
else if(cmd<=-100000&&cmd>=-104000){
  mystepper.step(map(cmd,-100000,-104000,-0,-4000));
}

}
}


void slot_1(){
    for(int i=0;i<32;i++){
      mystepper.step(4000);
    }
    delay(3500);
  stepper.setDirection(DRV8825_CLOCK_WISE);
  for (int i = 0; i < 15800; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<10;i++){
      mystepper.step(-4000);
    }
    delay(3500);
  
  stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 15800; i++)
  {
    stepper.step();
    
    delay(1);
  }

    delay(3500);
    for(int i=0;i<22;i++){
    mystepper.step(-4000);}
}

void slot_1_remove(){
    for(int i=0;i<22;i++){
      mystepper.step(4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_CLOCK_WISE);
  for (int i = 0; i < 15800; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<10;i++){
      mystepper.step(4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 15800; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<32;i++){
    mystepper.step(-4000);}
}

void slot_2(){
    for(int i=0;i<32;i++){
      mystepper.step(4000);
    }
    delay(3500);
  stepper.setDirection(DRV8825_CLOCK_WISE);
  for (int i = 0; i < 31200; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<10;i++){
      mystepper.step(-4000);
    }
    delay(3500);
  
  stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 31200; i++)
  {
    stepper.step();
    
    delay(1);
  }

    delay(3500);
    for(int i=0;i<22;i++){
    mystepper.step(-4000);}
}

void slot_2_remove(){
    for(int i=0;i<22;i++){
      mystepper.step(4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_CLOCK_WISE);
  for (int i = 0; i < 31200; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<10;i++){
      mystepper.step(4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 31200; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<32;i++){
    mystepper.step(-4000);}
}
void slot_12(){
  Serial.println("work?");
    for(int i=0;i<14;i++){
      mystepper.step(4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 16200; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<14;i++){
      mystepper.step(-4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_CLOCK_WISE);
  
  for (int i = 0; i < 16200; i++)
  {
    stepper.step();
    
    delay(1);
  }
}
void slot_12_remove(){
    stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 16200; i++)
  {
    stepper.step();
    
    delay(1);
  }
  delay(2000);
  for(int i=0;i<14;i++){
      mystepper.step(4000);
    }
    delay(2000);
      stepper.setDirection(DRV8825_CLOCK_WISE);
  
  for (int i = 0; i < 16200; i++)
  {
    stepper.step();
    
    delay(1);
  }
  delay(2000);
   for(int i=0;i<14;i++){
      mystepper.step(-4000);
    }
    delay(2000);
}
void slot_11(){
  Serial.println("work?");
    for(int i=0;i<14;i++){
      mystepper.step(4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 31500; i++)
  {
    stepper.step();
    
    delay(1);
  }
    delay(3500);
    for(int i=0;i<14;i++){
      mystepper.step(-4000);
    }
    delay(3500);
    stepper.setDirection(DRV8825_CLOCK_WISE);
  
  for (int i = 0; i < 31500; i++)
  {
    stepper.step();
    
    delay(1);
  }
}
void slot_11_remove(){
    stepper.setDirection(DRV8825_COUNTERCLOCK_WISE);
  for (int i = 0; i < 31500; i++)
  {
    stepper.step();
    
    delay(1);
  }
  delay(2000);
  for(int i=0;i<14;i++){
      mystepper.step(4000);
    }
    delay(2000);
      stepper.setDirection(DRV8825_CLOCK_WISE);
  
  for (int i = 0; i < 31500; i++)
  {
    stepper.step();
    
    delay(1);
  }
  delay(2000);
   for(int i=0;i<14;i++){
      mystepper.step(-4000);
    }
    delay(2000);
}
