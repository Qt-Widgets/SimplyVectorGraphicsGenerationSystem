#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "cshape.h"

class CRectangle : public CShape
{
public:
    CRectangle();
    virtual void paintShape(QPainter &);
    virtual void paintCentral(QPainter &);
    virtual QString getPointMessage()const;           //获取矢量图形点的坐标：以字符的形式输出
    virtual QString getColorMessage()const;           //获取填充颜色与画笔信息：以字符的形式输出

public:
    bool moveCenter;
    bool change;
};

#endif // CRECTANGLE_H
