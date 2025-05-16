from PIL import Image, ImageTk, ImageOps
from tkinter import messagebox
from ultralytics import YOLO
import tkinter as tk
import threading
import facebook
import requests
import serial
import queue
import time
import cv2


################################
# Communication configurations #
################################

# Universal communication config data
BAUD_RATE = 115200
SERIAL_WAIT = .500
WAIT_RESPONSE_TIMEOUT = 0.02       # Time to wait between command sends
CONFIRM_MESSAGE = "ok"      # Expected message to get from ESP after sending data
communication_type = 1      # Variable for deciding type of communication (0 = USB serial, 1 = BT serial, 3 = HTTP client)

# USB communication config data
USB_PORT = 'COM4'
USB_TIMEOUT = 1

# Bluetooth communication config data 
BLUETOOTH_PORT = 'COM6'
BLUETOOTH_TIMEOUT = 1

# HTTP communication config data
URL = 'http://192.168.4.1'  # Change IP of esp32 if necessary
HTTP_TIMEOUT = 0.3          # Amount of time to wait data sending in seconds 


if 0 == communication_type:
    try:    # Try to connect to serial comm
        usb_serial_comm = serial.Serial(USB_PORT, BAUD_RATE, timeout=USB_TIMEOUT)
        time.sleep(SERIAL_WAIT)   # Wait a bit for communication
        usb_serial_comm.flush()   # Clean any leftover messages at the start
    except serial.SerialException as exception_serial:
        messagebox.showerror("Failed at trying to open usb port", f"Failed to open usb port {USB_PORT}: \n{exception_serial}")
        exit()
elif 1 == communication_type:
    try:
        bt_serial_comm = serial.Serial(BLUETOOTH_PORT, BAUD_RATE, timeout=BLUETOOTH_TIMEOUT)
        time.sleep(SERIAL_WAIT)   # Wait a bit for communication
        bt_serial_comm.flush()    # Clean any leftover messages at the start
    except serial.SerialException as exception_bluetooth:
        messagebox.showerror("Failed at trying to open bluetooth port", f"Failed to open bluetooth port {BLUETOOTH_PORT}: \n{exception_bluetooth}")
        exit()


####################
# Commands to send #
####################

# Three characters are expected for every command (reset command is the exception, it does not need point 2):
#  1. Mode of operation
#  2. Shape to show
#  3. End of command

# Mode of operation command
MANUAL_CMD = "m"
ANIMATION_CMD = "a"
RESET_CMD = "r"

# Shape command
EXPANSION_CMD = "a"
HEART_CMD = "b"
PEACE_CMD = "c"
ROCK_CMD = "d"
HI_CMD = "e"
FIST_CMD = "f"


# End of command
END_OF_CMD = "|"

# Queue where commands will be stored
queue_commands = queue.Queue()
QUEUE_THREAD_END = "END"    # Indicator for telling queue thread to end task


####################################
# Variables for buttons and shapes #
####################################

# Exit button ends the program once clicked
EXIT_BUTTON_WIDTH = 16
EXIT_BUTTON_HEIGHT = 4
EXIT_BUTTON_X_ORIGIN = 160
EXIT_BUTTON_Y_ORIGIN = 100
EXIT_BUTTON_COLOR = "SkyBlue1"

# Capture button for taking picture
CAPTURE_BUTTON_WIDTH = 16
CAPTURE_BUTTON_HEIGHT = 4
CAPTURE_BUTTON_X_ORIGIN = 160
CAPTURE_BUTTON_Y_ORIGIN = 300
CAPTURE_BUTTON_COLOR = "SkyBlue2"

# Reset button for sending reset command
RESET_BUTTON_WIDTH = 16
RESET_BUTTON_HEIGHT = 4
RESET_BUTTON_X_ORIGIN = 160
RESET_BUTTON_Y_ORIGIN = 300
RESET_BUTTON_COLOR = "SkyBlue2"

# Change mode button for switching between capture and manual modes
MODE_BUTTON_WIDTH = 16
MODE_BUTTON_HEIGHT = 4
MODE_BUTTON_X_ORIGIN = 160
MODE_BUTTON_Y_ORIGIN = 500
MODE_BUTTON_COLOR = "SkyBlue3"

# Publish button for uploading picture to ITESO Facebook page
PUBLISH_BUTTON_WIDTH = 16
PUBLISH_BUTTON_HEIGHT = 4
PUBLISH_BUTTON_X_ORIGIN = 160
PUBLISH_BUTTON_Y_ORIGIN = 300
PUBLISH_BUTTON_COLOR = "PaleTurquoise1"

# Cancel button for NOT uploading picture to ITESO Facebook page
CANCEL_BUTTON_WIDTH = 16
CANCEL_BUTTON_HEIGHT = 4
CANCEL_BUTTON_X_ORIGIN = 160
CANCEL_BUTTON_Y_ORIGIN = 500
CANCEL_BUTTON_COLOR = "PaleTurquoise2"

# Show square is where text shows which hexagon was touched
show_square_lim_inf_hex_x = 30
show_square_lim_sup_hex_x = 290
show_square_lim_inf_hex_y = 630
show_square_lim_sup_hex_y = 780

show_square_lim_center_hex_x = show_square_lim_inf_hex_x + ((show_square_lim_sup_hex_x - show_square_lim_inf_hex_x) / 2)
show_square_lim_center_hex_y = show_square_lim_inf_hex_y + ((show_square_lim_sup_hex_y - show_square_lim_inf_hex_y) / 4)

show_square_hex_text_y = show_square_lim_inf_hex_y + ((show_square_lim_sup_hex_y - show_square_lim_inf_hex_y) / 2)

display_hex_text = None     # Has to be global for starting with nothing showing in show square

# Image label where picture is displayed
IMG_LABEL_COLOR = "salmon"
IMG_LABEL_X_ORIGIN = 930
IMG_LABEL_Y_ORIGIN = 430

# Image border data
IMAGE_BORDER_SIZE = 175
IMAGE_BORDER_COLOR = "White"

# Square settings for color and outline color
SQUARE_COLOR = "light blue"
SQUARE_OUTLINE_COLOR = "black"

# Font settings for text in squares and buttons
FONT_SIZE = 20
FONT_TYPE = "Arial"
FONT_COLOR = "Black"


#####################################
# Variables for hexagon coordinates #
#####################################

ROTATE_90_DEGREES = False   # For deciding if hexagons are rotated 90 degrees

# Number of hexagons in rows & columns
N_HEXAGONS_ROWS = 16
N_HEXAGONS_COLUMNS = 15

# Make list of N elements for creating hexagons
hexagon_rows = list(range(N_HEXAGONS_ROWS))
hexagon_columns = list(range(N_HEXAGONS_COLUMNS))

# Array where every hexagons coordinates, row-column and polygon id will be stored
hexagons = []

# Array flags for knowing if we are dragging on a shape
is_dragging = {}

# Every hexagon´s properties (in pixels)
hex_height = 48 if not ROTATE_90_DEGREES else 32
hex_width = 30 if not ROTATE_90_DEGREES else 59

# Pixels where the first hexagon will be displayed
# Every hexagon will take these values as a base
hex_start_x = 360 if not ROTATE_90_DEGREES else 235
hex_end_x = hex_start_x + hex_width
hex_start_y = 20 if not ROTATE_90_DEGREES else 35
hex_end_y = hex_start_y + hex_height

# Space between each hexagon (in pixels)
space_between_hex_x = 17 if not ROTATE_90_DEGREES else 4
space_between_hex_y = 3 if not ROTATE_90_DEGREES else 18

offset_x = 0 if not ROTATE_90_DEGREES else hex_width / 2 + space_between_hex_x / 2    # Offset for not displaying hexagons over each other
offset_y = hex_height / 2 + space_between_hex_y / 2 if not ROTATE_90_DEGREES else 0   # Offset for not displaying hexagons over each other

# Hexagon settings for color and outline color
NORMAL_HEXAGON_COLOR = "snow4"
PRESSED_HEXAGON_COLOR = "goldenrod1"
HEXAGON_OUTLINE_COLOR = "black"


###########################
# Facebook configurations #
###########################

facebook_message = '#DíadelITESO #SofIA'
facebook_access_token = 'TU_TOKEN_DE_ACCESO'


###################################
# Section for creating the screen #
###################################

# Create canvas
CAPTURE_CANVAS_COLOR = "pink"
MANUAL_CANVAS_COLOR = "white smoke"

default_screen = tk.Tk()
default_screen.attributes('-fullscreen', True)

canvas = tk.Canvas(default_screen, bg=MANUAL_CANVAS_COLOR)
canvas.pack(fill=tk.BOTH, expand=True)
mode = True           # Flag for switching between modes of operation (Capture & Manual modes)
camera_busy = False   # Flag for allowing AI detection when NOT in publish screen


#########################
# Images configurations #
#########################

# Sizes and pixels for images
ITESO_LOGO_SQUARE_COLOR = "Dark blue"
ITESO_LOGO_SQUARE_EXTRA = 10

ITESO_LOGO_LENGTH = 420
ITESO_LOGO_HEIGHT = 90

ITESO_LOGO_START_X = 1300
ITESO_LOGO_START_Y = 100

SOFIA_LOGO_LENGTH_MANUAL = 450
SOFIA_LOGO_HEIGHT_MANUAL = 280

SOFIA_LOGO_START_X_MANUAL = 1298
SOFIA_LOGO_START_Y_MANUAL = 300

SOFIA_LOGO_LENGTH_CAPTURE = 380
SOFIA_LOGO_HEIGHT_CAPTURE = 240

SOFIA_LOGO_START_X_CAPTURE = 200
SOFIA_LOGO_START_Y_CAPTURE = 720

# Pixels for positioning backdrop square for ITESO logo
iteso_logo_square_lim_inf_x = ITESO_LOGO_START_X - ITESO_LOGO_LENGTH/2 - ITESO_LOGO_SQUARE_EXTRA
iteso_logo_square_lim_sup_x = ITESO_LOGO_START_X + ITESO_LOGO_LENGTH/2 + ITESO_LOGO_SQUARE_EXTRA
iteso_logo_square_lim_inf_y = ITESO_LOGO_START_Y - ITESO_LOGO_HEIGHT/2 - ITESO_LOGO_SQUARE_EXTRA
iteso_logo_square_lim_sup_y = ITESO_LOGO_START_Y + ITESO_LOGO_HEIGHT/2 + ITESO_LOGO_SQUARE_EXTRA

# Open images first
ITESO_IMAGE = Image.open("logo_ITESO.png")
SOFIA_IMAGE = Image.open("logo_SOFIA.png")

# Resize images for fitting in Canvas
ITESO_IMAGE_MOD = ITESO_IMAGE.resize((ITESO_LOGO_LENGTH, ITESO_LOGO_HEIGHT))
SOFIA_IMAGE_MANUAL_MOD = SOFIA_IMAGE.resize((SOFIA_LOGO_LENGTH_MANUAL, SOFIA_LOGO_HEIGHT_MANUAL))
SOFIA_IMAGE_CAPTURE_MOD = SOFIA_IMAGE.resize((SOFIA_LOGO_LENGTH_CAPTURE, SOFIA_LOGO_HEIGHT_CAPTURE))

# Convert .png file to a format Tkinter can use
ITESO_LOGO = ImageTk.PhotoImage(ITESO_IMAGE_MOD)
SOFIA_LOGO_MANUAL = ImageTk.PhotoImage(SOFIA_IMAGE_MANUAL_MOD)
SOFIA_LOGO_CAPTURE = ImageTk.PhotoImage(SOFIA_IMAGE_CAPTURE_MOD)

# Name of image captured to display in capture screen
screen_image_path = "capture_with_border.png"

# Images for border
CORNERS_IMAGE__NAME = 'corners_image.png'
TOP_IMAGE__NAME = 'top_image.png'
BOTTOM_IMAGE__NAME = 'bottom_image.png'
LEFT_IMAGE__NAME = 'left_image.png'
RIGHT_IMAGE__NAME = 'right_image.png'

TOP_IMAGE = Image.open(TOP_IMAGE__NAME)
BOTTOM_IMAGE = Image.open(BOTTOM_IMAGE__NAME)
LEFT_IMAGE = Image.open(LEFT_IMAGE__NAME)
RIGHT_IMAGE = Image.open(RIGHT_IMAGE__NAME)

TOP_IMAGE_WIDTH, TOP_IMAGE_HEIGHT = TOP_IMAGE.size
BOTTOM_IMAGE_WIDTH, BOTTOM_IMAGE_HEIGHT = BOTTOM_IMAGE.size
LEFT_IMAGE_WIDTH, LEFT_IMAGE_HEIGHT = LEFT_IMAGE.size
RIGHT_IMAGE_WIDTH, RIGHT_IMAGE_HEIGHT = RIGHT_IMAGE.size


# ------------------------------------------------------------------------------------------------------------- #
# ------------------------------------------------------------------------------------------------------------- #
# ------------------------------------------ Start of code Functions ------------------------------------------ #
# ------------------------------------------------------------------------------------------------------------- #
# ------------------------------------------------------------------------------------------------------------- #

# ------------------------------------------------------------------------------------------------------------- #
# ----------------------------------------- Screens functions section ----------------------------------------- #
# ------------------------------------------------------------------------------------------------------------- #

# Function for toggling modes
def change_mode():
    global mode
    mode = not mode # Toggle mode

    canvas.delete("all")
    queue_commands.put(RESET_CMD + END_OF_CMD)  # Reset tiles when mode changes
    if mode:
        hexagons.clear()        # Clear content of old screen for new screen
        canvas.config(bg=MANUAL_CANVAS_COLOR)
        display_manual_screen()
    else:
        canvas.config(bg=CAPTURE_CANVAS_COLOR)
        display_capture_screen()


# -------------------------------------------- #
# ---------- Create screen functions --------- #
# -------------------------------------------- #

# Function for displaying capture screen
def display_capture_screen():

    # Create exit button on canvas
    exit_button = tk.Button(canvas, text="Click aquí para salir", command=exit_program, bg=EXIT_BUTTON_COLOR, width=EXIT_BUTTON_WIDTH, height=EXIT_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(EXIT_BUTTON_X_ORIGIN, EXIT_BUTTON_Y_ORIGIN, window=exit_button)

    # Create capture button on canvas
    capture_button = tk.Button(canvas, text="Tomar foto", command=picture, bg=CAPTURE_BUTTON_COLOR, width=CAPTURE_BUTTON_WIDTH, height=CAPTURE_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(CAPTURE_BUTTON_X_ORIGIN, CAPTURE_BUTTON_Y_ORIGIN, window=capture_button)

    # Create mode button on canvas
    mode_button = tk.Button(canvas, text="Cambiar a modo\nlibre", command=change_mode, bg=MODE_BUTTON_COLOR, width=MODE_BUTTON_WIDTH, height=MODE_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(MODE_BUTTON_X_ORIGIN, MODE_BUTTON_Y_ORIGIN, window=mode_button)

    # Insert images into Canvas
    canvas.create_image(SOFIA_LOGO_START_X_CAPTURE, SOFIA_LOGO_START_Y_CAPTURE, image=SOFIA_LOGO_CAPTURE)
    insert_captured_image()


# Function for opening window for picture publishing
def display_publish_screen():
    canvas.delete("all")

    insert_captured_image()

    def publish_and_close():
        publish()
        canvas.delete("all")
        display_capture_screen()

    def cancel_and_close():
        canvas.delete("all")
        display_capture_screen()

    publish_button = tk.Button(canvas, text="Guardar foto", command=publish_and_close, bg=PUBLISH_BUTTON_COLOR , width=PUBLISH_BUTTON_WIDTH, height=PUBLISH_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(PUBLISH_BUTTON_X_ORIGIN, PUBLISH_BUTTON_Y_ORIGIN, window=publish_button)

    cancel_button = tk.Button(canvas, text="Cancelar", command=cancel_and_close, bg=CANCEL_BUTTON_COLOR, width=CANCEL_BUTTON_WIDTH, height=CANCEL_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(CANCEL_BUTTON_X_ORIGIN, CANCEL_BUTTON_Y_ORIGIN, window=cancel_button)

    # Insert images into Canvas
    canvas.create_image(SOFIA_LOGO_START_X_CAPTURE, SOFIA_LOGO_START_Y_CAPTURE, image=SOFIA_LOGO_CAPTURE)


# Insert captured image on canvas
def insert_captured_image():
    img_label = tk.Label(canvas, bg=IMG_LABEL_COLOR)
    canvas.create_window(IMG_LABEL_X_ORIGIN, IMG_LABEL_Y_ORIGIN, window=img_label, anchor="center")

    try:    # Try opening captured image
        # Load image
        img_pil = Image.open(screen_image_path)
        img_tk = ImageTk.PhotoImage(image=img_pil)

        # Show picture in new frame
        img_label.config(image=img_tk)  # type: ignore
        img_label.image = img_tk
    except Exception as image_path_exception:
        print(f"No image to display at this time: {image_path_exception}")


# Function for displaying manual screen
def display_manual_screen():
    canvas.config(bg=MANUAL_CANVAS_COLOR)   # Change canvas background color

    # Create exit button on canvas
    exit_button = tk.Button(canvas, text="Click aquí para salir", command=exit_program, bg=EXIT_BUTTON_COLOR, width=EXIT_BUTTON_WIDTH, height=EXIT_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(EXIT_BUTTON_X_ORIGIN, EXIT_BUTTON_Y_ORIGIN, window=exit_button)

    # Create reset button on canvas
    mode_button = tk.Button(canvas, text="Click aquí para\nreiniciar", command=reset_manual_screen, bg=RESET_BUTTON_COLOR, width=RESET_BUTTON_WIDTH, height=RESET_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(RESET_BUTTON_X_ORIGIN, RESET_BUTTON_Y_ORIGIN, window=mode_button)

    # Create mode button on canvas
    mode_button = tk.Button(canvas, text="Cambiar a modo\ncaptura", command=change_mode, bg=MODE_BUTTON_COLOR, width=MODE_BUTTON_WIDTH, height=MODE_BUTTON_HEIGHT, font=(FONT_TYPE, FONT_SIZE))
    canvas.create_window(MODE_BUTTON_X_ORIGIN, MODE_BUTTON_Y_ORIGIN, window=mode_button)

    # Create show square on canvas
    canvas.create_rectangle(show_square_lim_inf_hex_x, show_square_lim_sup_hex_y, show_square_lim_sup_hex_x, show_square_lim_inf_hex_y, fill=SQUARE_COLOR, outline=SQUARE_OUTLINE_COLOR)
    canvas.create_text(show_square_lim_center_hex_x, show_square_lim_center_hex_y, text="Tocaste: ", fill=FONT_COLOR, font=(FONT_TYPE, FONT_SIZE))

    # Create iteso image square on canvas
    canvas.create_rectangle(iteso_logo_square_lim_inf_x, iteso_logo_square_lim_inf_y, iteso_logo_square_lim_sup_x, iteso_logo_square_lim_sup_y, fill=ITESO_LOGO_SQUARE_COLOR, outline=ITESO_LOGO_SQUARE_COLOR)

    # Insert images into Canvas
    canvas.create_image(ITESO_LOGO_START_X, ITESO_LOGO_START_Y, image=ITESO_LOGO)
    canvas.create_image(SOFIA_LOGO_START_X_MANUAL, SOFIA_LOGO_START_Y_MANUAL, image=SOFIA_LOGO_MANUAL)

    for i in hexagon_rows:          # hexagon rows
        for j in hexagon_columns:   # hexagon columns

            # Calculate the necessary position of each vertex of the hexagons for displaying on canvas
            if ROTATE_90_DEGREES:
                if i % 2 == 0:
                    add_x = 0
                else:                     # If row is odd number, add offset to position of hexagon
                    add_x = offset_x      # to not have the rows be on top of each other.
                hexagon_coordinates = [
                    (hex_width / 2 + hex_start_x + (hex_width * j) + (j * space_between_hex_x) + add_x, hex_start_y - hex_width / 4 + (hex_height * i) + (i * space_between_hex_y)),
                    (hex_end_x + (hex_width * j) + (j * space_between_hex_x) + add_x, hex_start_y + (hex_height * i) + (i * space_between_hex_y)),
                    (hex_end_x + (hex_width * j) + (j * space_between_hex_x) + add_x, hex_end_y + (hex_height * i) + (i * space_between_hex_y)),
                    (hex_width / 2 + hex_start_x + (hex_width * j) + (j * space_between_hex_x) + add_x, hex_end_y + hex_width / 4 + (hex_height * i) + (i * space_between_hex_y)),
                    (hex_start_x + (hex_width * j) + (j * space_between_hex_x) + add_x, hex_end_y + (hex_height * i) + (i * space_between_hex_y)),
                    (hex_start_x + (hex_width * j) + (j * space_between_hex_x) + add_x, hex_start_y + (hex_height * i) + (i * space_between_hex_y))
                ]
            else:
                if j % 2 == 0:
                    add_y = 0
                else:                     # If row is odd number, add offset to position of hexagon
                    add_y = offset_y      # to not have the rows be on top of each other.
                hexagon_coordinates = [
                    ((hex_start_x + (hex_width * j) + (j * space_between_hex_x)), (hex_start_y + (hex_height * i) + (i * space_between_hex_y) + add_y)),
                    ((hex_end_x + (hex_width * j) + (j * space_between_hex_x)), (hex_start_y + (hex_height * i) + (i * space_between_hex_y) + add_y)),
                    (((hex_end_x + hex_width/2.2) + (hex_width * j) + (j * space_between_hex_x)), ((hex_start_y + hex_height/2) + (i * hex_height) + (i * space_between_hex_y) + add_y)),
                    ((hex_end_x + (hex_width * j) + (j * space_between_hex_x)), (hex_end_y + (hex_height * i) + (i * space_between_hex_y) + add_y)),
                    ((hex_start_x + (hex_width * j) + (j * space_between_hex_x)), (hex_end_y + (hex_height * i) + (i * space_between_hex_y) + add_y)),
                    (((hex_start_x - hex_width/2.2) + (j * hex_width) + (j * space_between_hex_x)), ((hex_start_y + hex_height/2) + (i * hex_height) + (i * space_between_hex_y) + add_y))
                ]

            if (not ROTATE_90_DEGREES) and (i == N_HEXAGONS_ROWS-1) and (j % 2 != 0):
                pass        # Don't make hexagon in last row for uneven number columns
            else:
                polygon_id = canvas.create_polygon(hexagon_coordinates, fill=NORMAL_HEXAGON_COLOR, outline=HEXAGON_OUTLINE_COLOR)  # Create hexagon with specific colors
                hexagons.append((hexagon_coordinates, f"Hexágono: {i},{j}", polygon_id))    # Save string of each hexagon coordinates


# ------------------------------------------------------------------------------------------------------------- #
# -------------------------------------- Capture Screen functions section ------------------------------------- #
# ------------------------------------------------------------------------------------------------------------- #

# -------------------------------------------- #
# -------- Picture handling functions -------- #
# -------------------------------------------- #

# Function for taking picture with camera
def picture():
    global camera_busy
    camera_busy = True
    camera = cv2.VideoCapture(0)

    if not camera.isOpened():
        print("Webcam could not be opened. Verify ID of device and connection.")
        return
    ret, frame = camera.read()
    if ret:
        cv2.imwrite("capture_from_webcam_2.png", frame)
        camera.release()
        add_border_and_images("capture_from_webcam_2.png")
        display_publish_screen()
    else:
        print("Picture could not be taken with Webcam")
        camera.release()
    camera_busy = False


def add_border_and_images(image_path):
    img = Image.open(image_path)  # Open image

    # Add border
    img_size = 320
    img_with_white_border = ImageOps.expand(img, border=IMAGE_BORDER_SIZE, fill=IMAGE_BORDER_COLOR)

    # Load and resize images for borders maintaining 1:1 relation
    corners_img = Image.open(CORNERS_IMAGE__NAME).resize((IMAGE_BORDER_SIZE, IMAGE_BORDER_SIZE))
    top_img = Image.open(TOP_IMAGE__NAME).resize((int(img_size*1.7), int(IMAGE_BORDER_SIZE/1.7)))
    bottom_img = Image.open(BOTTOM_IMAGE__NAME).resize((img_size, int(img_size * BOTTOM_IMAGE_HEIGHT / BOTTOM_IMAGE_WIDTH)))
    left_img = Image.open(LEFT_IMAGE__NAME).resize((int(img_size * LEFT_IMAGE_WIDTH / LEFT_IMAGE_HEIGHT), img_size))
    right_img = Image.open(RIGHT_IMAGE__NAME).resize((int(img_size * RIGHT_IMAGE_WIDTH / RIGHT_IMAGE_HEIGHT), img_size))

    # Create new image with same size as image with white border
    new_img = Image.new('RGB', (img_with_white_border.width, img_with_white_border.height))
    new_img.paste(img_with_white_border, (0, 0))

    # Get positions for pasting borders on image
    top_x = (new_img.width - top_img.width) // 2
    bottom_x = (new_img.width - bottom_img.width) // 2
    left_y = (new_img.height - left_img.height) // 2
    right_y = (new_img.height - right_img.height) // 2

    # Paste border images
    new_img.paste(corners_img, (0, 0), corners_img)
    new_img.paste(corners_img, (img_with_white_border.width-corners_img.width, 5), corners_img)
    new_img.paste(corners_img, (0, img_with_white_border.height-corners_img.height-5), corners_img)
    new_img.paste(corners_img, (img_with_white_border.width-corners_img.width, img_with_white_border.height-corners_img.height-5), corners_img)

    new_img.paste(top_img, (top_x, IMAGE_BORDER_SIZE//5), top_img)
    new_img.paste(bottom_img, (bottom_x, new_img.height - bottom_img.height-5), bottom_img)
    new_img.paste(left_img, (0, left_y), left_img)
    new_img.paste(right_img, (new_img.width - right_img.width, right_y), right_img)

    new_img.save(screen_image_path)  # Save resulting image


# -------------------------------------------- #
# -------- Facebook handling functions ------- #
# -------------------------------------------- #

# Function for publishing image to ITESO facebook
def publish(save_locally=True):
    if save_locally:
        # Generate unique name for picture
        from datetime import datetime
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        local_filename = f"Dia_Iteso_{timestamp}.png"

        # Save image locally
        with open(local_filename, "wb") as local_file:
            with open(screen_image_path, "rb") as original_file:
                local_file.write(original_file.read())
        print(f"Image saved as: {local_filename}")
    else:
        post_image_to_facebook(screen_image_path, facebook_message, facebook_access_token)


# Function for uploading picture to ITESO facebook page
def post_image_to_facebook(image_path, message, access_token):
    graph = facebook.GraphAPI(access_token)
    with open(image_path, "rb") as image_file:
        graph.put_photo(image=image_file, message=message)


# ------------------------------------------------------------------------------------------------------------- #
# -------------------------------------- Manual Screen functions section -------------------------------------- #
# ------------------------------------------------------------------------------------------------------------- #

# -------------------------------------------- #
# ----------- Mouse event handlers ----------- #
# -------------------------------------------- #

# Function for handling mouse click event
def screen_touch_click(event):
    x = event.x     # Get coordinates of event in pixels
    y = event.y

    if mode:    # If the mode is manual
        # Loop for verifying if click event happened inside and which hexagon
        for coordinates, id_hex, polygon_id in hexagons:
            if click_in_hexagon((x, y), coordinates):
                change_polygon_color(polygon_id)
                is_dragging[id_hex] = True
                hex_number = get_hex_number(id_hex)          # Get row & column of touched hexagon
                show_pressed_hexagon(hex_number)             # Display touched hexagon in show square
                cmd = MANUAL_CMD + hex_number + END_OF_CMD  # Build cmd before sending through serial bus
                queue_commands.put(cmd)     # Put command in queue for thread to send
                break


# Function for handling mouse drag in canvas
def screen_touch_drag(event):
    x = event.x     # Get coordinates of event in pixels
    y = event.y

    if mode:    # If the mode is manual
        # Loop for verifying if click event happened inside and which hexagon
        for coordinates, id_hex, polygon_id in hexagons:
            if click_in_hexagon((x, y), coordinates):
                if id_hex not in is_dragging or not is_dragging[id_hex]:    # Execute code only once if we are inside shape
                    change_polygon_color(polygon_id)
                    is_dragging[id_hex] = True
                    hex_number = get_hex_number(id_hex)          # Get row & column of touched hexagon
                    show_pressed_hexagon(hex_number)             # Display touched hexagon in show square
                    cmd = MANUAL_CMD + hex_number + END_OF_CMD  # Build cmd before sending through serial bus
                    queue_commands.put(cmd)     # Put command in queue for thread to send
                break
            else:
                # Clear flag when mouse exits shape
                if id_hex in is_dragging and is_dragging[id_hex]:
                    is_dragging[id_hex] = False


# -------------------------------------------- #
# ---------- Polygon data functions ---------- #
# -------------------------------------------- #

# Function for ray-casting algorithm
def click_in_hexagon(pixels, coordinates):
    x, y = pixels
    total_pixels = len(coordinates)
    b = total_pixels - 1
    inside = False
    for a in range(total_pixels):
        if ((coordinates[a][1] > y) != (coordinates[b][1] > y)) and (x < (coordinates[b][0] - coordinates[a][0]) * (y - coordinates[a][1]) / (coordinates[b][1] - coordinates[a][1]) + coordinates[a][0]):
            inside = not inside
        b = a
    return inside


# Function for obtaining row & column
def get_hex_number(id_hex):
    data_section = id_hex.split(": ")                     # Cut string to data section
    row, column = map(int, data_section[1].split(","))    # Convert to integers
    return str(row*N_HEXAGONS_COLUMNS + column)


# Function for displaying which hexagon was touched on show square
def show_pressed_hexagon(hex_number):
    global display_hex_text     # We will be using the global variable

    # If there already exists text inside the square, delete it
    if display_hex_text is not None:
        canvas.delete(display_hex_text)
    display_hex_text = canvas.create_text(show_square_lim_center_hex_x, show_square_hex_text_y, text=f"Hexágono {hex_number}", fill="black", font=("Arial", FONT_SIZE))


# Function for resetting tiles
def reset_manual_screen():
    reset_polygon_color()
    queue_commands.put(RESET_CMD + END_OF_CMD)  # Put command in queue for thread to send


# Function for resetting color of every polygon saved in array
def reset_polygon_color():
    for coordinates, id_hex, polygon_id in hexagons:
        canvas.itemconfig(polygon_id, fill=NORMAL_HEXAGON_COLOR)   # Set polygon to default color


# Function for changing color of desired polygon in canvas
def change_polygon_color(polygon_id):
    current_color = canvas.itemcget(polygon_id, "fill")     # Get current color of polygon in canvas
    new_color = PRESSED_HEXAGON_COLOR if current_color == NORMAL_HEXAGON_COLOR else NORMAL_HEXAGON_COLOR      # Determine next color of polygon
    canvas.itemconfig(polygon_id, fill=new_color)           # Set new color of polygon


# ------------------------------------------------------------------------------------------------------------- #
# ----------------------------------------- Threads functions section ----------------------------------------- #
# ------------------------------------------------------------------------------------------------------------- #

# Function for detecting shape
def run_detection():
    camera = cv2.VideoCapture(0)
    model = YOLO('V8.pt')
    while not detection_event.is_set():
        if not mode and not camera_busy:     # If mode is capture and camera is not being used for picture taking
            camera = cv2.VideoCapture(0)
            try:
                ret, frame = camera.read()
                img_name = "webcam_image.png"
                cv2.imwrite(img_name, frame)
                source = 'webcam_image.png'
                results = model.predict(source=source, conf=0.33, imgsz=640)
                print(int(results[0].boxes.cls[0].item()))
                shape = int(results[0].boxes.cls[0].item())
                match shape:
                    case 0:
                        cmd = ANIMATION_CMD + HEART_CMD + END_OF_CMD
                        queue_commands.put(cmd)
                    case 1:
                        cmd = ANIMATION_CMD + PEACE_CMD + END_OF_CMD
                        queue_commands.put(cmd)
                    case 2:
                        cmd = ANIMATION_CMD + ROCK_CMD + END_OF_CMD
                        queue_commands.put(cmd)
                    case 3:
                        cmd = ANIMATION_CMD + HI_CMD + END_OF_CMD
                        queue_commands.put(cmd)
                    case 4:
                        cmd = ANIMATION_CMD + FIST_CMD + END_OF_CMD
                        queue_commands.put(cmd)
                    case _:
                        print("No cmd for detected shape")
                cv2.waitKey(3000)
            except Exception as frame_error:
                print(f"Ocurrió un error al leer la cámara: {frame_error}")
        else:
            camera.release()
        time.sleep(0.03)
    camera.release()


# Thread function for sending commands stored in Queue
def queue_send():
    while True:
        cmd = queue_commands.get()
        if cmd == QUEUE_THREAD_END:  # When queue holds "END", exit function
            break

        if 0 == communication_type:
            usb_serial_send_data(cmd)
        elif 1 == communication_type:
            bt_serial_send_data(cmd)
        elif 2 == communication_type:
            http_send_data(cmd)


# ------------------------------------------------------------------------------------------------------------- #
# -------------------------------------- Communication functions section -------------------------------------- #
# ------------------------------------------------------------------------------------------------------------- #

# -------------------------------------------- #
# ---- USB serial communication functions ---- #
# -------------------------------------------- #

# Function for sending array of data through usb serial communication
def usb_serial_send_data(data):
    message_bytes = bytes(data, 'utf-8')  # Convert data to bytes

    try:    # Try to send data, if not sent, there´s a problem with usb serial comm
        if usb_serial_comm.is_open:  # Check if usb serial comm is open
            try:
                usb_serial_comm.write(message_bytes)   # Send data bytes
                usb_serial_comm.flush()
                # usb_serial_receive_message()
                return True
            except serial.SerialException as exception_send:
                if not usb_serial_reconnect_port():
                    messagebox.showerror("Error sending data", f"Sending data through usb port failed {USB_PORT}: {exception_send}")
                return False
        else:
            if not usb_serial_reconnect_port():
                messagebox.showerror("Error, usb serial port not opened", f"The usb port {USB_PORT} is not opened")
            return False
    except serial.SerialException as exception_send:
        if not usb_serial_reconnect_port():
            messagebox.showerror("Error, usb serial port not detected", f"USB serial port error: {exception_send}")
        return False


# Function for receiving usb serial messages (used for debug only)
def usb_serial_receive_message():
    time.sleep(.10)     # Wait a bit for message
    full_message = ""

    while usb_serial_comm.in_waiting > 0:                      # Check if there´s available data
        message = usb_serial_comm.readline().decode().strip()  # Read and decode message
        full_message += message + "\n"

    if full_message:    # If full message isn´t blank
        print(full_message)
        # messagebox.showinfo("Serial port message", full_message)  # Show message in popup window


# Function for tying to reconnect to usb serial port
def usb_serial_reconnect_port():
    global usb_serial_comm

    try:
        usb_serial_comm = serial.Serial(USB_PORT, BAUD_RATE, timeout=USB_TIMEOUT)
        time.sleep(SERIAL_WAIT)    # Wait a bit for communication
        usb_serial_comm.flush()    # Clean any leftover messages
        messagebox.showinfo("Reconnecting usb serial port", f"Reconnection to usb serial port successful")
        return True
    except serial.SerialException as exception_reconnect:
        messagebox.showerror("Error reconnecting to usb port", f"Reconnecting usb port failed {USB_PORT}: \n{exception_reconnect}")
        return False


# -------------------------------------------- #
# - Bluetooth serial communication functions - #
# -------------------------------------------- #

# Function for sending data through bluetooth serial communication
def bt_serial_send_data(data):
    message_bytes = bytes(data, 'utf-8')  # Convert data to bytes

    try:    # Try to send data, if not sent, there´s a problem with bluetooth serial comm
        if bt_serial_comm.is_open:  # Check if bluetooth serial comm is open
            try:
                bt_serial_comm.write(message_bytes)   # Send data bytes
                bt_serial_comm.flush()
                
                start_time = time.time()
                while True:  # Wait for confirmation command
                    if bt_serial_comm.in_waiting > 0:
                        message = bt_serial_comm.readline().decode('utf-8').strip()
                        if CONFIRM_MESSAGE == message:
                            break
                    if time.time() - start_time > WAIT_RESPONSE_TIMEOUT:   # If response did not come, break
                        return False
                return True
            except serial.SerialException as exception_send:
                if not bt_serial_reconnect_port():
                    messagebox.showerror("Error sending data", f"Sending data through bluetooth port failed {BLUETOOTH_PORT}: {exception_send}")
                return False
        else:
            if not usb_serial_reconnect_port():
                messagebox.showerror("Error, bluetooth serial port not opened", f"The bluetooth port {BLUETOOTH_PORT} is not opened")
            return False
    except serial.SerialException as exception_send:
        if not usb_serial_reconnect_port():
            messagebox.showerror("Error, bluetooth serial port not detected", f"Bluetooth serial port error: {exception_send}")
        return False


# Function for tying to reconnect to bluetooth serial port
def bt_serial_reconnect_port():
    global bt_serial_comm

    try:
        bt_serial_comm = serial.Serial(BLUETOOTH_PORT, BAUD_RATE, timeout=BLUETOOTH_TIMEOUT)
        time.sleep(SERIAL_WAIT)   # Wait a bit for communication
        bt_serial_comm.flush()    # Clean any leftover messages
        messagebox.showinfo("Reconnecting bluetooth serial port", f"Reconnection to bluetooth serial port successful")
        return True
    except serial.SerialException as exception_reconnect:
        messagebox.showerror("Error reconnecting to bluetooth port", f"Reconnecting bluetooth port failed {BLUETOOTH_PORT}: \n{exception_reconnect}")
        return False


# -------------------------------------------- #
# ------- HTTP communication functions ------- #
# -------------------------------------------- #

# Function for sending data through HTTP communication
def http_send_data(data):
    try:
        response = requests.post(URL, data=data, timeout=HTTP_TIMEOUT)
        response.raise_for_status()        # Verify successful response (200 OK)
        print(f"Respuesta: {response.text}")
    except requests.exceptions.RequestException as http_exception:
        messagebox.showerror("HTTP communication error", f"Error: {http_exception}")


# ------------------------------------------------------------------------------------------------------------- #
# ------------------------------- Initialization of code, main functions section ------------------------------ #
# ------------------------------------------------------------------------------------------------------------- #

# Function for closing serial comm and destroying screen
def exit_program():
    detection_event.set()
    queue_commands.put(QUEUE_THREAD_END)        # Release queue thread task

    detection_thread.join()
    queue_thread.join()             # Wait until queue thread joins main
    default_screen.destroy()

    if 0 == communication_type:
        usb_serial_comm.close()
    elif 1 == communication_type:
        bt_serial_comm.close()

    exit()  # Safely exit code


# Thread for detecting shapes
detection_thread = threading.Thread(target=run_detection)
detection_event = threading.Event()
detection_thread.start()

# Thread for handling commands queue
queue_thread = threading.Thread(target=queue_send)
queue_thread.start()

# Send commands for when system is connected
queue_commands.put(RESET_CMD + END_OF_CMD)
time.sleep(SERIAL_WAIT)
queue_commands.put(ANIMATION_CMD + EXPANSION_CMD + END_OF_CMD)

# Bind mouse events to functions and display screen
default_screen.bind("<Button-1>", screen_touch_click)   # Binds mouse click event with function screen_touch
default_screen.bind("<B1-Motion>", screen_touch_drag)   # Binds mouse drag event with function screen_touch
change_mode()

# Start mainloop
default_screen.mainloop()
