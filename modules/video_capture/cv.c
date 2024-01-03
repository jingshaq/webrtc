
#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat imageA = cv::imread("home", cv::IMREAD_COLOR);
    cv::Mat imageB = cv::imread("home1.png", cv::IMREAD_COLOR);

    // 转换为灰度图
    cv::Mat grayA, grayB;
    cv::cvtColor(imageA, grayA, cv::COLOR_BGR2GRAY);
    cv::cvtColor(imageB, grayB, cv::COLOR_BGR2GRAY);

    // 计算结构相似性指数（SSIM）
    double score, diff;
    cv::Mat ssim_map;
    cv::compareSSIM(grayA, grayB, ssim_map);

    // 计算差异图
    cv::Mat diffImage;
    cv::absdiff(grayA, grayB, diffImage);

    // 对差异图进行阈值处理
    cv::Mat thresh;
    cv::threshold(diffImage, thresh, 0, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);

    // 寻找轮廓
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(thresh.clone(), contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 循环遍历每个轮廓，并打印边界框的坐标信息
    for (int i = 0; i < contours.size(); i++) {
        cv::Rect boundingBox = cv::boundingRect(contours[i]);
        // 输出边框的坐标信息
        std::cout << "x: " << boundingBox.x << ", y: " << boundingBox.y << ", width: " << boundingBox.width << ", height: " << boundingBox.height << std::endl;
    }

    return 0;
}
