#include "cline_s.h"

CLine_s::CLine_s(){
    this->moveCenter = false;
    this->change = false;
}

/// 绘制直线：通过两点确定一条直线的原理.
void CLine_s::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));
    painter.drawLine(this->startPoint,this->endPoint);
}

/// 显示控制点：方便鼠标控制图形进行修改操作.
void CLine_s::paintCentral(QPainter &painter){
    painter.setPen(QPen(Qt::red,1));
    painter.drawEllipse(startPoint,2,2);
    painter.setPen(QPen(Qt::green,1));
    painter.drawEllipse(endPoint,2,2);
}

///QString s = QString("%1").arg(a);

QString CLine_s::getPointMessage()const{
    QString start = QString("%1 %2").arg(this->startPoint.x()).arg(this->startPoint.y());
    QString end = QString("%1 %2").arg(this->endPoint.x()).arg(this->endPoint.y());
    return (start + " " + end);
}

QString CLine_s::getColorMessage()const{
    QString colorBrush = QString("%1 %2 %3").arg(
                this->fillColor.red()).arg(this->fillColor.green()).arg(this->fillColor.blue());
    QString colorPen = QString("%1 %2 %3").arg(
                this->penColor.red()).arg(this->penColor.green()).arg(this->penColor.blue());

    return (colorBrush + " " + colorPen + " " + QString::number(this->thick,10));
}
