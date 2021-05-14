/*
   Miltiple Ultrasonic Sensors
   Prints the distance read by many ultrasonic sensors in
   centimeters and inches. They are supported to four pins
   ultrasound sensors (liek HC-SC04) and three pins
   (like PING))) and Seeed Studio sensors).

   The circuit:
 * * In this circuit there is an ultrasonic module HC-SC04,
     PING))) and a Seeed Studio (4 pins, 3 pins, 3 pins,
     respectively), attached to digital pins as follows:
   ---------------------     ---------------------     -------------------
   | HC-SC04 | Arduino |     | PING))) | Arduino |     | Seeed | Arduino |
   ---------------------     ---------------------     -------------------
   |   Vcc   |   5V    |     |   Vcc   |   5V    |     |  Vcc  |   5V    |
   |   Trig  |   12    | AND |   SIG   |   10    | AND |  SIG  |    8    |
   |   Echo  |   13    |     |   Gnd   |   GND   |     |  Gnd  |   GND   |
   |   Gnd   |   GND   |     ---------------------     -------------------
   ---------------------
   Note: You do not obligatorily need to use the pins defined above

   By default, the distance returned by the read()
   method is in centimeters. To get the distance in inches,
   pass INC as a parameter.
   Example: ultrasonic.read(INC)

   created 3 Mar 2017
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)
   modified 11 Jun 2018
   by Erick Simões (github: @ErickSimoes | twitter: @AloErickSimoes)

   This example code is released into the MIT License.
*/

#include <Ultrasonic.h>

Ultrasonic ultrasonic1(52, 53);	  // An ultrasonic sensor HC-04
Ultrasonic ultrasonic2(50, 51);		// An ultrasonic sensor HC-
Ultrasonic ultrasonic3(48, 49);		// An ultrasonic sensor HC-
Ultrasonic ultrasonic4(46, 47);    // An ultrasonic sensor HC-
Ultrasonic ultrasonic5(44, 45);    // An ultrasonic sensor HC-


void setup() {
  Serial.begin(9600);
}

void loop() {

  Serial.print("R Sensor 01: ");
  Serial.print(ultrasonic1.read(CM)); // Prints the distance on the default unit (centimeters)
  Serial.print("cm");
  Serial.print("\t");    // prints a tab


  Serial.print("C Sensor 02: ");
  Serial.print(ultrasonic2.read(CM)); // Prints the distance making the unit explicit
  Serial.print("cm");
  Serial.print("\t");    // prints a tab


  Serial.print("L Sensor 03: ");
  Serial.print(ultrasonic3.read(CM)); // Prints the distance in inches
  Serial.print("cm");
  Serial.print("\t");    // prints a tab


  Serial.print("B Sensor 04: ");
  Serial.print(ultrasonic4.read(CM)); // Prints the distance in inches
  Serial.print("cm");
  Serial.print("\t");    // prints a tab


//  Serial.print("\t");    // prints a tab
  Serial.print("T Sensor 05: ");
  Serial.print(ultrasonic5.read(CM)); // Prints the distance in inches
  Serial.print("cm");
  // Serial.print("\t");    // prints a tab
  Serial.println();    // prints a tab








  delay(500);
}
