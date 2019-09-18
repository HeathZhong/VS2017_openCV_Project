// AWB_Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat InputImage, OutImage, ContrastImage;
	InputImage = imread("scene.jpg", IMREAD_COLOR);
	if (InputImage.data == nullptr)
	{
		cout << "Image load error!" << endl;
		return 0;
	}
	imshow("AWB_前", InputImage);

	vector<Mat> ImageBGR;
	split(InputImage, ImageBGR);
	double B_mean, G_mean, R_mean;
	B_mean = mean(ImageBGR[0], noArray())[0];
	G_mean = mean(ImageBGR[1], noArray())[0];
	R_mean = mean(ImageBGR[2], noArray())[0];
	double B_gain, G_gain, R_gain;
	B_gain = (B_mean + G_mean + R_mean) / (3 * B_mean);
	G_gain = (B_mean + G_mean + R_mean) / (3 * G_mean);
	R_gain = (B_mean + G_mean + R_mean) / (3 * R_mean);
	ImageBGR[0] = ImageBGR[0] * B_gain;
	ImageBGR[1] = ImageBGR[1] * G_gain;
	ImageBGR[2] = ImageBGR[2] * R_gain;
	merge(ImageBGR, OutImage);
	imshow("AWB_后", OutImage);
	ContrastImage = imread("scene1.jpg", IMREAD_COLOR);
	imshow("AWB_手机", ContrastImage);

	while (true)
	{
		if (waitKey(10) == 27)
			break;
	}
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
