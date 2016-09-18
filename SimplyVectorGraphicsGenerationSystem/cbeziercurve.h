#ifndef CBEZIERCURVE_H
#define CBEZIERCURVE_H

#include "cshape.h"

class CBezierCurve : public CShape
{
public:
    CBezierCurve();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //获取矢量图形点的坐标：以字符的形式输出
    QString getColorMessage()const;           //获取填充颜色与画笔信息：以字符的形式输出

public:
    //开始点
    //终点
    QPoint intermediatePointLeft; //中间点(左边)
    QPoint intermediatePointRight;//中间点(右边)
    //QPoint prevPointL;
    //QPoint nextPointR;
    bool moveCenter;
    bool changeEnd;
    bool changeLeft;
    bool changRight;
};

#endif // CBEZIERCURVE_H
