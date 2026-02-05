#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

extern "C" {
    #include "ff.h"
    #include "diskio.h"
    #include "hw_config.h"  
}

//Define SPI protocol GPIO pins
#define MISO_PIN 16 
#define CS_PIN 17
#define SCK_PIN 18
#define MOSI_PIN 19
#define CARD_DETECT_PIN 20

//====================== UNTESTEDDDDDD=============================//


FIL sd_init() {

    /*===========================SPI INITIALIZATION==================================*/
    // SPI0 with 1 Mhz baudrate 
    spi_init(spi0, 1000000); 

    //Format of data to send to the SD card
    spi_set_format(spi0, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);

    // Initialize SPI pins 
    gpio_set_function(MISO_PIN, GPIO_FUNC_SPI);
    gpio_set_dir(MISO_PIN, GPIO_IN);

    gpio_set_function(CS_PIN, GPIO_FUNC_SPI);
    gpio_set_dir(CS_PIN, GPIO_OUT);

    gpio_set_function(SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_dir(SCK_PIN, GPIO_OUT);

    gpio_set_function(MOSI_PIN, GPIO_FUNC_SPI);
    gpio_set_dir(MOSI_PIN, GPIO_OUT);

    /*===========================END SPI INITIALIZATION==============================*/

    /*===========================SD Card set up =====================================*/
    //Check if SD card is connected
    bool sdConnected = sd_check();

    if(!sdConnected){\
        printf("sd not detected !!");
        return;
    }

    //Open the directory "FLIGHTS" or "TESTS"
    
    DIR dir;
    f_opendir(&dir, "FLIGHTS");

    //Open file 
    FIL file;
    f_open(&file, "Today", FA_WRITE | FA_CREATE_ALWAYS);
    return file;
    
    /*===========================END SD Card set up =================================*/
}

bool sd_check(){
    //SET PiN as input 
    gpio_init(CARD_DETECT_PIN);
    gpio_set_dir(CARD_DETECT_PIN, GPIO_IN);

    //Return true if card detected and false if card not detected
    return gpio_get(CARD_DETECT_PIN);
}

bool sd_write(uint8_t* data, unsigned int bytesToWrite, FIL* file){
    //wait for SPI0 to becom available 
    while (spi_is_busy(spi0));
    return f_write(file, data, bytesToWrite, NULL);
}

/* NOTES: 
- Using FAT32 data format 
*/