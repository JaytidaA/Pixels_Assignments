//Rotate Image
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

void rotate180(cv::Mat & inp, cv::Mat & out);

int main(int argc, char * argv[])
{
	cv::Mat input = imread(argv[1], cv::IMREAD_COLOR);
	cv::Mat output = input.clone();

	//[cosa -sina] [x] = [xcosa - ysina] = [-x]
	//[sina  cosa] [y]   [xsina + ycosa]   [-y]
	
	rotate180(input, output);

	cv::imshow("Rotated Image", output);
	cv::waitKey(0);

	return 0;
}

void rotate180(cv::Mat & inp, cv::Mat & out){
	int h = inp.size().height;
	int w = inp.size().width;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			out.at<cv::Vec3b>(h-1-i, w-1-j) = inp.at<cv::Vec3b>(i, j);
		}
	}
}
