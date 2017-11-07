#include<opencv2\opencv.hpp>

using namespace cv;

int main(){

	//����һ���򵥵���
	/*Mat image = imread("lifehappy.png");
	Mat logo = imread("logo.jpg");
	if (!image.data || !logo.data)
		return 0;
	Mat imageROI;   //����һ������Ȥͼ������
	imageROI = image(Rect(0, 0, logo.cols, logo.rows)); //����imageROI��ֵ��image�е�һ���С��logoһ���������,���������ʼ���ǣ�0,0,������ʵ��imageROI��image�е���������ǹ����ڴ��
	addWeighted(imageROI,0.2,logo,0.7,0.,imageROI);     
	imshow("����Ȥ����",image);
	waitKey();*/

	//��������ͼ����ģ
	Mat image = imread("lifehappy.png");    //���屳����ͼ
	Mat logo = imread("logo.jpg");       //����logoͼ
	Mat mask = imread("logo.bmp",0);     //����logo��ͼ�����Ҷ�ͼ��Ϊ��ģmask��mask��logo��һ��ͼƬ,ֻ��mask�ǻҶ�ͼ��ʽ
	Mat imageROI = image(Rect(0,0,logo.cols,logo.rows)); //�������Ȥ��������ֵ��image�е�һ���С��logһ����������ʵ��imageROI��image�е���������ǹ����ڴ��

	if (!image.data || !mask.data || !logo.data)
		return 0;
	logo.copyTo(imageROI,mask);   //
	imshow("ͼ����ģ����Ȥ����",image);
	waitKey();
}