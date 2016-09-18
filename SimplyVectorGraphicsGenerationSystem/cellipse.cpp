#include "cellipse.h"

CEllipse::CEllipse(){
    this->moveCenter = false;
    this->change = false;
}

//������Բ������һ�����ΰ���һ����������Բ��Ψһ��ԭ�������Բ
//�ȹ����һ������,�������������Բ.
void CEllipse::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));

    painter.drawEllipse(this->startPoint.x() ,
                       this->startPoint.y() ,this->endPoint.x() - this->startPoint.x(),
                       this->endPoint.y() - this->startPoint.y());

}

void CEllipse::paintCentral(QPainter &painter){
    painter.setPen(QPen(Qt::red,1));
    painter.drawEllipse(startPoint,2,2);
    painter.setPen(QPen(Qt::green,1));
    painter.drawEllipse(endPoint,2,2);
}

QString CEllipse::getPointMessage()const{
    QString start = QString("%1 %2").arg(this->startPoint.x()).arg(this->startPoint.y());
    QString end = QString("%1 %2").arg(this->endPoint.x()).arg(this->endPoint.y());
    return (start + " " + end);
}

QString CEllipse::getColorMessage()const{
    QString colorBrush = QString("%1 %2 %3").arg(
                this->fillColor.red()).arg(this->fillColor.green()).arg(this->fillColor.blue());
    QString colorPen = QString("%1 %2 %3").arg(
                this->penColor.red()).arg(this->penColor.green()).arg(this->penColor.blue());

    return (colorBrush + " " + colorPen + " " + QString::number(this->thick,10));
}

