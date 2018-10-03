int Sliding2auto (){ // auto
    
    if (buffered_m_pwm <= buffered_p_pwm) 
    {     // менше/дорівнює авто
      while (buffered_m_pwm < buffered_p_pwm)
      {
        if (millis () - time_stepping > 5) 
        {
          time_stepping = millis () ;
          buffered_m_pwm = buffered_m_pwm + 1;
          analogWrite (w_main_pin, buffered_m_pwm);   
        }
      }
    }
    else {                    // більше ніж авто
      while (buffered_m_pwm > buffered_p_pwm){
        if (millis () - time_stepping > 3) {
          time_stepping = millis () ;
          buffered_m_pwm = buffered_m_pwm - 1;
          analogWrite (w_main_pin, buffered_m_pwm);  
        }
      }
    }
    return(p_pwm);
}
