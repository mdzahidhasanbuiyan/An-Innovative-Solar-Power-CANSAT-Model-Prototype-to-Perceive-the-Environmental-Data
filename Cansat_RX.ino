#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00001";


struct Data_Package {
  float a;
    float b;
    float c;
    float d;
    float e;
   //float f;
};
Data_Package data; 

struct Data_Package2 {
   float f;
  float g;
  int h; // lrd
  float i; // mq135 
int j;
int s;

};
Data_Package2 data2;

struct Data_Package3 {
    float k ;
    float l; 
    float m;
    float n;
    float o;
    float p;
};
Data_Package3 data3;

struct Data_Package4 {
    float q ;
    float r; 
   

};
Data_Package4 data4;











void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
 if (radio.available()) {


     radio.read(&data,sizeof(Data_Package));
     radio.read(&data2,sizeof(Data_Package2));
      radio.read(&data3,sizeof(Data_Package3));
    radio.read(&data4,sizeof(Data_Package4));




 }
  
    //Serial.print("Temperature = ");
    Serial.print(data.a);

   // Serial.print(",Pressure = ");
    Serial.print(", ");

    Serial.print(data.b);
   // Serial.print(",Humidity = ");
    Serial.print(", ");

    Serial.print(data.c);
    //Serial.print(",Gas = ");
    Serial.print(", ");
    Serial.print(data.d);
    //Serial.print(",Approx. Altitude = ");
    Serial.print(", ");
    Serial.print(data.e);
    //Serial.print(",Object Distance in = ");
    Serial.print(", ");
    Serial.print(data2.f);
    //Serial.print(",Object Distance cm = ");
    Serial.print(", ");
    Serial.print(data2.g);
    
if (data2.h == 0)
  {
    Serial.print(", ");
    Serial.print("Inside Bright ");
   
  }
 else if (data2.h == 1)
  {
    Serial.print(",Inside dark ");
    
  }

 Serial.print(", ");  
  Serial.print(data2.i);
 if (data2.i<=1000)
     {
      //digitalWrite(GreenLed, HIGH); // turn the Green LED on
     // digitalWrite(RedLed,LOW);    // turn the Red LED off
      //noTone(Buzzer);              // turn the Buzzer off
      Serial.print(",_Fresh Air"); //Message
     
     }
    // when air quality value greater than 1000PPM & less than 2000PPM  
    
    
    else if( data2.i>=1000 && data2.i<=2000 )
     {
     // digitalWrite(GreenLed,LOW);  // turn the Green LED off
      //digitalWrite(RedLed, HIGH ); // turn the Red LED on
     // noTone(Buzzer);              // turn the Buzzer off 
    Serial.print(",_Poor Air"); //Message
           
     }
    else if ( data2.i>=2000 )
     {
     // digitalWrite(GreenLed,LOW);  // turn the Green LED off
      //digitalWrite(RedLed,HIGH);   // turn the Red LED on
      //tone(Buzzer, 1000, 200);     // turn the Buzzer on
      Serial.print(",_Danger!!");
      
     }


if (data2.j ==1){
  Serial.print(" ,motion detected at ");
}
else if (data2.j==0){
  Serial.print(" ,motion ended at ");
}



	//Serial.print(",Acceleration X: ");

  Serial.print(", "); 
  Serial.print(data3.k); 
	//Serial.print(", Y: ");
  Serial.print(", "); 
  Serial.print(data3.l); 

	//Serial.print(", Z: ");
  Serial.print(", "); 
  Serial.print(data3.m); 
	//Serial.print(" m/s^2");


	//Serial.print(",Rotation X: ");
  Serial.print(", "); 
  Serial.print( data3.n); 
  Serial.print(", "); 
	//Serial.print(", Y: ");
  Serial.print( data3.o);
  Serial.print(", "); 
	//Serial.print(", Z: ");
  Serial.print(data3.p); 
	//Serial.print(" rad/s");
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





//delay(500);

}


