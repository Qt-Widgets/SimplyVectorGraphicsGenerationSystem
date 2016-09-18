#include "cbeziercurve.h"

//贝塞尔曲线类CBezierCurve的构造函数.
CBezierCurve::CBezierCurve()
{
    this->intermediatePointLeft = QPoint(0,0);
    this->intermediatePointRight = QPoint(0,0);

    this->moveCenter = false;
    this->changeEnd = false;
    this->changeLeft = false;
    this->changRight = false;
}

//绘制贝塞尔曲线:由四个点可以确定多种贝塞尔曲线,本绘制函数仅局限于其中的一种.
void CBezierCurve::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));

    QPainterPath path;                       //创建绘制路径
    path.moveTo(this->startPoint);           //设置初始点
    path.cubicTo(this->intermediatePointLeft,//创建贝塞尔路径
                 this->intermediatePointRight,
                 this->endPoint);
    painter.drawPath(path);                  //绘制路径
}

//显示控制点：包括移动与修改功能.
void CBezierCurve::paintCentral(QPainter &painter){
    //在此区域绘制相关的控制点
    painter.setPen(QPen(Qt::red,1));
    painter.drawEllipse(startPoint,2,2);
    painter.setPen(QPen(Qt::green,1));
    painter.drawEllipse(endPoint,2,2);
    painter.drawEllipse(intermediatePointLeft,2,2);
    painter.drawEllipse(intermediatePointRight,2,2);

    painter.drawLine(startPoint,intermediatePointLeft); //显示控制线Left
    painter.drawLine(endPoint,intermediatePointRight);  //显示控制线Right
}

QString CBezierCurve::getPointMessage()const{
    QString start = QString("%1 %2").arg(this->startPoint.x()).arg(this->startPoint.y());
    QString end = QString("%1 %2").arg(this->endPoint.x()).arg(this->endPoint.y());

    QString left = QString("%1 %2").arg(this->intermediatePointLeft.x()).arg(this->intermediatePointLeft.y());
    QString right = QString("%1 %2").arg(this->intermediatePointRight.x()).arg(this->intermediatePointRight.y());

    return (start + " " + end + " " + left + " " + right);
}

QString CBezierCurve::getColorMessage()const{
    QString colorBrush = QString("%1 %2 %3").arg(
                this->fillColor.red()).arg(this->fillColor.green()).arg(this->fillColor.blue());
    QString colorPen = QString("%1 %2 %3").arg(
                this->penColor.red()).arg(this->penColor.green()).arg(this->penColor.blue());

    return (colorBrush + " " + colorPen + " " + QString::number(this->thick,10));
}

