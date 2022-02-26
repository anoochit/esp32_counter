#include <Arduino.h>
#include "LedControl.h"

LedControl lc = LedControl(19, 5, 18, 1);

const int SWITCH = 36;

unsigned long delaytime = 250;
unsigned int counter = 0;

void setup()
{
  // put your setup code here, to run once:
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
  /* set pinmode */
  pinMode(36, INPUT_PULLDOWN);
}

void printNumber(int v)
{
  int ones;
  int tens;
  int hundreds;
  int thousands;
  int ten_thousand;
  int hundreds_thousand;
  int millions;
  int ten_millions;
  if (v <= 99999999)
  {
    ones = v % 10;
    v = v / 10;
    tens = v % 10;
    v = v / 10;
    hundreds = v % 10;
    v = v / 10;
    thousands = v % 10;
    v = v / 10;
    ten_thousand = v % 10;
    v = v / 10;
    hundreds_thousand = v % 10;
    v = v / 10;
    millions = v % 10;
    v = v / 10;
    ten_millions = v;
    // Now print the number digit by digit
    if (ten_millions > 0)
    {
      lc.setDigit(0, 7, (byte)ten_millions, false);
    }
    if (millions > 0)
    {
      lc.setDigit(0, 6, (byte)millions, false);
    }
    if (hundreds_thousand > 0)
    {
      lc.setDigit(0, 5, (byte)hundreds_thousand, false);
    }
    if (ten_thousand > 0)
    {
      lc.setDigit(0, 4, (byte)ten_thousand, false);
    }
    if (thousands > 0)
    {
      lc.setDigit(0, 3, (byte)thousands, false);
    }
    if (hundreds > 0)
    {
      lc.setDigit(0, 2, (byte)hundreds, false);
    }
    if (tens > 0)
    {
      lc.setDigit(0, 1, (byte)tens, false);
    }
    lc.setDigit(0, 0, (byte)ones, false);
  }
  else
  {
    lc.setChar(0, 0, 'E', false);
  }
}

void loop()
{
  if (digitalRead(SWITCH) == HIGH)
  {
    counter++;
    printNumber(counter);
    delay(delaytime);
  }
  else
  {
    printNumber(counter);
    delay(delaytime);
  }
}