/* 
This sketch draws to the 64x48 pixel MicroOLED
  
  Hardware Connections:
    We'll be using the Qwiic I2C interface on the MicroOLED
==============================================================================*/

#include <Wire.h>
#include <SFE_MicroOLED.h>
#include "images.h"

//////////////////////////
// MicroOLED Definition //
//////////////////////////
// The library assumes a reset pin is necessary
// The Qwiic OLED has RST hard-wired, so pick an arbitrary IO pin that is not being used
#define PIN_RESET 9  
// The DC_JUMPER is the I2C Address Select jumper
// Set to 1 if the jumper is open (Default), or set to 0 if it's closed
#define DC_JUMPER 1 

//////////////////////////////////
// MicroOLED Object Declaration //
//////////////////////////////////
// I2C declaration
// I2C will result in a very slow update rate
MicroOLED oled(PIN_RESET, DC_JUMPER);

void displaySplashScreen(void) {
    delay(100);
  
    // Set up I2C bus
    Wire.begin();

    // Init all of the pins and configure the OLED
    oled.begin();

    // clear(ALL) will clear out the OLED's graphic memory (gets rid of artifacts)
    // clear(PAGE) will clear the Arduino's display buffer
    oled.clear(ALL);

    // Display title text
    oled.setFontType(1);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("Artemis");
    oled.print("  Says");
    oled.display();

    // Pause for the title screen
    delay(1000);

    // Display starting text
    oled.setFontType(0);
    oled.clear(PAGE);
    oled.setCursor(0, 0);
    oled.print("Say \"go\" to start");
    oled.display();
}
//---------------------------------------------------------------
void displayText(const char* text){
   // Display text
      oled.setFontType(1);
      oled.clear(PAGE);
      oled.setCursor(0, 1);
      oled.print(text);
      oled.display();
}
//---------------------------------------------------------------
void drawUp()
{
    oled.clear(ALL);
    oled.clear(PAGE);
    oled.drawBitmap(up);
    oled.display();
}
//---------------------------------------------------------------
void drawRight()
{
    oled.clear(ALL);
    oled.clear(PAGE);
    oled.drawBitmap(right);
    oled.display();
}
//---------------------------------------------------------------
void drawDown()
{
    oled.clear(ALL);
    oled.clear(PAGE);
    oled.drawBitmap(down);
    oled.display();
}
//---------------------------------------------------------------
void drawLeft()
{
    oled.clear(ALL);
    oled.clear(PAGE);
    oled.drawBitmap(left);
    oled.display();
}
