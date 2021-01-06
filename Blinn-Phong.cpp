//#pragma once

#include <math.h>
#include <easyx.h>
#include "data.h"
#include "vectorOperate.h"
#include "Line.h"
#include "transform.h"

/*Blinn_Phong����ģ��
	double Ka ;//�����ⷴ��ϵ��
	double Ia ;//�������ǿ
	double Ip ;//���Դ��ǿ
	Point PLight ;//��Դλ��
	double Kd ;//������ϵ��
	Vector N ;//���㷨����
	Point P//�����Ƶ�
	double Ks //���淴��ϵ��
	Point view ;//�ӵ�
	double n ;//�����
*/
double Blinn_Phong(double Ka, double Ia, double Ip, Point PLight, double Kd, Vector N, Point P, double Ks, Point view, double n) {
	double I1 = Ia * Ka;//����������
	Vector L = { PLight.x - P.x,PLight.y - P.y,PLight.z - P.z };//��ָ���Դ������
	L = unitization(L);
	N = unitization(N);//��Ұ������м�����
	double I2 = Ip * Kd * dotProduct(L, N);//����������
	Vector V = { view.x - P.x,view.y - P.y,view.z - P.z };//��ָ���ӵ������
	V = unitization(V);
	Vector H = addVector(L, V);//���߷���
	H = unitization(H);
	double I3 = Ks * Ip * pow(dotProduct(H, N), n);
	return I1 + I2 + I3;
}
