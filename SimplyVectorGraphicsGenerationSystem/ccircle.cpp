#include "ccircle.h"

//��CCircle���캯��
CCircle::CCircle(){
    this->radius = 0;
    this->moveCenter = false;
    this->change = false;
}

//���Ʊ�׼Բ������ȷ��Բ�ĺͰ뾶���Ծ���һ��Բ��ԭ�����.
void CCircle::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));

    double x = this->endPoint.x() - this->startPoint.x();
    double y = this->endPoint.y() - this->startPoint.y();
    this->radius = sqrt(x * x + y * y);
    painter.drawEllipse(this->startPoint.x() - this->radius,
                        this->startPoint.y() - this->radius,this->radius*2,this->radius*2);

}

//���ƿ��Ƶ�
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

