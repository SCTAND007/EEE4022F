/*************************
 Bluetooth test program
*************************/

int counter = 0;
int incomingByte;
char string[6];  

void setup() {
  Serial.begin(115200);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    //read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    if (incomingByte == 'R') {
      Serial.print("RESET");
      counter=0;
    }
  }
  
  //if (counter=100000)
  //{
  //  counter = 0;
  //}
  if (counter<10)
  {
     Serial.print("0000");
     Serial.print(counter);
  }
  else if (counter<100)
  {
    Serial.print("000");
    Serial.print(counter);
  }
  else if (counter<1000)
  {
    Serial.print("00");
    Serial.print(counter);
  }
  else if (counter<10000)
  {
    Serial.print("0");
    Serial.print(counter);
  }
  else
  {
    Serial.print(counter);
  }

  
  counter++;
  delay(1000);
}
