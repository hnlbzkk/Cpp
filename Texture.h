#pragma once
//ʵ����������صĺ���
#include <easyx.h>
#include "data.h"

//ͼƬ����ת��������
Point picToTexture(int width, int height, int x, int y);

//��������ת��ɫ����������
Point texttureToBuff(double x, double y, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

//ʵ�ְ��������ɫ�ӵ�һ���ı�����ȥ�޸Ļ�����
void addTexture(IMAGE img, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void addTexture(COLORREF color, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);


//�����������㷨
extern int colorBuffered[GRAPHIC_LENGTH][GRAPHIC_WIDTH];//�����������ɫ
extern int pictureColor[PICTURE_LENGTH][PICTURE_WIDTH];//��Ƭ����
void showScreen();
void showScreen2();
void clearBuffer();