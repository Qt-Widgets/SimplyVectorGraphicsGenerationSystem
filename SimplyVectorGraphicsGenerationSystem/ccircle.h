#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "cshape.h"
#include <cmath>

class CCircle : public CShape
{
public:
    CCircle();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    QString getColorMessage()const;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���

public:
    bool moveCenter;
    bool change;
    int radius;
};

#endif // CCIRCLE_H
