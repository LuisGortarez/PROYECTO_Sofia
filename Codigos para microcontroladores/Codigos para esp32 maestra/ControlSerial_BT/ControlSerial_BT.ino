/*
  Name:		  ControlSerial_BT.ino
  Created:	07/02/2025 11:46:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Código de ESP32 maestra que recibe, por comunicación BT, el 
            comando referente al movimiento que se debe realizar y la
            envía por comunicación serial a las esp32 esclavas.
*/


#include <BluetoothSerial.h>


/////////////////////////////////////////////
//// Definitions for setting the program ////
/////////////////////////////////////////////

// Serial communication settings
#define BAUD_RATE               115200   // Baud rate of connection
#define RX_PIN                  16       // Rx pin for communicating with other ESPs
#define TX_PIN                  17       // Tx pin for communicating with other ESPs
#define BLUETOOTH_DEVICE_NAME   "sOFIa"  // Device name for BT connection

// Project configurations
#define N_SLAVES                4        // Number of ESPs connected to the serial bus
#define ESP_SLAVE_WAIT          3        // Time for sleeping between chars sending in ms

// Delimiters and commands
#define CONFIRM_COMMAND         "ok"     // Command to send for confirming data
#define END_DATA                '|'      // Character for indicating end of data

// Create serial port for ESP communication
HardwareSerial SlaveSerial(1);      // Serial 1

// Bluetooth object declaration
BluetoothSerial SerialBT;


/////////////////////////////////////////////
////////// Setup & loop functions ///////////
/////////////////////////////////////////////

void setup()
{
  Serial.begin(BAUD_RATE);                // Communication with PC used for debug
  SerialBT.begin(BLUETOOTH_DEVICE_NAME);  // Communication with Bluetooth

  SlaveSerial.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);     // Communication with slave ESPs

  BluetoothConnect();
}


void loop()
{ // Function for handling data by Bluetooth
  static String data;
  
  if(SerialBT.available() > 0)
  {
    data = SerialBT.readStringUntil(END_DATA);
    data += END_DATA;
    SlaveSend(data);
    SerialBT.println(CONFIRM_COMMAND);
  }

  if(!SerialBT.connected())
  {
    Serial.println("Conexión perdida");
    BluetoothConnect();
  }
}


///////////////////////////////////////////////
//////// Slave data handling function /////////
///////////////////////////////////////////////

void BluetoothConnect()
{ // Function for connecting to bluetooth device
  while(!SerialBT.connected())
  { // Wait until connection has been set
    delay(1000);
    Serial.println("Esperando conexión...");
  }

  Serial.println("¡Conectado!");
}


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
 