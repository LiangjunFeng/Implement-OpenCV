# Implement-OpenCV
The Repository contains some useful code that implements with OpenCV and C++  

I refer to the [Authoritative Code](https://github.com/opencv/opencv),it helps me a lot,and it's also great if you are willing to help me

improve my code,There are more information about the OpenCV on my [CSDN BLOG](http://write.blog.csdn.net/postlist)

# INTRODUCTION

## 1.DftAndIdft.cpp
It's a application of `DFT` and `IDFT`. Firstly, I trnsfer the picture from time domain to frequency domain

by `DFT`, And In frequency domain, process all the pixels,lastly,tansfer the picture back to time domain

by `IDFE`. the original picture I use is the moive,[lalaland 's advertisement](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/lalaland_2.jpg) 

the reslut, source image:

  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/Source%20Image.png)
 


the reslut, Amplitude spectrum:

  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/Amplitude%20spectrum.png) 
 


the reslut, reconstructed image:


  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/reconstructed%20image.png) 


the result, Pro Amplitude spectrum:

  
  ![](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DftAndIdft/Pro%20Amplitude%20spectrum.png) 
  
 
 ## 1.LinearAndNonLinearFilter.cpp
 the cpp file contains three normal `linear Filteres` and two `nonlinear Filteres` ,They are Box Filter\Mean Filter\
 
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
 the code `draw the Convex Hull` of the ['xiaoxin'](https://github.com/LiangjunFeng/Implement-OpenCV/blob/master/Picture/DrawConvexHull/xiaoxin.jpg),I like the cartoon very much, so, I make the result a gif.
 
the code is easy but efficient, it's still welcome to help me improve it, and you could also add some interesting 

elements to it,the code uses convexHull function and findContour function mainly.

the resalut:


 
 
 
 # CONTRIBUTOR

-----------------------------------------------------------------------
                                        CANTACT CARD
                               Author:     LiangjunFeng
                               Blog:       http://my.csdn.net/Liangjun_Feng
                               E-mail:     zhumavip@163.com
                               School:     zhejiang University
                               Begin from: 2017/8
-----------------------------------------------------------------------
  
