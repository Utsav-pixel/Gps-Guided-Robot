//Pins For motorDriver
#define dir1 11 
#define dir2 12 

#define pwm1 9
#define pwm2 10

#define pwmSpeed 100
#define turningSpeed 20


void setup() {
pinMode (dir1, OUTPUT);

 pinMode (dir2, OUTPUT);

 pinMode (pwm1, OUTPUT);

 pinMode (pwm2, OUTPUT);
Serial.begin(9600);
}

void loop() {
Forward(pwmSpeed);
//Backward(turningSpeed);
//Right(turningSpeed);
//Left(turningSpeed);                        //Uncomment command one by one to check
}                                           



//By default 0 is for Clockwise and 1 for anticlockwise


void Forward(byte pwmValue) 
{
  digitalWrite(dir1,1); 
  analogWrite(pwm1,pwmValue);

  digitalWrite(dir2,0); 
  analogWrite(pwm2,pwmValue);
  delay(3000);
Serial.print("Right motor ACW                        Left motor CW");                                //ACW - anticlockWise               CW ClockWise

}





void Backward(byte pwmValue) 
{
  digitalWrite(dir1,0); 
  analogWrite(pwm1,pwmValue);

  digitalWrite(dir2,1); 
  analogWrite(pwm2,pwmValue);
    delay(3000);
Serial.print("Right motor CW                        Left motor ACW");
}






void Left(byte pwmValue)
{
  
  digitalWrite(dir1,1); 
  analogWrite(pwm1,pwmValue);

  digitalWrite(dir2,1); 
  analogWrite(pwm2,pwmValue);
    delay(3000);
Serial.print("Right motor ACW                        Left motor ACW");
}





void Right(byte pwmValue)
{
  digitalWrite(dir1,0); 
  analogWrite(pwm1,pwmValue);

  digitalWrite(dir2,0); 
  analogWrite(pwm2,pwmValue);
    delay(3000);
Serial.print("Right motor CW                        Left motor CW");
}
