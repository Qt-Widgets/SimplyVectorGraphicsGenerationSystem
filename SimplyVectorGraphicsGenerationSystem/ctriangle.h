#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "cshape.h"

class CTriangle : public CShape
{
public:
    CTriangle();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    QString getColorMessage()const;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���

public:
    bool moveCenter;   //�ƶ����Ƶ�
    bool changeLeft;   //���޸ĵ�
    bool changeRight;  //���޸ĵ�
};

#endif // CTRIANGLE_H
