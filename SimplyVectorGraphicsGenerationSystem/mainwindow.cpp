///==============================================================
/// 源文件mainwindow.cpp
///
/// 说明：主窗口类MainWindow的函数实现部分
///
///
/// 创建时间：2012-02-28
///=============================================================

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){
#ifdef Q_WS_X11
    setAttribute(Qt::WA_TranslucentBackground, true);
#endif


    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(245, 255, 255));
    setPalette(pal);

    this->resize (1280,720);
    this->setWindowIcon(QIcon(":/new/image_png/vector.png"));
    this->setWindowTitle (tr("简易矢量图形生成系统"));
    /// ======================================================================================
    this->bar = this->addToolBar(tr("Tool"));
    this->group = new QActionGroup(bar);

    // 画线
    QAction *drawLineAction = new QAction("直线",bar);
       drawLineAction->setIcon(QIcon(":/new/image_png/line.png"));
    drawLineAction->setToolTip(tr("画一条直线"));
    drawLineAction->setStatusTip(tr("画一条直线"));
    drawLineAction->setCheckable(true);
    drawLineAction->setChecked(true);
    group->addAction(drawLineAction);
    bar->addAction(drawLineAction);

    //画矩形
    QAction *drawRectangleAction = new QAction("矩形",bar);
    drawRectangleAction->setIcon(QIcon(":/new/image_png/rectangle.png"));
    drawRectangleAction->setToolTip(tr("画一个矩形(可填充)"));
    drawRectangleAction->setStatusTip(tr("画一个矩形(可填充)"));
    drawRectangleAction->setCheckable(true);
    group->addAction(drawRectangleAction);
    bar->addAction(drawRectangleAction);

    //画矩形_s
    QAction *drawRectangle_sAction = new QAction("几何矩形",bar);
    drawRectangle_sAction->setIcon(QIcon(":/new/image_png/rectangle_s.png"));
    drawRectangle_sAction->setToolTip(tr("画一个几何矩形"));
    drawRectangle_sAction->setStatusTip(tr("画一个几何矩形"));
    drawRectangle_sAction->setCheckable(true);
    group->addAction(drawRectangle_sAction);
    bar->addAction(drawRectangle_sAction);

    //画标准园
    QAction *drawCircleAction = new QAction("标准圆",bar);
    drawCircleAction->setIcon(QIcon(":/new/image_png/circle.png"));
    drawCircleAction->setToolTip(tr("画一个标准圆"));
    drawCircleAction->setStatusTip(tr("画一个标准圆"));
    drawCircleAction->setCheckable(true);
    group->addAction(drawCircleAction);
    bar->addAction(drawCircleAction);

    //画椭圆
    QAction *drawEllipseAction = new QAction("椭圆",bar);
    drawEllipseAction->setIcon(QIcon(":/new/image_png/ellipse.png"));
    drawEllipseAction->setToolTip(tr("画一个椭圆"));
    drawEllipseAction->setStatusTip(tr("画一个椭圆"));
    drawEllipseAction->setCheckable(true);
    group->addAction(drawEllipseAction);
    bar->addAction(drawEllipseAction);

    //画三角形
    QAction *drawTriangleAction = new QAction("三角形",bar);
    drawTriangleAction->setIcon(QIcon(":/new/image_png/triangle.png"));
    drawTriangleAction->setToolTip(tr("画一个三角形"));
    drawTriangleAction->setStatusTip(tr("画一个三角形"));
    drawTriangleAction->setCheckable(true);
    group->addAction(drawTriangleAction);
    bar->addAction(drawTriangleAction);

    //画贝塞尔曲线
    QAction *drawBezierCurveAction = new QAction("贝塞尔曲线",bar);
    drawBezierCurveAction->setIcon(QIcon(":/new/image_png/bezier_curve.png"));
    drawBezierCurveAction->setToolTip(tr("画一段曲线(贝塞尔曲线)"));
    drawBezierCurveAction->setStatusTip(tr("画一段曲线(贝塞尔曲线)"));
    drawBezierCurveAction->setCheckable(true);
    group->addAction(drawBezierCurveAction);
    bar->addAction(drawBezierCurveAction);

    // 控制模式
    QAction *controlModeAction = new QAction("控制模式",bar);
    controlModeAction->setIcon(QIcon(":/new/image_png/control_mode.png"));
    controlModeAction->setToolTip(tr("控制模式"));
    controlModeAction->setStatusTip(tr("控制模式"));
    controlModeAction->setCheckable(true);
    controlModeAction->setChecked(false);
    group->addAction(controlModeAction);
    bar->addAction(controlModeAction);


    this->statusMsg = new QLabel;
    statusBar()->addWidget(statusMsg);

    this->canvasWidget = new CanvasWidget(this);
    setCentralWidget(canvasWidget);

    connect(controlModeAction,SIGNAL(triggered()),this,
            SLOT(controlModeTriggered()));
    connect(drawLineAction,SIGNAL(triggered()),this,
            SLOT(drawLineActionTriggered()));
    connect(drawRectangleAction,SIGNAL(triggered()),this,
            SLOT(drawRectangleTriggered()));
    connect(drawRectangle_sAction,SIGNAL(triggered()),this,
            SLOT(drawRectangle_sTriggered()));
    connect(drawCircleAction,SIGNAL(triggered()),this,
            SLOT(drawCircleTriggered()));
    connect(drawEllipseAction,SIGNAL(triggered()),this,
            SLOT(drawEllipseTriggered()));
    connect(drawTriangleAction,SIGNAL(triggered()),this,
            SLOT(drawTriangleTriggered()));
    connect(drawBezierCurveAction,SIGNAL(triggered()),this,
            SLOT(drawBezierCurveTriggered()));

    connect(this,SIGNAL(changeCurrentShape(CShape::ShapeName)),
            canvasWidget,SLOT(setCurrentShape(CShape::ShapeName)));

    /// =======================================================================


    this->colorManageDialog = new ColorManageDialog(this);
    this->preciseDrawDialog = new PreciseDrawDialog(this);

    this->fileBar = this->addToolBar(tr("File"));
    this->fileGroup = new QActionGroup(this->fileBar);

    QAction *clearAction = new QAction(tr("Clear"),this->fileBar);
    clearAction->setIcon(QIcon(":/new/image_png/clear.png"));
    clearAction->setToolTip(tr("清除画板"));
    clearAction->setStatusTip(tr("清除画板"));
    clearAction->setCheckable(true);
    this->fileGroup->addAction(clearAction);
    this->fileBar->addAction(clearAction);

    QAction *openAction = new QAction(tr("Save"),this->fileBar);
    openAction->setIcon(QIcon(":/new/image_png/open.png"));
    openAction->setToolTip(tr("打开矢量图"));
    openAction->setStatusTip(tr("打开矢量图"));
    openAction->setCheckable(true);
    this->fileGroup->addAction(openAction);
    this->fileBar->addAction(openAction);

    QAction *saveAction = new QAction(tr("Save"),this->fileBar);
    saveAction->setIcon(QIcon(":/new/image_png/save.png"));
    saveAction->setToolTip(tr("保存矢量图"));
    saveAction->setStatusTip(tr("保存矢量图"));
    saveAction->setCheckable(true);
    this->fileGroup->addAction(saveAction);
    this->fileBar->addAction(saveAction);

    QAction *setBrushColorAction = new QAction(tr("Brush"),this->fileBar);
    setBrushColorAction->setIcon(QIcon(":/new/image_png/ColorManageDialog.png"));
    setBrushColorAction->setToolTip(tr("填充色与画笔管理"));
    setBrushColorAction->setStatusTip(tr("填充色与画笔管理"));
    setBrushColorAction->setCheckable(true);
    this->fileGroup->addAction(setBrushColorAction);
    this->fileBar->addAction(setBrushColorAction);

    QAction *preciseDrawAction = new QAction(tr("Brush"),this->fileBar);
    preciseDrawAction->setIcon(QIcon(":/new/image_png/PreciseDrawDialog.png"));
    preciseDrawAction->setToolTip(tr("精确绘图"));
    preciseDrawAction->setStatusTip(tr("精确绘图"));
    preciseDrawAction->setCheckable(true);
    this->fileGroup->addAction(preciseDrawAction);
    this->fileBar->addAction(preciseDrawAction);

    connect(clearAction,SIGNAL(triggered()),this,SLOT(clearTriggered()));
    connect(openAction,SIGNAL(triggered()),this,SLOT(openTriggered()));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(saveTriggered()));
    connect(this->colorManageDialog,SIGNAL(catchClicked()),this,SLOT(setBrushPenColor()));
    connect(this->preciseDrawDialog,SIGNAL(catchClicked()),this,SLOT(preciseDraw()));
    connect(preciseDrawAction,SIGNAL(triggered()),this,SLOT(preciseDrawTriggered()));

    connect(setBrushColorAction,SIGNAL(triggered()),this,
            SLOT(setBrushPenColorTriggered()));

}

void MainWindow::drawLineActionTriggered(){
    emit changeCurrentShape(CShape::Line_s);
}

void MainWindow::drawRectangleTriggered(){
    emit changeCurrentShape(CShape::Rectangle);
}

void MainWindow::controlModeTriggered(){
    emit changeCurrentShape(CShape::Control);
}

void MainWindow::drawRectangle_sTriggered(){
    emit changeCurrentShape(CShape::Rectangle_s);
}

void MainWindow::drawCircleTriggered(){
    emit changeCurrentShape(CShape::Circle);
}

void MainWindow::drawEllipseTriggered(){
    emit changeCurrentShape(CShape::Ellipse);
}

void MainWindow::drawTriangleTriggered(){
    emit changeCurrentShape(CShape::Triangle);
}

void MainWindow::drawBezierCurveTriggered(){
    emit changeCurrentShape(CShape::BezierCurve);
}

///清除画板
void MainWindow::clearTriggered(){
    this->canvasWidget->clear();
}

///保存绘制的矢量图形
void MainWindow::saveTriggered(){
    QString filename = QFileDialog::getSaveFileName(this,tr("SAVE_File"),"d://","Shape Files(*.txt)");
    if(!filename.isEmpty())
        this->canvasWidget->save(filename);
}

///设置填充颜色
void MainWindow::setBrushPenColorTriggered(){
    colorManageDialog->exec();
}

void MainWindow::setBrushPenColor(){
    this->canvasWidget->resetBrushPen(
                colorManageDialog->getBrushColor(),
                colorManageDialog->getPenColor(),
                colorManageDialog->getThick());
}
void MainWindow::openTriggered(){

    QString filename = QFileDialog::getOpenFileName(this,tr("OPEN_File"),tr("D://"),tr("Shape File(*.txt)"));
    if(!filename.isEmpty())
        this->canvasWidget->open(filename);

}


void MainWindow::preciseDrawTriggered(){
    this->preciseDrawDialog->exec();
}


//槽函数
void MainWindow::preciseDraw(){
    this->canvasWidget->getPreciseDrawMsg(this->preciseDrawDialog->getShapeName(),
                                          this->preciseDrawDialog->getStart(),
                                          this->preciseDrawDialog->getEnd(),
                                          this->preciseDrawDialog->getContralA(),
                                          this->preciseDrawDialog->getContralB());
}
