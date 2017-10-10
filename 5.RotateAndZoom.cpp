//-------------------------------------【head file\namesapce declaration】------------------------------
//                         statement:  declare head file and namespace
//-----------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//--------------------------------------【main()function】----------------------------------------------
//                          statement:    our code run from here
//-----------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]){
	Point2f srcTriangle[3];
	Point2f dstTriangle[3];

	Mat rotMat(2,3,CV_32FC1);
	Mat warpMat(2,3,CV_32FC1);
	Mat srcImage,dstImage_warp,dstImage_warp_rotate;

	srcImage = imread("/Users/zhuxiaoxiansheng/Desktop/planet.png",1 );
	imshow("srcImage",srcImage);
	waitKey();

	//==========================================【warp Image】====================================================
	dstImage_warp = Mat::zeros(srcImage.rows,srcImage.cols,srcImage.type());

	srcTriangle[0] = Point2f(0,0);
	srcTriangle[1] = Point2f(static_cast<float>(srcImage.cols -1),0);
	srcTriangle[2] = Point2f(0,static_cast<float>(srcImage.rows -1));

  dstTriangle[0] = Point2f(static_cast<float>(srcImage.cols*0.0),static_cast<float>(srcImage.rows*0.33));
  dstTriangle[1] = Point2f(static_cast<float>(srcImage.cols*0.65),static_cast<float>(srcImage.rows*0.35));
  dstTriangle[2] = Point2f(static_cast<float>(srcImage.cols*0.15),static_cast<float>(srcImage.rows*0.6));

	warpMat = getAffineTransform(srcTriangle,dstTriangle);
	warpAffine(srcImage,dstImage_warp,warpMat,dstImage_warp.size());

	imshow("warpshow",dstImage_warp);
	waitKey();
	//============================================================================================================

	//============================================【Rotate function】==============================================
	Point center = Point(dstImage_warp.cols/2,dstImage_warp.rows/2);
	double angle = -30;
	double scale = 0.8;
	rotMat = getRotationMatrix2D(center,angle,scale);
	warpAffine(dstImage_warp,dstImage_warp_rotate,rotMat,dstImage_warp.size());
	imshow("rotateshow",dstImage_warp_rotate);
	waitKey();
  //============================================================================================================

	return 0;
}
