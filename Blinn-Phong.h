#pragma once

//���һЩ���㷨�йصĺ���

/*Blinn_Phong����ģ��
	double Ka ;//�����ⷴ��ϵ��
	double Ia ;//����������
	double Ip ;//���Դ����
	Point PLight ;//��Դλ��
	double Kd ;//������ϵ��
	Vector N ;//���㷨����
	Point P//�����Ƶ�
	double Ks //���淴��ϵ��
	Point view ;//�ӵ�
	double n ;//���淴��ָ��
*/
double Blinn_Phong(double Ka, double Ia, double Ip, Point PLight, double Kd, Vector N, Point P, double Ks, Point view, double n);
