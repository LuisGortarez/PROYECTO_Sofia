import tkinter as tk
from ultralytics import YOLO
import cv2
import pygame
import threading
import facebook
from PIL import Image, ImageTk  # Importar PIL

def post_image_to_facebook(image_path, message, access_token):
    # Crear el objeto de GraphAPI
    graph = facebook.GraphAPI(access_token)
    
    # Leer la imagen
    with open(image_path, "rb") as image_file:
        # Publicar la imagen con un mensaje
        graph.put_photo(image=image_file, message=message)

def start_detection_thread():
    detection_thread = threading.Thread(target=run_detection)
    detection_thread.start()

def picture():
    cap2 = cv2.VideoCapture(1)
    print("Tomar foto")
    if not cap2.isOpened():
        print("No se pudo abrir la Webcam 2. Verifica el número del dispositivo y la conexión.")
        return
    ret, frame = cap2.read()
    if ret:
        cv2.imwrite("capture_from_webcam_2.png", frame)
        cap2.release()
        open_publish_window(frame)
    else:
        print("No se pudo capturar imagen de la Webcam 2")
        cap2.release()

def open_publish_window(image):
    publish_window = tk.Toplevel(root)
    publish_window.attributes('-fullscreen', True)
    publish_window.configure(bg='#6BA4FA')

    img_label = tk.Label(publish_window, bg='#6BA4FA')
    img_label.pack(pady=20)

    # Convertir la imagen a un formato adecuado para Tkinter
    img_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    img_pil = Image.fromarray(img_rgb)
    img_tk = ImageTk.PhotoImage(image=img_pil)
    
    # Mostrar la imagen en el nuevo frame
    img_label.config(image=img_tk)
    img_label.image = img_tk
    
    button_frame = tk.Frame(publish_window, bg='#6BA4FA')
    button_frame.pack(pady=20)

    publish_button = tk.Button(button_frame, text="Publicar foto", command=publish, width=20, height=5)
    publish_button.pack(side=tk.LEFT, padx=20)

    cancel_button = tk.Button(button_frame, text="Cancelar", command=publish_window.destroy, width=20, height=5)
    cancel_button.pack(side=tk.RIGHT, padx=20)

def publish():
    print("¡Vamos a publicar la foto!")
    post_image_to_facebook(image_path, message, access_token)

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
            if results and results[0].boxes:  # Verifica si hay detecciones
                for result in results:
                    for box in result.boxes:
                        class_num = int(box.cls[0].item())  # Convierte el número de clase a entero
                        if class_num <= 5:
                            print(f"Reproduciendo sonido para clase {class_num}")
                            pygame.mixer.music.load(sound_paths[class_num])  # Carga el sonido correspondiente
                            pygame.mixer.music.play()
                        else:
                            print(f"Clase fuera de rango: {class_num}")
            else:
                pygame.mixer.music.stop()  # Detén cualquier sonido si no hay detecciones

            cv2.waitKey(3000)  # Espera un tiempo corto para continuar con la siguiente iteración

        except Exception as e:
            print(f"Ocurrió un error: {e}")
            pygame.mixer.music.stop()  # Asegura que se detenga la música en caso de error
    
    cap.release()

# Configuración de la interfaz gráfica
root = tk.Tk()
access_token = 'TU_TOKEN_DE_ACCESO'
message = '#DíadelITESO #SofIA'
image_path = 'capture_from_webcam_2.png'
root.title("SofIA")
root.attributes('-fullscreen', True)  # Ventana de pantalla completa
root.configure(bg='#6BA4FA')  # Fondo de color #6BA4FA

# Crear un frame para centrar los botones
frame = tk.Frame(root, bg='#6BA4FA')
frame.place(relx=0.5, rely=0.5, anchor=tk.CENTER)

start_button = tk.Button(frame, text="Tomar foto", command=picture, width=20, height=5)
start_button.pack(side=tk.LEFT, padx=20)

# Iniciar la detección en un hilo separado
start_detection_thread()

root.mainloop()
