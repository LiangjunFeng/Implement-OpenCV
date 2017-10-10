//-------------------------------------【head file\namesapce declaration】------------------------------
//                         statement:  declare head file and namespace
//-----------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

//--------------------------------------【main()function】----------------------------------------------
//                          statement:    our code run from here
//-----------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]){
	Mat srcImage = imread("/Users/zhuxiaoxiansheng/Desktop/church.jpg",0);
	imshow("srcImage",srcImage);
	waitKey();

	Mat cornerStrength;
	cornerHarris(srcImage,cornerStrength,2,3,0.01);

	Mat harrisCorner;
	threshold(cornerStrength,harrisCorner,0.00001,255,THRESH_BINARY);
	imshow("show",harrisCorner);
	waitKey();

	return(0);
}
