const float VCC = 3.68;
const float R_DIV = 800;
const float StrR = 9780.0;
const float BenR = 17300.0;
int F1 = A1;        // analog pin 0
int c = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           //  setup serial
  Serial.println("F1,");
}

void loop() {
  while (c<500){
  // put your main code here, to run repeatedly:
  int flexADC = analogRead(F1);
  float flexV = flexADC*VCC/1023.0;
  float flexR = R_DIV*(VCC/flexV-1.0);
  float angle = map(flexR, StrR, BenR, 0, 90.0);
  float myAngle = angle/250*90;
  //Serial.print(angle);
  //Serial.print(",")'
  Serial.print(myAngle);
  Serial.println(",");
  delay(10);
  c = c+1;
  }
}
