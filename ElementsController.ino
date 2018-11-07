int joyStickSwitchPin;
int joyStickXPin;
int joyStickYPin;
int potMeterPin;
int fanPin;
int xx;
int yy;
int fanSpeed;
int rotation;
int lastRotation;
int joyStickSwitch;
int switchPin;

void setup() {
  // put your setup code here, to run once:
  joyStickSwitchPin = 11;
  joyStickXPin = 14;
  joyStickYPin = 15;
  potMeterPin = 16;
  switchPin = 10;
  fanPin = A3;
  pinMode(joyStickSwitchPin, INPUT);
  pinMode(joyStickXPin, INPUT);
  pinMode(joyStickYPin, INPUT);
  pinMode(potMeterPin, INPUT);
  pinMode(fanPin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(joyStickSwitchPin));
  xx = analogRead(joyStickXPin);
  yy = analogRead(joyStickYPin);
  joyStickSwitch = digitalRead(joyStickSwitchPin);
  rotation = analogRead(potMeterPin);
  fanSpeed = analogRead(fanPin);
  if(lastRotation > rotation){
    if(lastRotation - rotation > 5){
      Serial.println(lastRotation - rotation);
    }
  } 
  else
  {
    if(rotation - lastRotation > 5){
      Keyboard.write("5");
    }
  }
  
  lastRotation = rotation;
  if(fanSpeed <= 10){
    Serial.print("fan Output: ");
    Serial.println(fanSpeed);
    Keyboard.write("6");
  }

  if(xx < 450){
    
    Serial.print("Joy stick x");
    Serial.println(xx);
    Keyboard.write("l");
    
  }

 if(xx > 580){
  Serial.print("Joy stick x");
  Serial.println(xx);
  Keyboard.write("j");
 }

  if(yy < 450){
    Serial.print("Joy stick y");
    Serial.println(yy);
    Keyboard.write("k");
  }

  if(yy > 580){
    Serial.print("Joy stick y");
    Serial.println(yy);
    Keyboard.print("i");
  }
  
  /*if(joyStickSwitch == HIGH){
    
    Serial.print("Joy stick pushed: ");
    Serial.println(joyStickSwitch);
    
  }*/

  /*if(digitalRead(switchPin) == HIGH){
    Serial.print("Switch pushed: ");
    Serial.println(digitalRead(switchPin));
  }*/
  
  delay(20);
}
