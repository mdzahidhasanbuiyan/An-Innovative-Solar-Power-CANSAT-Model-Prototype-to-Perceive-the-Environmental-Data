
void mq135()
 {
  // Read Senso value
  MQ135 gasSensor = MQ135(A0);
  float air_quality = gasSensor.getPPM();
  // Print Senso value on Serial Monitor Window
 // Serial.print(",Air Quality: ");  
 // Serial.print(air_quality);
  //Serial.println("  PPM");   
  //Serial.println();
  data2.i=air_quality;
   
   
   
    }