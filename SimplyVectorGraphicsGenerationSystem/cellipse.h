#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "cshape.h"

class CEllipse : public CShape
{
public:
    CEllipse();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //获取矢量图形点的坐标：以字符的形式输出
    QString getColorMessage()const;           //获取填充颜色与画笔信息：以字符的形式输出

public:
    bool moveCenter;
    bool change;
};

#endif // CELLIPSE_H
