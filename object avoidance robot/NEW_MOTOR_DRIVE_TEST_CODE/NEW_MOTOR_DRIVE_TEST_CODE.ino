/*
This code for This https://robu.in/product/smartelex-15d-dual-channel-dc-motor-driver/ Motor Drive to Test
this Motor Drive Connect the DIR and PWM pins Respectively and Control Motor Direction by giving Input in
Serial monitor @9600BPS Send commands to Serial monitor 

F = Forward 
B = Backward 
R = Right
L = Left
S = Stop

Creator: Utsav 
last commit: Ishwariy

*/


//Pins For motorDriver
#define dir1 7
#define dir2 5

#define pwm1 6
#define pwm2 4

#define pwmSpeed 100


/* Always Declared Function Prototype  */
void Forward(byte pwmValue);
void Backward(byte pwmValue);
void Right(byte pwmValue);
void Left(byte pwmValue);
void Stop(byte pwmValue);


void setup() {
  pinMode (dir1, OUTPUT);

  pinMode (dir2, OUTPUT);

  pinMode (pwm1, OUTPUT);

  pinMode (pwm2, OUTPUT);
  Serial.begin(9600);
}

void loop() {


  if (Serial.available() > 0) {
    char input = Serial.read();

    if (input == 'F')
      Forward(pwmSpeed);


    if (input == 'B')
      Backward(pwmSpeed);


    if (input == 'R')
      Right(pwmSpeed);


    if (input == 'L')
      Left(pwmSpeed);

    if (input == 'S')
      Stop(pwmSpeed);


  }


  // Forward(pwmSpeed);
  //Backward(pwmSpeed);
  //Right(pwmSpeed);
  //Left(pwmSpeed);                        //Uncomment command one by one to check
  //Stop(pwmValue);

}



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
 F
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
