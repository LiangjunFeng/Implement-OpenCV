//-------------------------------------【head file\namesapce declaration】------------------------------
//                         statement:  declare head file and namespace
//-----------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;


//-------------------------------------【public Variables】---------------------------------------------
//                         statement:  declare global variables
//-----------------------------------------------------------------------------------------------------
Mat g_srcImage,g_srcGrayImage,g_dstImage;

Mat g_cannyDetectedEdges;
int g_cannyLowThreshold = 1;

Mat g_sobelGradient_X,g_sobelGradient_Y;
Mat g_sobelAbsGradient_X,g_sobelAbsGrandient_Y;
int g_sobelKernelSize = 1;

Mat g_scharrGradient_X,g_scharrGradient_Y;
Mat g_scharrAbsGradient_X,g_scharrAbsGradient_Y;

//-------------------------------------【public function】---------------------------------------------
//                         statement:  declare global function
//-----------------------------------------------------------------------------------------------------
static void on_Canny(int,void*);
static void on_Sobel(int,void*);
void Scharr();

//--------------------------------------【main()function】----------------------------------------------
//                          statement:    our code run from here
//-----------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]){
    g_srcImage = imread("/Users/zhuxiaoxiansheng/Desktop/horse.jpg",1 );

    namedWindow("【srcIamge】");
    imshow("【srcIamge】",g_srcImage);
    waitKey();

    g_dstImage.create(g_srcImage.size(),g_srcImage.type());
    cvtColor(g_srcImage,g_srcGrayImage,COLOR_BGR2GRAY);

    //======================================【CannyDetectedEdges】========================================
    namedWindow("CannyDetectedEdges");
    createTrackbar("Canny","CannyDetectedEdges",&g_cannyLowThreshold,120,on_Canny);
    on_Canny(0,0);
    while((char)(waitKey(1)!='q')){}
    //===================================================================================================

    //======================================【SobelDetectedEdges】========================================
    namedWindow("SobelDetectedEdges");
    createTrackbar("Sobel","SobelDetectedEdges",&g_sobelKernelSize,3,on_Sobel);
    on_Sobel(0,0);
    while((char)(waitKey(1)!='q')){}
    //===================================================================================================

    //=====================================【Scharr()function】==========================================
    namedWindow("Scharr");
    Scharr();
    while((char)(waitKey(1)!='q')){}
    //===================================================================================================
    	    return 0;

}


//----------------------------------【on_Canny() function】--------------------------------------------
//                          statement:    canny detected edge's help function
//-----------------------------------------------------------------------------------------------------
static void on_Canny(int, void *){
	blur(g_srcGrayImage,g_cannyDetectedEdges,Size(3,3));
	Canny(g_cannyDetectedEdges,g_cannyDetectedEdges,g_cannyLowThreshold,g_cannyLowThreshold*3,3);
	g_dstImage = Scalar::all(0);
	g_srcImage.copyTo(g_dstImage,g_cannyDetectedEdges);
	imshow("CannyDetectedEdges",g_dstImage);
}

//----------------------------------【Sobel() function】----------------------------------------------
//                        statement:    sobel detected edge's help function
//-----------------------------------------------------------------------------------------------------
static void on_Sobel(int, void *){
	Sobel(g_srcImage,g_sobelGradient_X,CV_16S,1,0,(2*g_sobelKernelSize+1),1,1,BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_X,g_sobelAbsGradient_X);
	Sobel(g_srcImage,g_sobelGradient_Y,CV_16S,1,0,(2*g_sobelKernelSize+1),1,1,BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_Y,g_sobelAbsGrandient_Y);

	addWeighted(g_sobelAbsGradient_X,0.5,g_sobelAbsGrandient_Y,0.5,0,g_dstImage);
    imshow("SobelDetectedEdges",g_dstImage);
}

//----------------------------------【Scharr()  function】--------------------------------------------
//                          statement:    using Scharr method to detected edge
//-----------------------------------------------------------------------------------------------------
void Scharr(){
	Scharr(g_srcImage,g_scharrGradient_X,CV_16S,1,0,1,BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_X,g_scharrAbsGradient_X);

	Scharr(g_srcImage,g_scharrGradient_Y,CV_16S,1,0,1,BORDER_DEFAULT);
	convertScaleAbs(g_scharrGradient_Y,g_scharrAbsGradient_Y);

	addWeighted(g_scharrAbsGradient_X,0.5,g_scharrAbsGradient_Y,0.5,0,g_dstImage);
	imshow("Scharr",g_dstImage);
}
