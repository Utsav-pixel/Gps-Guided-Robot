#include <Ultrasonic.h>

//Pin attach between microcontroller and motor Driver

#define dir1 7
#define dir2 5

#define pwm1 6
#define pwm2 4




//******************************CALIBRATION Value********************************************//
#define Val  150             //distance highest range of sensor
#define Dis   40          //minimum distance
#define Dis1  45          //minimum distance
#define MinPWM 30

#define turningspeed 90    //Turning speed of bot ---must be less and efficient
#define interval 600     // Time tiill robot moves backward without obstruction
#define pwmspeed 130      // Max forward Speed
#define U_turntime 1500  //Time take by bot to complete u turn at u turning Speed






Ultrasonic RightSensor(52, 53);    // An ultrasonic sensor HC-04
Ultrasonic FrontSensor(50, 51);   // An ultrasonic sensor HC-
Ultrasonic LeftSensor(48, 49);   // An ultrasonic sensor HC-
Ultrasonic BackSensor(46, 47);    // An ultrasonic sensor HC-



void setup()

{

  pinMode (dir1, OUTPUT);

  pinMode (dir2, OUTPUT);

  pinMode (pwm1, OUTPUT);

  pinMode (pwm2, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  unsigned long constanttime = millis();
  bool n = 0;
  if (((FrontSensor.read(CM) + Dis) >= (Dis + Val)) && (n == 0))          //No obstruction in front go forward
  {
    Forward(pwmspeed);
  }

  else if ( (Val > FrontSensor.read(CM)) && (FrontSensor.read(CM) > Dis) && (n == 0))                //object is getting near so speed will decrease
  {
    int avgSpeed = 0 ;
    float x;
    x = MinPWM * Val;
    x = x / pwmspeed;
    x = x - Dis;
    avgSpeed = (FrontSensor.read(CM) + x) * pwmspeed;
    avgSpeed = avgSpeed / Val;
    if (avgSpeed < MinPWM)
    {
      avgSpeed = MinPWM;
    }
    else if (avgSpeed > pwmspeed)
    {
      avgSpeed = pwmspeed;
    }
    Forward(avgSpeed);
  }

  else if (((FrontSensor.read(CM) <= Dis) && (n == 0)) || ((FrontSensor.read(CM) > Dis) && (n == 0)) || ((FrontSensor.read(CM) <= Dis) && (n == 0)))   //There is object so bot will check for right and turn right or check left and turn left
  {
    if ((LeftSensor.read(CM) > Dis1) && (RightSensor.read(CM) > Dis1)  && (n == 0))
    {
      Right(turningspeed);
    }
    else if ((LeftSensor.read(CM) <= Dis1) && (RightSensor.read(CM) > Dis1)  && (n == 0))
    {
      Right(turningspeed);
    }

    else if  ((LeftSensor.read(CM) > Dis1) && (RightSensor.read(CM) <= Dis1) && (n == 0))
    {
      Left(turningspeed);
    }

    if (LeftSensor.read(CM) <= Dis1 && RightSensor.read(CM) <= Dis1)      // if both diretion i have object present bot will move backward for interval amount of time then take uturn and if and object present at back it will stop



    {
      n = 1;
    }
  }
  while (n == 1)
  {
    unsigned long currenttime = millis();

    if (BackSensor.read(CM) > Dis)
    {
      Backward(turningspeed);

      if (currenttime - constanttime >= interval)
      {
        Right(turningspeed);
        delay(U_turntime);
        n = 0;
      }

      else if ((currenttime - constanttime < interval) && (BackSensor.read(CM) <= Dis))
      {
        n = 0;
      }

    }





    else if (BackSensor.read(CM) <= Dis)
    {
      n = 0;
    }


  }






}




//********************************Direction Command*****************************/



//By default 0 is for Clockwise and 1 for anticlockwise


void Forward(byte pwmValue)
{
  digitalWrite(dir1, 0);
  analogWrite(pwm1, pwmValue);

  digitalWrite(dir2, 0);
  analogWrite(pwm2, pwmValue);
  delay(1000);
  Serial.print("IT'S MOVING FORWARD");  // Both motor in CW Dir.

  Serial.print(pwmValue);  // Both motor in CW Dir.

}




void Backward(byte pwmValue)
{
  digitalWrite(dir1, 1);
  analogWrite(pwm1, pwmValue);

  digitalWrite(dir2, 1);
  analogWrite(pwm2, pwmValue);
  delay(1000);
  Serial.print("IT'S MOVING BACKWARD");  // Both motor in ACW Dir
}






void Left(byte pwmValue)
{

  digitalWrite(dir1, 0);
  analogWrite(pwm1, pwmValue);

  digitalWrite(dir2, 1);
  analogWrite(pwm2, pwmValue);
  delay(1000);
  Serial.print("IT'S MOVING LEFT"); // RM is CW Dir and LM is ACW Dir
}





void Right(byte pwmValue)
{
  digitalWrite(dir1, 1);
  analogWrite(pwm1, pwmValue);

  digitalWrite(dir2, 0);
  analogWrite(pwm2, pwmValue);
  delay(1000);
  Serial.print("IT'S MOVING RIGHT"); // RM is ACW Dir and LM is CW Dir
}



void Stop(byte pwmValue)
{
  pwmValue = 0;
  digitalWrite(dir1, 0);
  analogWrite(pwm1, pwmValue);

  digitalWrite(dir2, 0);
  analogWrite(pwm2, pwmValue);
  delay(1000);
  Serial.print("IT'S STOPED MOVING"); // RM is ACW Dir and LM is CW Dir
}
