#ifndef CBEZIERCURVE_H
#define CBEZIERCURVE_H

#include "cshape.h"

class CBezierCurve : public CShape
{
public:
    CBezierCurve();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    QString getColorMessage()const;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���

public:
    //��ʼ��
    //�յ�
    QPoint intermediatePointLeft; //�м��(���)
    QPoint intermediatePointRight;//�м��(�ұ�)
    //QPoint prevPointL;
    //QPoint nextPointR;
    bool moveCenter;
    bool changeEnd;
    bool changeLeft;
    bool changRight;
};

#endif // CBEZIERCURVE_H
