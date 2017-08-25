/*
    e-Gizmo SD/MMC Card Shield test 
    Sample codes
    
    Note: if you are using Arduino Mega
    Schematic: https://www.arduino.cc/en/uploads/Main/arduino-mega2560-schematic.pdf
    Please connect the ff. SPI connection:
    SD/MMC Card Shield--->SPI--->ArduinoMEGA
    D10--->SS  ---> D53
    D11--->MOSI---> D51
    D12--->MISO---> D50
    D13--->SCK ---> D52
    
    e-Gizmo Mechatronix Central
    http://www.e-gizmo.com
    
    
 */


#include <SD.h>

// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 4;

void setup()
{
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
  // make a string for assembling the data to log:
  String dataString = "Hello World";
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println("Hello World");
    dataFile.close();
    // print to the serial port too:
//    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
//  else {
//    Serial.println("error opening datalog.txt");
//  } 

}

void loop()
{
}

