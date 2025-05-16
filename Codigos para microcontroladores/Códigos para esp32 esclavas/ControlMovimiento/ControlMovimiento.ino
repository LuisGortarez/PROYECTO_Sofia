/*
  Name:		  ControlMovimiento.ino
  Created:	07/02/2025 11:25:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Código principal donde llamamos a las funciones 
            de creación de figuras dependiendo del comando
            recibido a través de la comunicación serial.
*/

#include <Arduino.h>
#include <stdint.h>

#include "SOFIAanimations.h"
#include "SOFIAnumbers.h"
#include "SOFIAletters.h"
#include "SOFIAsymbols.h"
#include "SOFIAemojis.h"
#include "SOFIAwords.h"
#include "SOFIAmodes.h"


// ----------------------------------------------------- //
// -------- Definitions for setting the program -------- //
// ----------------------------------------------------- //

// Create serial port for ESP communication
HardwareSerial MasterSerial(1);   // Serial 1

// Serial communication settings
#define BAUD_RATE         115200  // Baud rate of connection

#define RX_PIN            16      // Rx pin for communicating with Master
#define TX_PIN            17      // Tx pin for communicating with Master

#define POWER_DELAY_MS    1000    // Time to wait for drivers to power on in ms


// ----------------------------------------------------- //
// --------------- Setup & Loop function --------------- //
// ----------------------------------------------------- //

void setup()
{
  Serial.begin(BAUD_RATE);      // Communication with PC (for debugging purposes)
  MasterSerial.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);    // Communication with master ESP

  delay(POWER_DELAY_MS);        // Wait some time after power ON for allowing drivers to be activated

  // Verify which drivers are connected to ESP
  g_drivers_found.driver_0_found = pca9685_0.begin();
  if(g_drivers_found.driver_0_found)     // If a driver is found, set the drivers frequency
    pca9685_0.setPWMFreq(PWM_FREQUENCY); // Attempting to control a driver whose frequency hasn´t been set will cause constant rebooting
  g_drivers_found.driver_1_found = pca9685_1.begin();
  if(g_drivers_found.driver_1_found)
    pca9685_1.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_2_found = pca9685_2.begin();
  if(g_drivers_found.driver_2_found)
    pca9685_2.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_3_found = pca9685_3.begin();
  if(g_drivers_found.driver_3_found)
    pca9685_3.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_4_found = pca9685_4.begin();
  if(g_drivers_found.driver_4_found)
    pca9685_4.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_5_found = pca9685_5.begin();
  if(g_drivers_found.driver_5_found)
    pca9685_5.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_6_found = pca9685_6.begin();
  if(g_drivers_found.driver_6_found)
    pca9685_6.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_7_found = pca9685_7.begin();
  if(g_drivers_found.driver_7_found)
    pca9685_7.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_8_found = pca9685_8.begin();
  if(g_drivers_found.driver_8_found)
    pca9685_8.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_9_found = pca9685_9.begin();
  if(g_drivers_found.driver_9_found)
    pca9685_9.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_10_found = pca9685_10.begin();
  if(g_drivers_found.driver_10_found)
    pca9685_10.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_11_found = pca9685_11.begin();
  if(g_drivers_found.driver_11_found)
    pca9685_11.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_12_found = pca9685_12.begin();
  if(g_drivers_found.driver_12_found)
    pca9685_12.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_13_found = pca9685_13.begin();
  if(g_drivers_found.driver_13_found)
    pca9685_13.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_14_found = pca9685_14.begin();
  if(g_drivers_found.driver_14_found)
    pca9685_14.setPWMFreq(PWM_FREQUENCY);
  g_drivers_found.driver_15_found = pca9685_15.begin();
  if(g_drivers_found.driver_15_found)
    pca9685_15.setPWMFreq(PWM_FREQUENCY);

  SetQuadrants();       // With driver searching done, determine which tiles can be moved by the ESP
  ResetTiles();         // Reset all tiles before making shapes
}


void loop()
{
  static char serial_data = 0;
  static system_mode_t mode = standby;

  mode = GetMode();

  if(MasterSerial.available() > 0)
  { // Check if there´s data in serial comm
    serial_data = MasterSerial.read();
    
    if(reset_mode == mode)
    { // When reset mode is activated, send characters to reset mode function
      ResetMode(serial_data);
    }
    else if(column_mode == mode)
    { // When column mode is activated, send characters to column mode function
      ColumnMode(serial_data);
    }
    else if(row_mode == mode)
    { // When row mode is activated, send characters to row mode function
      RowMode(serial_data);
    }
    else if(manual_mode == mode)
    { // When manual mode is activated, send characters to manual mode function
      ManualMode(serial_data);
    }
    else if(animation_mode == mode)
    { // When animation mode is activated, send characters to animation mode function
      AnimationMode(serial_data);
    }
    else if(number_mode == mode)
    { // When number mode is activated, send characters to number mode function
      NumberMode(serial_data);
    }
    else if(letter_mode == mode)
    { // When letter mode is activated, send characters to letter mode function
      LetterMode(serial_data);
    }
    else if(symbol_mode == mode)
    { // When symbol mode is activated, send characters to symbol mode function
      SymbolMode(serial_data);
    }
    else if(emoji_mode == mode)
    { // When emoji mode is activated, send characters to emoji mode function
      EmojiMode(serial_data);
    }
    else if(word_mode == mode)
    { // When word mode is activated, send characters to word mode function
      WordMode(serial_data);
    }
    else
    {
      ChangeMode(serial_data);
    }
    
    while(MasterSerial.available() > 0)
    { // Clean serial bus
      serial_data = MasterSerial.read();
    }
  }

  if(sleep_mode == mode)
  {
    AnimationExecute(sleepy);
  }
}


// ----------------------------------------------------- //
// ------------------- Code functions ------------------ //
// ----------------------------------------------------- //

// Decide which figue to show in piece based on shape command received
void ChangeMode(uint8_t command)
{
  if(RESET_CMD == command)
    SetMode(reset_mode);
  else if(COLUMN_CMD == command)
    SetMode(column_mode);
  else if(ROW_CMD == command)
    SetMode(row_mode);
  else if(MANUAL_CMD == command)
    SetMode(manual_mode);
  else if(ANIMATION_CMD == command)
    SetMode(animation_mode);
  else if(NUMBER_CMD == command)
    SetMode(number_mode);
  else if(LETTER_CMD == command)
    SetMode(letter_mode);
  else if(SYMBOL_CMD == command)
    SetMode(symbol_mode);
  else if(EMOJI_CMD == command)
    SetMode(emoji_mode);
  else if(WORD_CMD == command)
    SetMode(word_mode);
  else
    Serial.println("COMMAND NOT FOUND");
}
