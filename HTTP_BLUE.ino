void b0() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 0;  
  Serial.println(b_pwm);
}

void b1() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 1;  
  Serial.println(b_pwm);
}

void b2() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 4;  
  Serial.println(b_pwm);
}

void b3() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 9;  
  Serial.println(b_pwm);
}

void b4() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 13;  
  Serial.println(r_pwm);
}

void b5() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 18;  
  Serial.println(b_pwm);
}

void b6() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 25;  
  Serial.println(b_pwm);
}

void b7() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 35;  
  Serial.println(b_pwm);
}

void b8() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 50;  
  Serial.println(b_pwm);
}

void b9() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 75;  
  Serial.println(b_pwm);
}

void b10() 
{
  HTTP.send(200, "text/html", webPage);
  b_pwm = 100;  
  Serial.println(b_pwm);
}
