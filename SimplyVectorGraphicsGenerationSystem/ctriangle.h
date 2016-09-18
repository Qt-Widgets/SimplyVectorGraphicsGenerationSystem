#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "cshape.h"

class CTriangle : public CShape
{
public:
    CTriangle();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //获取矢量图形点的坐标：以字符的形式输出
    QString getColorMessage()const;           //获取填充颜色与画笔信息：以字符的形式输出

public:
    bool moveCenter;   //移动控制点
    bool changeLeft;   //左修改点
    bool changeRight;  //右修改点
};

#endif // CTRIANGLE_H
