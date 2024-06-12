//Hollowed Rectangle
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

int main(int argc, char * argv[])
{
	int length, breadth, thickness;
	cv::Point2i top_left(0, 0);
	cv::Vec3i red(0, 0, 255);
	//BGR Colour Format

	cv::Mat input = cv::imread(argv[1], cv::IMREAD_COLOR);
	if(input.empty()){
		std::cout << "Failed to Load Image.\n";
		return 1;
	}
	std::cout << "The image proportions are: " << input.size().width << " x " << input.size().height << std::endl;

	std::cout << "Enter the starting-coordinates of rect:\n";
	std::cout << "x: "; std::cin >> top_left.x;
	std::cout << "y: "; std::cin >> top_left.y;

	std::cout << "Enter the width of the rectangle: "; std::cin >> length;
	std::cout << "Enter the height of the rectangle: "; std::cin >> breadth;
    std::cout << "Enter the thickness of the rectangle: "; std::cin >> thickness;
	
	cv::Point2i bottom_right(top_left.x + length, top_left.y + breadth);

	cv::rectangle(input, top_left, bottom_right, red, thickness);

	cv::imshow("Hollowed Rectangle", input);
	cv::waitKey(0);

	return 0;
}
