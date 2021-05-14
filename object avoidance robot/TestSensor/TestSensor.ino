#define trigPin1 11
#define echoPin1 10

void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin1, OUTPUT);

 pinMode(echoPin1, INPUT);
 Serial.begin(9600);
}

void loop() {
 Serial.println(Sensor());
  

}


long Sensor ()    
{

long dur;

 digitalWrite(trigPin1, LOW); 

 delayMicroseconds(5); // delays are required for a succesful sensor operation.

 digitalWrite(trigPin1, HIGH);

 delayMicroseconds(10); //this delay is required as well!

 digitalWrite(trigPin1, LOW);

 dur = pulseIn(echoPin1, HIGH);

 return (dur/50);// convert the distance to centimeters.

}
