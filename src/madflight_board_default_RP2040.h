//This pin layout is optimized for Raspberry Pi Pico board: UART, PWM on side; I2C, SPI, PPM on the other side

#define HW_BOARD_NAME "DEFAULT RP2040 BOARD - Raspberry Pi Pico (W)"
#define HW_MCU "RP2040" //RP2040 - not all pin combinations are allowed, see datasheet

//-------------------------------------
// PIN DEFINITIONS
//-------------------------------------
//NOTE: DON'T USE SAME PIN TWICE. All pins here get configured, even if they are not used. Set pin to -1 to disable.

//LED:
#ifndef HW_PIN_LED
  #define HW_PIN_LED               25 //internal on Raspberry Pi Pico
#endif
#ifndef HW_LED_ON
  #define HW_LED_ON                 1 //0:low is on, 1:high is on
#endif

//IMU SPI:
#ifndef HW_PIN_SPI_MOSI
  #define HW_PIN_SPI_MOSI          16 //spi0: 0, 4, 16(default)   spi1:  8, 12(default)
#endif
#ifndef HW_PIN_SPI_MISO
  #define HW_PIN_SPI_MISO          19 //spi0: 3, 7, 19(default)   spi1: 11, 15(default)
#endif
#ifndef HW_PIN_SPI_SCLK
  #define HW_PIN_SPI_SCLK          18 //spi0: 2, 6, 18(default)   spi1: 10, 14(default)
#endif
#ifndef HW_PIN_IMU_CS
  #define HW_PIN_IMU_CS            17 //spi0: 1, 5, 17(default)   spi1:  9, 13(default)
#endif
#ifndef HW_PIN_IMU_EXTI
  #define HW_PIN_IMU_EXTI          22 //only used when USE_IMU_INTERRUPT is defined
#endif

//BARO/MAG I2C:
#ifndef HW_PIN_I2C_SDA
  #define HW_PIN_I2C_SDA           20 //Wire: 0, 4(default), 8, 12, 16, 20   Wire1: 2, 6, 10, 14, 18, 26(default)
#endif
#ifndef HW_PIN_I2C_SCL
  #define HW_PIN_I2C_SCL           21 //Wire: 1, 5(default), 9, 13, 17, 21   Wire1: 3, 7, 11, 15, 19, 27(default)
#endif

//Outputs:
#ifndef HW_OUT_COUNT
  #define HW_OUT_COUNT             12
#endif
#ifndef HW_PIN_OUT_LIST
  #define HW_PIN_OUT_LIST {2,3,4,5,6,7,10,11,12,13,14,15}
#endif

//Serial debug on USB Serial port (no GPIO pins)

//RC Receiver:
#ifndef HW_PIN_RCIN_RX
  #define HW_PIN_RCIN_RX            1 //uart0: 1(default), 5, 13, 17   uart1: 5, 9(default) , this pin is also used as PPM input
#endif
#ifndef HW_PIN_RCIN_TX
  #define HW_PIN_RCIN_TX            0 //uart0: 0(default), 4, 12, 16   uart1: 4, 8(default)
#endif

//GPS:
#ifndef HW_PIN_GPS_RX
  #define HW_PIN_GPS_RX             9 //uart0: 1(default), 5, 13, 17   uart1: 5, 9(default)
#endif
#ifndef HW_PIN_GPS_TX
  #define HW_PIN_GPS_TX             8 //uart0: 0(default), 4, 12, 16   uart1: 4, 8(default)
#endif

//Battery ADC
#ifndef HW_PIN_BAT_V
  #define HW_PIN_BAT_V             28 //pin A2
#endif
#ifndef HW_PIN_BAT_I
  #define HW_PIN_BAT_I             -1
#endif

//BlackBox SPI:
#ifndef HW_PIN_SPI2_MISO
  #define HW_PIN_SPI2_MISO         -1
#endif
#ifndef HW_PIN_SPI2_MOSI
  #define HW_PIN_SPI2_MOSI         -1
#endif
#ifndef HW_PIN_SPI2_SCLK
  #define HW_PIN_SPI2_SCLK         -1
#endif
#ifndef HW_PIN_BB_CS
  #define HW_PIN_BB_CS             -1
#endif

const int HW_PIN_OUT[] = HW_PIN_OUT_LIST;

//-------------------------------------
//Include Libraries
//-------------------------------------
#include <Wire.h>                      //I2C communication
#include <SPI.h>                       //SPI communication
#include "madflight/hw_RP2040/RP2040_PWM.h"  //Servo and onshot
#include <pico/stdlib.h>               //set_sys_clock_khz()

//-------------------------------------
//Bus Setup
//-------------------------------------
//uncomment one line only
SerialUART gps_Serial = SerialUART(uart1, HW_PIN_GPS_TX, HW_PIN_GPS_RX); //uart0 or uart1
//SerialPIO gps_Serial = SerialPIO(HW_PIN_GPS_TX, HW_PIN_GPS_RX, 32); //PIO uarts, any pin allowed

//uncomment one line only
SerialUART *rcin_Serial = new SerialUART(uart0, HW_PIN_RCIN_TX, HW_PIN_RCIN_RX); //uart0 or uart1
//SerialPIO *rcin_Serial = new SerialPIO(HW_PIN_RCIN_TX, HW_PIN_RCIN_RX, 32); //PIO uarts, any pin allowed

typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1

SPIClassRP2040 *spi = new SPIClassRP2040(spi0, HW_PIN_SPI_MISO, HW_PIN_IMU_CS, HW_PIN_SPI_SCLK, HW_PIN_SPI_MOSI); //spi0 or spi1
SPIClassRP2040 *bb_spi = new SPIClassRP2040(spi1, HW_PIN_SPI2_MISO, HW_PIN_BB_CS, HW_PIN_SPI2_SCLK, HW_PIN_SPI2_MOSI); //spi0 or spi1
