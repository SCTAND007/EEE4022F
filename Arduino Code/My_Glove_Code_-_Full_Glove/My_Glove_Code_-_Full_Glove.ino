int counter = 0;

// initializations for flex sensors
int F1 = A0;        // analog pin 0
int F2 = A1;        // analog pin 0
int F3 = A2;        // analog pin 0
int F4 = A3;        // analog pin 0
int F5 = A6;        // analog pin 0
                    // outside leads to ground and +3.3V
int valu1 = 0;        // variable to store the value read
int valu2 = 0;
int valu3 = 0;
int valu4 = 0;
int valu5 = 0;


// initializations for IMU
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);


// initialization for contact sensors
int C1 = 2;   // choose the input pin (for a pushbutton)
int C2 = 3;
int C3 = 4;
int C4 = 5;
int val1 = 0;     // variable for reading the pin status
int val2 = 0;
int val3 = 0;
int val4 = 0;

//------------------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           //  setup serial
  
  // flex sensor setup
  // no set up


  // IMU sensor set up
  //Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);


  // contact sensor set up
  pinMode(C1, INPUT);    // declare pushbutton as input
  pinMode(C2, INPUT);    // declare pushbutton as input
  pinMode(C3, INPUT);    // declare pushbutton as input
  pinMode(C4, INPUT);    // declare pushbutton as input
  


  // CSV Heading setup
  Serial.println("F1,F2,F3,F4,F5,qW,qX,qY,qZ,C1,C2,C3,C4,");
}

void loop() {
  // put your main code here, to run repeatedly:
while(counter<101)
{  
  //flex sensor code
  valu1 = analogRead(F1);        // read the input pin
  Serial.print(valu1);          // debug value
  Serial.print(",");
  valu2 = analogRead(F2);        // read the input pin
  Serial.print(valu2);          // debug value
  Serial.print(",");
  valu3 = analogRead(F3);        // read the input pin
  Serial.print(valu3);          // debug value
  Serial.print(",");
  valu4 = analogRead(F4);        // read the input pin
  Serial.print(valu4);          // debug value
  Serial.print(",");
  valu5 = analogRead(F5);        // read the input pin
  Serial.print(valu5);          // debug value
  Serial.print(",");


  //IMU code
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);

  imu::Quaternion quat = bno.getQuat();

  Serial.print(quat.w(), 4);
  Serial.print(",");
  Serial.print(quat.y(), 4);
  Serial.print(",");
  Serial.print(quat.x(), 4);
  Serial.print(",");
  Serial.print(quat.z(), 4);
  Serial.print(",");

  //contact sensor code
  val1 = digitalRead(C1);  // read input value
  Serial.print(val1);
  Serial.print(",");
  val2 = digitalRead(C2);  // read input value
  Serial.print(val2);
  Serial.print(",");
  val3 = digitalRead(C3);  // read input value
  Serial.print(val3);
  Serial.print(",");
  val4 = digitalRead(C4);  // read input value
  Serial.print(val4);
  Serial.println(",");

  delay(100);
  counter = counter+1;
}
}
