Este código puede enviar comandos por tres canales diferentes. Estos tres canales son: USB serial, Bluetooth y HTTP.
Para elegir el canal basta con asignar un valor de 0 a 2 a la variable communication_type ubicada en la línea 23.

Algunas consideraciones:
	1. Al ejecutar este programa se corren la ejecución principal y dos hilos:
		a. La ejecución principal que crea las pantallas mostradas y maneja los eventos de click en pantalla. También guarda comandos en la cola de comandos.
		b. El primer hilo maneja el reconocimiento de imágenes y guarda comandos en la cola de comandos si es que detecta una figura. Termina cuando la ejecución principal activa un evento asociado a la terminación de este hilo.
		c. El segundo hilo se encarga de tomar comandos guardados en cola de comandos y enviarlos por el canal de comunicación elegido. Este hilo no se detiene hasta leer "END" de la cola de comandos. Este dato es guardado por la ejecución principal.

	2. Para utilizar el modo HTTP es necesario conectarse a un punto de acceso que crea el microcontrolador maestro como si fuera una red WiFi. Al hacer esto se imposibilita la opción 	de subir imágenes a Facebook ya que no se tendrá acceso a WiFi en este caso.

	3. El programa está pensado para una pantalla con resolución específica. Para hacer más grande o más chico las imágenes, botones y figuras se deben modificar las variables que le dan tamaño a estos elementos. Las variables para esto se encuentran entre las líneas 92 y 258.

Para ejecutar este código es necesario la versión de las siguientes librerías:

 pillow		11.1.0
 ultralytics	8.3.24
 tk		0.1.0 <----- IMPORTANTE Hacer "pip upgrade tk" para el manejo de los eventos táctiles.
 facebook-sdk	3.1.0
 requests	2.32.3
