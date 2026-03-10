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
//perform reading of altitude
    //bmp.readAltitude(1013.25);

// put function declarations here:
void initializeBMP();
int myFunction(int, int);

Adafruit_BMP5xx bmp;


void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  Serial.begin(9600);
  while (!Serial);
  initializeBMP();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bmp.dataReady()) {
    bmp.performReading();
    float currAltitude = bmp.readAltitude(1013.25);
    Serial.println(currAltitude);
  }
}

// put function definitions here:
void initializeBMP() {
  if (!bmp.begin()) {
    // Handle initialization failure
    while (1) {
      delay(100);
    }
  }

  // Set oversampling, filter, ODR, power mode, and enable pressure measurement CHANGE AS DESIRED 
  bmp.setPressureOversampling((bmp5xx_oversampling_t)BMP5_OVERSAMPLING_2X);
  bmp.setIIRFilterCoeff((bmp5xx_iir_filter_t)BMP5_IIR_FILTER_COEFF_15);
  bmp.setOutputDataRate((bmp5xx_odr_t)BMP5_ODR_50_HZ);
  bmp.setPowerMode((bmp5xx_powermode_t)BMP5_POWERMODE_NORMAL);
  bmp.enablePressure(true);
}

int myFunction(int x, int y) {
  return x + y;
}