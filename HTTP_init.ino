void wm (int val)
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = val;  
  Serial.println(m_pwm);
}


void HTTP_init(void) {
  HTTP.onNotFound(handleNotFound); // Сообщение если нет страницы. Попробуйте ввести http://192.168.0.101/restar?device=ok&test=1&led=on
  HTTP.on("/", handleRoot); // Главная страница http://192.168.0.101/
  HTTP.on("/restart", handle_Restart); // Перезагрузка модуля по запросу вида http://192.168.0.101/restart?device=ok
 //Main
  HTTP.on("/v0", v0);
  HTTP.on("/v1", v1);
  HTTP.on("/v2", v2);
  HTTP.on("/v3", v3);
  HTTP.on("/v4", v4);    
  HTTP.on("/v5", v5);    
  HTTP.on("/v6", v6);    
  HTTP.on("/v7", v7);    
  HTTP.on("/v8", v8);    
  HTTP.on("/v9", v9);    
  HTTP.on("/v10", v10);

//SECONDARY
  HTTP.on("/s0", s0);
  HTTP.on("/s1", s1);
  HTTP.on("/s2", s2);
  HTTP.on("/s3", s3);
  HTTP.on("/s4", s4);    
  HTTP.on("/s5", s5);    
  HTTP.on("/s6", s6);    
  HTTP.on("/s7", s7);    
  HTTP.on("/s8", se8);    
  HTTP.on("/s9", s9);    
  HTTP.on("/s10", s10);
  
  //RED
  HTTP.on("/r0", r0);
  HTTP.on("/r1", r1);
  HTTP.on("/r2", r2);
  HTTP.on("/r3", r3);
  HTTP.on("/r4", r4);    
  HTTP.on("/r5", r5);    
  HTTP.on("/r6", r6);    
  HTTP.on("/r7", r7);    
  HTTP.on("/r8", r8);    
  HTTP.on("/r9", r9);    
  HTTP.on("/r10", r10);

  //RED
  HTTP.on("/g0", g0);
  HTTP.on("/g1", g1);
  HTTP.on("/g2", g2);
  HTTP.on("/g3", g3);
  HTTP.on("/g4", g4);    
  HTTP.on("/g5", g5);    
  HTTP.on("/g6", g6);    
  HTTP.on("/g7", g7);    
  HTTP.on("/g8", g8);    
  HTTP.on("/g9", g9);    
  HTTP.on("/g10", g10);

  //BLUE
  HTTP.on("/b0", b0);
  HTTP.on("/b1", b1);
  HTTP.on("/b2", b2);
  HTTP.on("/b3", b3);
  HTTP.on("/b4", b4);    
  HTTP.on("/b5", b5);    
  HTTP.on("/b6", b6);    
  HTTP.on("/b7", b7);    
  HTTP.on("/b8", b8);    
  HTTP.on("/b9", b9);    
  HTTP.on("/b10", b10);
  
  HTTP.on("/pwm_mode", pwm_mode);
  
  HTTP.begin(); // Запускаем HTTP сервер
}

// Ответ если страница не найдена
void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += HTTP.uri();
  message += "\nMethod: ";
  message += (HTTP.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += HTTP.args();
  message += "\n";
  for (uint8_t i=0; i<HTTP.args(); i++){
    message += " " + HTTP.argName(i) + ": " + HTTP.arg(i) + "\n";
  }
  HTTP.send(404, "text/plain", message);
}

// Ответ при обращении к основной странице
void handleRoot() {
  HTTP.send(200, "text/html", webPage);
}

// Перезагрузка модуля по запросу вида http://192.168.0.101/restart?device=ok
void handle_Restart() {
  String restart = HTTP.arg("device");
  if (restart == "ok") ESP.restart();
  HTTP.send(200, "text/plain", "OK");
}

void v0() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 0;  
  Serial.println(m_pwm);
}

void v1() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 1;  
  Serial.println(m_pwm);
}

void v2() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 4;  
  Serial.println(m_pwm);
}

void v3() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 9;  
  Serial.println(m_pwm);
}

void v4() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 13;  
  Serial.println(m_pwm);
}

void v5() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 18;  
  Serial.println(m_pwm);
}

void v6() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 25;  
  Serial.println(m_pwm);
}

void v7() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 35;  
  Serial.println(m_pwm);
}

void v8() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 50;  
  Serial.println(m_pwm);
}

void v9() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 75;  
  Serial.println(m_pwm);
}

void v10() 
{
  HTTP.send(200, "text/html", webPage);
  m_pwm = 100;  
  Serial.println(m_pwm);
}
void pwm_mode  () {
  HTTP.send(200, "text/html", webPage);
  buffered_m_pwm = m_pwm; // buffering
  buffered_p_pwm = p_pwm; // buffering
  photo_mode = !photo_mode; //mode of pwm
  Serial.println(p_pwm);

}
