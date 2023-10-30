
void motorStop()
{
  leftServo.writeMicroseconds(1500);
  rightServo.writeMicroseconds(1500);
  Serial.println("motorStop");
  delay(200);
}

//--------------------------------------------- Adelante
void motorForward()
{
  leftServo.writeMicroseconds(1500 - (power+adj));
  rightServo.writeMicroseconds(1500 + power);
  Serial.println("motorForward");

}

//---------------------------------------------Atras
void motorBackward()
{
  leftServo.writeMicroseconds(1500 + power);
  rightServo.writeMicroseconds(1500 - power);
  Serial.println("motorBackward");
}

//--------------------------------------------- Tiempo de funcionamiento
void motorFwTime (unsigned int time)
{
  motorForward();
  delay (time);
  motorStop();
  Serial.println("motorFwTime");
}

//---------------------------------------------
void motorBwTime (unsigned int time)
{
  motorBackward();
  delay (time);
  motorStop();
  Serial.println("motorBwTime");
}

//------------------------------------------------
void motorTurn(int direction, int degrees)
{
  leftServo.writeMicroseconds(1500 - (iniMotorPower+adj)*direction);
  rightServo.writeMicroseconds(1500 - iniMotorPower*direction);
  delay (round(adjTurn*degrees+20));
  motorStop();
  Serial.println("motorTurn");
}

//---------------------------------------------------
void motorPIDcontrol()
{
  
  int leftMotorSpeed = 1500 - (iniMotorPower+adj) - PIDvalue;
  int rightMotorSpeed = 1500 + iniMotorPower - PIDvalue;
  
  // The motor speed should not exceed the max PWM value
   constrain(leftMotorSpeed, 1000, 2000);
   constrain(rightMotorSpeed, 1000, 2000);
  
  leftServo.writeMicroseconds(leftMotorSpeed);
  rightServo.writeMicroseconds(rightMotorSpeed);
  
  //Serial.print (PIDvalue);
  //Serial.print (" ==> Left, Right:  ");
  //Serial.print (leftMotorSpeed);
  //Serial.print ("   ");
  //Serial.println (rightMotorSpeed);
  Serial.println("motorPIDcontrol");
}

//---------------------------------------------------
void runExtraInch(void)
{
  motorPIDcontrol();
  delay(extraInch);
  motorStop();
  Serial.println("runExtraInch");
}

//---------------------------------------------------
void goAndTurn(int direction, int degrees)
{
  motorPIDcontrol();
  delay(adjGoAndTurn);
  motorTurn(direction, degrees);
  Serial.println("goAndTurn");
}

