#include "ctriangle.h"

CTriangle::CTriangle(){
    this->moveCenter = false;
    this->changeLeft = false;
    this->changeRight = false;
}

//绘制三角形:通过三个不在同一直线上的点确定一个三角形.
void CTriangle::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));
    painter.drawLine(this->startPoint,this->endPoint);
    painter.drawLine(this->startPoint,this->centralPoint);
    painter.drawLine(this->centralPoint,this->endPoint);
}

/**
  注：利用鼠标绘制的三角形只能是等腰三角形,但可以在控制修改模式下
     对所绘制的等腰三角形进行拖拉操作,能够创建出任意三角形.
  **/

//显示控制点
void CTriangle::paintCentral(QPainter &painter){
    painter.setPen(QPen(Qt::red,1));
    painter.drawEllipse(startPoint,2,2);
    painter.setPen(QPen(Qt::green,1));
    painter.drawEllipse(centralPoint,2,2);
    painter.drawEllipse(endPoint,2,2);
}


QString CTriangle::getPointMessage()const{
    QString start = QString("%1 %2").arg(this->startPoint.x()).arg(this->startPoint.y());
    QString end = QString("%1 %2").arg(this->endPoint.x()).arg(this->endPoint.y());
    QString central =  QString("%1 %2").arg(this->centralPoint.x()).arg(this->centralPoint.y());


    return start + " " + end + " " + central;
}

QString CTriangle::getColorMessage()const{
    QString colorBrush = QString("%1 %2 %3").arg(
                this->fillColor.red()).arg(this->fillColor.green()).arg(this->fillColor.blue());
    QString colorPen = QString("%1 %2 %3").arg(
                this->penColor.red()).arg(this->penColor.green()).arg(this->penColor.blue());

    return (colorBrush + " " + colorPen + " " + QString::number(this->thick,10));
}

