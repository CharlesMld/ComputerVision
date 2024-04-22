// OpenImg.cpp
#include <opencv2/highgui.hpp>
#include <iostream>
static void onMouse(int event, int x, int y, int flags, void* param){
    cv::Mat *xyz = ((cv::Mat*)param); //cast and deref the param
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        cv::Vec3b val ;
        val = (&xyz).at(cv::Vec3b) >(y,x).at; // opencv is row-major ! 
        std::cout << "x= " << x << " y= " << y << "val= "<<val<< std::endl;
    }
}
int main(int argc, char** argv){
    cv::Mat xyz;
    cv::Mat img = cv::imread("robocup.jpg");
    cv::namedWindow("Example 1");
    cv::imshow("Example 1", img);
    cv::setMouseCallback("Example 1", onMouse, &xyz);
    cv::waitKey(0);
    return 0;
}