void s0() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 0;  
  Serial.println(b_pwm);
}

void s1() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 1;  
  Serial.println(b_pwm);
}

void s2() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 4;  
  Serial.println(b_pwm);
}

void s3() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 9;  
  Serial.println(b_pwm);
}

void s4() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 13;  
  Serial.println(r_pwm);
}

void s5() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 18;  
  Serial.println(b_pwm);
}

void s6() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 25;  
  Serial.println(b_pwm);
}

void s7() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 35;  
  Serial.println(b_pwm);
}

void se8() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 50;  
  Serial.println(b_pwm);
}

void s9() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 75;  
  Serial.println(b_pwm);
}

void s10() 
{
  HTTP.send(200, "text/html", webPage);
  s_pwm = 100;  
  Serial.println(b_pwm);
}
