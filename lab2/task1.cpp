#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main(int argc, char** argv){
    cv::Mat color = cv::imread("../street_scene.png");
    cv::namedWindow("Example 1");
    cv::imshow("Example 1", color);
    cv::waitKey(0);

    cv::Mat gray ;
    cv::cvtColor(color, gray, cv::COLOR_BGR2GRAY);
    cv::imshow("Example", gray);
    cv::waitKey(0);

    cv::Size s = gray.size();
    std::cout << s.height << std::endl; // Print an integer
    cv::Mat edge_map(s.height, s.width, CV_8UC1, cv::Scalar(0));
    cv::Canny(gray, edge_map, 150, 200);
    cv::imshow("Example", edge_map);
    cv::waitKey(0);

    return 0;
}
