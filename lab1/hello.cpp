// OpenImg.cpp
#include <opencv2/highgui.hpp>
int main(int argc, char** argv){
    cv::Mat img = cv::imread("robocup.jpg");
    cv::namedWindow("Example 1");
    cv::imshow("Example 1", img);
    cv::waitKey(0);
    return 0;
}