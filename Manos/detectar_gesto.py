from ultralytics import YOLO
import matplotlib.pyplot as plt
import cv2
from IPython.display import display, Image 

# Cargar el modelo YOLOv5 preentrenado
model = YOLO('V8_huevuda.pt')

s = 0
#s = 'C:\Manos te van a faltar\images'

# Hacer predicciones
results = model.predict(source=s, conf=0.33, imgsz=640)

print("si baja")

# Mostrar los resultados con bounding boxes
if (s != 0):
    for result in results:
        img = cv2.imread(result.path)
        for box in result.boxes:
            # Pasar el tensor a variables
            x1, y1, x2, y2 = map(int, box.xyxy[0].tolist())
            label = result.names[box.cls[0].item()] 
            confidence = box.conf[0].item() 
            cv2.rectangle(img, (x1, y1), (x2, y2), (0, 255, 0), 2)
            cv2.putText(img, f'{label} {confidence:.2f}', (x1, y1 - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0, 255, 0), 2)
        plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
        plt.axis('off')
        plt.show()
