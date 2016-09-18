///===============================================================
/// ͷ�ļ�cshape.h
///
/// ˵��������CShape����������.�����󲿷ֻ���ʸ��ͼ�εĻ��������빦��.
///
///
/// ����ʱ�䣺2012-02-28
///===============================================================

#ifndef CSHAPE_H
#define CSHAPE_H

#include <QtGui>

class CShape
{
public:
    CShape();
    virtual void paintShape(QPainter &) = 0;    //���麯��������ͼ��
    virtual void paintCentral(QPainter &) = 0;  //���麯������ʾ���Ƶ�,�����ͼ�ε��޸Ĳ���
    virtual QString getPointMessage()const = 0;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    virtual QString getColorMessage()const = 0;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���


public:
    QPoint startPoint;     //��ʼ��
    QPoint centralPoint;   //���ĵ�
    QPoint endPoint;       //������
    QColor fillColor;      //�����ɫ
    QColor penColor;       //������ɫ
    int thick;             //�ֶ�

    enum ShapeName{
        Line_s,      //��(�������ñ��������߻��ƶ���)
        Rectangle,   //����
        Rectangle_s, //����(�޸���)
        Circle,      //��׼Բ
        Triangle,    //������
        Ellipse,     //��Բ
        BezierCurve, //����������
        Control      //����
    };
};

#endif // CSHAPE_H
