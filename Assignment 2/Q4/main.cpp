//Hollowed Circle
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

int main(int argc, char * argv[])
{
	int radius, thickness;
	cv::Point2i center(0, 0);
	cv::Vec3i red(0, 0, 255);
	//BGR Colour Format

	cv::Mat input = cv::imread(argv[1], cv::IMREAD_COLOR);
	if(input.empty()){
		std::cout << "Failed to Load Image.\n";
		return 1;
	}
	std::cout << "The image proportions are: " << input.size().width << " x " << input.size().height << std::endl;

	std::cout << "Enter the center-coordinates of circle:\n";
	std::cout << "x: "; std::cin >> center.x;
	std::cout << "y: "; std::cin >> center.y;

	std::cout << "Enter the radius of the circle: "; std::cin >> radius;
    std::cout << "Enter the thickness of the circle: "; std::cin >> thickness;

	cv::circle(input, center, radius, red, thickness);

	cv::imshow("Hollowed Circle", input);
	cv::waitKey(0);

	return 0;
}
