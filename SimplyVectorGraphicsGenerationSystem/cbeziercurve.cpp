#include "cbeziercurve.h"

//������������CBezierCurve�Ĺ��캯��.
CBezierCurve::CBezierCurve()
{
    this->intermediatePointLeft = QPoint(0,0);
    this->intermediatePointRight = QPoint(0,0);

    this->moveCenter = false;
    this->changeEnd = false;
    this->changeLeft = false;
    this->changRight = false;
}

//���Ʊ���������:���ĸ������ȷ�����ֱ���������,�����ƺ��������������е�һ��.
void CBezierCurve::paintShape(QPainter &painter){
    painter.setBrush(QBrush(this->fillColor));
    painter.setPen(QPen(this->penColor,this->thick));

    QPainterPath path;                       //��������·��
    path.moveTo(this->startPoint);           //���ó�ʼ��
    path.cubicTo(this->intermediatePointLeft,//����������·��
                 this->intermediatePointRight,
                 this->endPoint);
    painter.drawPath(path);                  //����·��
}

//��ʾ���Ƶ㣺�����ƶ����޸Ĺ���.
void CBezierCurve::paintCentral(QPainter &painter){
    //�ڴ����������صĿ��Ƶ�
    painter.setPen(QPen(Qt::red,1));
    painter.drawEllipse(startPoint,2,2);
    painter.setPen(QPen(Qt::green,1));
    painter.drawEllipse(endPoint,2,2);
    painter.drawEllipse(intermediatePointLeft,2,2);
    painter.drawEllipse(intermediatePointRight,2,2);

    painter.drawLine(startPoint,intermediatePointLeft); //��ʾ������Left
    painter.drawLine(endPoint,intermediatePointRight);  //��ʾ������Right
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

