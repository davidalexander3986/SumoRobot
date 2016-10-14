/*
 * Code to run sumo bot in high school competition. Takes analog voltage input 
 * from IR distance sensor, and converts it to a double value to represent
 * distance. Motors are constantly inverted, so the sumo robot continuously
 * spins around, waiting for distance value to be small enough (meaning
 * opposing sumo bot has been detected) and moves forward quickly. 
 * Uses code from "Dual MC33926 Motor Shield header file. 
 *
 *
 *
 */

#include "DualMC33926MotorShield.h"

#define pin A1
DualMC33926MotorShield md;
 
void stopIfFault()
{
  if (md.getFault())
  {
    Serial.println("fault");
    while(1);
  }
}
 
void setup()
{
  Serial.begin (9600);
  pinMode(pin, INPUT);

  Serial.println("Dual MC33926 Motor Shield");
  md.init();
}

 

void loop()
{
        //Convert the analog voltage to the distance

    uint16_t value = analogRead (pin);
    double distance = get_IR(value);

    if(distance<35)
    {
          md.setSpeeds(275, 275);
     }
     else
     {
          md.setM1Speed(-150);
          md.setM2Speed(150);


     }
     delay(50);
}

double get_IR (uint16_t value) {
    if (value < 16)  value = 16;
    return 2076.0 / (value - 11.0);
}
//return distance (cm)

