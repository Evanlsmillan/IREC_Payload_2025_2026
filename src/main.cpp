#include <Arduino.h>
#include <Adafruit_BMP5xx.h>

//create sensor object
    //Adafruit_BMP5xx bmp;
//initialize the BMP sensor
//set oversampling and 
    //bmp.setPressureOversampling(BMP5_OVERSAMPLING_2X);  1X (fastest least accurate), 2X, 4X, 8X, 16X, 32X, 64X, 128X(slowest, most accurate)
//filter settings
    //bmp.setIIRFilterCoeff(BMP5_IIR_FILTER_COEFF_1);  0 (filter off), 1, 3, 7, 15, 31, 63, 127 (higher is stronger filtering)
//set output data rate (ODR)
    //bmp.setOutputDataRate(BMP5_ODR_50_HZ);  0.5Hz, 1Hz, 2Hz, 4Hz, 10Hz, 25Hz, 50Hz, 100Hz
//set power mode
    //bmp.setPowerMode(BMP5_POWERMODE_NORMAL);  SLEEP, FORCED, NORMAL
//enable pressure measurement
    //bmp.enablePressure(true);
//configure interrupts (optional)
    //bmp.configureInterrupt(BMP5_LATCHED, BMP5_ACTIVE_HIGH, BMP5_INTR_PUSH_PULL, BMP5XX_INTERRUPT_DATA_READY, true);
//perform reading of temperature and pressure
    //bmp.performReading();
    //bmp.pressure

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}