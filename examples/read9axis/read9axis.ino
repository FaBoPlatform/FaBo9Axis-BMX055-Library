/**
 @file read9axis.ino
 @brief This is an Example for the FaBo 9Axis(BMX055) I2C Brick.

   http://fabo.io/219.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#include <Wire.h>
#include <FaBo9Axis_BMX055.h>

FaBo9Axis fabo9axis;

int accel[3];
int gyro[3];
int mag[3];

char output_string[100];

void setup() {
  Serial.begin(115200);
  
  // Device initialize
  while(!fabo9axis.begin()){
    Serial.println("Not found 9Axis BMX055");
    delay(5000);
  }  
  
  Serial.println("I am BMX055");
}

void loop() {

  // Read Accel  -> X:accel[0], Y:accel[1], Z:accel[2]
  fabo9axis.readAccel(accel);
  
  // Read Gyro   -> X:gyro[0], Y:gyro[1], Z:gyro[2]
  fabo9axis.readGyro(gyro);
  
  // Read Magnet -> X:mag[0], Y:mag[1], Z:mag[2]
  fabo9axis.readMag(mag);

  // Output log
  sprintf(output_string, "Accel X:%d, Y:%d, Z:%d\0", accel[0], accel[1], accel[2]);
  Serial.println(output_string);
  
  sprintf(output_string, "Gyro  X:%d, Y:%d, Z:%d\0", gyro[0], gyro[1], gyro[2]);
  Serial.println(output_string);
  
  sprintf(output_string, "Mag   X:%d, Y:%d, Z:%d\r\n\0", mag[0], mag[1], mag[2]);
  Serial.println(output_string);
  
  delay(500);
}
