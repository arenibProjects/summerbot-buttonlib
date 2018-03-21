#include "button.h"
#include "starter.h"
Starter starter = {6,true,true};
int counter = 10;
void setup() {
  Serial.begin(9600);
  delay(100);
  starter.init();
  Serial.println("inited");
  delay(500);
  starter.arm();
  Serial.println("armed");
  while(!starter.isLaunched());
  Serial.println("launched");
}

void loop() {//for fun
  delay(1000);
  if(counter>0){
    Serial.print(counter);
    Serial.println("!");
  }else{
    Serial.println("BOOM!");
    while(1);
  }
  counter--;
}

