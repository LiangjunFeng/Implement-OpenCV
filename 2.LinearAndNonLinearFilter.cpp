//-------------------------------------【head file\namesapce declaration】------------------------------
//                         statement:  declare head file and namespace
//-----------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

//-------------------------------------【public Variables】---------------------------------------------
//                         statement:  declare global variables
//-----------------------------------------------------------------------------------------------------
Mat g_srcImage,g_dstImage1,g_dstImage2,g_dstImage3,g_dstImage4,g_dstImage5;
int g_nBoxFilterValue = 3;
int g_nMeanBlurValue = 3;
int g_nGaussianBlurValue = 3;
int g_nMedianBlurValue = 10;
int g_nBilateralFilterValue = 10;

//-------------------------------------【public function】---------------------------------------------
//                         statement:  declare global function
//-----------------------------------------------------------------------------------------------------
static void on_BoxFilter(int,void*);
static void on_MeanBlur(int,void*);
static void on_GaussianBlur(int,void*);
static void on_MedianBlur(int,void *);
static void on_BilateralFilter(int,void *);

//--------------------------------------【main()function】----------------------------------------------
//                          statement:    our code run from here
//-----------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]){
    g_srcImage = imread("/Users/zhuxiaoxiansheng/Desktop/lalaland_1.jpeg",1 );
	resize(g_srcImage,g_srcImage,Size(1000,640));

    g_dstImage1 = g_srcImage.clone();
    g_dstImage2 = g_srcImage.clone();
    g_dstImage3 = g_srcImage.clone();

    namedWindow("【<0>original window】",1);
    imshow("【<0>original window】",g_srcImage);
    waitKey();

    //==========================================【<1>BoxFilter】========================================
    namedWindow("【<1>BoxFilter】",1);
    createTrackbar("<1>BoxFilter Kernal Value : ","【<1>BoxFilter】", &g_nBoxFilterValue,50,on_BoxFilter);
    on_BoxFilter(g_nBoxFilterValue,0);
    //=================================================================================================

    while(char(waitKey(1))!='q'){}

    //==========================================【<2>MeanFilter】=======================================
    namedWindow("【<2>MeanFilter】",1);
    createTrackbar("<2>MeanFilter Kernal Value : ","【<2>MeanFilter】", &g_nMeanBlurValue,50,on_MeanBlur);
    on_MeanBlur(g_nMeanBlurValue,0);
    //=================================================================================================

    while(char(waitKey(1))!='q'){}

    //==========================================【<3>GaussianFilter】===================================
    namedWindow("【<3>GaussianFilter】",1);
    createTrackbar("<3>GaussianFilter Kernal Value : ","【<3>GaussianFilter】", &g_nGaussianBlurValue,50,on_GaussianBlur);
    on_GaussianBlur(g_nGaussianBlurValue,0);
    //=================================================================================================

    while(char(waitKey(1))!='q'){}

    //==========================================【<4>MedianFilter】===================================
    namedWindow("【<4>MedianFilter】",1);
    createTrackbar("<4>MedianFilter Kernal Value : ","【<4>MedianFilter】", &g_nMedianBlurValue,50,on_MedianBlur);
    on_MedianBlur(g_nMedianBlurValue,0);
    //=================================================================================================

    while(char(waitKey(1))!='q'){}

    //==========================================【<5>BilateralFilter】===================================
    namedWindow("【<5>BilateralFilter】",1);
    createTrackbar("<5>BilateralFilter Kernal Value : ","【<5>BilateralFilter】", &g_nBilateralFilterValue,50,on_BilateralFilter);
    on_BilateralFilter(g_nBilateralFilterValue,0);
    //=================================================================================================

    while(char(waitKey(1))!='q'){}

    return 0;

}

//----------------------------------【on_BoxFilter() function】-----------------------------------------
//                          statement:    BoxFilter's help function
//-----------------------------------------------------------------------------------------------------
static void on_BoxFilter(int, void *){
	boxFilter(g_srcImage,g_dstImage1,-1,Size(g_nBoxFilterValue+1,g_nBoxFilterValue+1));
	imshow("【<1>BoxFilter】",g_dstImage1);
}

//----------------------------------【on_MeanBlur() function】-----------------------------------------
//                          statement:    MeanFilter's help function
//-----------------------------------------------------------------------------------------------------
static void on_MeanBlur(int, void *){
	blur(g_srcImage,g_dstImage2,Size(g_nMeanBlurValue+1,g_nMeanBlurValue+1),Point(-1,-1));
	imshow("【<2>MeanFilter】",g_dstImage2);
}

//----------------------------------【on_GaussianBlur() function】--------------------------------------
//                          statement:    GaussianFilter's help function
//-----------------------------------------------------------------------------------------------------
static void on_GaussianBlur(int, void *){
	GaussianBlur(g_srcImage,g_dstImage3,Size(g_nGaussianBlurValue*2+1,g_nGaussianBlurValue*2+1),0,0);
	imshow("【<3>GaussianFilter】",g_dstImage3);
}

//----------------------------------【on_MedianBlur() function】----------------------------------------
//                          statement:    MedianFilter's help function
//-----------------------------------------------------------------------------------------------------
static void on_MedianBlur(int, void *){
	medianBlur(g_srcImage,g_dstImage4,g_nMedianBlurValue*2+1);
	imshow("【<4>MedianFilter】",g_dstImage4);
}

//----------------------------------【on_BilateralFilter() function】-----------------------------------
//                          statement:    BilateralFilter's help function
//-----------------------------------------------------------------------------------------------------
static void on_BilateralFilter(int, void *){
	bilateralFilter(g_srcImage,g_dstImage5,g_nBilateralFilterValue,g_nBilateralFilterValue*2,g_nBilateralFilterValue/2);
	imshow("【<5>BilateralFilter】",g_dstImage5);
}

