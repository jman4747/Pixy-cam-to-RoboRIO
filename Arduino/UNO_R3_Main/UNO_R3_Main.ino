//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with 
// Pixy and Arduino.  This program simply prints the detected object blocks 
// (including color codes) through the serial console.  It uses the Arduino's 
// ICSP port.  For more information go here:
//
// http://cmucam.org/projects/cmucam5/wiki/Hooking_up_Pixy_to_a_Microcontroller_(like_an_Arduino)
//

   
#include <SPI.h>  
#include <Pixy.h>

// This is the main Pixy object 
Pixy pixy;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(57600);
  pixy.init();
  Serial.print("on\n");
  delay(1000);
  Serial.print("waiting\n");

  
}

void loop()
{ 
  static String C = "wait\n";
  int j;
  uint16_t blocks;
  char buf[32]; 
  
  // grab blocks!
  blocks = pixy.getBlocks();
  
  
  if (Serial.available() > 0)
  {
    C = Serial.readString();
    if (C == "go\n")
    {
      Serial.print("User command: " + C);
      delay(1000);
    }
    else
    {
    Serial.print("User command: " + C);
    }
  }
  
  if(C == "go\n")
  {
     if (blocks)// If there are blocks detected, print them!
     {
                  //i++;
                   // do this (print) every 2 frames because printing every
                   // frame would bog down the Arduino(not)
                   /*if (i%2==0)
                     {*/
       for (j=0; j<blocks; j++)
       {
       //sprintf(buf, "  block %d: ", j);
       //Serial.print(buf); 
       pixy.blocks[j].print();
       }
         //}
      }  
  }
  
  else if(C == "wait\n")
  {
    delay(250);
  }
  else if(C == "light\n")
  {
    Serial.print("not implemented\n");
    C = "wait\n";
    Serial.print("waiting\n");
    delay(250);
  }
  else if(C == "help\n")
  {
    Serial.print("command list:\ncommand: go = activate camera & start data stream\n");
    Serial.print("command: wait = stop data stream\n");
    Serial.print("command: light = toggle LED ring on or off\nLED ring cannot be toggled off if camera is active\r\n");
    C = "wait\n";
    Serial.print("waiting\n");
    delay(250);
  }
  else
  {
    Serial.print("bad command\n");
    C = "wait\n";
    Serial.print("waiting\n");
    delay(250);
  }

}

