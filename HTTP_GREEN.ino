void g0() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 0;  
  Serial.println(g_pwm);
}

void g1() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 1;  
  Serial.println(r_pwm);
}

void g2() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 4;  
  Serial.println(r_pwm);
}

void g3() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 9;  
  Serial.println(r_pwm);
}

void g4() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 13;  
  Serial.println(r_pwm);
}

void g5() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 18;  
  Serial.println(r_pwm);
}

void g6() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 25;  
  Serial.println(r_pwm);
}

void g7() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 35;  
  Serial.println(r_pwm);
}

void g8() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 50;  
  Serial.println(r_pwm);
}

void g9() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 75;  
  Serial.println(r_pwm);
}

void g10() 
{
  HTTP.send(200, "text/html", webPage);
  g_pwm = 100;  
  Serial.println(r_pwm);
}
