///===============================================================
/// 源文件cshape.cpp
///
/// 说明：实现基类CShape的构造函数.
///
///
/// 创建时间：2012-02-28
///===============================================================

#include "cshape.h"

CShape::CShape(){
    this->startPoint = QPoint(0,0);
    this->endPoint = QPoint(0,0);
    this->centralPoint = QPoint(0,0);

    this->fillColor = Qt::white;           //默认填充颜色为白色
    this->penColor = Qt::black;            //默认画笔颜色为黑色
    this->thick = 2;                       //默认笔的粗度
}
