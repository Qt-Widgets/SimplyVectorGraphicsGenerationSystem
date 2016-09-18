#ifndef CRECTANGLE_S_H
#define CRECTANGLE_S_H

#include "crectangle.h"

class CRectangle_s : public CRectangle
{
public:
    CRectangle_s();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //��ȡʸ��ͼ�ε�����꣺���ַ�����ʽ���
    QString getColorMessage()const;           //��ȡ�����ɫ�뻭����Ϣ�����ַ�����ʽ���
};

#endif // CRECTANGLE_S_H
