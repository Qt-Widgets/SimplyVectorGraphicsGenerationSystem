///===============================================================
/// Դ�ļ�cshape.cpp
///
/// ˵����ʵ�ֻ���CShape�Ĺ��캯��.
///
///
/// ����ʱ�䣺2012-02-28
///===============================================================

#include "cshape.h"

CShape::CShape(){
    this->startPoint = QPoint(0,0);
    this->endPoint = QPoint(0,0);
    this->centralPoint = QPoint(0,0);

    this->fillColor = Qt::white;           //Ĭ�������ɫΪ��ɫ
    this->penColor = Qt::black;            //Ĭ�ϻ�����ɫΪ��ɫ
    this->thick = 2;                       //Ĭ�ϱʵĴֶ�
}
