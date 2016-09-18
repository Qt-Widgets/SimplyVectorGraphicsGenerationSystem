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
    QString getPointMessage()const;           //获取矢量图形点的坐标：以字符的形式输出
    QString getColorMessage()const;           //获取填充颜色与画笔信息：以字符的形式输出

public:
    bool moveCenter;
    bool change;
    int radius;
};

#endif // CCIRCLE_H
