#include "Line.h"
#include <iostream>
#include <easyx.h>
//#include "data.h"
#include "Blinn-Phong.h"
#include "transform.h"
#include "Texture.h"

using namespace std;


//����
void drawPoint(int x, int y, int color) {//���õľ���easyX�еĻ��㺯��
    if(x >= 0 && y > 0 && x < GRAPHIC_LENGTH && y < GRAPHIC_WIDTH)
        colorBuffered[x][y] = color;
    //putpixel(x, y, color);
}
//���������޸Ķ�Ӧ����ɫ
int changeColorByLight(int color, float light) {
    if (light < 0) {
        light = 0;
    }
    if (light > 1)
        light = 1;
    float h, s, l;
    float* H = &h, * S = &s, * L = &l;
    RGBtoHSL(color, H, S, L);
    float olight = *L;
    //light = olight+(2-4 * olight)* light*light + (4 * olight -1)*light-0.5;
    //light = olight;
    return HSLtoRGB(*H, *S, light);
}

//������Light���Ȳ���
void drawPoint(int x, int y, int color, double light) {
    int changedColor = changeColorByLight(color, light);
    drawPoint(x, y, changedColor);
}

//���߶κ���
//���(x1,y1)���յ�(x2,y2)����ɫ����ʵ�� Ĭ��ʵ��
void drawLine(int  x1, int  y1, int  x2, int  y2, int color, int type /*= SOLID_LINE*/) {
    if (x1 == x2) {//б�ʲ�����ʱ
        if (y1 <= y2) {
            for (int y = y1; y <= y2; y++) {
                if (type == SOLID_LINE) {
                    drawPoint(x1, y, color);
                };
                if (type == DASH_LINE) {//���ߣ���3������ʾ
                    if ((y / 3) % 2 == 0) {
                        drawPoint(x1, y, color);
                    }
                };
            }
        }
        else {
            for (int y = y2; y <= y1; y++) {
                if (type == SOLID_LINE) {
                    drawPoint(x1, y, color);
                };
                if (type == DASH_LINE) {//���ߣ���3������ʾ
                    if ((y / 3) % 2 == 0) {
                        drawPoint(x1, y, color);
                    }
                };
            }
        }
        return;
    };//б�ʲ����ڵ�������

    int dx = x2 - x1;
    int dy = y2 - y1;
    double k = (float)dy / (float)dx;//б��

    if (k >= -1 && k <= 1) {//-1<=б��<=1��
        if (x1 <= x2) {//p1 x����Сʱ
            double y = y1;
            for (int x = x1; x <= x2; x++) {
                if (type == DASH_LINE) {//���ߣ���3������ʾ
                    if ((x / 3) % 2 == 0) {
                        drawPoint(x, (int)(y + 0.5), color);
                    }
                };
                if (type == SOLID_LINE) {
                    drawPoint(x, (int)(y + 0.5), color);
                };
                y += k;
            }
        }
        else {
            double y = y2;
            for (int x = x2; x <= x1; x++) {
                if (type == DASH_LINE) {//���ߣ���3������ʾ
                    if ((x / 3) % 2 == 0) {
                        drawPoint(x, (int)(y + 0.5), color);
                    }
                };
                if (type == SOLID_LINE) {
                    drawPoint(x, (int)(y + 0.5), color);
                };
                y += k;
            }
        }
    }
    else {//б�ʾ���ֵ����1�����
        double k = (float)dx / (float)dy;//б��
        if (y1 <= y2) {
            double x = x1;
            for (int y = y1; y <= y2; y++) {
                if (type == DASH_LINE) {//���ߣ���3������ʾ
                    if ((y / 3) % 2 == 0) {
                        drawPoint((int)(x + 0.5), y, color);
                    }
                };
                if (type == SOLID_LINE) {
                    drawPoint((int)(x + 0.5), y, color);
                };
                x += k;
            }
        }
        else {
            double x = x2;
            for (int y = y2; y < y1; y++) {
                if (type == DASH_LINE) {//���ߣ���3������ʾ
                    if ((y / 3) % 2 == 0) {
                        drawPoint((int)(x + 0.5), y, color);
                    }
                };
                if (type == SOLID_LINE) {
                    drawPoint((int)(x + 0.5), y, color);
                };
                x += k;
            }
        }
    }
}
void drawLine(Point p1, Point p2, int color, int type /*= SOLID_LINE*/) {
    drawLine((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y, color, type);
}

//����Ļ�ϻ��ֳ�һ������Ϊ��ʾ����
void drawWindow() {
    drawLine(WINDOW_LEFT, WINDOW_BOTTOM, WINDOW_LEFT, WINDOW_TOP, WHITE);//left
    drawLine(WINDOW_RIGHT, WINDOW_BOTTOM, WINDOW_RIGHT, WINDOW_TOP, WHITE);//right
    drawLine(WINDOW_LEFT, WINDOW_BOTTOM, WINDOW_RIGHT, WINDOW_BOTTOM, WHITE);//bottom    
    drawLine(WINDOW_LEFT, WINDOW_TOP, WINDOW_RIGHT, WINDOW_TOP, WHITE);//top
}
