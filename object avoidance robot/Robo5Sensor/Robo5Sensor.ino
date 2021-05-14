
//*************************Pins Attached to microcontroller and sensor*************************//

//Pins for front Sensor
#define trigPin1 50
#define echoPin1 51

//Pins for Right Sensor
#define trigPin2  52
#define echoPin2  53

//Pins for Left Sensor
#define trigPin3  48
#define echoPin3  49

//Pins for Top Sensor
#define trigPin4  44
#define echoPin4  45

//Pins for Back Sensor
#define trigPin5  46
#define echoPin5  47

#define dir1 7
#define dir2 5 

#define pwm1 6
#define pwm2 4




//******************************CALIBRATION Value********************************************//
#define Val  100             //distance highest range of sensor
#define Dis   20          //minimum distance
#define Height 10
#define turningspeed 20    //Turning speed of bot ---must be less and efficient
#define interval 1000     // Time tiill robot moves backward without obstruction
#define pwmspeed 250      // Max forward Speed
#define U_turntime 3000  //Time take by bot to complete u turn at u turning Speed



void setup() 

{

 pinMode(trigPin1, OUTPUT);

 pinMode(echoPin1, INPUT);

 pinMode(trigPin2, OUTPUT);

 pinMode(echoPin2, INPUT);

 pinMode(trigPin3, OUTPUT);

 pinMode(echoPin3, INPUT);

 pinMode(trigPin4, OUTPUT);

 pinMode(echoPin4, INPUT);

 pinMode(trigPin5, OUTPUT);

 pinMode(echoPin5, INPUT);

 
 pinMode (dir1, OUTPUT);

 pinMode (dir2, OUTPUT);

 pinMode (pwm1, OUTPUT);

 pinMode (pwm2, OUTPUT);
Serial.begin(9600);

}

void loop()
{
  unsigned long constanttime = millis();
  bool n=0;
  if(((FrontSensor() +Dis) >= (Dis + Val)) && (n==0) && (TopSensor()>Height))                //No obstruction in front go forward
 { Forward(pwmspeed); }

 else if ( (Val > FrontSensor())&&(FrontSensor() >Dis) && (n==0) && (TopSensor()>Height))                       //object is getting near so speed will decrease
 {
 int avgSpeed ;
 avgSpeed=(FrontSensor()-Dis)*pwmspeed;
 avgSpeed=avgSpeed/(Val-Dis); 

  Forward(avgSpeed);
  }

  else if (((FrontSensor() <= Dis) && (n==0) && (TopSensor()>Height))||((FrontSensor() > Dis) && (n==0) && (TopSensor()<=Height)))                         //There is object so bot will check for right and turn right or check left and turn left
  {
   if ((LeftSensor() > Dis) && (RightSensor() > Dis)  && (n==0))
   {Right(turningspeed);}
   else if ((LeftSensor() <= Dis) && (RightSensor() > Dis)  && (n==0))
    {Right(turningspeed);}

    else if  ((LeftSensor() > Dis) && (RightSensor() <= Dis) && (n==0))
   {Left(turningspeed);}
    
    if (LeftSensor() <= Dis && RightSensor() <= Dis)      // if both diretion i have object present bot will move backward for interval amount of time then take uturn and if and object present at back it will stop

                                    
    
    {
      n=1; }}
      while (n==1)
     {
      unsigned long currenttime = millis();
      
        if (BackSensor() > Dis)
        { 
          backward(turningspeed);

           if (currenttime - constanttime >= interval)
           {
            Right(turningspeed);
            delay(U_turntime);
            n=0;
            }

        else if ((currenttime - constanttime < interval)&& (BackSensor() <= Dis))
        {n=0;}
        
        }

      

        
        
        else if (BackSensor <= Dis)
        {n=0;} 
        
        
        }
      
      
      
    
    
    
    }
 



//************************************Sensor Detection Functions***************************//


long FrontSensor ()

{

long dur;

 digitalWrite(trigPin1, LOW); 

 delayMicroseconds(5); // delays are required for a succesful sensor operation.

 digitalWrite(trigPin1, HIGH);

 delayMicroseconds(10); //this delay is required as well!

 digitalWrite(trigPin1, LOW);

 dur = pulseIn(echoPin1, HIGH);

 return (dur/30);// convert the distance to centimeters.

}






long RightSensor () 

{

long dur;

 digitalWrite(trigPin2, LOW);

 delayMicroseconds(5); // delays are required for a succesful sensor operation.

 digitalWrite(trigPin2, HIGH);

 delayMicroseconds(10); //this delay is required as well!

 digitalWrite(trigPin2, LOW);

 dur = pulseIn(echoPin2, HIGH);

 return (dur/62);// convert the distance to centimeters.


}








long LeftSensor ()    
{

long dur;

 digitalWrite(trigPin3, LOW); 

 delayMicroseconds(5); // delays are required for a succesful sensor operation.

 digitalWrite(trigPin3, HIGH);

 delayMicroseconds(10); //this delay is required as well!

 digitalWrite(trigPin3, LOW);

 dur = pulseIn(echoPin3, HIGH);

 return (dur/50);// convert the distance to centimeters.

}





long TopSensor ()    
{

long dur;

 digitalWrite(trigPin4, LOW); 

 delayMicroseconds(5); // delays are required for a succesful sensor operation.

 digitalWrite(trigPin4, HIGH);

 delayMicroseconds(10); //this delay is required as well!

 digitalWrite(trigPin4, LOW);

 dur = pulseIn(echoPin4, HIGH);

 return (dur/50);// convert the distance to centimeters.

}






long BackSensor ()    
{

long dur;

 digitalWrite(trigPin5, LOW); 

 delayMicroseconds(5); // delays are required for a succesful sensor operation.

 digitalWrite(trigPin5, HIGH);

 delayMicroseconds(10); //this delay is required as well!

 digitalWrite(trigPin5, LOW);

 dur = pulseIn(echoPin5, HIGH);

 return (dur/50);// convert the distance to centimeters.

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
}
