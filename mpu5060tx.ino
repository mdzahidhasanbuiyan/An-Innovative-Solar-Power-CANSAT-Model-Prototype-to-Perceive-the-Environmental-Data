void mpu6050() {
	/* Get new sensor events with the readings */
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);





//	Serial.print(",Acceleration X: ");
//	Serial.print(a.acceleration.x);
  data3.k=a.acceleration.x;

//	Serial.print(", Y: ");
//	Serial.print(a.acceleration.y);
   data3.l=a.acceleration.y;

//	Serial.print(", Z: ");
	//Serial.print(a.acceleration.z);
  data3.m=a.acceleration.z;

	//Serial.print(" m/s^2");




//	Serial.print(",Rotation X: ");
//	Serial.print(g.gyro.x);
  data3.n=g.gyro.x;


//	Serial.print(", Y: ");

//	Serial.print(g.gyro.y);
  data3.o=g.gyro.y;

//	Serial.print(", Z: ");

//	Serial.print(g.gyro.z);
  data3.p=g.gyro.z;

	//erial.println(" rad/s");




}