from cvzone.SerialModule import SerialObject
from cv2 import rectangle
from cvzone.HandTrackingModule import HandDetector
import cv2 as cv
import math

def size(num):
    n=0
    while num:
        n += 1
        num=int(num/10)
    return n

arduino = SerialObject("COM4")
cap = cv.VideoCapture(0)
cap.set(3, 1280)
cap.set(4, 720)
min= 20
max= 300
detector = HandDetector(maxHands=1,detectionCon=0.8)


while True:
    isTrue, img = cap.read()
  #  hands, img = detector.findHands(img)
  #  img = cv.flip(img,1)
    hands = detector.findHands(img, draw= False)
    if len(hands):

        thumb_tip =tuple(hands[0].get('lmList')[4])
        index_tip =tuple( hands[0].get('lmList')[8])
        xc = int(( thumb_tip[0] + index_tip[0] ) / 2 )
        yc = int(( thumb_tip[1] + index_tip[1] ) / 2 )
        mid_tips = ( xc , yc )
        cv.line(img, thumb_tip , index_tip ,  (255,255,255), thickness = 3)

        cv.circle(img,thumb_tip,9,(0,255,0),thickness=-1)
        cv.circle(img,index_tip,9,(0,255,0),thickness=-1)
        cv.circle(img,mid_tips,9,(0,255,0),thickness=-1)

        dist = int(math.dist(list(thumb_tip),list(index_tip)))
        cv.putText(img,"Distance:"+str(dist), (20,40), cv.FONT_HERSHEY_TRIPLEX , 1.0 , (100,120,200), thickness =2)

        cv.rectangle(img,(40,180),(90,540), (0,255,0), thickness=3)

        map_max = int((280/360 ) * dist)
        if 537 - map_max < 183:
          fill_rect = 183
        else:
          fill_rect = 537 - map_max
        cv.rectangle(img, (43,fill_rect),(87,537), (0,255,0) ,thickness=-1)
        distance = int(((dist - 20)/ 520) *255)
        
        arduino.sendData([distance])


    else:
        arduino.sendData([0])
    
    cv.imshow('Image',img)
    if cv.waitKey(1) & 0xFF == 27:
        arduino.sendData([000])
        break
    