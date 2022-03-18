#include<graphics.h> //包含easyX运行库
#include "Frame.h"

int main()
{
	//设定窗口大小为650*650像素  一堵墙为25*25像素  共26堵墙的大小  坦克为50*50像素
	initgraph(650, 650); //初始化窗口
	Frame::playFrame();
	system("pause"); //防止系统瞬间退出
	return 0;
}