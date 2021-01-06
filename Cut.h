#pragma once
#include "data.h"
#include "Line.h"

#define LEFT 1 //���� 0001
#define RIGHT 2//���� 0010
#define BOTTOM 4//���� 0100
#define TOP 8//���� 1000
//ֱ�߲ü��㷨��������ת������
int encode(int x, int y);
//ֱ�߲ü��㷨
void C_S_Line_CLip(int x1, int y1, int x2, int y2, int XL, int XR, int YB, int YT, int dashline = 1);

//�ж�һ����Ļ�ϵĵ��Ƿ��ڴ�����
bool isInWindow(int x, int y);

//�ж�һ�����Ƿ����������ڲ�
bool isInCube(Cube cube, Point p);

/*
	�ж�һ�����������һ������ڲο����Ƿ�ɼ�
	�߼���ȡһ������ñ����ܽ���һ���㣬���Ҹõ㳯�Ųο��㡣����õ������������棬��ô�õ㲻�ɼ������򣬿ɼ�
*/
bool isVisiblePoint(Cube cube, Point prp, Point p);

//�ж�������ı��Ƿ�ɼ�
bool isVisibleSide(Cube cube, Point prp, Line edge);

//�ж�����������Ƿ�ɼ�
bool isVisibleSurface(Cube cube, Point prp, Surface surface);