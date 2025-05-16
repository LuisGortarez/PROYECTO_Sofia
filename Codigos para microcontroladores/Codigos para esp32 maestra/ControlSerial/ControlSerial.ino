/*
  Name:		  ControlSerial.ino
  Created:	16/05/2025 11:57:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Código de ESP32 maestra que recibe, por comunicación serial, el 
            comando referente al movimiento que se debe realizar y la
            envía por comunicación serial a las esp32 esclavas.
*/

/////////////////////////////////////////////
//// Definitions for setting the program ////
/////////////////////////////////////////////

// Serial communication settings
#define BAUD_RATE               115200   // Baud rate of connection
#define RX_PIN                  16       // Rx pin for communicating with other ESPs
#define TX_PIN                  17       // Tx pin for communicating with other ESPs

// Project configurations
#define N_SLAVES                4        // Number of ESPs connected to the serial bus
#define ESP_SLAVE_WAIT          3        // Time for sleeping between chars sending in ms

// Delimiters and commands
#define END_DATA                '|'      // Character for indicating end of data

// Create serial port for ESP communication
HardwareSerial SlaveSerial(1);      // Serial 1


/////////////////////////////////////////////
////////// Setup & loop functions ///////////
/////////////////////////////////////////////

void setup()
{
  Serial.begin(BAUD_RATE);                // Main communication channel

  SlaveSerial.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);     // Communication with slave ESPs
}


void loop()
{ // Function for handling data by Bluetooth
  static String data;
  
  if(Serial.available() > 0)
  {
    data = Serial.readStringUntil(END_DATA);
    data += END_DATA;
    SlaveSend(data);
  }
}


///////////////////////////////////////////////
//////// Slave data handling function /////////
///////////////////////////////////////////////

void SlaveSend(String data)
{ // Function for sending data received to slave ESPs
  static uint8_t n_char = 0;
  static uint8_t n_slave = 0;

  for(n_char = 0; n_char < data.length(); n_char++)
  { // Send all data char by char
    for(n_slave = 0; n_slave < N_SLAVES; n_slave++)
    {
      SlaveSerial.print(data.charAt(n_char));
    }

    delay(ESP_SLAVE_WAIT); // Give time for slave ESPs to read/clean bus before sending next char
  }
}
 