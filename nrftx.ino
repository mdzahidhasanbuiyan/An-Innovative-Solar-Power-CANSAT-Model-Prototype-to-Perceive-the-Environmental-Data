
void nrf() {
  
bme680();
hc_sr04();
ldr();
mq135();
mpu6050();
flame();
//gps1();

    Serial.print("Temperature = ");
    Serial.print(data.a);
    Serial.print(",Pressure = ");
    Serial.print(data.b);
    Serial.print(",Humidity = ");
    Serial.print(data.c);
    Serial.print(",Gas = ");
    Serial.print(data.d);
    Serial.print(",Approx. Altitude = ");
    Serial.print(data.e);

    Serial.print(",Object Distance in = ");
    Serial.print(data2.f);

    Serial.print(",Object Distance cm = ");
    Serial.print(data2.g);



    if (data2.h == 0)
  {
    Serial.print(",Inside Bright_Led is off");
     
  }
 else if (data2.h == 1)
  {
    Serial.print(",Inside dark_Led is on ");
   
  }


  Serial.print(",Air Quality: ");  
  Serial.print(data2.i);
 if (data2.i<=1000)
     {
      Serial.print("_Fresh Air"); //Message
     
     }
    // when air quality value greater than 1000PPM & less than 2000PPM  
    
    
    else if( data2.i>=1000 && data2.i<=2000 )
     {
    Serial.print("_Poor Air"); //Message
           
     }
    else if ( data2.i>=2000 )
     {
      Serial.print("_Danger!!");
      //delay(200);
     }


if (data2.j ==1){
  Serial.print(" ,motion detected at ");
}
else if (data2.j==0){
  Serial.print(" ,motion ended at ");
}


	Serial.print(",Acceleration X: ");
  Serial.print(data3.k); 
	Serial.print(", Y: ");
  Serial.print(data3.l); 
	Serial.print(", Z: ");
  Serial.print(data3.m); 
	//Serial.print(" m/s^2");


	Serial.print(",Rotation X: ");
  Serial.print( data3.n); 
	Serial.print(", Y: ");
  Serial.print( data3.o);
	Serial.print(", Z: ");
  Serial.print(data3.p); 
	Serial.print(" rad/s");

  

  Serial.print(",Latitude= "); 
  Serial.print( data4.q);
  Serial.print(" ,Longitude= "); 
  Serial.print(data4.r);




if (data2.s ==1){
  Serial.println(" ,flamen ended at");
}

else if (data2.s==0){
  Serial.println(" ,flame detected at  ");
}


  radio.write(&data, sizeof(Data_Package));
  radio.write(&data2, sizeof(Data_Package2));
  radio.write(&data3, sizeof(Data_Package3));
  radio.write(&data4, sizeof(Data_Package4));

//delay(500);

}
