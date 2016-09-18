///==============================================================
/// Դ�ļ�mainwindow.cpp
///
/// ˵������������MainWindow�ĺ���ʵ�ֲ���
///
///
/// ����ʱ�䣺2012-02-28
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
    this->setWindowTitle (tr("����ʸ��ͼ������ϵͳ"));
    /// ======================================================================================
    this->bar = this->addToolBar(tr("Tool"));
    this->group = new QActionGroup(bar);

    // ����
    QAction *drawLineAction = new QAction("ֱ��",bar);
       drawLineAction->setIcon(QIcon(":/new/image_png/line.png"));
    drawLineAction->setToolTip(tr("��һ��ֱ��"));
    drawLineAction->setStatusTip(tr("��һ��ֱ��"));
    drawLineAction->setCheckable(true);
    drawLineAction->setChecked(true);
    group->addAction(drawLineAction);
    bar->addAction(drawLineAction);

    //������
    QAction *drawRectangleAction = new QAction("����",bar);
    drawRectangleAction->setIcon(QIcon(":/new/image_png/rectangle.png"));
    drawRectangleAction->setToolTip(tr("��һ������(�����)"));
    drawRectangleAction->setStatusTip(tr("��һ������(�����)"));
    drawRectangleAction->setCheckable(true);
    group->addAction(drawRectangleAction);
    bar->addAction(drawRectangleAction);

    //������_s
    QAction *drawRectangle_sAction = new QAction("���ξ���",bar);
    drawRectangle_sAction->setIcon(QIcon(":/new/image_png/rectangle_s.png"));
    drawRectangle_sAction->setToolTip(tr("��һ�����ξ���"));
    drawRectangle_sAction->setStatusTip(tr("��һ�����ξ���"));
    drawRectangle_sAction->setCheckable(true);
    group->addAction(drawRectangle_sAction);
    bar->addAction(drawRectangle_sAction);

    //����׼԰
    QAction *drawCircleAction = new QAction("��׼Բ",bar);
    drawCircleAction->setIcon(QIcon(":/new/image_png/circle.png"));
    drawCircleAction->setToolTip(tr("��һ����׼Բ"));
    drawCircleAction->setStatusTip(tr("��һ����׼Բ"));
    drawCircleAction->setCheckable(true);
    group->addAction(drawCircleAction);
    bar->addAction(drawCircleAction);

    //����Բ
    QAction *drawEllipseAction = new QAction("��Բ",bar);
    drawEllipseAction->setIcon(QIcon(":/new/image_png/ellipse.png"));
    drawEllipseAction->setToolTip(tr("��һ����Բ"));
    drawEllipseAction->setStatusTip(tr("��һ����Բ"));
    drawEllipseAction->setCheckable(true);
    group->addAction(drawEllipseAction);
    bar->addAction(drawEllipseAction);

    //��������
    QAction *drawTriangleAction = new QAction("������",bar);
    drawTriangleAction->setIcon(QIcon(":/new/image_png/triangle.png"));
    drawTriangleAction->setToolTip(tr("��һ��������"));
    drawTriangleAction->setStatusTip(tr("��һ��������"));
    drawTriangleAction->setCheckable(true);
    group->addAction(drawTriangleAction);
    bar->addAction(drawTriangleAction);

    //������������
    QAction *drawBezierCurveAction = new QAction("����������",bar);
    drawBezierCurveAction->setIcon(QIcon(":/new/image_png/bezier_curve.png"));
    drawBezierCurveAction->setToolTip(tr("��һ������(����������)"));
    drawBezierCurveAction->setStatusTip(tr("��һ������(����������)"));
    drawBezierCurveAction->setCheckable(true);
    group->addAction(drawBezierCurveAction);
    bar->addAction(drawBezierCurveAction);

    // ����ģʽ
    QAction *controlModeAction = new QAction("����ģʽ",bar);
    controlModeAction->setIcon(QIcon(":/new/image_png/control_mode.png"));
    controlModeAction->setToolTip(tr("����ģʽ"));
    controlModeAction->setStatusTip(tr("����ģʽ"));
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
    clearAction->setToolTip(tr("�������"));
    clearAction->setStatusTip(tr("�������"));
    clearAction->setCheckable(true);
    this->fileGroup->addAction(clearAction);
    this->fileBar->addAction(clearAction);

    QAction *openAction = new QAction(tr("Save"),this->fileBar);
    openAction->setIcon(QIcon(":/new/image_png/open.png"));
    openAction->setToolTip(tr("��ʸ��ͼ"));
    openAction->setStatusTip(tr("��ʸ��ͼ"));
    openAction->setCheckable(true);
    this->fileGroup->addAction(openAction);
    this->fileBar->addAction(openAction);

    QAction *saveAction = new QAction(tr("Save"),this->fileBar);
    saveAction->setIcon(QIcon(":/new/image_png/save.png"));
    saveAction->setToolTip(tr("����ʸ��ͼ"));
    saveAction->setStatusTip(tr("����ʸ��ͼ"));
    saveAction->setCheckable(true);
    this->fileGroup->addAction(saveAction);
    this->fileBar->addAction(saveAction);

    QAction *setBrushColorAction = new QAction(tr("Brush"),this->fileBar);
    setBrushColorAction->setIcon(QIcon(":/new/image_png/ColorManageDialog.png"));
    setBrushColorAction->setToolTip(tr("���ɫ�뻭�ʹ���"));
    setBrushColorAction->setStatusTip(tr("���ɫ�뻭�ʹ���"));
    setBrushColorAction->setCheckable(true);
    this->fileGroup->addAction(setBrushColorAction);
    this->fileBar->addAction(setBrushColorAction);

    QAction *preciseDrawAction = new QAction(tr("Brush"),this->fileBar);
    preciseDrawAction->setIcon(QIcon(":/new/image_png/PreciseDrawDialog.png"));
    preciseDrawAction->setToolTip(tr("��ȷ��ͼ"));
    preciseDrawAction->setStatusTip(tr("��ȷ��ͼ"));
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

///�������
void MainWindow::clearTriggered(){
    this->canvasWidget->clear();
}

///������Ƶ�ʸ��ͼ��
void MainWindow::saveTriggered(){
    QString filename = QFileDialog::getSaveFileName(this,tr("SAVE_File"),"d://","Shape Files(*.txt)");
    if(!filename.isEmpty())
        this->canvasWidget->save(filename);
}

///���������ɫ
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


//�ۺ���
void MainWindow::preciseDraw(){
    this->canvasWidget->getPreciseDrawMsg(this->preciseDrawDialog->getShapeName(),
                                          this->preciseDrawDialog->getStart(),
                                          this->preciseDrawDialog->getEnd(),
                                          this->preciseDrawDialog->getContralA(),
                                          this->preciseDrawDialog->getContralB());
}
