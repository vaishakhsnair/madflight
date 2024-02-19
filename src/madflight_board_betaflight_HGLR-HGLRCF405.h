/*==============================================================================
Generated on: 2024-02-19 11:58:16.223647
Generated by: betaflight_target_converter.py
Source: https://github.com/betaflight/unified-targets
Board name: HGLRCF405
Manufacturer ID: HGLR

//copy this line to madflight.ino to use this flight controller (or copy/paste the whole file)
#include "boards/../madflight_board_betaflight_HGLR-HGLRCF405.h"
==============================================================================*/

#define HW_BOARD_NAME "BETAFLIGHT-HGLR-HGLRCF405"
#define HW_MCU "STM32F405"

//Defines from betaflight. Note: madflight will pick the last sensor defined here, this might not be the sensor that is actually on the board. Comment the offending sensors out.
#define IMU_USE  IMU_USE_SPI_MPU6000
#define BARO_USE  BARO_USE_SPI_BMP280
#define OSD_USE  OSD_USE_MAX7456
#define BB_USE  BB_USE_FLASH
#define BB_FLASH_TYPE  "W25Q128FV"

//Sensor specific setup
#define IMU_ALIGN  IMU_ALIGN_CW180
#define BARO_I2C_ADR  0
#define MAG_I2C_ADR  0

//LED:
const int HW_PIN_LED      = PA8;
const int HW_LED_ON       = 1; //0:low is on, 1:high is on

//IMU SPI: (SPI1)
const int HW_PIN_SPI_MISO = PA6;
const int HW_PIN_SPI_MOSI = PA7;
const int HW_PIN_SPI_SCLK = PA5;
const int HW_PIN_IMU_CS   = PA4;
const int HW_PIN_IMU_EXTI = PC4;

//BARO/MAG I2C: (I2C0)
const int HW_PIN_I2C_SDA  = -1;
const int HW_PIN_I2C_SCL  = -1;

//Outputs:
const int HW_OUT_COUNT    = 4;
const int HW_PIN_OUT[]    = {PB0,PB1,PA3,PB5};

//RC Receiver: (SERIAL1)
const int HW_PIN_RCIN_RX  = PA10;
const int HW_PIN_RCIN_TX  = PA9;
const int HW_PIN_RCIN_INVERTER = -1;

//GPS: (SERIAL3)
const int HW_PIN_GPS_RX   = PB11;
const int HW_PIN_GPS_TX   = PB10;
const int HW_PIN_GPS_INVERTER = -1;

//Battery ADC voltage and current inputs:
const int HW_PIN_BAT_V    = PC2;
const int HW_PIN_BAT_I    = PC1;

//Include Libraries
#include <Wire.h>                      //I2C communication
#include <SPI.h>                       //SPI communication
#include "src/hw_STM32/STM32_PWM.h"    //Servo and oneshot

//Bus Setup
HardwareSerial *rcin_Serial = new HardwareSerial(HW_PIN_RCIN_RX, HW_PIN_RCIN_TX);
HardwareSerial gps_Serial(HW_PIN_GPS_RX, HW_PIN_GPS_TX);
typedef TwoWire HW_WIRETYPE; //define the class to use for I2C
HW_WIRETYPE *i2c = &Wire; //&Wire or &Wire1
SPIClass *spi = &SPI;

//Serial
#define HW_SERIAL_COUNT 5
#define HW_PIN_SERIAL { {1,PA9,PA10,-1}, {2,PA2,-1,-1}, {3,PB10,PB11,-1}, {4,-1,PA1,-1}, {6,PC6,PC7,-1} } // {INDEX,TX,RX,INVERTER}

//SPI
#define HW_SPI_COUNT 3
#define HW_PIN_SPI { {1,PA5,PA6,PA7}, {2,PB13,PB14,PB15}, {3,PC10,PC11,PC12} } // {INDEX,SCK,MISO,MOSI}

//I2C
#define HW_I2C_COUNT 1
#define HW_PIN_I2C { {1,PB8,PB9} } // {INDEX,SCL,SDA}

//Motors:
#define HW_MOTOR_COUNT 4
#define HW_MOTOR_OUT {PB0,PB1,PA3,PB5}

//other pins
#define HW_PIN_BEEPER PB4
#define HW_PIN_PPM PB8
#define HW_PIN_LED_STRIP PB6
//#define HW_PIN_LED PA8
#define HW_PIN_ESCSERIAL PB8
#define HW_PIN_CAMERA_CONTROL PB7
#define HW_PIN_ADC_BATT PC2
#define HW_PIN_ADC_RSSI PA0
#define HW_PIN_ADC_CURR PC1
#define HW_PIN_BARO_CS PB3
#define HW_PIN_FLASH_CS PB12
#define HW_PIN_OSD_CS PA15
#define HW_PIN_GYRO_EXTI PC4
#define HW_PIN_GYRO_CS PA4
#define HW_PIN_GYRO_CS_2 PC14

//set statements
#define HW_SET_GYRO_TO_USE FIRST
#define HW_SET_ALIGN_MAG DEFAULT
#define HW_SET_MAG_BUSTYPE I2C
#define HW_SET_MAG_I2C_DEVICE 1
#define HW_SET_MAG_I2C_ADDRESS 0
#define HW_SET_MAG_SPI_DEVICE 0
#define HW_SET_BARO_BUSTYPE SPI
#define HW_SET_BARO_SPI_DEVICE 3
#define HW_SET_BARO_I2C_DEVICE 0
#define HW_SET_BARO_I2C_ADDRESS 0
#define HW_SET_RX_SPI_BUS 0
#define HW_SET_RX_SPI_LED_INVERSION OFF
#define HW_SET_ADC_DEVICE 2
#define HW_SET_BLACKBOX_DEVICE SPIFLASH
#define HW_SET_DSHOT_BURST OFF
#define HW_SET_CURRENT_METER ADC
#define HW_SET_BATTERY_METER ADC
#define HW_SET_IBATA_SCALE 400
#define HW_SET_BEEPER_INVERSION ON
#define HW_SET_BEEPER_OD OFF
#define HW_SET_BEEPER_FREQUENCY 0
#define HW_SET_SDCARD_DETECT_INVERTED OFF
#define HW_SET_SDCARD_MODE OFF
#define HW_SET_SDCARD_SPI_BUS 0
#define HW_SET_SYSTEM_HSE_MHZ 8
#define HW_SET_MAX7456_CLOCK NOMINAL
#define HW_SET_MAX7456_SPI_BUS 3
#define HW_SET_MAX7456_PREINIT_OPU OFF
#define HW_SET_CC2500_SPI_CHIP_DETECT ON
#define HW_SET_LED_INVERSION 0
#define HW_SET_DASHBOARD_I2C_BUS 1
#define HW_SET_DASHBOARD_I2C_ADDR 60
#define HW_SET_USB_MSC_PIN_PULLUP ON
#define HW_SET_FLASH_SPI_BUS 2
#define HW_SET_GYRO_1_BUSTYPE SPI
#define HW_SET_GYRO_1_SPIBUS 1
#define HW_SET_GYRO_1_I2CBUS 0
#define HW_SET_GYRO_1_I2C_ADDRESS 0
#define HW_SET_GYRO_1_SENSOR_ALIGN CW180
#define HW_SET_GYRO_2_BUSTYPE SPI
#define HW_SET_GYRO_2_SPIBUS 1
#define HW_SET_GYRO_2_I2CBUS 0
#define HW_SET_GYRO_2_I2C_ADDRESS 0
#define HW_SET_GYRO_2_SENSOR_ALIGN CW0
#define HW_SET_I2C1_PULLUP OFF
#define HW_SET_I2C1_OVERCLOCK ON
#define HW_SET_I2C2_PULLUP OFF
#define HW_SET_I2C2_OVERCLOCK ON
#define HW_SET_I2C3_PULLUP OFF
#define HW_SET_I2C3_OVERCLOCK ON


/*
#==============================================================================
# BetaFlight Source file
#==============================================================================
# Betaflight / STM32F405 (S405) 4.0.0 Apr  3 2019 / 14:30:44 (22b9f3453) MSP API: 1.41

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_BARO
#define USE_BARO_SPI_BMP280
#define USE_MAX7456
#define USE_FLASH
#define USE_FLASH_W25Q128FV

board_name HGLRCF405
manufacturer_id HGLR

# resources
resource BEEPER 1 B04
resource MOTOR 1 B00
resource MOTOR 2 B01
resource MOTOR 3 A03
resource MOTOR 4 B05
resource PPM 1 B08
resource LED_STRIP 1 B06
resource SERIAL_TX 1 A09
resource SERIAL_TX 2 A02
resource SERIAL_TX 3 B10
resource SERIAL_TX 6 C06
resource SERIAL_RX 1 A10
resource SERIAL_RX 3 B11
resource SERIAL_RX 4 A01
resource SERIAL_RX 6 C07
resource I2C_SCL 1 B08
resource I2C_SDA 1 B09
resource LED 1 A08
resource SPI_SCK 1 A05
resource SPI_SCK 2 B13
resource SPI_SCK 3 C10
resource SPI_MISO 1 A06
resource SPI_MISO 2 B14
resource SPI_MISO 3 C11
resource SPI_MOSI 1 A07
resource SPI_MOSI 2 B15
resource SPI_MOSI 3 C12
resource ESCSERIAL 1 B08
resource CAMERA_CONTROL 1 B07
resource ADC_BATT 1 C02
resource ADC_RSSI 1 A00
resource ADC_CURR 1 C01
resource BARO_CS 1 B03
resource FLASH_CS 1 B12
resource OSD_CS 1 A15
resource GYRO_EXTI 1 C04
resource GYRO_CS 1 A04
resource GYRO_CS 2 C14

# timer
timer B00 AF2
# pin B00: TIM3 CH3 (AF2)
timer B01 AF2
# pin B01: TIM3 CH4 (AF2)
timer A03 AF1
# pin A03: TIM2 CH4 (AF1)
timer B05 AF2
# pin B05: TIM3 CH2 (AF2)
timer C08 AF3
# pin C08: TIM8 CH3 (AF3)
timer C09 AF3
# pin C09: TIM8 CH4 (AF3)
timer B06 AF2
# pin B06: TIM4 CH1 (AF2)
timer B08 AF3
# pin B08: TIM10 CH1 (AF3)
timer C06 AF3
# pin C06: TIM8 CH1 (AF3)
timer C07 AF3
# pin C07: TIM8 CH2 (AF3)
timer A09 AF1
# pin A09: TIM1 CH2 (AF1)
timer A10 AF1
# pin A10: TIM1 CH3 (AF1)
timer A01 AF2
# pin A01: TIM5 CH2 (AF2)
timer A02 AF3
# pin A02: TIM9 CH1 (AF3)

# dma
dma ADC 2 1
# ADC 2: DMA2 Stream 3 Channel 1
dma pin B00 0
# pin B00: DMA1 Stream 7 Channel 5
dma pin B01 0
# pin B01: DMA1 Stream 2 Channel 5
dma pin A03 1
# pin A03: DMA1 Stream 6 Channel 3
dma pin B05 0
# pin B05: DMA1 Stream 5 Channel 5
dma pin C08 0
# pin C08: DMA2 Stream 2 Channel 0
dma pin C09 0
# pin C09: DMA2 Stream 7 Channel 7
dma pin B06 0
# pin B06: DMA1 Stream 0 Channel 2
dma pin C06 0
# pin C06: DMA2 Stream 2 Channel 0
dma pin C07 0
# pin C07: DMA2 Stream 2 Channel 0
dma pin A09 0
# pin A09: DMA2 Stream 6 Channel 0
dma pin A10 0
# pin A10: DMA2 Stream 6 Channel 0
dma pin A01 0
# pin A01: DMA1 Stream 4 Channel 6

# feature
feature OSD

# master
set gyro_to_use = FIRST
set align_mag = DEFAULT
set mag_bustype = I2C
set mag_i2c_device = 1
set mag_i2c_address = 0
set mag_spi_device = 0
set baro_bustype = SPI
set baro_spi_device = 3
set baro_i2c_device = 0
set baro_i2c_address = 0
set rx_spi_bus = 0
set rx_spi_led_inversion = OFF
set adc_device = 2
set blackbox_device = SPIFLASH
set dshot_burst = OFF
set current_meter = ADC
set battery_meter = ADC
set ibata_scale = 400
set beeper_inversion = ON
set beeper_od = OFF
set beeper_frequency = 0
set sdcard_detect_inverted = OFF
set sdcard_mode = OFF
set sdcard_spi_bus = 0
set system_hse_mhz = 8
set max7456_clock = NOMINAL
set max7456_spi_bus = 3
set max7456_preinit_opu = OFF
set cc2500_spi_chip_detect = ON
set led_inversion = 0
set dashboard_i2c_bus = 1
set dashboard_i2c_addr = 60
set usb_msc_pin_pullup = ON
set flash_spi_bus = 2
set gyro_1_bustype = SPI
set gyro_1_spibus = 1
set gyro_1_i2cBus = 0
set gyro_1_i2c_address = 0
set gyro_1_sensor_align = CW180
set gyro_2_bustype = SPI
set gyro_2_spibus = 1
set gyro_2_i2cBus = 0
set gyro_2_i2c_address = 0
set gyro_2_sensor_align = CW0
set i2c1_pullup = OFF
set i2c1_overclock = ON
set i2c2_pullup = OFF
set i2c2_overclock = ON
set i2c3_pullup = OFF
set i2c3_overclock = ON

*/