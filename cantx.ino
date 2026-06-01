
//Nrf
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 8); // CE, CSN
const byte address[6] = "00001";
// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
   float a;
   float b;
   float c;
   float d;
   float e;
};
Data_Package data; // Create a variable with the above structure
struct Data_Package2 {
    float f;
    float g;
    int h; 
    float i;
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
  // float q ;
   //float r;

};
Data_Package3 data3;


struct Data_Package4 {
    float q ;
   float r; 
};
Data_Package4 data4;







//bme680
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME680 bme;


//hc sr04

int trigPin = 2;    // Trigger
int echoPin = 3;    // Echo
long duration, cm, inches;


 //ldr
 int LDRSensor = 4;




 //mq135
 #include "MQ135.h"  


// Pir Moton
int pirPin = 6;
int val ;



//mpu 6050
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
Adafruit_MPU6050 mpu;


//gps
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
static const int RXPin = 10, TXPin = 7;
//static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);




//flame
int flame_sensor = 5;
int flame_detected;









void setup() {
 

  //nrf
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();



  //bme680
  Serial.begin(9600);
  while (!Serial);

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150);


// hc sr 04
 //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


//ldr
  pinMode (LDRSensor, INPUT);
 // pinMode (LED1, OUTPUT);
  Serial.begin (9600);





//mq135

  // Start serial communication between arduino and your computer

  


//pir 
  pinMode(pirPin, INPUT);


 pinMode(flame_sensor, INPUT);


  //mpu6050

  	// Try to initialize!
	if (!mpu.begin()) {
		Serial.println("Failed to find MPU6050 chip");
		while (1) {
	
		}
	}
	Serial.println("MPU6050 Found!");

	// set accelerometer range to +-8G
	mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

	// set gyro range to +- 500 deg/s
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);

	// set filter bandwidth to 21 Hz
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);



//gps
// ss.begin(GPSBaud);

pinMode(1, OUTPUT);
}

void loop() {

 nrf();


//led();


}
