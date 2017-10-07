//---------------------------------【head file\namesapce declaration】---------------------------------
//                         statement:  declare head file and namespace
//-----------------------------------------------------------------------------------------------------
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;

//-------------------------------------【public function】---------------------------------------------
//                         statement:  declare global function
//-----------------------------------------------------------------------------------------------------
void Centralization(Mat &imageName);
void FrequencyProcess(Mat matName[]);

//--------------------------------------【main()function】----------------------------------------------
//                          statement:    our code run from here
//-----------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]){

    //load the picture in gray-scale mode
    Mat srcImage = imread("/Users/zhuxiaoxiansheng/Desktop/lalaland_2.jpg",0);
    resize(srcImage,srcImage,Size(1000*1.5,640*1.5));
   
    //show the original picture
    imshow("Source Image",srcImage); 
    waitKey();

    //expend the picture to the optimal size,the border filled with 0
    int m = getOptimalDFTSize(srcImage.rows);
    int n = getOptimalDFTSize(srcImage.cols);
    Mat padded;
    copyMakeBorder(srcImage,padded,0,m-srcImage.rows,0,n-srcImage.cols,BORDER_CONSTANT,Scalar::all(0));

    //create space for the DFT's result
    //meanwhile combine the planes array to one array
    Mat planes[] = {Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F)};
    Mat complexI;
    merge(planes,2,complexI);
    
    //using DFT in-place
    dft(complexI,complexI);

    //figure out the magnitude according to the complex number
    split(complexI,planes);
    magnitude(planes[0],planes[1],planes[0]);
    Mat magnitudeImage = planes[0];

    //zoom by logarithmic scale
    magnitudeImage += Scalar::all(1);
    log(magnitudeImage,magnitudeImage);

    //centralization and normalize the magnitude spectru
    //show the image in frequency domain
    Centralization(magnitudeImage);
    normalize(magnitudeImage,magnitudeImage,0,1,NORM_MINMAX);
    imshow("Amplitude spectrum",magnitudeImage);
    waitKey(0);

    //process the picture in the frequency domain
    FrequencyProcess(planes);

    //create spcae for processd Image
    Mat processedImage;
    merge(planes,2,processedImage);

    //IDFT and show the picture in time domain
    idft(processedImage,processedImage,DFT_SCALE|DFT_REAL_OUTPUT);
    normalize(processedImage,processedImage,0,255,CV_MINMAX);
    processedImage.convertTo(processedImage,CV_8UC1);
    imshow("reconstructed image",processedImage);
    waitKey();

    //show the picture in frequency domain
    magnitude(planes[0],planes[1],planes[0]);
    magnitudeImage = planes[0];
    magnitudeImage += Scalar::all(1);
    log(magnitudeImage,magnitudeImage);
    Centralization(magnitudeImage);
    normalize(magnitudeImage,magnitudeImage,0,1,NORM_MINMAX);
    imshow("Pro Amplitude spectrum",magnitudeImage);
    waitKey(0);

    return 0;

}

//---------------------------------【Centralization function】-----------------------------------------
//                         statement:  using to centralise the frequency spectrum
//-----------------------------------------------------------------------------------------------------
void Centralization(Mat &imageName){
    //if the numbers of cols and rows are odd,reduce one to be a even
	imageName = imageName(Rect(0,0,imageName.cols &-2,imageName.rows &-2));

    int cx = imageName.cols/2;
    int cy = imageName.rows/2;

    Mat q0(imageName,Rect(0,0,cx,cy)); //the left and up region of ROI
    Mat q1(imageName,Rect(cx,0,cx,cy)); //the right and up region of ROI
    Mat q2(imageName,Rect(0,cy,cx,cy)); //the left and down region of ROI
    Mat q3(imageName,Rect(cx,cy,cx,cy)); //the right and down region of ROI

    //exchange the quadrant
    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

}

//----------------------------------【FrequencyProcess function】--------------------------------------
//                             statement:  process the image's pixel
//-----------------------------------------------------------------------------------------------------
void FrequencyProcess(Mat matName[]){
    double ESP = 0.000001;
    for( int i = 0; i < matName[0].rows; ++i )
        for( int j = 0; j < matName[0].cols; ++j )
        {
            double dx = i - matName[0].rows/2;
            double dy = j - matName[0].cols/2;
            matName[0].at<float>(i, j) = (1 - exp(-100/(pow(dx, 2) + pow(dy, 2) + ESP)))* matName[0].at<float>(i, j);
            matName[1].at<float>(i, j) = (1 - exp(-100/(pow(dx, 2) + pow(dy, 2) + ESP)))* matName[1].at<float>(i, j);
        }
}

