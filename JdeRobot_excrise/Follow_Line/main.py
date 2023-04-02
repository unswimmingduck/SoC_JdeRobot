from GUI import GUI
from HAL import HAL
import cv2 as cv
import numpy as np
# Enter sequential code!

keneral = np.ones((4,4))
pre_erro = 0
acc_erro = 0
lowest_thresh = np.array([0, 43, 46])
top_thresh = np.array([26,255,255])
Kp = 0.91
Ki = 0.000000002
Kd = 0.777
D_iter = 5
E_iter = 1

HAL.setV(4)
while True:
    # Enter iterative code!
    img = HAL.getImage()
    height, width, channel = img.shape

    # image process to make the imgae more smooth so that we can obtain more information
    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
    blur = cv.GaussianBlur(hsv, (5,5), 0)

    # detect the color of line
    res = cv.inRange(blur, lowest_thresh, top_thresh)
    d = cv.dilate(res, kernel=keneral, iterations=D_iter)
    e = cv.erode(d, kernel=keneral, iterations=E_iter)

    # caculate the center of the line
    m = cv.moments(e)
    cx = int(m['m10']/m['m00'])
    cy = int(m['m01']/m['m00'])

    a = float((m['m20']/m['m00']) - cx*cx)
    b = float((m['m11']/m['m00']) - cx*cy)
    c = float((m['m02']/m['m00']) - cy*cy)

    theta = cv.fastAtan2(b*2, a-c)/2
    
    # position PID control

    cur_erro = -(cx - width/2)/300
    angular = Kp*(cur_erro) + Ki* acc_erro+ Kd*(cur_erro -  pre_erro)
  
    pre_erro = cur_erro
    acc_erro = acc_erro + cur_erro
    
    
    HAL.setW(angular)
    
    GUI.showImage(img)