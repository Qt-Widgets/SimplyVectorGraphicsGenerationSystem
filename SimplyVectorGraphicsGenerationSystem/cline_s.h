#ifndef CLINE_S_H
#define CLINE_S_H

#include "cshape.h"

class CLine_s : public CShape
{
public:
    CLine_s();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    QString getColorMessage()const;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���

public:
    bool moveCenter;         //ͼ���ƶ����
    bool change;             //ͼ���޸ı��
};

#endif // CLINE_S_H
