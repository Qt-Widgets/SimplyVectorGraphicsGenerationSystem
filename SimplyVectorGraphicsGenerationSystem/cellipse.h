#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "cshape.h"

class CEllipse : public CShape
{
public:
    CEllipse();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    QString getColorMessage()const;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���

public:
    bool moveCenter;
    bool change;
};

#endif // CELLIPSE_H
