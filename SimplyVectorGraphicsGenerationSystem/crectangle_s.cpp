#include "crectangle_s.h"

CRectangle_s::CRectangle_s(){
    this->moveCenter = false;
    this->change = false;
}

//绘制矩形：不会覆盖前一图层
void CRectangle_s::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));
    painter.drawLine(this->startPoint.x(),this->startPoint.y(),
                     this->endPoint.x(),this->startPoint.y());
    painter.drawLine(this->startPoint.x(),this->startPoint.y(),
                     this->startPoint.x(),this->endPoint.y());
    painter.drawLine(this->endPoint.x(),this->startPoint.y(),
                     this->endPoint.x(),this->endPoint.y());
    painter.drawLine(this->startPoint.x(),this->endPoint.y(),
                     this->endPoint.x(),this->endPoint.y());
}

//显示控制点
void CRectangle_s::paintCentral(QPainter &painter){
    painter.setPen(QPen(Qt::red,1));
    painter.drawEllipse(startPoint,2,2);
    painter.setPen(QPen(Qt::green,1));
    painter.drawEllipse(endPoint,2,2);
}

QString CRectangle_s::getPointMessage()const{
    QString start = QString("%1 %2").arg(this->startPoint.x()).arg(this->startPoint.y());
    QString end = QString("%1 %2").arg(this->endPoint.x()).arg(this->endPoint.y());
    return (start + " " + end);
}

QString CRectangle_s::getColorMessage()const{
    QString colorBrush = QString("%1 %2 %3").arg(
                this->fillColor.red()).arg(this->fillColor.green()).arg(this->fillColor.blue());
    QString colorPen = QString("%1 %2 %3").arg(
                this->penColor.red()).arg(this->penColor.green()).arg(this->penColor.blue());

    return (colorBrush + " " + colorPen + " " + QString::number(this->thick,10));
}










