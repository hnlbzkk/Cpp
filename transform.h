#pragma once

#include "data.h"
#include "vectorOperate.h"

/*
 * ����java�����࣬�洢�任����
*/

//��ͶӰ���ϵĵ�ת������Ļ�ĵ�
Point windowToScreen(Point p);

//��Ļ�ϵ�ת����ͶӰ���ϵĵ�
Point screenToWindow(Point p);

//��һ��������ת������Ļ��
Triangle triangleToScreen(Triangle t);

/*
    ��������任
    ��ģ������任������ռ�
    @parameterģ�����������������е�λ��location
    @parameterģ������ϵ��������λ�������������еı�ʾ��ʽ
    @returnһ���任����
*/
Matrix worldTransform(ModelCoordinate mc);


//����camera����������ת��ɹ۲�������
Matrix viewTransform(Camera camera);

/*
    ͶӰ�任
    ͶӰ����xyƽ��
    prpָ����ͶӰ�ο��㣬������ȷ��ͶӰ����(͸��ͶӰ)��ͶӰ����ƽ��ͶӰ��
    type ����ָ����ͶӰ���ͣ���͸��orƽ�У�

    prp�������ǣ�0��0��d��
*/
Matrix projectionTransform(Point prp, int type = PARALLEL_PROJECTION);

//һ����point���������任��,�õ�������Ļ������
Point transform(Matrix worldTransform, Matrix viewTransform, Matrix projectionTransform, Point point);
