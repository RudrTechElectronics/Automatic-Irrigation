 
//www.edisonsciencecorner.blogspot.com
 
//https://www.youtube.com/channel/UCESZHuYTzx0Eyd3yJ8u60Fg
 
 
 
#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>
 
#include <BlynkSimpleEsp8266.h>
 
 
char auth[] = "vV-V8RS57KNSiY4vmDse0oth9zQ6MWS5"; // blynk token
 
 
char ssid[] = "Rudra home";   //ssid//password
 
 
char pass[] = "rudra@123";    //password
 
int moisture;
 
int data;
 
void setup() { 
 
  Serial.begin(9600);
 
  pinMode(A0,INPUT);
 
  Blynk.begin(auth, ssid, pass);
 
  
 
}
 
 
void loop()
 
 
{
 
  Blynk.run();
 
moisture = analogRead(0);       //Read Analog value of first sensor
 
  delay(100);   
 
  data = map(moisture,500,1023,100,0);                
 
  Serial.print("moisture = ");     //to the serial monitor
 
  Serial.print(data );

  Serial.print('/n');
 
  Blynk.virtualWrite(V5, data );  // to Blynk server


 
 
    }
