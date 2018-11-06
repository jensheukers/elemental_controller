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

void setup() {
  // put your setup code here, to run once:
  joyStickSwitchPin = 11;
  joyStickXPin = 14;
  joyStickYPin = 15;
  potMeterPin = 16;
  fanPin = A3;
  pinMode(joyStickSwitchPin, INPUT);
  pinMode(joyStickXPin, INPUT);
  pinMode(joyStickYPin, INPUT);
  pinMode(potMeterPin, INPUT);
  pinMode(fanPin, INPUT);
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
      Serial.println(rotation - lastRotation);
    }
  }
  lastRotation = rotation;
  if(fanSpeed <= 10){
    Serial.print("fan Output: ");
    Serial.println(fanSpeed);
  }

  if(xx < 450 || xx > 580){
    
    Serial.print("Joy stick x");
    Serial.println(xx);
    
  }

  if(yy < 450 || yy > 580){

    Serial.print("Joy stick y");
    Serial.println(yy);
    
  }

  Serial.println(joyStickSwitch);
  
  if(joyStickSwitch == HIGH){
    
    Serial.println("Joy stick pushed!");
    
  }
  
  delay(20);
}
