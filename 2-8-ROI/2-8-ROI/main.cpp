#include<opencv2\opencv.hpp>

using namespace cv;

int main(){

	//方法一：简单叠加
	/*Mat image = imread("lifehappy.png");
	Mat logo = imread("logo.jpg");
	if (!image.data || !logo.data)
		return 0;
	Mat imageROI;   //定义一个感兴趣图像区域
	imageROI = image(Rect(0, 0, logo.cols, logo.rows)); //对象imageROI的值是image中的一块大小和logo一样大的区域,该区域的起始点是（0,0,），事实上imageROI和image中的这块区域是共享内存的
	addWeighted(imageROI,0.2,logo,0.7,0.,imageROI);     
	imshow("感兴趣区域",image);
	waitKey();*/

	//方法二：图像掩模
	Mat image = imread("lifehappy.png");    //定义背景大图
	Mat logo = imread("logo.jpg");       //定义logo图
	Mat mask = imread("logo.bmp",0);     //将做logo的图像读入灰度图作为掩模mask。mask和logo是一张图片,只是mask是灰度图形式
	Mat imageROI = image(Rect(0,0,logo.cols,logo.rows)); //定义感兴趣区域，它的值是image中的一块大小和log一样的区域，事实上imageROI和image中的这块区域是共享内存的

	if (!image.data || !mask.data || !logo.data)
		return 0;
	logo.copyTo(imageROI,mask);   //
	imshow("图像掩模感兴趣区域",image);
	waitKey();
}