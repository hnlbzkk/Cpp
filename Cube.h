#pragma once

#include "data.h"
#include <easyx.h>

//��������֮����ɫ���ȵĲ�ͬ�������Բ�ֵʹ����ɫ����,
//��������Ļ����
//������ɫ��ֵ�����¸߹����м������ʱ��߹�ʧЧ����Ҫע��
void gouraud_paintLine(int point1_x, int point1_y, double point1_light, int point2_x, int point2_y, double point2_light, int color);

//phong��ɫ��������һ����
void phong_paintLine(int point1_x, int point1_y, Vector point1_v, Point p1, int point2_x, int point2_y, Vector point2_v, Point p2, int color, int flagl,
	double Ka, double Ia, double Ip, Point PLight, double Kd, double Ks, Point view, double n);

//Ϳһ�������Σ���������������Ļ����
void gouraud_paintTriangle(int p1_x, int p1_y, double p1_light,
	int p2_x, int p2_y, double p2_light,
	int p3_x, int p3_y, double p3_light, int color);

//�������Σ�����phong��ɫ����
void phong_paintTriangle(int p1_x, int p1_y, Vector v1, Point p1,
	int p2_x, int p2_y, Vector v2, Point p2,
	int p3_x, int p3_y, Vector v3, Point p3, int color, int flagl,
	double Ka, double Ia, double Ip, Point Plight, double Kd, double Ks, Point view, double n);

//Ϳһ���ı���,������Ļ���꣬���ҵ��˳���շ������α�ע
void gouraud_paintQuadrangle(int p1_x, int p1_y, double p1_light,
	int p2_x, int p2_y, double p2_light,
	int p3_x, int p3_y, double p3_light,
	int p4_x, int p4_y, double p4_light, int color);

//Ϳһ���ı���,������Ļ���꣬���ҵ��˳���շ������α�ע
void phong_paintQuadrangle(int p1_x, int p1_y, Vector v1, Point p1,
	int p2_x, int p2_y, Vector v2, Point p2,
	int p3_x, int p3_y, Vector v3, Point p3,
	int p4_x, int p4_y, Vector v4, Point p4,
	int color, int flagl,
	double Ka, double Ia, double Ip, Point Plight, double Kd, double Ks, Point view, double n);

/*
��Ļ�ϻ�һ��������
��Ҫ֪������������任���󣬹۲�����任����ͶӰ�任����������,ͶӰ�ο��㣨����ȷ����Щ�߿��Կ�����
����gouraud��ɫ����(��ɫ��ֵ)
*/
void gouraud_drawCube(Matrix worldTransform, Matrix viewTransform, Matrix projectionTransform, Cube cube, Point prp,
	double Ka, double Ia, double Ip, Point PLight, double Kd, double Ks, Point view, double n, int color, int model = 0/*0��ʾ�߿�ģʽ,1�ǹ���ģʽ*/);

/*
��Ļ�ϻ�һ��������
��Ҫ֪������������任���󣬹۲�����任����ͶӰ�任����������,ͶӰ�ο��㣨����ȷ����Щ�߿��Կ�����
�������һ�������õ���phong����(������ֵ)
*/
void phong_drawCube(Matrix worldTransform, Matrix viewTransform, Matrix projectionTransform, Cube cube, Point prp,
	double Ka, double Ia, double Ip, Point PLight, double Kd, double Ks, Point view, double n, int color, IMAGE img,
	int model = 1, int flagt = 1, int flagl = 1/*0��ʾ�߿�ģʽ,1�ǹ���ģʽ*/, int flagc = 1);