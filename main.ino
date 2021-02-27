#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_BMP280.h>

#define BMP280_ADRESA (0x76)
#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)


Adafruit_BMP280 bmp;
//Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
int korekce = 32;


// The LCD constructor - address shown is 0x27 - may or may not be correct for yours
// Also based on YWRobot LCM1602 IIC V1
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  Serial.begin(9600);
//I2C
  if (!bmp.begin(BMP280_ADRESA)) {
    Serial.println("BMP280 senzor nenalezen, zkontrolujte zapojeni!");
    while (1);
 }

/*
//SPI
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }

  /* Default settings from datasheet. */
  
 //bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
 //                 Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
 //                 Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
 //                Adafruit_BMP280::FILTER_X16,      /* Filtering. */
 //                Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */


  lcd.begin(20, 4); // sixteen characters across - 2 lines
  lcd.backlight();
  // first character - 1st line
  //lcd.setCursor(0, 0);
  //lcd.print("Nazdar Picicky!");
  // 8th character - 2nd line
  //lcd.setCursor(19, 4);
  //lcd.print("x");
}


void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nazdar Picicky!");
  
  lcd.setCursor(0, 1);
   lcd.print("Teplota: ");
  lcd.print(bmp.readTemperature());
  lcd.println("C.");
  
  lcd.setCursor(0, 2);
  lcd.print("Tlak: ");
  lcd.print(bmp.readPressure());
  lcd.println("Pa");
  
  lcd.setCursor(0, 3);
  lcd.print("Vyska: ");
  lcd.print(bmp.readAltitude());
  lcd.println("m.");
  delay(1000);
  
}
