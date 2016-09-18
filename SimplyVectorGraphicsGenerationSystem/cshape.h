///===============================================================
/// 头文件cshape.h
///
/// 说明：基类CShape的声明部分.包括大部分基础矢量图形的基本属性与功能.
///
///
/// 创建时间：2012-02-28
///===============================================================

#ifndef CSHAPE_H
#define CSHAPE_H

#include <QtGui>

class CShape
{
public:
    CShape();
    virtual void paintShape(QPainter &) = 0;    //纯虚函数：绘制图形
    virtual void paintCentral(QPainter &) = 0;  //纯虚函数：显示控制点,方面对图形的修改操作
    virtual QString getPointMessage()const = 0;           //获取矢量图形点的坐标：以字符的形式输出
    virtual QString getColorMessage()const = 0;           //获取填充颜色与画笔信息：以字符的形式输出


public:
    QPoint startPoint;     //开始点
    QPoint centralPoint;   //中心点
    QPoint endPoint;       //结束点
    QColor fillColor;      //填充颜色
    QColor penColor;       //画笔颜色
    int thick;             //粗度

    enum ShapeName{
        Line_s,      //线(并非利用贝塞尔曲线绘制而成)
        Rectangle,   //矩形
        Rectangle_s, //矩形(无覆盖)
        Circle,      //标准圆
        Triangle,    //三角形
        Ellipse,     //椭圆
        BezierCurve, //贝塞尔曲线
        Control      //控制
    };
};

#endif // CSHAPE_H
