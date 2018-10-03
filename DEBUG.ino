#include <ESP8266WiFi.h>        //Содержится в пакете
#include <ESP8266WebServer.h>   //Содержится в пакете


#define l_treshold 200 // low threshold (auto)
#define h_treshold 700 // high threshold (auto)

#define pr_pin A0 // photoresistor input pin
#define force_pin 13 // pin for hand start

#define w_main_pin 5 // output main
#define w_second_pin 4 //small white
#define R_pin 14 //RED pin 14(D5)
#define G_pin 15 //Green pin 15(D8)
#define B_pin 0 //Blue pin 0(D3)


IPAddress apIP(192, 168, 4, 1); // ip wifi-host (server)
  
// Web интерфейс для устройства
ESP8266WebServer HTTP(80); // server port

// Определяем переменные wifi
String _ssid     = "Compton"; // Wi-Fi name
String _password = "9b0a7YhTcGZ"; // Wi-Fi Password
String _ssidAP = "WiFi";   // AP Wi-Fi name
String _passwordAP = ""; // AP Wi-Fi Password

String webPage = "<!DOCTYPE html>"
                  "<html>"
                  " <head>"
                  "  <meta charset=\"utf-8\">"
                  "  <title>Compton light</title>"
                  " </head>"
                  "  <body>"
                  "     <table align=\"center\" width=\"100%\">"
                  "        <tr align=\"center\">"
                  "          <td>"
                  "            <h1>Compton Light Project</h1>"
                  "             <div align=\"center\">"
                  "             <p> Main strip brightness: "
                  "               <br>"
                  "               <a href=\"v0\"><button>OFF</button></a>&nbsp;"
                  "               <a href=\"v1\"><button>1%</button></a>&nbsp;"
                  "               <a href=\"v2\"><button>4%</button></a>&nbsp;"
                  "               <a href=\"v3\"><button>9%</button></a>&nbsp;"
                  "               <a href=\"v4\"><button>13%</button></a>&nbsp;"
                  "               <a href=\"v5\"><button>18%</button></a>&nbsp;"
                  "               <a href=\"v6\"><button>25%</button></a>&nbsp;"
                  "               <a href=\"v7\"><button>35%</button></a>&nbsp;"
                  "               <a href=\"v8\"><button>50%</button></a>&nbsp;"
                  "               <a href=\"v9\"><button>70%</button></a>&nbsp;"
                  "               <a href=\"v10\"><button>100%</button></a>&nbsp;"
                  "             </p>"
                  "           </div>"
                  "        </td>"
                  "       </tr>"     
                  "        <tr align=\"center\">"
                  "          <td>"
                  "             <div align=\"center\">"
                  "             <p> Second strip brightness: "
                  "               <br>"
                  "               <a href=\"s0\"><button>OFF</button></a>&nbsp;"
                  "               <a href=\"s1\"><button>1%</button></a>&nbsp;"
                  "               <a href=\"s2\"><button>4%</button></a>&nbsp;"
                  "               <a href=\"s3\"><button>9%</button></a>&nbsp;"
                  "               <a href=\"s4\"><button>13%</button></a>&nbsp;"
                  "               <a href=\"s5\"><button>18%</button></a>&nbsp;"
                  "               <a href=\"s6\"><button>25%</button></a>&nbsp;"
                  "               <a href=\"s7\"><button>35%</button></a>&nbsp;"
                  "               <a href=\"s8\"><button>50%</button></a>&nbsp;"
                  "               <a href=\"s9\"><button>70%</button></a>&nbsp;"
                  "               <a href=\"s10\"><button>100%</button></a>&nbsp;"
                  "             </p>"
                  "           </div>"
                  "        </td>"
                  "       </tr>"     
                  "       <tr align=\"center\">"
                  "          <td>"

                  "             <div align=\"center\">"
                  "             <p> RED: "
                  "               <br>"
                  "               <a href=\"r0\"><button>OFF</button></a>&nbsp;"
                  "               <a href=\"r1\"><button>1%</button></a>&nbsp;"
                  "               <a href=\"r2\"><button>4%</button></a>&nbsp;"
                  "               <a href=\"r3\"><button>9%</button></a>&nbsp;"
                  "               <a href=\"r4\"><button>13%</button></a>&nbsp;"
                  "               <a href=\"r5\"><button>18%</button></a>&nbsp;"
                  "               <a href=\"r6\"><button>25%</button></a>&nbsp;"
                  "               <a href=\"r7\"><button>35%</button></a>&nbsp;"
                  "               <a href=\"r8\"><button>50%</button></a>&nbsp;"
                  "               <a href=\"r9\"><button>70%</button></a>&nbsp;"
                  "               <a href=\"r10\"><button>100%</button></a>&nbsp;"
                  "             </p>"
                  "           </div>"
                  "        </td>"
                  "       </tr>"     
                  "       <tr align=\"center\">"
                  "          <td>"

                  "             <div align=\"center\">"
                  "             <p> GREEN: "
                  "               <br>"
                  "               <a href=\"g0\"><button>OFF</button></a>&nbsp;"
                  "               <a href=\"g1\"><button>1%</button></a>&nbsp;"
                  "               <a href=\"g2\"><button>4%</button></a>&nbsp;"
                  "               <a href=\"g3\"><button>9%</button></a>&nbsp;"
                  "               <a href=\"g4\"><button>13%</button></a>&nbsp;"
                  "               <a href=\"g5\"><button>18%</button></a>&nbsp;"
                  "               <a href=\"g6\"><button>25%</button></a>&nbsp;"
                  "               <a href=\"g7\"><button>35%</button></a>&nbsp;"
                  "               <a href=\"g8\"><button>50%</button></a>&nbsp;"
                  "               <a href=\"g9\"><button>70%</button></a>&nbsp;"
                  "               <a href=\"g10\"><button>100%</button></a>&nbsp;"
                  "             </p>"
                  "           </div>"
                  "        </td>"
                  "       </tr>"     
                  "       <tr align=\"center\">"
                  "          <td>"

                  "             <div align=\"center\">"
                  "             <p> BLUE: "
                  "               <br>"
                  "               <a href=\"b0\"><button>OFF</button></a>&nbsp;"
                  "               <a href=\"b1\"><button>1%</button></a>&nbsp;"
                  "               <a href=\"b2\"><button>4%</button></a>&nbsp;"
                  "               <a href=\"b3\"><button>9%</button></a>&nbsp;"
                  "               <a href=\"b4\"><button>13%</button></a>&nbsp;"
                  "               <a href=\"b5\"><button>18%</button></a>&nbsp;"
                  "               <a href=\"b6\"><button>25%</button></a>&nbsp;"
                  "               <a href=\"b7\"><button>35%</button></a>&nbsp;"
                  "               <a href=\"b8\"><button>50%</button></a>&nbsp;"
                  "               <a href=\"b9\"><button>70%</button></a>&nbsp;"
                  "               <a href=\"b10\"><button>100%</button></a>&nbsp;"
                  "             </p>"
                  "           </div>"
                  "        </td>"
                  "       </tr>"
                  "       <tr align=\"center\">"
                  "         <td><a href=\"pwm_mode\"><button>Mode</button></a>&nbsp;</td>"
                  "       </tr>"         
                  "  </body>"
                  "</html>";
                   
                   
byte m_pwm = 0; // settable value of PWM for manual mode 
byte p_pwm = 0; // settable value of PWM for photo(auto) mode 
byte s_pwm = 0; // settable value of PWM for Second strip
byte r_pwm = 0; // settable value of PWM for red
byte g_pwm = 0; // settable value of PWM for green
byte b_pwm = 0; // settable value of PWM for blue
byte buffered_p_pwm = 0; // buffered (copy) of m_pwm
byte buffered_m_pwm = 0; // buffered (copy) of p_pwm
boolean photo_mode = 0; // light mode flag
boolean _status = 0; // hand mode status

unsigned long time_stepping = 0; // time value for sliding 

void setup() {
  pinMode(w_main_pin, OUTPUT); // setting pinmode for white main strip
  pinMode(w_second_pin, OUTPUT); // setting pinmode for white side strip
  pinMode(R_pin, OUTPUT); // setting pinmode for Red 
  pinMode(G_pin, OUTPUT); // setting pinmode for Green
  pinMode(B_pin, OUTPUT); // setting pinmode for Blue
  pinMode(force_pin, INPUT);
  analogWriteFreq(150); // frequency for PWM
  analogWriteRange(100); // Stepping 1-100%
  analogWrite(w_main_pin, 0); // white main LED-off at beginning
  analogWrite(w_second_pin, 0); // white secondary LED-off at beginning
  analogWrite(R_pin, 0); // RED LED-off at beginning
  analogWrite(G_pin, 0); // GREEN LED-off at beginning
  analogWrite(B_pin, 0); // BLUE LED-off at beginning

  /*_________________________________________________
  analogWrite(R_pin, 100); // RED LED-off at beginning
  analogWrite(G_pin, 100); // GREEN LED-off at beginning
  analogWrite(B_pin, 100); // BLUE LED-off at beginning
  //_________________________________________________*/
  
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Start 1-WIFI");
  //Запускаем WIFI
  WIFIinit();
  //Настраиваем и запускаем HTTP интерфейс
  Serial.println("Start 2-WebServer");
  HTTP_init();
}

void loop() {
/*  p_pwm = analogRead(pr_pin); // read automatic pwm value range (0-1023)
  p_pwm = map(p_pwm, l_treshold, h_treshold, 0, 100); // range transforming (250-700 to 0-100)
  p_pwm = constrain(p_pwm, 0, 100); // range cutting
  //Serial.println(p_pwm);
  */
  _status = digitalRead(force_pin);

//RGB processing
  
  analogWrite(R_pin, r_pwm);
  analogWrite(G_pin, g_pwm);
  analogWrite(B_pin, b_pwm);
  analogWrite(w_second_pin, s_pwm);

//  ******main light processing
 
  if (_status == 1) analogWrite(w_main_pin, 100);// white main LED-on if pin SC
  else {
      if (photo_mode == 1) 
      {
        analogWrite(w_main_pin, Sliding2auto ());
      }
      else
      {
        analogWrite(w_main_pin, Sliding2manual ());
      }
  } 
//  ******  
  HTTP.handleClient();
  delay(1);
}
