from ultralytics import YOLO
import matplotlib.pyplot as plt
import cv2
from IPython.display import display, Image 
import pygame

cap = cv2.VideoCapture(0)
model = YOLO('V8_huevuda.pt')
default_image_path = 'C:\\Manos te van a faltar\\corazon.jpg'
sound_path = 'C:\\Manos te van a faltar\\732943__moodyfingers__hand-crank-music-box-g5-note.flac'
pygame.mixer.init()

while True:
    ret, frame = cap.read()
    img_name = "webcam_image.png"
    cv2.imwrite(img_name, frame)
    s = 'C:\\Manos te van a faltar\\webcam_image.png'
    results = model.predict(source=s, conf=0.33, imgsz=640)
    
    if results and results[0].boxes:  # Verifica si hay detecciones
        for result in results:
            img = cv2.imread(result.path)
            for box in result.boxes:
                x1, y1, x2, y2 = map(int, box.xyxy[0].tolist())
                label = result.names[box.cls[0].item()] 
                confidence = box.conf[0].item() 
                cv2.rectangle(img, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.putText(img, f'{label} {confidence:.2f}', (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
            cv2.namedWindow('Image', cv2.WND_PROP_FULLSCREEN)
            cv2.setWindowProperty('Image', cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
            pygame.mixer.music.load(sound_path)
            pygame.mixer.music.play()
            cv2.imshow('Image', img)
    else:
        img = cv2.imread(default_image_path)
        cv2.namedWindow('Image', cv2.WND_PROP_FULLSCREEN)
        cv2.setWindowProperty('Image', cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
        cv2.imshow('Image', img)
    
    cv2.waitKey(3000)  # Espera 3 segundos
    cv2.destroyAllWindows()  # Cierra la ventana después de 3 segundos
