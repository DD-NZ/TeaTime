#include <OneWire.h>
#include <DallasTemperature.h>

// DS18S20 TEMP
int DS18S20_Pin = 4;
OneWire ds(DS18S20_Pin);
DallasTemperature tempSensor(&ds);


void setup() {
 //set baud rate to serial
  Serial.begin(115200);
  tempSensor.begin();

}
void loop() {
  Serial.println(getTemp());
  delay(1000);

}

float getTemp(){
   tempSensor.requestTemperatures();          // Send the command to get temperature readings
   float temp = tempSensor.getTempCByIndex(0);
   return temp;
}
