void r0() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 0;  
  Serial.println(r_pwm);
}

void r1() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 1;  
  Serial.println(r_pwm);
}

void r2() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 4;  
  Serial.println(r_pwm);
}

void r3() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 9;  
  Serial.println(r_pwm);
}

void r4() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 13;  
  Serial.println(r_pwm);
}

void r5() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 18;  
  Serial.println(r_pwm);
}

void r6() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 25;  
  Serial.println(r_pwm);
}

void r7() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 35;  
  Serial.println(r_pwm);
}

void r8() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 50;  
  Serial.println(r_pwm);
}

void r9() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 75;  
  Serial.println(r_pwm);
}

void r10() 
{
  HTTP.send(200, "text/html", webPage);
  r_pwm = 100;  
  Serial.println(r_pwm);
}
