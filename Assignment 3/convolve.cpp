//Convolution Algorithm
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

void convolve(cv::Mat IMG, cv::Mat OUT, cv::Mat Kernel){
	int w_K = Kernel.size().width, h_K = Kernel.size().height;
	if((w_K != h_K) || (w_K%2 == 0) || (h_K%2 == 0)){ std::cout << "Kernel should be odd square matrix\n"; return; }
	if(Kernel.type() != CV_64FC1){ std::cout << "Kernel should be a 64-bit FLoating Grayscale Matrix!\n"; return; }

	int diff_cent = (w_K - 1)/2;
	cv::Mat rotKernel = Kernel.clone();
	for(int i = 0; i < h_K; i++){
	for(int j = 0; j < w_K; j++){
		rotKernel.at<float>(i, j) = Kernel.at<float>(h_K-1-i, w_K-1-j);
	}}

	int w_I = IMG.size().width, h_I = IMG.size().height;
	for(int i = 0; i < h_I; i++){
	for(int j = 0; j < w_I; j++){
	if((i + 1 > diff_cent) && (i < h_I - diff_cent) && (j + 1 > diff_cent) && (j < w_I - diff_cent)){

		float b = 0, g = 0, r = 0;
		for(int i1 = 0; i1 < h_K; i1++){
		for(int j1 = 0; j1 < w_K; j1++){
			b += int(rotKernel.at<float>(i1, j1) * (float)IMG.at<cv::Vec3b>(i + i1, j + j1)[0]);
			g += int(rotKernel.at<float>(i1, j1) * (float)IMG.at<cv::Vec3b>(i + i1, j + j1)[1]);
			r += int(rotKernel.at<float>(i1, j1) * (float)IMG.at<cv::Vec3b>(i + i1, j + j1)[2]);
		}}
		b = (b > 255.0)?255.0:b; b = (b < 0.0)?0.0:b;
		g = (g > 255.0)?255.0:g; g = (g < 0.0)?0.0:g;
		r = (r > 255.0)?255.0:r; r = (r < 0.0)?0.0:r;
		OUT.at<cv::Vec3b>(i, j) = cv::Vec3b(b, g, r);
	}
	else{
		OUT.at<cv::Vec3b>(i, j) = cv::Vec3b(255, 255, 255);
	}}}
}

int main(int argc, char * argv[])
{
	int order;
	std::cout << "Enter the order of the Kernel/Filter: "; std::cin >> order;

	cv::Mat krl(order, order, CV_64FC1);
	cv::Mat img = cv::imread(argv[1], cv::IMREAD_COLOR);
	cv::Mat out = img.clone();
	
	for(int i = 0; i < order; i++){
	for(int j = 0; j < order; j++){
		std::cout << "Enter the (" << i << ", " << j << ")th element of the kernel: ";
		std::cin >> krl.at<float>(i, j);
	}}
	std::cout << "Kernel entered!\n";
	std::cout << "Convolving...\n";
	convolve(img, out, krl);

	cv::imshow("Input Image", img);
	cv::imshow("Convolution", out);
	cv::waitKey(0);

	return 0;
}
