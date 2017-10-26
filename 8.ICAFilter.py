import numpy as np
import cv2 as cv
from sklearn import preprocessing
from numpy import random
import math

def LoadPicture(path):                   #Load the picture's data ,and reshape it
    img = cv.imread(path,0)
    img = cv.resize(img,(300,300))
    return img

def addSaltyNoise(image,count = 1000):                 #add salty noise on the picture , and meanwhile  
    img = image.copy()                                 #create another two pictues,one for ica,one for comparing
    img2 = np.zeros((img.shape[0],img.shape[1]))
    img3 = image.copy()
    coutn = count
    for k in range(coutn):
        xi = int(np.random.uniform(0,img.shape[1]))
        xj = int(np.random.uniform(0,img.shape[0]))
        if img.ndim == 2:
            img[xj,xi] = 255
            img2[xj,xi] = 255
            img3[xj,xi] = 0
        elif img.ndim == 3:
            img[xj,xi,0] = 255
            img[xj,xi,1] = 255
            img[xj,xi,2] = 255
    return img,img2,img3

def show(name,img):                       #show a picture
    cv.namedWindow(name)
    cv.imshow(name,img)
    cv.waitKey()

def close():                             #close all the pictures
    cv.destroyAllWindows()
    cv.waitKey(1)
    
def normalize(image):                    #normalize the picture that have been processed to unit8 type
    img = image.copy()
    img -= img.min()
    img /= img.max()
    img = img*255
    img = img.astype(np.uint8)
    return img

def mFilter(image):                      #show the result of some other filters
    img = image.copy()
    kernel = np.ones((5,5),np.float32)/25
    c = cv.filter2D(img,-1,kernel)
    d = cv.blur(img,(3,5))
    e = cv.bilateralFilter(img,9,75,75)
    f = cv.GaussianBlur(img,(5,5),0)
    show('org',img)
    show('box',c)
    show('blur',d)
    show('bilateral',e)
    show('Gauss',f)
    
def showICA(dataS,length,bordth):         #show the results of ica
    a = dataS[:,0].reshape(length,bordth)
    b = dataS[:,1].reshape(length,bordth)
    a = normalize(a)
    b = normalize(b)
    c = a-b
    show('isolateb',a)
    show('isolatea',b)
    show('minus',c)
    
def transferToMatrix(image1,image2,length,bordth):      #make matrix from two pictures
    data = []    
    a = image1.reshape(length*bordth,1)
    a = (np.ravel(a)).tolist()
    data.append(a)
    
    b = image2.reshape(length*bordth,1)
    b = (np.ravel(b)).tolist()
    data.append(b)  
    
    data = np.mat(data)  
    return data

def getRandomW(length):                                 #creat a square matrix
    W = random.random(size=(length,length))
    return W

def GFunction(data):                                    #the first derivate function
    def G(x):
        y = x*math.exp(-0.5*(x**2))
        return y
    length,bordth = data.shape
    output = np.zeros((length,bordth))
    for i in range(length):
        for j in range(bordth):
            output[i,j] = G(data[i,j])
    return output

def gFunction(data):                                  #the second derivate function
    def g(x):
        y = -1*(x**2)*math.exp(-0.5*(x**2))
        return y
    length,bordth = data.shape
    output = np.zeros((length,bordth))
    for i in range(length):
        for j in range(bordth):
            output[i,j] = g(data[i,j])
    return output   

def distance(W,oldW):                                 #compare the differences between two pictures
    length = len(W)
    t = 0.
    for i in range(length):
        t += abs(float(W[i]) - float(oldW[i]))
    return t  

def eigOrth(data):                                    #orthogonalization
    data = np.mat(preprocessing.scale(data.T).T)
    D,E = np.linalg.eig(data.dot(data.T))
    D = np.diag(D**(-0.5))
    data = E*D*E.T*data
    return data

if __name__ == '__main__':
#load the picture,convert it to n*2's matrix,init W
#====================================================================
    path = "/Users/zhuxiaoxiansheng/Desktop/Lena.png"
    image = LoadPicture(path)
    length,bordth = image.shape
    imageSalty,virtualSalty,comp = addSaltyNoise(image,5000)
    data = transferToMatrix(imageSalty,virtualSalty,length,bordth)
    data = eigOrth(data)
    W = getRandomW(data.shape[0])
    W = eigOrth(W)


#Figure out W using Newton's method
#====================================================================
    MAX_T = 10000
    for i in range(W.shape[0]):
        j,t,w = 0,1,W[:,i]
        while j < MAX_T and t > 5e-14:
            oldw = w.copy()
            for k in range(W.shape[1]):
                w[k] = np.mean(np.multiply(data[k,:],GFunction(w.T*data)))-np.mean(np.multiply(gFunction(w.T*data),w[k]))
            temp = np.zeros((W.shape[0],1))
            for k in range(i):
                temp += float(w.T*W[:,k])*W[:,k]
            w = w - temp
            w = w/math.sqrt(w.T*w)
            W[:,i] = w
            t = distance(W[:,i],oldw)
            print(t)
            j += 1
    dataS = (W.T.dot(data)).T
    
#compare the reslut with other method  
#====================================================================
    show('org',image)
    show('salty',imageSalty)
    show('compare',comp)
    showICA(dataS,length,bordth)   
    mFilter(imageSalty)
    close()
