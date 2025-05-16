Para que el sistema funcione, se requiere de un microcontrolador maestro y cuatro microcontroladores esclavos. Cada esclavo controla un cuadrante de la obra.

o El microcontrolador maestro está encargado de recibir comandos por parte de un dispositivo externo y enviar ese mismo comando a los microcontroladores esclavos.
o Un microcontrolador esclavo recibe el comando del maestro, lo procesa, y se comunica con los drivers PCA9685 para ajustar los canales PWM que deben ser modificados provocando un cambio en la posición del servo. Estos cambios de posición de servos específicos crean la figura o animación que fue solicitada por el dispositivo externo al enviar el comando al microcontrolador maestro.

Un comando consiste de tres caracteres en el caso de todos los modos de operación salvo en el modo de reset y algunos casos de los modos columna, fila y manual.
Estos tres carácteres son:
	1. Modo de operación
	2. Figura a mostrar
	3. Fin de comando

* Reset solo recibe el punto 1 y 3.
* Modos columna y fila pueden recibir 2 caracteres en el punto 2 para mover las columnas/filas mayores a 9.
* Modo manual puede recibir hasta 3 caracteres en el punto 2 para mover una placa en específico.

- El modo de operación determina si se desplegará una de las siguientes:
	1. animación (carácter 'a')
	2. columna (carácter 'c')
	3. emoji (carácter 'e')
	4. fila (carácter 'f')
	5. letra (carácter 'l')
	6. manual (carácter 'm')
	7. número (carácter 'n')
	8. reset (carácter 'r')
	9. símbolo (carácter 's')
	10. palabra (carácter 'w')

- Las figuras a mostrar están dadas por los siguientes carácteres de cada modo de operación: 
	1. animación (carácteres de 'a' a 'j')
	2. columna (recibe desde '0' hasta '1''4')
	3. emoji (carácteres de 'a' a 'o')
	4. fila (recibe desde '0' hasta '1''5')
	5. letra (carácteres de 'a' a 'z')
	6. manual (recibe desde '0' hasta '2''3''9')
	7. número (carácteres de '0' a '9')
	8. reset (Reset NO recibe un carácter en esta etapa)
	9. símbolo (carácteres de 'a' a 'w')
	10. palabra (carácteres de 'a' a 'd')

- El fin de comando indica que se ha recibido toda la información y es seguro comenzar a procesar lo recibido. Este carácter es utilizado para todo modo de operación y es el carácter '|'.

Ejemplos de comandos:
	Para mover la placa 137 hay que enviar el comando: m137|
	Para mostrar una animación x: af|
	Para mostrar el número 5: n5|
	Para mover la columna 12: c12|
	Para regresar todas las placas a su posición original: r|