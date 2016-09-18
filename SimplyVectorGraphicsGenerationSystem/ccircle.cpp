#include "ccircle.h"

//类CCircle构造函数
CCircle::CCircle(){
    this->radius = 0;
    this->moveCenter = false;
    this->change = false;
}

//绘制标准圆：利用确定圆心和半径可以决定一个圆的原理绘制.
void CCircle::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));

    double x = this->endPoint.x() - this->startPoint.x();
    double y = this->endPoint.y() - this->startPoint.y();
    this->radius = sqrt(x * x + y * y);
    painter.drawEllipse(this->startPoint.x() - this->radius,
                        this->startPoint.y() - this->radius,this->radius*2,this->radius*2);

}

//绘制控制点
void CCircle::paintCentral(QPainter &painter){
    painter.setPen(QPen(Qt::red,1));
    painter.drawEllipse(startPoint,2,2);
    painter.setPen(QPen(Qt::green,1));
    painter.drawEllipse(endPoint,2,2);
}

QString CCircle::getPointMessage()const{
    QString start = QString("%1 %2").arg(this->startPoint.x()).arg(this->startPoint.y());
    QString end = QString("%1 %2").arg(this->endPoint.x()).arg(this->endPoint.y());
    return (start + " " + end);
}

QString CCircle::getColorMessage()const{
    QString colorBrush = QString("%1 %2 %3").arg(
                this->fillColor.red()).arg(this->fillColor.green()).arg(this->fillColor.blue());
    QString colorPen = QString("%1 %2 %3").arg(
                this->penColor.red()).arg(this->penColor.green()).arg(this->penColor.blue());

    return (colorBrush + " " + colorPen + " " + QString::number(this->thick,10));
}

