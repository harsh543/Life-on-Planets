#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;
Mat applyCustomColorMap(Mat& im_gray)
{
    unsigned char b[] = {255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,253,251,249,247,245,242,241,238,237,235,233,231,229,227,225,223,221,219,217,215,213,211,209,207,205,203,201,199,197,195,193,191,189,187,185,183,181,179,177,175,173,171,169,167,165,163,161,159,157,155,153,151,149,147,145,143,141,138,136,134,132,131,129,126,125,122,121,118,116,115,113,111,109,107,105,102,100,98,97,94,93,91,89,87,84,83,81,79,77,75,73,70,68,66,64,63,61,59,57,54,52,51,49,47,44,42,40,39,37,34,33,31,29,27,25,22,20,18,17,14,13,11,9,6,4,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    unsigned char g[] = { 255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,252,250,248,246,244,242,240,238,236,234,232,230,228,226,224,222,220,218,216,214,212,210,208,206,204,202,200,198,196,194,192,190,188,186,184,182,180,178,176,174,171,169,167,165,163,161,159,157,155,153,151,149,147,145,143,141,139,137,135,133,131,129,127,125,123,121,119,117,115,113,111,109,107,105,103,101,99,97,95,93,91,89,87,85,83,82,80,78,76,74,72,70,68,66,64,62,60,58,56,54,52,50,48,46,44,42,40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2,0 };

    
    unsigned char r[] = {195,194,193,191,190,189,188,187,186,185,184,183,182,181,179,178,177,176,175,174,173,172,171,170,169,167,166,165,164,163,162,161,160,159,158,157,155,154,153,152,151,150,149,148,147,146,145,143,142,141,140,139,138,137,136,135,134,133,131,130,129,128,127,126,125,125,125,125,125,125,125,125,125,125,125,125,125,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126,126};
    
    Mat channels[] = {Mat(256,1, CV_8U, b), Mat(256,1, CV_8U, g), Mat(256,1, CV_8U, r)};
    Mat lut; // Create a lookup table
    merge(channels, 3, lut);
    
    Mat im_color;
    LUT(im_gray, lut, im_color);
    
    return im_color;

}

int main( int argc, char** argv )
{   Mat image,fin_img;
    image = imread("waterbody.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

   namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
                      // Show our image inside it.

  

    // Create Matrices (make sure there is an image in input!)

    Mat channel[3];
 Mat hsv_channels[3];
    imshow( "Original Image", image );


    // The actual splitting.
    split(image, channel);


   channel[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);//Set blue channel to 0

    //Merging red and green channels
  
    merge(channel,3,image);
    imshow("R+G", image);
  

 imwrite("dest.jpg",image);
  //Output 1 RGB images
 cv:imshow("RGB Image",image);
   ///hsv conversion  
  cvtColor(image,hsv,CV_RGB2HSV);  
 ///Output 2 displaying HUE Image  
  cv::imshow("hsv",hsv);
 Mat hsv_channels[3];
 cv::split( HSV, hsv_channels );
 Mat gray=hsv_channels[2];
 //We increase the brightness of image by scale of 10
  Mat imgH = gray + Scalar(10, 10, 10);
 //output 3 increasing brightness of image
  cv:imshow("Bright image",imH);
 Mat saturated;

double saturation = 10;
double scale = 1;

//Saturating the gray image 
img.convertTo(saturated, gray, scale, saturation); 
 //Output 4 Saturated image
 cv:imshow("Saturated image",saturated);
 
 //applying pseudo coloring on the image based on pixel value(intensity)
 Mat im_color = applyCustomColorMap(saturated);
    //Output 5:Psedo colored image based on intensity
    imshow("Pseudo Colored Image", im_color);
 
}
