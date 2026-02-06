#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>


static const uint8_t ONE_WIRE_BUS = 2; // GP2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

class tempSensor {
    public:
      tempSensor();
      float getTempC();
};


tempSensor::tempSensor() {
  Serial.begin(115200);
  delay(1500); // give time for Serial Monitor to attach
  Serial.println("Starting DS18B20 test...");

  sensors.begin();

  int count = sensors.getDeviceCount();
  Serial.print("Devices found on OneWire bus: ");
  Serial.println(count);

  if (count == 0) {
    Serial.println("No devices found. Check wiring + 4.7k pullup + pin number.");
  }
}

float tempSensor::getTempC() {
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0);
}