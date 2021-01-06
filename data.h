#pragma once

#define PI 3.14159265358979323846
#define RAD (PI / 180) * 10 //10��

#define WINDOW_LENGTH 4//��������ϵ��Ҫ��ʾ��ƽ�棬Ĭ����[-2,2][-2,2]
#define WINDOW_WIDTH 4

#define SCREEN_LENGTH 400
#define SCREEN_WIDTH 400//����������ϵת������Ļʱ�Ĵ�С

#define SCREEN_CENTER_X 320
#define SCREEN_CENTER_Y 240//��������ϵԭ���Ӧ����Ļ����

#define GRAPHIC_LENGTH 640
#define GRAPHIC_WIDTH 480//����ͼ�εĴ�С����ʵ�ϣ����ֵ����С��������Ļ�Ĵ�С�����˴��������

#define PARALLEL_PROJECTION 1//����ƽ��ͶӰ
#define PERSPECTIVE_PROJECTION 2//����͸��ͶӰ

#define STEP 0.1//wsad,���������ƶ�camera(����)�Ĳ���

#define SOLID_LINE 1 //ʵ��
#define DASH_LINE 2//����

#define PICTURE_LENGTH 1920//ͼƬ��
#define PICTURE_WIDTH 1200//ͼƬ��

//���ڴ�С,Ҳ�ǲü��ı�
#define WINDOW_LEFT SCREEN_CENTER_X - SCREEN_LENGTH / 2
#define WINDOW_RIGHT SCREEN_CENTER_X + SCREEN_LENGTH / 2
#define WINDOW_TOP SCREEN_CENTER_Y - SCREEN_LENGTH / 2
#define WINDOW_BOTTOM SCREEN_CENTER_Y + SCREEN_LENGTH / 2

/**
	*��Ķ��壬3ά
	*�����Ͻ�����������ڿռ�����һһ��Ӧ��
*/
struct Point
{
	double x;
	double y;
	double z;
};
/**
	*�����Ķ���,3ά
*/
struct Vector
{
	double x;
	double y;
	double z;
};

/**
	*����Ķ���
	*��ά�ռ�ı任�������4*4���������
*/
struct Matrix {
	double matrix[4][4];
};

/*
	����һ����������ϵ
*/
struct ModelCoordinate {
	Point location;
	Vector u;
	Vector v;
	Vector n;
};
/*
	camera�Ķ���
	������������������ϵ�е�λ�ú�����ÿ����λ������
*/
struct Camera {
	Point location;
	Vector u;
	Vector v;
	Vector n;
};

//ֱ�ߵĶ���
struct Line {
	Point p1;
	Point p2;
};

//�����εĶ���
struct Triangle {
	Point v1;
	Point v2;
	Point v3;
};

//���������Ķ���
typedef struct {
	Point p1;
	Point p2;
	Point p3;
	Point p4;
}Surface;

//������Ķ���
//�˸����� (0,0,0) (1,0,0) (0,1,0) (0,0,1) (1,1,0) (0,1,1) (1,0,1) (1,1,1)
struct Cube {
	Point p1;//��Ϊ������ԭ��
	Point p2;//������u�᷽��
	Point p3;//������v�᷽��
	Point p4;//������n�᷽��
	Point p5;//uOvƽ������һ��
	Point p6;//vOnƽ������һ��
	Point p7;//nOuƽ������һ��
	Point p8;//�������һ����
};