void gps1(){
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){




      //Serial.print(",Latitude= "); 

     // Serial.print(gps.location.lat(), 6);

      data4.q=(gps.location.lat(), 6);

     // Serial.println(" ,Longitude= "); 
      //Serial.println(gps.location.lng(), 6);

      data4.r=(gps.location.lng(), 6);

    }

//else if (ss.available() < 0) {

//Serial.println("No GPS detected");

//}
    
  //}
}

}