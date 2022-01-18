import cv2 as cv
from cvzone.FaceDetectionModule import FaceDetector
from cvzone.SerialModule import SerialObject

arduino = SerialObject("COM8")
capture= cv.VideoCapture(0)
detector = FaceDetector()


while True:
    isTrue, img=capture.read()
    img,bboxs = detector.findFaces(img)

    if(bboxs):
        arduino.sendData([1])
    else:
        arduino.sendData([0])

    cv.imshow('LIVE',img)
    if cv.waitKey(1) & 0xFF==27:
        break


