#include "transform.h"
#include <iostream>



//��ͶӰ���ϵĵ�ת������Ļ�ĵ�
Point windowToScreen(Point p) {
    Point result;

    result.x = (p.x * SCREEN_LENGTH / WINDOW_LENGTH) + SCREEN_CENTER_X;
    result.y = (p.y * SCREEN_LENGTH / WINDOW_LENGTH) + SCREEN_CENTER_Y;
    result.z = p.z;

    return result;
}

//��Ļ�ϵ�ת����ͶӰ���ϵĵ�
Point screenToWindow(Point p){
    Point result;

    result.x = (p.x - SCREEN_CENTER_X) * WINDOW_LENGTH / SCREEN_LENGTH;
    result.y = (p.y - SCREEN_CENTER_Y) * WINDOW_LENGTH / SCREEN_LENGTH;
    result.z = p.z;

    return result;
}

//��һ��������ת������Ļ��
Triangle triangleToScreen(Triangle t) {
    Triangle result;

    result.v1 = windowToScreen(t.v1);
    result.v2 = windowToScreen(t.v2);
    result.v3 = windowToScreen(t.v3);

    return result;
}

/*
    ��������任
    ��ģ������任������ռ�
    @parameter m1 ģ�����������������е�λ��location
    @parameter m2 ģ������ϵ��������λ�������������еı�ʾ��ʽ
    @return һ���任����
*/
Matrix worldTransform(ModelCoordinate mc) {
    Matrix m1, m2;

    double temp1[4][4] = { 
        {1,0,0,mc.location.x}, 
        {0,1,0,mc.location.y}, 
        {0,0,1,mc.location.z}, 
        {0,0,0,1} 
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m1.matrix[i][j] = temp1[i][j];//m1�洢ƽ��
        }
    }

    double temp2[4][4] = { 
        {mc.u.x,mc.v.x,mc.n.x,0}, 
        {mc.u.y,mc.v.y,mc.n.y,0}, 
        {mc.u.z,mc.v.z,mc.n.z,0}, 
        {0,     0,     0,     1}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m2.matrix[i][j] = temp2[i][j];//m2�洢����任
        }
    }

    return matrixMultiply(m1, m2);
}


//����camera����������ת��ɹ۲�������
Matrix viewTransform(Camera camera) {
    Matrix m1, m2;

    double temp1[4][4] = { 
        {1,0,0,-camera.location.x}, 
        {0,1,0,-camera.location.y}, 
        {0,0,1,-camera.location.z}, 
        {0,0,0,1} 
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m1.matrix[i][j] = temp1[i][j];//m1�洢ƽ��
        }
    }

    double temp2[4][4] = { 
        {camera.u.x,camera.u.y,camera.u.z,0}, 
        {camera.v.x,camera.v.y,camera.v.z,0}, 
        {camera.n.x,camera.n.y,camera.n.z,0}, 
        {0,         0,         0,         1}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m2.matrix[i][j] = temp2[i][j];//m2�洢����任
        }
    }

    return matrixMultiply(m2, m1);
}

/*
    ͶӰ�任
    ͶӰ����xyƽ��
    prpָ����ͶӰ�ο��㣬������ȷ��ͶӰ����(͸��ͶӰ)��ͶӰ����ƽ��ͶӰ��
    type ����ָ����ͶӰ���ͣ���͸��orƽ�У�
    prp�������ǣ�0��0��d��
*/

Matrix projectionTransform(Point prp, int type) {
    Matrix result = { 
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 1
    };

    switch (type) {
    case PARALLEL_PROJECTION:
        return result;
    case PERSPECTIVE_PROJECTION:
        result.matrix[3][2] = -1 / prp.z;
        return result;
    }
}

//һ����point���������任��,�õ�������Ļ������
Point transform(Matrix worldTransform, Matrix viewTransform, Matrix projectionTransform, Point point) {
    Vector v = { point.x,point.y,point.z };

    v = matrixVectorProduct(worldTransform, v);
    v = matrixVectorProduct(viewTransform, v);
    v = matrixVectorProduct(projectionTransform, v);
    Point p = { v.x,v.y,v.z };
    p = windowToScreen(p);

    return p;
}
