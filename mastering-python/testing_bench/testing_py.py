import cv2
import time
import os
import urllib.request
import mediapipe as mp
from mediapipe.tasks import python
from mediapipe.tasks.python import vision

# 1. Download Google's standard Object Detection model (EfficientDet-Lite0)
model_path = "efficientdet_lite0.tflite"
if not os.path.exists(model_path):
    print("Downloading Object Detection model...")
    url = "https://storage.googleapis.com/mediapipe-models/object_detector/efficientdet_lite0/int8/1/efficientdet_lite0.tflite"
    urllib.request.urlretrieve(url, model_path)
    print("Download complete!")

# 2. Configure the Object Detector
base_options = python.BaseOptions(model_asset_path=model_path)
options = vision.ObjectDetectorOptions(
    base_options=base_options,
    running_mode=vision.RunningMode.VIDEO,
    max_results=3, # Maximum number of objects to detect at once
    score_threshold=0.5 # Only show objects it is 50%+ confident about
)
detector = vision.ObjectDetector.create_from_options(options)

# 3. Open webcam and process frames
cap = cv2.VideoCapture(0)
last_timestamp_ms = 0

while cap.isOpened():
    success, frame = cap.read()
    if not success:
        break
    
    # We do not flip this frame horizontally so text on objects remains readable
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_frame)
    
    # Ensure timestamp strictly increases
    timestamp_ms = int(time.time() * 1000)
    if timestamp_ms <= last_timestamp_ms:
        timestamp_ms = last_timestamp_ms + 1
    last_timestamp_ms = timestamp_ms
    
    # Detect objects
    results = detector.detect_for_video(mp_image, timestamp_ms)
    
    # Process and draw bounding boxes
    if results.detections:
        for detection in results.detections:
            # Get bounding box coordinates
            bbox = detection.bounding_box
            start_point = (int(bbox.origin_x), int(bbox.origin_y))
            end_point = (int(bbox.origin_x + bbox.width), int(bbox.origin_y + bbox.height))
            
            # Draw rectangle around the object
            cv2.rectangle(frame, start_point, end_point, (0, 255, 0), 2)
            
            # Get category name and probability score
            category = detection.categories[0]
            category_name = category.category_name
            probability = round(category.score * 100, 1)
            
            # Display text above the bounding box
            result_text = f"{category_name} ({probability}%)"
            cv2.putText(frame, result_text, (start_point[0], start_point[1] - 10), 
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)

    cv2.imshow('Object Detection', frame)
    
    if cv2.waitKey(5) & 0xFF == 27: # Press 'Esc' to exit
        break

cap.release()
cv2.destroyAllWindows()