int Sliding2manual () {    //sliding to manual
      if (buffered_p_pwm <= buffered_m_pwm) {     // менше/дорівнює авто
        while (buffered_p_pwm < buffered_m_pwm && photo_mode == 0){
          if (millis () - time_stepping > 5) {
            time_stepping = millis () ;
            buffered_p_pwm = buffered_p_pwm + 1;
            analogWrite (w_main_pin, buffered_p_pwm);           
          }
        }
       }
      else {                    // більше ніж мануал
        while (buffered_p_pwm > buffered_m_pwm && photo_mode == 0){
          if (millis () - time_stepping > 3) {
            time_stepping = millis () ;
            buffered_p_pwm = buffered_p_pwm - 1;
            analogWrite (w_main_pin, buffered_p_pwm); 
          }
        }
      }
    return(m_pwm);
}    
//    ***********************************************************************
    
