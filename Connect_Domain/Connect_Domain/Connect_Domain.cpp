// Connect_Domain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat InputImage, OutImage;
	InputImage = imread("cell.jpg", IMREAD_COLOR);
	if (InputImage.data == nullptr)
	{
		cout << "Load image error !" << endl;
		return 0;
	}
	imshow("src", InputImage);
	Mat BinaryImage, GrayImage, CannyImage;
	cvtColor(InputImage, GrayImage, COLOR_BGR2GRAY);
	imshow("Gray", GrayImage);
	
	Canny(GrayImage, CannyImage, 30, 60);
// 	erode(CannyImage, CannyImage, 3);  //腐蚀
// 	dilate(CannyImage, CannyImage, 3); //膨胀
	imshow("Canny",CannyImage);
	findContours(CannyImage, );
	//imshow("Binary", BinaryImage);

	while (true)
	{
		if (waitKey(10) == 27)
			break;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

