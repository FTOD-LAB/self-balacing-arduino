#include "motors_control.hpp"
Motors m;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = -255; i < 256; i+=5){
    m.set(-i);
    Serial.print(i); Serial.print("\n");
    delay(50);
  }
}
