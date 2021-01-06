#include "vectorOperate.h"
#include <math.h>

//��������Ļ�ת
Vector pointToVector(Point p) {
    return { p.x,p.y,p.z };
}

Point vectorToPoint(Vector v) {
    return { v.x,v.y,v.z };
}

//��������
double mod(Vector v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

//��λ����
Vector unitization(Vector v) {
    double m = mod(v);

    Vector result = { v.x / m,v.y / m,v.z / m };

    return result;
}

//��
Vector addVector(Vector v1, Vector v2) {
    Vector v;

    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    v.z = v1.z + v2.z;

    return v;
}

//��
Vector subVector(Vector v1, Vector v2) {
    Vector v;

    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;

    return v;
}

//���
double dotProduct(Vector v1, Vector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

//���
Vector crossProduct(Vector v1, Vector v2) {
    Vector v;

    v.x = v1.y * v2.z - v1.z * v2.y;
    v.y = v1.z * v2.x - v1.x * v2.z;
    v.z = v1.x * v2.y - v1.y * v2.x;

    return v;
}

/**
    *ʸ���;���ĳ˻�
    *Ҳ���ǵ������������任
    *�˷������е���ʸ���;�������㣬Ҫ�Ȱ�ʸ��ӳ�䵽4ά�������������λ�����ԭ����ά��
*/
Vector matrixVectorProduct(Matrix m, Vector v) {
    Vector result;

    result.x = m.matrix[0][0] * v.x + m.matrix[0][1] * v.y + m.matrix[0][2] * v.z + m.matrix[0][3];
    result.y = m.matrix[1][0] * v.x + m.matrix[1][1] * v.y + m.matrix[1][2] * v.z + m.matrix[1][3];
    result.z = m.matrix[2][0] * v.x + m.matrix[2][1] * v.y + m.matrix[2][2] * v.z + m.matrix[2][3];
    double n = m.matrix[3][0] * v.x + m.matrix[3][1] * v.y + m.matrix[3][2] * v.z + m.matrix[3][3];
    result.x /= n;
    result.y /= n;
    result.z /= n;

    return result;
}

//����;���ĳ˻���4ά����
Matrix matrixMultiply(Matrix m1, Matrix m2) {
    Matrix result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            double temp = 0;
            for (int k = 0; k < 4; k++) {
                temp += m1.matrix[i][k] * m2.matrix[k][j];
            }
            result.matrix[i][j] = temp;
        }
    }
    return result;
}
//��������ϵ
//��x����ת
Vector rotateX(Vector v, double rad) {
    Vector result;

    double cosValue = cos(rad);
    double sinValue = sin(rad);

    result.x = v.x;
    result.y = cosValue * v.y + sinValue * v.z;
    result.z = -sinValue * v.y + cosValue * v.z;

    return result;
}

//��y����ת
Vector rotateY(Vector v, double rad) {
    Vector result;

    double cosValue = cos(rad);
    double sinValue = sin(rad);

    result.x = cosValue * v.x - sinValue * v.z;
    result.y = v.y;
    result.z = sinValue * v.x + cosValue * v.z;

    return result;
}

//��z����ת
Vector rotateZ(Vector v, double rad) {
    Vector result;

    double cosValue = cos(rad);
    double sinValue = sin(rad);

    result.x = cosValue * v.x + sinValue * v.y;
    result.y = -sinValue * v.x + cosValue * v.y;
    result.z = v.z;

    return result;
}

