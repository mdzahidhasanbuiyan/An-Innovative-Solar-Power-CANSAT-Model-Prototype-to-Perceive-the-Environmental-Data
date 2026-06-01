void bme680() {
  if (! bme.performReading()) {
    //Serial.println("Failed to perform reading :(");
    return;
  }
  //Serial.print("Temperature = ");
  //Serial.print
  data.a=(bme.temperature);
  //Serial.println(" *C");

  //Serial.print("Pressure = ");
  //Serial.print
  
  data.b=(bme.pressure / 100.0);
  //Serial.println(" hPa");

  //Serial.print("Humidity = ");
  //Serial.print
  
  data.c=(bme.humidity);
  //Serial.println(" %");

  //Serial.print("Gas = ");
  //Serial.print
  



  
  data.d=(bme.gas_resistance );
 // Serial.println(" KOhms");

  //Serial.print("Approx. Altitude = ");
  //Serial.print
  
  data.e=(bme.readAltitude(SEALEVELPRESSURE_HPA));
  //Serial.println(" m");

  //Serial.println();
  //delay(500);




  
}
