///==============================================================
/// 头文件canvaswidget.h
///
/// 说明：类CanvasWidget的声明部分.
///      CanvasWidget继承子QWidget控件类,为绘制矢量图而创建的一个画板类.
///
///
/// 创建时间：2012-02-28
///==============================================================

#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QtGui>
#include <iostream>

#include "cshape.h"
#include "cline_s.h"
#include "crectangle.h"
#include "crectangle_s.h"
#include "ctriangle.h"
#include "ccircle.h"
#include "cellipse.h"
#include "cbeziercurve.h"
#include <QtWidgets>

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = NULL);

signals:

public slots:
    void setCurrentShape(CShape::ShapeName);

public:
    CShape::ShapeName shapeName;

    bool showControl;       //显示控制标识
    bool controlMode;       //控制模式

    bool perm;

    CLine_s *line;
    CRectangle *rectangle;
    CRectangle_s *rectangle_s;
    CCircle *circle;
    CEllipse *ellipse;
    CTriangle *triangle;
    CBezierCurve *bezierCurve;

    QList<CLine_s*>  lineVector;
    QList<CRectangle*> rectangleVector;
    QList<CRectangle_s*> rectangle_sVector;
    QList<CCircle*> circleVector;
    QList<CEllipse*> ellipseVector;
    QList<CTriangle*> triangleVector;
    QList<CBezierCurve*> bezierCurveVector;

protected:
    void paintEvent(QPaintEvent *);          //绘图事件函数重载
    void mousePressEvent(QMouseEvent *);     //鼠标点击事件函数重载
    void mouseMoveEvent(QMouseEvent *);      //鼠标移动事件函数重载
    void mouseReleaseEvent(QMouseEvent *);   //鼠标点击后释放消息重载

public:
    void clear();
    void save(QString const & fileName);
    void open(QString const & fileName);
    void openEdit(QString & line);

    void resetBrushPen(QColor const &,     //填充颜色
                       QColor const &,     //画笔颜色
                       int const &);       //画笔粗度

    void getPreciseDrawMsg(CShape::ShapeName const &,
                           QPoint const &,
                           QPoint const &,
                           QPoint const &,
                           QPoint const &);

private:
    QColor currentBrushColor;
    QColor currentPenColor;
    int currentPenThick;

};

#endif // CANVASWIDGET_H
