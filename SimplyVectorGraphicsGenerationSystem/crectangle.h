#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "cshape.h"

class CRectangle : public CShape
{
public:
    CRectangle();
    virtual void paintShape(QPainter &);
    virtual void paintCentral(QPainter &);
    virtual QString getPointMessage()const;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    virtual QString getColorMessage()const;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���

public:
    bool moveCenter;
    bool change;
};

#endif // CRECTANGLE_H
