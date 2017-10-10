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
Mat g_srcImage,g_grayImage;
int g_nThresh = 200;
int g_nMaxThresh = 255;
RNG g_rng(12345);

//-------------------------------------【public function】---------------------------------------------
//                         statement:  declare global function
//-----------------------------------------------------------------------------------------------------
static void on_ContoursChange(int,void*);

//--------------------------------------【main()function】----------------------------------------------
//                          statement:    our code run from here
//-----------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]){
	g_srcImage = imread("/Users/zhuxiaoxiansheng/Desktop/map_1.png");
	resize(g_srcImage,g_srcImage,Size(g_srcImage.cols*0.5,g_srcImage.rows*0.5));
	cvtColor(g_srcImage,g_grayImage,COLOR_BGR2GRAY);
	blur(g_grayImage,g_grayImage,Size(3,3));
    imshow("srcImage",g_srcImage);
    waitKey();

	namedWindow("show",WINDOW_AUTOSIZE);
    createTrackbar("ThresholdValue: ","show",&g_nThresh,g_nMaxThresh,on_ContoursChange);
    on_ContoursChange(0,0);
    waitKey();

    return(0);
}

//----------------------------------【on_ContoursChange() function】--------------------- --------------
//                          statement:      help function
//-----------------------------------------------------------------------------------------------------
static void on_ContoursChange(int,void*){
	Mat threshold_output;
	vector<vector<Point> >  contours;
	vector<Vec4i> hierarchy;

	threshold(g_grayImage,threshold_output,g_nThresh,255,THRESH_BINARY);

	findContours(threshold_output,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());
	vector<Point2f> center(contours.size());
	vector<float>radius(contours.size());

	for (int i = 0;i < contours.size();i++){
		approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
		boundRect[i] = boundingRect(Mat(contours_poly[i]));
		minEnclosingCircle(contours_poly[i],center[i],radius[i]);
	}

	Mat drawing = Mat::zeros(threshold_output.size(),CV_8UC3);
	for(int i = 0 ; i < contours.size(); i++){
		Scalar color = Scalar(g_rng.uniform(0,255),g_rng.uniform(0,255),g_rng.uniform(0,255));
		drawContours(drawing,contours_poly,i,color,1,8,vector<Vec4i>(),0,Point());
		rectangle(drawing,boundRect[i].tl(),boundRect[i].br(),color,2,8,0);
		circle(drawing,center[i],(int)radius[i],color,2,8,0);
	}

	imshow("show",drawing);

}
