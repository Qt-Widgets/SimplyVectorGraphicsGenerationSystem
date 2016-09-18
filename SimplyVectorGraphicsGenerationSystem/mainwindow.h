///
/// 头文件mainwindow.h
///
/// 说明：主窗口类MainWindow的声明部分
///
///
/// 创建时间：2012-02-28

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "canvaswidget.h"
#include "cshape.h"

#include "colormanagedialog.h"
#include "precisedrawdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = NULL);

signals:
     void changeCurrentShape(CShape::ShapeName newShape);

public slots:
     void controlModeTriggered();

     void clearTriggered();  //清除屏幕
     void saveTriggered();  //保存文件
     void openTriggered(); //打开文件

     void setBrushPenColorTriggered();//设置填充颜色
     void setBrushPenColor();

     void preciseDrawTriggered();
     void preciseDraw();

     void drawLineActionTriggered();
     void drawRectangleTriggered();
     void drawRectangle_sTriggered();
     void drawCircleTriggered();
     void drawEllipseTriggered();
     void drawTriangleTriggered();
     void drawBezierCurveTriggered();

private:
     QToolBar *bar;
     QActionGroup *group;
     QLabel *statusMsg;
     CanvasWidget *canvasWidget;

     QActionGroup *fileGroup;
     QToolBar *fileBar;

     ColorManageDialog *colorManageDialog;
     PreciseDrawDialog  *preciseDrawDialog;

};

#endif // MAINWINDOW_H
