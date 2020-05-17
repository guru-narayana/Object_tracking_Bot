import numpy as np
import cv2
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(25,GPIO.OUT)
GPIO.setup(24,GPIO.OUT)
kernel = np.ones((20,20), np.uint8)
vid = cv2.VideoCapture(0)
GPIO.output(18,GPIO.LOW)
GPIO.output(23,GPIO.LOW)
GPIO.output(25,GPIO.LOW)
GPIO.output(24,GPIO.LOW)
# 18 right
# 23 left
# 25 front
# 24 back
while (True):
    # Capture the video frame
    # by frame
    ret, frame = vid.read()
    image = cv2.flip(frame, 1)
    original = image.copy()
    image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    lower = np.array([28, 150, 0], dtype="uint8")
    upper = np.array([54, 255, 255], dtype="uint8")
    mask = cv2.inRange(image, lower, upper)
    opening = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
    contours = cv2.findContours(opening, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    cnt = contours[0]
    x,y,w,h = cv2.boundingRect(cnt)
    cv2.rectangle(original,(x,y),(x+w,y+h),(255,0,0),2)
    area = (x+w)*(y+h)
    center = (int((2*x+w)/2),int((2*y+h)/2))
    cv2.circle(original,center,9,(0,0,255),2)
    if not (area == 0):
        if center[0] < 150:
            GPIO.output(18,GPIO.HIGH)
            time.sleep(0.001)
            GPIO.output(18,GPIO.LOW)
        if 150<center[0]<450:
            GPIO.output(18,GPIO.LOW)
            GPIO.output(23,GPIO.LOW)
        if center[0] > 450:
            GPIO.output(23,GPIO.HIGH)
            time.sleep(0.001)
            GPIO.output(23,GPIO.LOW)
        if area > 150000:
            print("0")
            GPIO.output(24,GPIO.HIGH)
            time.sleep(0.001)
            GPIO.output(24,GPIO.LOW)
        if area < 150000:
            print("1")
            GPIO.output(25,GPIO.HIGH)
            time.sleep(0.001)
            GPIO.output(25,GPIO.LOW)
    else:
        GPIO.output(18,GPIO.LOW)
        GPIO.output(23,GPIO.LOW)
        GPIO.output(25,GPIO.LOW)
        GPIO.output(24,GPIO.LOW)
    cv2.imshow("guru",original)
    cv2.imshow('mask', opening)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
GPIO.output(18,GPIO.LOW)
vid.release()
# Destroy all the windows
cv2.destroyAllWindows()
