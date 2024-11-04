import tkinter as tk
from ultralytics import YOLO
import cv2
import pygame
import threading
import facebook
from PIL import Image, ImageTk, ImageOps
from Final_V3 import *


def post_image_to_facebook(image_path, message, access_token):
    graph = facebook.GraphAPI(access_token)
    with open(image_path, "rb") as image_file:
        graph.put_photo(image=image_file, message=message)

def start_detection_thread():
    detection_thread = threading.Thread(target=run_detection)
    detection_thread.start()

def picture():
    cap2 = cv2.VideoCapture(1)
    if not cap2.isOpened():
        print("No se pudo abrir la Webcam 2. Verifica el número del dispositivo y la conexión.")
        return
    ret, frame = cap2.read()
    if ret:
        cv2.imwrite("capture_from_webcam_2.png", frame)
        cap2.release()
        add_border_and_images("capture_from_webcam_2.png")
        open_publish_window("capture_with_border.png")
    else:
        print("No se pudo capturar imagen de la Webcam 2")
        cap2.release()

def add_border_and_images(image_path):
    # Abrir la imagen principal
    img = Image.open(image_path)

    # Añadir borde blanco
    border_size = 200  # Tamaño del borde blanco
    img_size = 320
    img_with_white_border = ImageOps.expand(img, border=border_size, fill='white')

    # Cargar y redimensionar imágenes para los bordes conservando la relación de aspecto
    top_img = Image.open('top_image.png').resize((img_with_white_border.width, int(border_size * 1080 / 1080)))  # Relación 1:1
    bottom_img = Image.open('bottom_image.png').resize((img_size, int(img_size * 219 / 409)))  # Manteniendo aspecto
    left_img = Image.open('left_image.png').resize((int(370 * 90 / 199), 370))  # Manteniendo aspecto
    right_img = Image.open('right_image.png').resize((int(img_size * 108 / 184), img_size))  # Manteniendo aspecto

    # Crear una nueva imagen con el mismo tamaño que la imagen con borde blanco
    new_img = Image.new('RGB', (img_with_white_border.width, img_with_white_border.height))
    new_img.paste(img_with_white_border, (0, 0))

    # Calcular las posiciones para pegar las imágenes de borde
    top_x = (new_img.width - top_img.width) // 2
    bottom_x = (new_img.width - bottom_img.width) // 2
    left_y = (new_img.height - left_img.height) // 2
    right_y = (new_img.height - right_img.height) // 2

    # Pegar las imágenes de borde
    new_img.paste(top_img, (top_x, 0), top_img)
    new_img.paste(bottom_img, (bottom_x, new_img.height - bottom_img.height), bottom_img)
    new_img.paste(left_img, (0, left_y), left_img)
    new_img.paste(right_img, (new_img.width - right_img.width, right_y), right_img)

    # Guardar la imagen resultante
    new_img.save("capture_with_border.png")


def open_publish_window(image_path):
    publish_window = tk.Toplevel(root)
    publish_window.attributes('-fullscreen', True)
    publish_window.configure(bg='#6BA4FA')

    img_label = tk.Label(publish_window, bg='#6BA4FA')
    img_label.pack(pady=20)

    # Cargar la imagen desde el archivo
    img_pil = Image.open(image_path)
    img_tk = ImageTk.PhotoImage(image=img_pil)
    
    # Mostrar la imagen en el nuevo frame
    img_label.config(image=img_tk)
    img_label.image = img_tk
    
    button_frame = tk.Frame(publish_window, bg='#6BA4FA')
    button_frame.pack(pady=20)

    publish_button = tk.Button(button_frame, text="Publicar foto", command=publish, width=20, height=5, font=fuente)
    publish_button.pack(side=tk.LEFT, padx=20)

    cancel_button = tk.Button(button_frame, text="Cancelar", command=publish_window.destroy, width=20, height=5, font=fuente)
    cancel_button.pack(side=tk.RIGHT, padx=20)

def publish(save_locally=False):
    if save_locally:
        # Genera un nombre único para la imagen
        from datetime import datetime
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        local_filename = f"local_capture_{timestamp}.png"
        
        # Guarda la imagen localmente
        with open(local_filename, "wb") as local_file:
            with open("capture_with_border.png", "rb") as original_file:
                local_file.write(original_file.read())
        print(f"Imagen guardada como {local_filename}")
    else:
        post_image_to_facebook("capture_with_border.png", message, access_token)


def run_detection():
    cap = cv2.VideoCapture(0)
    model = YOLO('V8.pt')
    sound_paths = [
        'latido.mp3',
        'peace.mp3',
        'punio.mp3',
        'riff.mp3',
        'Hi.mp3'
    ]
    pygame.mixer.init()
    
    while True:
        try:
            class_num = 0
            ret, frame = cap.read()
            if not ret:
                break
            img_name = "webcam_image.png"
            cv2.imwrite(img_name, frame)
            s = 'webcam_image.png'
            results = model.predict(source=s, conf=0.33, imgsz=640)
            if results and results[0].boxes:
                for result in results:
                    for box in result.boxes:
                        class_num = int(box.cls[0].item())
                        if class_num <= 5 or class_num <= 2:
                            
                            pygame.mixer.music.load(sound_paths[class_num])
                            pygame.mixer.music.play()
                        else:
                            print(f"Clase fuera de rango: {class_num}")
                        shape_detected(class_num)
            else:
                pygame.mixer.music.stop()

            cv2.waitKey(3000)

        except Exception as e:
            print(f"Ocurrió un error: {e}")
            pygame.mixer.music.stop()
    
    cap.release()

root = tk.Tk()
fuente = ("Modern No. 20", 45)
save_locally = True
access_token = 'TU_TOKEN_DE_ACCESO'
message = '#DíadelITESO #SofIA'
image_path = 'capture_from_webcam_2.png'
root.title("SofIA")
root.attributes('-fullscreen', True)
root.configure(bg='#6BA4FA')

frame = tk.Frame(root, bg='#6BA4FA')
frame.place(relx=0.5, rely=0.5, anchor=tk.CENTER)

start_button = tk.Button(frame, text="Tomar foto", command=picture, width=20, height=5, font=fuente)
start_button.pack(side=tk.LEFT, padx=20)

#start_detection_thread()

root.mainloop()
