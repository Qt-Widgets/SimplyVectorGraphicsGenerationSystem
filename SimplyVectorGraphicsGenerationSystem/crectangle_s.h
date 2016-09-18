#ifndef CRECTANGLE_S_H
#define CRECTANGLE_S_H

#include "crectangle.h"

class CRectangle_s : public CRectangle
{
public:
    CRectangle_s();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //获取矢量图形点的坐标：以字符的形式输出
    QString getColorMessage()const;           //获取填充颜色与画笔信息：以字符的形式输出
};

#endif // CRECTANGLE_S_H
