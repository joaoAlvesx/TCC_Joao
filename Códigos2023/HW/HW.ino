 int val = 5 ;  
 
 void setup()  
 {  
   Serial.begin(9600); // sensor buart rate     
 }  
 void loop()   
 {  
  val = digitalRead(5); // IR Sensor output pin connected to D1  
  Serial.println(val);  // see the value in serial m0nitor in Arduino IDE  
  delay(100);        

  }  
