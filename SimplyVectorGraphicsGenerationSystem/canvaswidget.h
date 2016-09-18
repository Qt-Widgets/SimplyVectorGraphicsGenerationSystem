///==============================================================
/// ͷ�ļ�canvaswidget.h
///
/// ˵������CanvasWidget����������.
///      CanvasWidget�̳���QWidget�ؼ���,Ϊ����ʸ��ͼ��������һ��������.
///
///
/// ����ʱ�䣺2012-02-28
///==============================================================

#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QtGui>
#include <iostream>

#include "cshape.h"
#include "cline_s.h"
#include "crectangle.h"
#include "crectangle_s.h"
#include "ctriangle.h"
#include "ccircle.h"
#include "cellipse.h"
#include "cbeziercurve.h"
#include <QtWidgets>

class CanvasWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CanvasWidget(QWidget *parent = NULL);

signals:

public slots:
    void setCurrentShape(CShape::ShapeName);

public:
    CShape::ShapeName shapeName;

    bool showControl;       //��ʾ���Ʊ�ʶ
    bool controlMode;       //����ģʽ

    bool perm;

    CLine_s *line;
    CRectangle *rectangle;
    CRectangle_s *rectangle_s;
    CCircle *circle;
    CEllipse *ellipse;
    CTriangle *triangle;
    CBezierCurve *bezierCurve;

    QList<CLine_s*>  lineVector;
    QList<CRectangle*> rectangleVector;
    QList<CRectangle_s*> rectangle_sVector;
    QList<CCircle*> circleVector;
    QList<CEllipse*> ellipseVector;
    QList<CTriangle*> triangleVector;
    QList<CBezierCurve*> bezierCurveVector;

protected:
    void paintEvent(QPaintEvent *);          //��ͼ�¼���������
    void mousePressEvent(QMouseEvent *);     //������¼���������
    void mouseMoveEvent(QMouseEvent *);      //����ƶ��¼���������
    void mouseReleaseEvent(QMouseEvent *);   //��������ͷ���Ϣ����

public:
    void clear();
    void save(QString const & fileName);
    void open(QString const & fileName);
    void openEdit(QString & line);

    void resetBrushPen(QColor const &,     //�����ɫ
                       QColor const &,     //������ɫ
                       int const &);       //���ʴֶ�

    void getPreciseDrawMsg(CShape::ShapeName const &,
                           QPoint const &,
                           QPoint const &,
                           QPoint const &,
                           QPoint const &);

private:
    QColor currentBrushColor;
    QColor currentPenColor;
    int currentPenThick;

};

#endif // CANVASWIDGET_H
