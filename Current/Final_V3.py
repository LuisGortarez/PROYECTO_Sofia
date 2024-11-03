from tkinter import messagebox
import serial
import time

#######################
# Various Definitions #
#######################

SERIAL_PORT = 'COM4'
BAUD_RATE = 115200
TIMEOUT = 1

TO_ASCII = 48               # For making integers be ASCII

ROTATE_90_DEGREES = False   # For deciding if hexagons are rotated 90 degrees

WELCOME_CMD = 1
HEART_CMD = 2
GREETING_CMD = 3
ROCK_CMD = 4
SLEEP_CMD = 5
HEXAGON_RESET_CMD = 0

SHAPE_DONE_CMD = "done"
shape_done = False

#######################################
# Serial communication configurations #
#######################################

# Jona: Si no tienes conectada una esp32, no se ejecuta el código. Si quieres comenta estas líneas
try:    # Try to connect to serial comm
    comm = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=TIMEOUT)
    time.sleep(.500)    # Wait a bit for communication
    comm.flushInput()   # Clean any leftover messages at the start
except serial.SerialException as exception_begin:
    messagebox.showerror("Error al intentar abrir el puerto serial", f"No se pudo abrir el puerto {SERIAL_PORT}: \n{exception_begin}")
    exit()

###########################
# Start of code Functions #
###########################


# Function for handling AI detected shapes
def shape_detected(shape):
    # JONA: Compara shape con las etiquetas de las figuras por IA para mandar comando a la esp32
    if shape:
        cmd_send(HEART_CMD)

    elif shape:
        cmd_send(GREETING_CMD)

    elif shape:
        cmd_send(ROCK_CMD)

    elif shape:
        cmd_send(SLEEP_CMD)

    elif shape:
        cmd_send(HEXAGON_RESET_CMD)


# Function for deciding command to send through serial comm
def cmd_send(figure):
    global shape_done

    if WELCOME_CMD == figure:
        send_data(WELCOME_CMD)
        while not shape_done:
            receive_message()
        shape_done = False
    elif HEART_CMD == figure:
        send_data(HEART_CMD)
        while not shape_done:
            receive_message()
        shape_done = False
    elif GREETING_CMD == figure:
        send_data(GREETING_CMD)
        while not shape_done:
            receive_message()
        shape_done = False
    elif ROCK_CMD == figure:
        send_data(ROCK_CMD)
        while not shape_done:
            receive_message()
        shape_done = False
    elif SLEEP_CMD == figure:
        send_data(SLEEP_CMD)
        while not shape_done:
            receive_message()
        shape_done = False
    elif HEXAGON_RESET_CMD == figure:
        send_data(HEXAGON_RESET_CMD)
        while not shape_done:
            receive_message()
        shape_done = False
    else:
        pass


# Function for sending array of data through serial communication
def send_data(data):
    # Check if data is an integer or an array
    if isinstance(data, int):
        data = [data]

    message = [ord('[')] + [num + TO_ASCII for num in data] + [ord(']')]

    message_bytes = bytes(message)  # Convert data to bytes

    try:    # Try to send data, if not sent, there´s a problem with serial comm
        if comm.is_open:  # Check if comm is open
            try:
                comm.write(message_bytes)   # Send data bytes
                receive_message()
                return True
            except serial.SerialException as exception_send:
                if not reconnect_port():
                    messagebox.showerror("Error al mandar datos", f"No se pudo mandar datos por el puerto {SERIAL_PORT}: {exception_send}")
                return False
        else:
            if not reconnect_port():
                messagebox.showerror("Error, el puerto serial no está abierto", f"El puerto {SERIAL_PORT} no está abierto.")
            return False
    except serial.SerialException as exception_send:
        if not reconnect_port():
            messagebox.showerror("Error, no se detectó puerto serial", f"Error de puerto serial: {exception_send}")
        return False


# Function for receiving serial messages (used for debug only)
def receive_message():
    global shape_done

    time.sleep(.10)     # Wait a bit for message
    full_message = ""
    message = 0

    while comm.in_waiting > 0:                      # Check if there´s available data
        message = comm.readline().decode().strip()  # Read and decode message
        full_message += message + "\n"

    if full_message:                                # If full message isn´t blank
        messagebox.showinfo("Mensaje del puerto serial", full_message)  # Show message in popup window
        if SHAPE_DONE_CMD == message:
            shape_done = True


# Function for trying to reconnect to serial port
def reconnect_port():
    global comm

    try:
        comm = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=TIMEOUT)
        time.sleep(.500)    # Wait a bit for communication
        comm.flushInput()   # Clean any leftover messages
        messagebox.showinfo("Reconectado al puerto serial", f"Se logró reconectar al puerto serial")
        return True
    except serial.SerialException as exception_reconnect:
        messagebox.showerror("Error al intentar reconectar el puerto serial", f"No se pudo reconectar el puerto {SERIAL_PORT}: \n{exception_reconnect}")
        return False


# Function for closing serial comm and exiting program
def exit_program():
    comm.close()
    exit()


def main():
    # Upon program start, send welcome command
    # cmd_send(WELCOME_CMD) # JONA: Esta línea se queda comentada, si no, envía por serial y se queda bloqueado hasta recibir respuesta del esp32

    while True:
        shape_detected(False)  # JONA: Ejecuta esta línea cuando se haya detectado una figura, de argumento manda la figura detectada


###################################
# Execution of main code function #
###################################

if __name__ == '__main__':
    main()
