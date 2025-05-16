Pueden utilizarse cualquiera de los tres códigos presentes en la ESP32 maestra. Cada uno cuenta con una forma distinta de comunicarse con la ESP32:

o ControlSerial: Comunicación serial a través del cable de alimentación. 
o ControlSerial_BT: Comunicación serial Bluetooth. El dispositivo debe estar emparejado con la ESP32 reconocible como "sOFIa". Cada vez que recibe datos, envía un mensaje "OK".
o ControlSerial_HTTP: Comunicación a través de un servidor HTTP con el nombre "sOFIa" y la contraseña "sOFIa2025". Se crea un punto de acceso al que se debe conectar el dispositivo que ejecute la interfaz en Python. Cada vez que recibe una solicitud POST, envía un mensaje "OK".

Manetener en cuenta lo siguiente: Si se utiliza el código "ControlSerial_HTTP", no será posible conectar la interfaz de Python a Facebook o cualquier otro sitio web ya que debemos estar conectados al punto de acceso que crea la ESP32.