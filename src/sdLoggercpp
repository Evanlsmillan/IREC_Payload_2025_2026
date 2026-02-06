#include <stdio.h>
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

//Define SPI protocol GPIO pins
#define MISO_PIN 7 
#define CS_PIN 9
#define SCK_PIN 6
#define MOSI_PIN 8

class SDLogger {
    File file;
    std::string path;
    public:
        SDLogger(std::string directoryName, std::string title);
        void sd_write(float data);
};

SDLogger::SDLogger(std::string directoryName, std::string title){

    // Configure SPI pin directions 
    pinMode(MISO_PIN, INPUT);
    pinMode(SCK_PIN, OUTPUT);
    pinMode(MOSI_PIN, OUTPUT);
    pinMode(CS_PIN, OUTPUT);

    if (!SD.begin(CS_PIN)) {
        Serial.println("initialization of SD card failed");
        while (1);
    }
    this -> path = directoryName + "/" + title;
}

void SDLogger::sd_write(float data){
    //wait for SPI0 to becom available
    file = SD.open(path.c_str(), FILE_WRITE);
    
    //In case file doesn't open correctly 
    if (!file) {
        Serial.println("error opening file");
        return;
    }

    file.print("temp C: ");;
    file.println(data);
    file.close();
}

/* NOTES: 
- Using FAT32 data format 
*/