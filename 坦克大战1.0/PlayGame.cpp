#include<graphics.h> //����easyX���п�
#include "Frame.h"

int main()
{
	//�趨���ڴ�СΪ650*650����  һ��ǽΪ25*25����  ��26��ǽ�Ĵ�С  ̹��Ϊ50*50����
	initgraph(650, 650); //��ʼ������
	Frame::playFrame();
	system("pause"); //��ֹϵͳ˲���˳�
	return 0;
}