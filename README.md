# Implement-OpenCV
The Repository contains some useful code that implements with OpenCV and C++  

I refer to the [Authoritative Code](https://github.com/opencv/opencv),it helps me a lot,and it's also great if you are willing to help me

improve my code,There are more information about the OpenCV on my [CSDN BLOG](http://write.blog.csdn.net/postlist)

# INTRODUCTION

## 1.DftAndIdft.cpp
It's a application of `DFT` and `IDFT`. Firstly, I trnsfer the picture from time domain to frequency domain

by `DFT`, And In frequency domain, process all the pixels,lastly,tansfer the picture back to time domain

by `IDFE`. the original picture I use is the moive,[lalaland 's advertisement](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/lalaland_2.jpg) 

There are more details in :  [detail document about the algorithms](http://blog.csdn.net/baimafujinji/article/details/51724371)

the reslut, source image:

  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/Source%20Image.png)
 


the reslut, Amplitude spectrum:

  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/Amplitude%20spectrum.png) 
 


the reslut, reconstructed image:


  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/reconstructed%20image.png) 


the result, Pro Amplitude spectrum:

  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/Pro%20Amplitude%20spectrum.png) 
  
 
## 2.LinearAndNonLinearFilter.cpp
The cpp file contains three normal `linear Filteres` and two `nonlinear Filteres` ,They are Box Filter\Mean Filter\
 
GaussianFilter\Median Filter and Bilateral Filter，and meanwhile, I creat Track bar for each of them,we could move the 
 
key to adjust the Filteres' function,the filteres are applied in one picture,[another lalaland advertisement](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/LinearAndNonlinearFilter/lalaland_1.jpeg),so we could 
 
compare their function
 
the result, Mean Filter:
 
![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/LinearAndNonlinearFilter/Median.png)
 
the result, Gaussian Filter:
 
![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/LinearAndNonlinearFilter/Gaussian.png)
 
the result, Box Filter:
 
![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/LinearAndNonlinearFilter/BoxFilter.png)
 
the result, Median Filter:
 
![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/LinearAndNonlinearFilter/Median.png)
 
the result,Bilateral Filter:
 
![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/LinearAndNonlinearFilter/Bilateral.png)
 
 ## 3.DrawConvexHull
The code `draw the Convex Hull` of the ['xiaoxin's photo'](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DrawConvexHull/xiaoxin.jpg),I like the cartoon very much, so, I make the result a gif.
 
the code is easy but efficient, it's still welcome to help me improve it, and you could also add some interesting 

elements to it,the code uses convexHull function and findContour function mainly.

the resalut:

![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DrawConvexHull/xiaoxin.gif)
 
 ## 4.EdgeDetected
Here contains Three different kinds of methods for `edge detected`,They are `Canny/Sobel/Scharr`,the pictue I use 

is [Two Horses's picture](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/EdgeDetected/horse.jpg) that I download from Baidu,Put the different effect results here to compare the differences between 

them

the result, Canny:

![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/EdgeDetected/Canny.png)

the result, Sobel:

![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/EdgeDetected/Sobel.png)

the result, Scharr:

![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/EdgeDetected/Scharr.png)

## 5.RotateAndZoom
Here I use a [planet picture](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/EdgeDetected/planet.png) implement the `rotation and zooming`,Firstly,I use the zooming function,and follow by the

rotate funtion,I show the output all in the code, but I just put the last result here, if you are interesting in the middle 

process,you colud run the code in the repositry by yourself

the resutlt, zoom and rotate:

![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/RotateAndZoom/planet_Rotate.png)


## 6.HarrisCorner
The HurrisCorner is a useful and interesting algrithom, I use the function in OpenCV to implement on a ["church picture"](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/HurrisCorner/church.png)

and really, the function has a good effect

the result,HurrisCorner:

![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/HurrisCorner/harricorner.png)

## 7.CircleAndRectObj
The code could use circles and rectangles to wraps the obejects' contours in the ["world map"](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/HurrisCorner/map_1.png),I use the findcontour and 

some other functions in the OpenCV

the result,CircleAndRectObj:

![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/CircleAndRectObej/map.gif)
 
 # CONTRIBUTOR

-----------------------------------------------------------------------
                                        CANTACT CARD
                               Author:     LiangjunFeng
                               Blog:       http://my.csdn.net/Liangjun_Feng
                               E-mail:     zhumavip@163.com
                               School:     zhejiang University
                               Begin from: 2017/8
-----------------------------------------------------------------------
   
