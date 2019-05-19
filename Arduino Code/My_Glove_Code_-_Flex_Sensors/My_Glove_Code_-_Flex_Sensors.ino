int F1 = A0;        // analog pin 0
int F2 = A1;        // analog pin 0
int F3 = A2;        // analog pin 0
int F4 = A3;        // analog pin 0
int F5 = A6;        // analog pin 0
                    // outside leads to ground and +3.3V
int val1 = 0;        // variable to store the value read
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

void setup() {
  Serial.begin(9600);           //  setup serial
  Serial.println("F1,F2,F3,F4,F5,");
}

void loop() {
  val1 = analogRead(F1);        // read the input pin
  Serial.print(val1);          // debug value
  Serial.print(",");
  val2 = analogRead(F2);        // read the input pin
  Serial.print(val2);          // debug value
  Serial.print(",");
  val3 = analogRead(F3);        // read the input pin
  Serial.print(val3);          // debug value
  Serial.print(",");
  val4 = analogRead(F4);        // read the input pin
  Serial.print(val4);          // debug value
  Serial.print(",");
  val5 = analogRead(F5);        // read the input pin
  Serial.print(val5);          // debug value
  Serial.print(",");
  Serial.println("");
  delay(10);
}
