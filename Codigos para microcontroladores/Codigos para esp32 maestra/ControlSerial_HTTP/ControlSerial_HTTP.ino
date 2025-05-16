/*
  Name:		  ControlSerial_HTTP.ino
  Created:	18/03/2025  18:32:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Código de ESP32 maestra que recibe, por comunicación HTTP, 
            el comando referente al movimiento que se debe realizar y 
            la envía por su pin Tx2 (bus serial) a las esp32 esclavas.
*/

#include <WiFi.h>
#include <WebServer.h>


/////////////////////////////////////////////
//// Definitions for setting the program ////
/////////////////////////////////////////////

// Serial communication settings
#define BAUD_RATE         115200   // Baud rate of connection
#define RX_PIN            16       // Rx pin for communicating with other ESPs
#define TX_PIN            17       // Tx pin for communicating with other ESPs

// Project configurations
#define N_SLAVES                4        // Number of ESPs connected to the serial bus
#define ESP_SLAVE_WAIT          3        // Time for sleeping between chars sending in ms

// Create serial port for ESP communication
HardwareSerial SlaveSerial(1);      // Serial 1

// Create server on port 80
WebServer server(80);


/////////////////////////////////////////////
////////// Setup & loop functions ///////////
/////////////////////////////////////////////

void setup()
{
  // Access point information
  const char *SSID = "sOFIa";
  const char *PASSWORD = "sOFIa2025";

  Serial.begin(BAUD_RATE);
  SlaveSerial.begin(BAUD_RATE, SERIAL_8N1, RX_PIN, TX_PIN);     // Communication with slave ESPs

  // Start ESP32 as Access Point
  WiFi.softAP(SSID, PASSWORD);

  delay(1000);
  Serial.println("Punto de acceso iniciado");
  Serial.print("IP del ESP32: ");
  Serial.println(WiFi.softAPIP());

  // Define HTTP route of server
  server.on("/", HTTP_POST, handlepost);

  // Start server
  server.begin();
}


void loop()
{
  server.handleClient();
}


/////////////////////////////////////////////////
//////// Server data handling functions /////////
/////////////////////////////////////////////////

void handlepost()
{ // Function for handling data sent by POST
  static String data_received = "";

  if(server.hasArg("plain"))
  {
    data_received = server.arg("plain");  // Get data
    if(data_received.length() > 0)
    {
      server.send(200, "text/plain", "OK");  // Respond with OK, don´t forget to do it every time data is received

      SlaveSend(data_received); // Send data to slaves
    }
    else
    {
      server.send(400, "text/plain", "Datos vacíos recibidos");
    }
  }
  else
  {
    server.send(400, "text/plain", "No se recibieron datos");
  }
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
