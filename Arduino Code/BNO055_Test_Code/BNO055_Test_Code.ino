#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

int c = 0;

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  Serial.println("qW:,qX:,qY:,qZ:,direction");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
}

void loop(void) 
{
  while(c<400){
  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  imu::Quaternion quat = bno.getQuat();

int W = quat.w()*100;
int X = quat.x()*100;
int Y = quat.y()*100;
int Z = quat.z()*100;
int q[4] = {W, X, Y, Z};

int hand_dir[4] = {0, 1, 0, 0};
int q2w = hand_dir[0];
int q2x = hand_dir[1];
int q2y = hand_dir[2];
int q2z = hand_dir[3];

// The quaternion product of q and hand_dir
int w1 = W*q2w - X*q2x - Y*q2y - Z*q2z;
int x1 = W*q2x + X*q2w + Y*q2z - Z*q2y;
int y1 = W*q2y - X*q2z + Y*q2w + Z*q2x;
int z1 = W*q2z + X*q2y - Y*q2x + Z*q2w;

int qconj = (W,-X,-Y,-Z);

// The quaternion product of (q x hand_dir) and the conjugate of q
int w2 = w1*(W) - x1*(-X) - y1*(-Y) - z1*(-Z);
int x2 = w1*(-X) + x1*(W) + y1*(-Z) - z1*(-Y);
int y2 = w1*(-Y) - x1*(-Z) + y1*(W) + z1*(-X);
int z2 = w1*(-Z) + x1*(-Y) - y1*(-X) + z1*(W);

int direct = -100;
if (y2 < 0.5)
{
  direct = 100;      //hand points up
}
else if (y2 < -0.5)
{
  direct = 0;
}

// Display the quat data and direction 
Serial.print(quat.w(), 3);
Serial.print(",");
Serial.print(quat.y(), 3);
Serial.print(",");
Serial.print(quat.x(), 3);
Serial.print(",");
Serial.print(quat.z(), 3);
Serial.print(",");
Serial.print(direct);
Serial.println(",");

c = c+1;
delay(10);
}
}
