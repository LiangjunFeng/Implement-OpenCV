//-------------------------------------【head file\namesapce declaration】------------------------------
//                         statement:  declare head file and namespace
//-----------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
typedef vector<Point> vec;

//-------------------------------------【public Variables】---------------------------------------------
//                         statement:  declare global variables
//-----------------------------------------------------------------------------------------------------
Mat g_srcImage,g_grayImage;
int g_nThresh = 50;
int g_maxThresh = 255;
RNG g_rng(12345);
Mat srcImage_copy;
Mat g_thresholdImage_ouput;
vector<vec> g_vContours;
vector<Vec4i> g_vHierarchy;

//-------------------------------------【public function】---------------------------------------------
//                         statement:  declare global function
//-----------------------------------------------------------------------------------------------------
static void on_ThreshChange(int,void*);

//--------------------------------------【main()function】----------------------------------------------
//                          statement:    our code run from here
//-----------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]){
	  g_srcImage = imread("/Users/zhuxiaoxiansheng/Desktop/xiaoxin.jpg",1 );
	  cvtColor(g_srcImage,g_grayImage,COLOR_BGR2GRAY);
  	blur(g_grayImage,g_grayImage,Size(3,3));

    namedWindow("srcIamge");
    imshow("srcImage",g_srcImage);
    waitKey();

    namedWindow("show");
    createTrackbar("ThresholdValue:","show",&g_nThresh,g_maxThresh,on_ThreshChange);
    on_ThreshChange(0,0);

    waitKey();
    return(0);

}

//----------------------------------【thresh_callback() function】--------------------------------------
//                          statement:    Thresh's help function
//-----------------------------------------------------------------------------------------------------
static void on_ThreshChange(int,void*){
	  threshold(g_grayImage,g_thresholdImage_ouput,g_nThresh,255,THRESH_BINARY);
	  findContours(g_thresholdImage_ouput,g_vContours,g_vHierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

	  vector<vec> hull(g_vContours.size());
	  for(unsigned int i =0;i < g_vContours.size();i++)
		convexHull(Mat(g_vContours[i]),hull[i],false);
 
  	Mat drawing = Mat::zeros(g_thresholdImage_ouput.size(),CV_8UC3);
	  for(unsigned int i = 0;i<g_vContours.size();i++){
		Scalar color = Scalar(g_rng.uniform(0,255),g_rng.uniform(0,255),g_rng.uniform(0,255));
		drawContours(drawing,g_vContours,i,color,1,8,vector<Vec4i>(),0,Point());
		drawContours(drawing,hull,i,color,1,8,vector<Vec4i>(),0,Point());
	}
	imshow("show",drawing);

}
