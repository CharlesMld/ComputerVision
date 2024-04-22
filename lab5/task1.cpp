#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char** argv){
    cv::Mat gray_img = cv::imread("Asphalt cracks/Asphalt-3.png");
    cv::namedWindow("Example 1");
    cv::imshow("Example 1", gray_img);
    cv::waitKey(0);

    // Convert img to gray
    cv::cvtColor(gray_img, gray_img, cv::COLOR_BGR2GRAY);

    // Histogram calculation
    int hist_size = 256;
    float range[] = {0,256};
    const float* hist_range[] = {range}; 
    cv::Mat hist;
    cv::calcHist(gray_img, 1, 0, cv::Mat(), hist, &hist_size, hist_range, true, false);

    // Image smoothing
    cv::Mat smoothed ;
    cv::equalizeHist(gray_img, smoothed);
    // cv::medianBlur(gray_img, hist, 3); no good
    cv::imshow("Smoothed", smoothed);
    cv::waitKey(0);

    // Otsu's thresholding
    cv::Size s = hist.size();
    cv::Mat segmented_img(s.height, s.width, CV_8UC1, cv::Scalar(0));
    cv::threshold(hist, segmented_img, 0 , 100, cv::THRESH_OTSU);
    cv::namedWindow("Example 2");
    cv::imshow("Example 2", segmented_img);
    cv::waitKey(0);
    return 0;
}
