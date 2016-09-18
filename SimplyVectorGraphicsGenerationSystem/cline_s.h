#ifndef CLINE_S_H
#define CLINE_S_H

#include "cshape.h"

class CLine_s : public CShape
{
public:
    CLine_s();
    void paintShape(QPainter &);
    void paintCentral(QPainter &);
    QString getPointMessage()const;           //获取矢量图形点的坐标：以字符的形式输出
    QString getColorMessage()const;           //获取填充颜色与画笔信息：以字符的形式输出

public:
    bool moveCenter;         //图形移动标记
    bool change;             //图形修改标记
};

#endif // CLINE_S_H
