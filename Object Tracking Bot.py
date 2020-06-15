import numpy as np
import cv2
import time
from control import writenumber
kernel = np.ones((20,20), np.uint8)
kernel1 = np.ones((40,40), np.uint8)
vid = cv2.VideoCapture(0)
while (True):
    center = ()
    ret, frame = vid.read()
    image = cv2.flip(frame, 1)
    original = image.copy()
    image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    lower = np.array([20, 100, 100], dtype="uint8")
    upper = np.array([50, 255, 255], dtype="uint8")
    mask = cv2.inRange(image, lower, upper)
    opening = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
    closed = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel1)
    contours = cv2.findContours(closed, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    cnt = contours[0]
    x,y,w,h = cv2.boundingRect(cnt)
    cv2.rectangle(original,(x,y),(x+w,y+h),(255,0,0),2)
    area = (x+w)*(y+h)
    center = (int((2*x+w)/2),int((2*y+h)/2))
    cv2.circle(original,center,9,(0,0,255),2)
    if not (area == 0):
        if center[0] < 150:
            writenumber(3)
            time.sleep(0.001)
            writenumber(0)
        if 150<center[0] and center[0]<450:
            writenumber(0)
        if center[0] > 450:
            writenumber(4)
            time.sleep(0.001)
            writenumber(0)
        if area > 200000:
            writenumber(2)
            time.sleep(0.001)
            writenumber(0)
        if area < 150000:
            writenumber(1)
            time.sleep(0.001)
            writenumber(0)
        if area < 200000 and area > 150000:
            writenumber(0)
    else:
       writenumber(0) 
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
vid.release()
cv2.destroyAllWindows()
