int C1 = 5;   // choose the input pin (for a pushbutton)
int C2 = 4;
int C3 = 3;
int C4 = 2;
int val1 = 0;     // variable for reading the pin status
int val2 = 0;
int val3 = 0;
int val4 = 0;
int c = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(C1, INPUT);    // declare pushbutton as input
  pinMode(C2, INPUT);    // declare pushbutton as input
  pinMode(C3, INPUT);    // declare pushbutton as input
  pinMode(C4, INPUT);    // declare pushbutton as input
  Serial.begin(9600);           //  setup serial
  Serial.println("C1,C2,C3,C4,");
}

void loop() {
  while (c<800) {
  // put your main code here, to run repeatedly:
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
  delay(10);
  c = c + 1;
  }
}
