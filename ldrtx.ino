void ldr()
 {
   int  Sensordata= digitalRead (LDRSensor);
   //Serial.print("Sensor value:");
   //Serial.println(Sensordata);
   data2.h=Sensordata;
 }