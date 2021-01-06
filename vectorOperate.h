#pragma once
#include "data.h"
/*
* ����java�����࣬�洢��������
*/
//��������Ļ�ת
Vector pointToVector(Point p);
Point vectorToPoint(Vector v);
//��������
double mod(Vector v);
//��λ����
Vector unitization(Vector v);

//�Ӽ�
Vector addVector(Vector v1, Vector v2);
Vector subVector(Vector v1, Vector v2);

//���
double dotProduct(Vector v1, Vector v2);
//���
Vector crossProduct(Vector v1, Vector v2);

//ʸ���;���ĳ˻�
Vector matrixVectorProduct(Matrix m, Vector v);
//����;���ĳ˻���4ά���� 
Matrix matrixMultiply(Matrix m1, Matrix m2);

//ZXY��
Vector rotateZ(Vector v, double rad);
Vector rotateX(Vector v, double rad);
Vector rotateY(Vector v, double rad);