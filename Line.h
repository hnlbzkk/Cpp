#pragma once
#include "data.h"

//����
void drawPoint(int x, int y, int color);

//���������޸Ķ�Ӧ����ɫ
int changeColorByLight(int color, float light);

//������Light���Ȳ���
void drawPoint(int x, int y, int color, double light);

//���߶κ���
void drawLine(int x1, int y1, int x2, int y2, int color, int type = SOLID_LINE);
void drawLine(Point p1, Point p2, int color, int type = SOLID_LINE);

//����Ļ�ϻ��ֳ�һ������Ϊ��ʾ����
void drawWindow();
