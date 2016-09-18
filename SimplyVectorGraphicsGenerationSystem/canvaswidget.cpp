#include "canvaswidget.h"

//构造函数
CanvasWidget::CanvasWidget(QWidget *parent) :
    QWidget(parent){

    this->setCursor(Qt::CrossCursor);

    this->showControl = true;
    this->controlMode = false;
    this->perm = false;
    this->shapeName = CShape::Line_s;

    this->line = NULL;
    this->rectangle = NULL;
    this->rectangle_s = NULL;
    this->circle = NULL;
    this->ellipse = NULL;
    this->triangle = NULL;
    this->bezierCurve = NULL;

    this->currentBrushColor = QColor(255,255,255);
    this->currentPenColor = QColor(0,0,0);
    this->currentPenThick = 2;

}

///清除
void CanvasWidget::clear(){
    this->lineVector.clear();
    this->rectangleVector.clear();
    this->rectangle_sVector.clear();
    this->circleVector.clear();
    this->ellipseVector.clear();
    this->triangleVector.clear();
    this->bezierCurveVector.clear();
    update();
}

///打开
void CanvasWidget::open(QString const & fileName){
    QFile ifile(fileName);
    QTextStream in;

    QString line;

    //清理当前矢量图信息
    this->clear();

    if (!ifile.open(QFile::ReadOnly | QFile::Text)) {    //打开读入文件
           std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                     << ": " << qPrintable(ifile.errorString())
                     << std::endl;
           exit(1);
       }

    in.setDevice(&ifile);
    while(!in.atEnd()){
        line = in.readLine();
        this->openEdit(line);
    }

    ifile.close();
}

//读取文件编辑：获取文件中的矢量图信息
//按行处理
void CanvasWidget::openEdit(QString & line){
    QStringList list = line.split(" ",QString::SkipEmptyParts);

    if(list.at(0) == "1"){//直线
        this->line = new CLine_s;

        this->line->startPoint.setX(list.at(1).toInt());
        this->line->startPoint.setY(list.at(2).toInt());
        this->line->endPoint.setX(list.at(3).toInt());
        this->line->endPoint.setY(list.at(4).toInt());

        this->line->fillColor = QColor(list.at(5).toInt(),
                                       list.at(6).toInt(),
                                       list.at(7).toInt());
        this->line->penColor = QColor(list.at(8).toInt(),
                                       list.at(9).toInt(),
                                       list.at(10).toInt());
        this->line->thick = list.at(11).toInt();
        this->lineVector<<this->line;
    }
   else if(list.at(0) == "2"){//矩形
        this->rectangle = new CRectangle;

        this->rectangle->startPoint.setX(list.at(1).toInt());
        this->rectangle->startPoint.setY(list.at(2).toInt());
        this->rectangle->endPoint.setX(list.at(3).toInt());
        this->rectangle->endPoint.setY(list.at(4).toInt());

        this->rectangle->fillColor = QColor(list.at(5).toInt(),
                                       list.at(6).toInt(),
                                       list.at(7).toInt());
        this->rectangle->penColor = QColor(list.at(8).toInt(),
                                       list.at(9).toInt(),
                                       list.at(10).toInt());
        this->rectangle->thick = list.at(11).toInt();
        this->rectangleVector<<rectangle;
    }
    else if(list.at(0) == "3"){//几何矩形
        this->rectangle = new CRectangle_s;

        this->rectangle_s->startPoint.setX(list.at(1).toInt());
        this->rectangle_s->startPoint.setY(list.at(2).toInt());
        this->rectangle_s->endPoint.setX(list.at(3).toInt());
        this->rectangle_s->endPoint.setY(list.at(4).toInt());

        this->rectangle_s->fillColor = QColor(list.at(5).toInt(),
                                       list.at(6).toInt(),
                                       list.at(7).toInt());
        this->rectangle_s->penColor = QColor(list.at(8).toInt(),
                                       list.at(9).toInt(),
                                       list.at(10).toInt());
        this->rectangle_s->thick = list.at(11).toInt();
        this->rectangle_sVector<<rectangle_s;
    }
    else if(list.at(0) == "4"){//标准圆
        this->circle = new CCircle;

        this->circle->startPoint.setX(list.at(1).toInt());
        this->circle->startPoint.setY(list.at(2).toInt());
        this->circle->endPoint.setX(list.at(3).toInt());
        this->circle->endPoint.setY(list.at(4).toInt());

        this->circle->fillColor = QColor(list.at(5).toInt(),
                                       list.at(6).toInt(),
                                       list.at(7).toInt());
        this->circle->penColor = QColor(list.at(8).toInt(),
                                       list.at(9).toInt(),
                                       list.at(10).toInt());
        this->circle->thick = list.at(11).toInt();
        this->circleVector<<circle;
    }
    else if(list.at(0) == "5"){//椭圆
        this->ellipse = new CEllipse;

        this->ellipse->startPoint.setX(list.at(1).toInt());
        this->ellipse->startPoint.setY(list.at(2).toInt());
        this->ellipse->endPoint.setX(list.at(3).toInt());
        this->ellipse->endPoint.setY(list.at(4).toInt());

        this->ellipse->fillColor = QColor(list.at(5).toInt(),
                                       list.at(6).toInt(),
                                       list.at(7).toInt());
        this->ellipse->penColor = QColor(list.at(8).toInt(),
                                       list.at(9).toInt(),
                                       list.at(10).toInt());
        this->ellipse->thick = list.at(11).toInt();
        this->ellipseVector<<ellipse;
    }
    else if(list.at(0) == "6"){//三角形
        this->triangle = new CTriangle;

        this->triangle->startPoint.setX(list.at(1).toInt());
        this->triangle->startPoint.setY(list.at(2).toInt());
        this->triangle->endPoint.setX(list.at(3).toInt());
        this->triangle->endPoint.setY(list.at(4).toInt());
        this->triangle->centralPoint.setX(list.at(5).toInt());
        this->triangle->centralPoint.setY(list.at(6).toInt());

        this->triangle->fillColor = QColor(list.at(7).toInt(),
                                       list.at(8).toInt(),
                                       list.at(9).toInt());
        this->triangle->penColor = QColor(list.at(10).toInt(),
                                       list.at(11).toInt(),
                                       list.at(12).toInt());
        this->triangle->thick = list.at(13).toInt();
        this->triangleVector<<triangle;
    }
    else if(list.at(0) == "7"){//贝塞尔曲线
        this->bezierCurve = new CBezierCurve;

        this->bezierCurve->startPoint.setX(list.at(1).toInt());
        this->bezierCurve->startPoint.setY(list.at(2).toInt());
        this->bezierCurve->endPoint.setX(list.at(3).toInt());
        this->bezierCurve->endPoint.setY(list.at(4).toInt());

        this->bezierCurve->intermediatePointLeft.setX(list.at(5).toInt());
        this->bezierCurve->intermediatePointLeft.setY(list.at(6).toInt());
        this->bezierCurve->intermediatePointRight.setX(list.at(7).toInt());
        this->bezierCurve->intermediatePointRight.setY(list.at(8).toInt());

        this->bezierCurve->fillColor = QColor(list.at(9).toInt(),
                                       list.at(10).toInt(),
                                       list.at(11).toInt());
        this->bezierCurve->penColor = QColor(list.at(12).toInt(),
                                       list.at(13).toInt(),
                                       list.at(14).toInt());
        this->bezierCurve->thick = list.at(15).toInt();
        this->bezierCurveVector<<bezierCurve;
    }
}

///保存
void CanvasWidget::save(QString const & fileName){

    QString record;

    QTextStream writes;
    QFile ofile(fileName);

    if(!ofile.open(QFile::WriteOnly | QFile::Append)){
        std::cerr<<"错误:无法写入文件！"<<qPrintable(fileName)
                <<":"<<qPrintable(ofile.errorString())
               <<std::endl;
    }
    writes.setDevice(&ofile);

    /// [1]
    for(int i = 0;i < this->lineVector.size();i++){
        QStringList res;
        res<<"1"<<this->lineVector.at(i)->getPointMessage()
          <<this->lineVector.at(i)->getColorMessage();
        record = res.join(" ");
        writes<<record;
        writes<<"\r\n";
    }
    /// [2]
    for(int i = 0;i < this->rectangleVector.size();i++){
        QStringList res;
        res<<"2"<<this->rectangleVector.at(i)->getPointMessage()
          <<this->rectangleVector.at(i)->getColorMessage();
        record = res.join(" ");
        writes<<record;
        writes<<"\r\n";
    }

    /// [3]
    for(int i = 0;i < this->rectangle_sVector.size();i++){
        QStringList res;
        res<<"3"<<this->rectangle_sVector.at(i)->getPointMessage()
          <<this->rectangle_sVector.at(i)->getColorMessage();
        record = res.join(" ");
        writes<<record;
        writes<<"\r\n";
    }

    /// [4]
    for(int i = 0;i < this->circleVector.size();i++){
        QStringList res;
        res<<"4"<<this->circleVector.at(i)->getPointMessage()
          <<this->circleVector.at(i)->getColorMessage();
        record = res.join(" ");
        writes<<record;
        writes<<"\r\n";
    }

    /// [5]
    for(int i = 0;i < this->ellipseVector.size();i++){
        QStringList res;
        res<<"5"<<this->ellipseVector.at(i)->getPointMessage()
          <<this->ellipseVector.at(i)->getColorMessage();
        record = res.join(" ");
        writes<<record;
        writes<<"\r\n";
    }

    /// [6]
    for(int i = 0;i < this->triangleVector.size();i++){
        QStringList res;
        res<<"6"<<this->triangleVector.at(i)->getPointMessage()
          <<this->triangleVector.at(i)->getColorMessage();
        record = res.join(" ");
        writes<<record;
        writes<<"\r\n";
    }

    /// [7]
    for(int i = 0;i < this->bezierCurveVector.size();i++){
        QStringList res;
        res<<"7"<<this->bezierCurveVector.at(i)->getPointMessage()
          <<this->bezierCurveVector.at(i)->getColorMessage();
        record = res.join(" ");
        writes<<record;
        writes<<"\r\n";
    }

    ofile.close();
}

///重置填充色与画笔
void CanvasWidget::resetBrushPen(QColor const &brushColor,
                                 QColor const &penColor,
                                 int const &thick)
{
    this->currentBrushColor = brushColor;
    this->currentPenColor = penColor;
    this->currentPenThick = thick;
}

///槽函数
void CanvasWidget::setCurrentShape(CShape::ShapeName shapeName){
    if(shapeName != CShape::Control){
        this->shapeName = shapeName;
        this->controlMode = false;
        this->setCursor(Qt::CrossCursor);
    }
    else if(this->shapeName != shapeName){
        this->controlMode = true;
        this->setCursor(Qt::PointingHandCursor);
    }
}


void CanvasWidget::getPreciseDrawMsg(CShape::ShapeName const &type,
                       QPoint const &start,
                       QPoint const &end,
                       QPoint const &contralA,
                       QPoint const &contralB){
    switch(type){
    case CShape::Line_s:
    {//CLine_s
        line = new CLine_s;
        perm = true;
        this->lineVector<< line;
        line->fillColor = this->currentBrushColor;
        line->penColor = this->currentPenColor;
        line->thick = this->currentPenThick;
        line->startPoint = start;
        line->endPoint = end;
    }
        break;
    case CShape::Rectangle:
    {//CRectangle
        this->rectangle = new CRectangle;
        perm = true;
        rectangle->fillColor = this->currentBrushColor;
        rectangle->penColor = this->currentPenColor;
        rectangle->thick = this->currentPenThick;
        this->rectangleVector<<this->rectangle;
        this->rectangle->startPoint = start;
        this->rectangle->endPoint = end;
    }
        break;
    case CShape::Rectangle_s:
    {//CRectangle_s
        this->rectangle_s = new CRectangle_s;
        perm = true;
        rectangle_s->fillColor = this->currentBrushColor;
        rectangle_s->penColor = this->currentPenColor;
        rectangle_s->thick = this->currentPenThick;
        this->rectangle_sVector<<this->rectangle_s;
        this->rectangle_s->startPoint = start;
        this->rectangle_s->endPoint = end;
    }
        break;
    case CShape::Circle:
    {//CCircle
        this->circle = new CCircle;
        perm = true;
        circle->fillColor = this->currentBrushColor;
        circle->penColor = this->currentPenColor;
        circle->thick = this->currentPenThick;
        this->circleVector<<this->circle;
        this->circle->startPoint = start;
        this->circle->endPoint = end;
    }
        break;
    case CShape::Ellipse:
    {//CEllipse
        this->ellipse = new CEllipse;
        perm = true;
        ellipse->fillColor = this->currentBrushColor;
        ellipse->penColor = this->currentPenColor;
        ellipse->thick = this->currentPenThick;
        this->ellipseVector<<this->ellipse;
        this->ellipse->startPoint = start;
        this->ellipse->endPoint = end;
    }
        break;
    case CShape::Triangle:
    {//CTriangle
        this->triangle = new CTriangle;
        perm = true;
        triangle->fillColor = this->currentBrushColor;
        triangle->penColor = this->currentPenColor;
        triangle->thick = this->currentPenThick;
        this->triangleVector<<this->triangle;
        this->triangle->startPoint = start;
        this->triangle->endPoint = end;
        this->triangle->centralPoint = contralA;
    }
        break;
    case CShape::BezierCurve:
    {//CBezierCurve
        this->bezierCurve = new CBezierCurve;
        perm = true;
        bezierCurve->fillColor = this->currentBrushColor;
        bezierCurve->penColor = this->currentPenColor;
        bezierCurve->thick = this->currentPenThick;
        this->bezierCurveVector<<this->bezierCurve;
        this->bezierCurve->startPoint = start;
        this->bezierCurve->intermediatePointLeft = contralA;
        this->bezierCurve->endPoint = end;
        this->bezierCurve->intermediatePointRight = contralB;
    }
        break;
    default:
        break;
    }
    update();
}

//绘图事件函数重载
void CanvasWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);//启用反走样
    painter.setBrush(Qt::white);
    //设置背景颜色为白色
    painter.drawRect(0,0,this->size().width(),this->size().height());

    //设置画笔为黑色
    painter.setPen(QPen(this->currentPenColor,this->currentPenThick));

    /// 画出所有的线段
    foreach(CLine_s *line,this->lineVector){
        line->paintShape(painter);
        if(this->showControl){
            line->paintCentral(painter);
        }
    }

    /// 画出所有矩形
    foreach(CRectangle *rectangle,this->rectangleVector){
        rectangle->paintShape(painter);
        if(this->showControl){
            rectangle->paintCentral(painter);
        }
    }

    /// 画出所有矩形_s
    foreach(CRectangle_s *rectangle_s,this->rectangle_sVector){
        rectangle_s->paintShape(painter);
        if(this->showControl){
            rectangle_s->paintCentral(painter);
        }
    }

    /// 画出所有的标准圆
    foreach(CCircle *circle,this->circleVector){
        circle->paintShape(painter);
        if(this->showControl){
            circle->paintCentral(painter);
        }
    }

    /// 画出所有的椭圆
    foreach(CEllipse *ellipse,this->ellipseVector){
        ellipse->paintShape(painter);
        if(this->showControl){
            ellipse->paintCentral(painter);
        }
    }

    /// 画出所有的三角形
    foreach(CTriangle *triangle,this->triangleVector){
        triangle->paintShape(painter);
        if(this->showControl){
            triangle->paintCentral(painter);
        }
    }

    /// 画出曲线(仅能画一段曲线)
    foreach(CBezierCurve *bezierCurve,this->bezierCurveVector){
        bezierCurve->paintShape(painter);
        if(this->showControl){
            bezierCurve->paintCentral(painter);
        }
    }

}
/// 鼠标点击事件
void CanvasWidget::mousePressEvent(QMouseEvent *event){

    if(event->button () == Qt::LeftButton){
        if(!this->controlMode){
            switch(this->shapeName){
            case CShape::Line_s:
            {//CLine_s
                line = new CLine_s;
                perm = true;
                this->lineVector<< line;
                line->fillColor = this->currentBrushColor;
                line->penColor = this->currentPenColor;
                line->thick = this->currentPenThick;
                line->startPoint = event->pos();
                line->endPoint = event->pos();
            }
                break;
            case CShape::Rectangle:
            {//CRectangle
                this->rectangle = new CRectangle;
                perm = true;
                rectangle->fillColor = this->currentBrushColor;
                rectangle->penColor = this->currentPenColor;
                rectangle->thick = this->currentPenThick;
                this->rectangleVector<<this->rectangle;
                this->rectangle->startPoint = event->pos();
                this->rectangle->endPoint = event->pos();
            }
                break;
            case CShape::Rectangle_s:
            {//CRectangle_s
                this->rectangle_s = new CRectangle_s;
                perm = true;
                rectangle_s->fillColor = this->currentBrushColor;
                rectangle_s->penColor = this->currentPenColor;
                rectangle_s->thick = this->currentPenThick;
                this->rectangle_sVector<<this->rectangle_s;
                this->rectangle_s->startPoint = event->pos();
                this->rectangle_s->endPoint = event->pos();
            }
                break;
            case CShape::Circle:
            {//CCircle
                this->circle = new CCircle;
                perm = true;
                circle->fillColor = this->currentBrushColor;
                circle->penColor = this->currentPenColor;
                circle->thick = this->currentPenThick;
                this->circleVector<<this->circle;
                this->circle->startPoint = event->pos();
                this->circle->endPoint = event->pos();
            }
                break;
            case CShape::Ellipse:
            {//CEllipse
                this->ellipse = new CEllipse;
                perm = true;
                ellipse->fillColor = this->currentBrushColor;
                ellipse->penColor = this->currentPenColor;
                ellipse->thick = this->currentPenThick;
                this->ellipseVector<<this->ellipse;
                this->ellipse->startPoint = event->pos();
                this->ellipse->endPoint = event->pos();
            }
                break;
            case CShape::Triangle:
            {//CTriangle
                this->triangle = new CTriangle;
                perm = true;
                triangle->fillColor = this->currentBrushColor;
                triangle->penColor = this->currentPenColor;
                triangle->thick = this->currentPenThick;
                this->triangleVector<<this->triangle;
                this->triangle->startPoint = event->pos ();
                this->triangle->endPoint = event->pos ();
                this->triangle->centralPoint = event->pos ();
            }
                break;
            case CShape::BezierCurve:
            {//CBezierCurve
                this->bezierCurve = new CBezierCurve;
                perm = true;
                bezierCurve->fillColor = this->currentBrushColor;
                bezierCurve->penColor = this->currentPenColor;
                bezierCurve->thick = this->currentPenThick;
                this->bezierCurveVector<<this->bezierCurve;
                this->bezierCurve->startPoint = event->pos();
                this->bezierCurve->intermediatePointLeft = QPoint(
                            event->pos().x() + 20,event->pos().y() + 20);
                this->bezierCurve->endPoint = event->pos();
                this->bezierCurve->intermediatePointRight = QPoint(
                            event->pos().x() - 20,event->pos().y() - 20);
            }
                break;
            default:
                break;
            }
        }
        else{//控制模式
            /// lineVector [1]
            for(int i = 0; i < this->lineVector.size();i++){
                QRect center = QRect(this->lineVector.at(i)->startPoint.x() - 10,
                                     this->lineVector.at(i)->startPoint.y() - 10,20,20);
                QRect changeR = QRect(this->lineVector.at(i)->endPoint.x() - 10,
                                      this->lineVector.at(i)->endPoint.y() - 10,20,20);
                if(center.contains(event->pos())){
                    this->lineVector.at(i)->moveCenter = true;
                    int x = event->pos().x() - this->lineVector.at(i)->startPoint.x();
                    int y = event->pos().y() - this->lineVector.at(i)->startPoint.y();

                    this->lineVector.at(i)->startPoint = event->pos();
                    this->lineVector.at(i)->endPoint.setX(this->lineVector.at(i)->endPoint.x() + x);
                    this->lineVector.at(i)->endPoint.setY(this->lineVector.at(i)->endPoint.y() + y);
                    update();
                    break;
                }
                else if(changeR.contains(event->pos())){
                    this->lineVector.at(i)->change = true;
                    this->lineVector.at(i)->endPoint = event->pos();
                }
            }

            /// rectangleVector[2]
            for(int i = 0;i < this->rectangleVector.size();i++){
                QRect center = QRect(this->rectangleVector.at(i)->startPoint.x() - 10,
                                     this->rectangleVector.at(i)->startPoint.y() - 10,20,20);
                QRect changeR = QRect(this->rectangleVector.at(i)->endPoint.x() - 10,
                                      this->rectangleVector.at(i)->endPoint.y() - 10,20,20);
                if(center.contains(event->pos())){
                    this->rectangleVector.at(i)->moveCenter = true;
                    int x = event->pos().x() - this->rectangleVector.at(i)->startPoint.x();
                    int y = event->pos().y() - this->rectangleVector.at(i)->startPoint.y();

                    this->rectangleVector.at(i)->startPoint = event->pos();
                    this->rectangleVector.at(i)->endPoint.setX(this->rectangleVector.at(i)->endPoint.x() + x);
                    this->rectangleVector.at(i)->endPoint.setY(this->rectangleVector.at(i)->endPoint.y() + y);
                    update();
                    break;
                }
                else if(changeR.contains(event->pos())){
                    this->rectangleVector.at(i)->change = true;
                    this->rectangleVector.at(i)->endPoint = event->pos();
                }
            }

            /// rectangle_sVector[3]
            for(int i = 0;i < this->rectangle_sVector.size();i++){
                QRect center = QRect(this->rectangle_sVector.at(i)->startPoint.x() - 10,
                                     this->rectangle_sVector.at(i)->startPoint.y() - 10,20,20);
                QRect changeR = QRect(this->rectangle_sVector.at(i)->endPoint.x() - 10,
                                      this->rectangle_sVector.at(i)->endPoint.y() - 10,20,20);
                if(center.contains(event->pos())){
                    this->rectangle_sVector.at(i)->moveCenter = true;
                    int x = event->pos().x() - this->rectangle_sVector.at(i)->startPoint.x();
                    int y = event->pos().y() - this->rectangle_sVector.at(i)->startPoint.y();

                    this->rectangle_sVector.at(i)->startPoint = event->pos();
                    this->rectangle_sVector.at(i)->endPoint.setX(this->rectangle_sVector.at(i)->endPoint.x() + x);
                    this->rectangle_sVector.at(i)->endPoint.setY(this->rectangle_sVector.at(i)->endPoint.y() + y);
                    update();
                    break;
                }
                else if(changeR.contains(event->pos())){
                    this->rectangle_sVector.at(i)->change = true;
                    this->rectangle_sVector.at(i)->endPoint = event->pos();
                }
            }

            /// circleVector [4]
            for(int i = 0;i < this->circleVector.size();i++){
                QRect center = QRect(this->circleVector.at(i)->startPoint.x() - 10,
                                     this->circleVector.at(i)->startPoint.y() - 10,20,20);
                QRect changeR = QRect(this->circleVector.at(i)->endPoint.x() - 10,
                                      this->circleVector.at(i)->endPoint.y() - 10,20,20);
                if(center.contains(event->pos())){
                    this->circleVector.at(i)->moveCenter = true;
                    int x = event->pos().x() - this->circleVector.at(i)->startPoint.x();
                    int y = event->pos().y() - this->circleVector.at(i)->startPoint.y();

                    this->circleVector.at(i)->startPoint = event->pos();
                    this->circleVector.at(i)->endPoint.setX(this->circleVector.at(i)->endPoint.x() + x);
                    this->circleVector.at(i)->endPoint.setY(this->circleVector.at(i)->endPoint.y() + y);
                    update();
                    break;
                }
                else if(changeR.contains(event->pos())){
                    this->circleVector.at(i)->change = true;
                    this->circleVector.at(i)->endPoint = event->pos();
                }
            }

            /// ellipseVector [5]
            for(int i = 0;i < this->ellipseVector.size();i++){
                QRect center = QRect(this->ellipseVector.at(i)->startPoint.x() - 10,
                                     this->ellipseVector.at(i)->startPoint.y() - 10,20,20);
                QRect changeR = QRect(this->ellipseVector.at(i)->endPoint.x() - 10,
                                      this->ellipseVector.at(i)->endPoint.y() - 10,20,20);
                if(center.contains(event->pos())){
                    this->ellipseVector.at(i)->moveCenter = true;
                    int x = event->pos().x() - this->ellipseVector.at(i)->startPoint.x();
                    int y = event->pos().y() - this->ellipseVector.at(i)->startPoint.y();

                    this->ellipseVector.at(i)->startPoint = event->pos();
                    this->ellipseVector.at(i)->endPoint.setX(this->ellipseVector.at(i)->endPoint.x() + x);
                    this->ellipseVector.at(i)->endPoint.setY(this->ellipseVector.at(i)->endPoint.y() + y);
                    update();
                    break;
                }
                else if(changeR.contains(event->pos())){
                    this->ellipseVector.at(i)->change = true;
                    this->ellipseVector.at(i)->endPoint = event->pos();
                }
            }

            /// triangleVector [6]
            for(int i = 0;i < this->triangleVector.size();i++){
                QRect center = QRect(this->triangleVector.at(i)->startPoint.x() - 10,
                                     this->triangleVector.at(i)->startPoint.y() - 10,20,20);
                QRect changeR = QRect(this->triangleVector.at(i)->endPoint.x() - 10,
                                      this->triangleVector.at(i)->endPoint.y() - 10,20,20);
                QRect changeL = QRect(this->triangleVector.at (i)->centralPoint.x () - 10,
                                      this->triangleVector.at (i)->centralPoint.y () - 10,20,20);
                if(center.contains(event->pos())){
                    this->triangleVector.at(i)->moveCenter = true;
                    int x = event->pos().x() - this->triangleVector.at(i)->startPoint.x();
                    int y = event->pos().y() - this->triangleVector.at(i)->startPoint.y();

                    this->triangleVector.at(i)->startPoint = event->pos();
                    this->triangleVector.at(i)->endPoint.setX(this->triangleVector.at(i)->endPoint.x() + x);
                    this->triangleVector.at(i)->endPoint.setY(this->triangleVector.at(i)->endPoint.y() + y);
                    update();
                    break;
                }
                else if(changeR.contains(event->pos())){
                    this->triangleVector.at(i)->changeRight= true;
                    this->triangleVector.at(i)->endPoint = event->pos();
                }
                else if(changeL.contains(event->pos())){
                    this->triangleVector.at(i)->changeLeft = true;
                    this->triangleVector.at(i)->centralPoint = event->pos();
                }
            }

            /// bezierCurveVector [7]
            for(int i = 0; i < this->bezierCurveVector.size();i++){
                QRect center = QRect(this->bezierCurveVector.at(i)->startPoint.x() - 10,
                                     this->bezierCurveVector.at(i)->startPoint.y() - 10,20,20);
                QRect changeEnd = QRect(this->bezierCurveVector.at(i)->endPoint.x() - 10,
                                        this->bezierCurveVector.at(i)->endPoint.y() - 10,20,20);
                QRect changeLeft = QRect(this->bezierCurveVector.at(i)->intermediatePointLeft.x() - 10,
                                         this->bezierCurveVector.at(i)->intermediatePointLeft.y() - 10,20,20);
                QRect changeRight = QRect(this->bezierCurveVector.at(i)->intermediatePointRight.x() - 10,
                                          this->bezierCurveVector.at(i)->intermediatePointRight.y() - 10,20,20);
                if(center.contains(event->pos())){
                    this->bezierCurveVector.at(i)->moveCenter = true;
                    int x = event->pos().x() - this->bezierCurveVector.at(i)->startPoint.x();
                    int y = event->pos().y() - this->bezierCurveVector.at(i)->startPoint.y();

                    this->bezierCurveVector.at(i)->startPoint = event->pos();
                    this->bezierCurveVector.at(i)->endPoint.setX(this->bezierCurveVector.at(i)->endPoint.x() + x);
                    this->bezierCurveVector.at(i)->endPoint.setY(this->bezierCurveVector.at(i)->endPoint.y() + y);
                    this->bezierCurveVector.at(i)->intermediatePointLeft.setX(
                                this->bezierCurveVector.at(i)->intermediatePointLeft.x() + x);
                    this->bezierCurveVector.at(i)->intermediatePointRight.setX(
                                this->bezierCurveVector.at(i)->intermediatePointRight.x() + x);

                    update();
                    break;
                }
                else if(changeEnd.contains(event->pos())){
                    this->bezierCurveVector.at(i)->changeEnd = true;
                    this->bezierCurveVector.at(i)->endPoint = event->pos();
                }
                else if(changeLeft.contains(event->pos())){
                    this->bezierCurveVector.at(i)->changeLeft = true;
                    this->bezierCurveVector.at(i)->intermediatePointLeft = event->pos();
                }
                else if(changeRight.contains(event->pos())){
                    this->bezierCurveVector.at(i)->changRight = true;
                    this->bezierCurveVector.at(i)->intermediatePointRight = event->pos();
                }
            }


        }
    }
    else if(event->button () == Qt::RightButton){
        this->showControl = this->showControl == true ? false : true;
    }

    update();
}

//鼠标移动事件函数重载
void CanvasWidget::mouseMoveEvent(QMouseEvent *event){
    if(!this->controlMode){
        switch(this->shapeName){
        case CShape::Line_s:
        {//CLine_s
            if(line && perm){
                this->line->endPoint = event->pos();
            }
        }
            break;
        case CShape::Rectangle:
        {//CRectangle
            if(this->rectangle && perm){
                this->rectangle->endPoint = event->pos();
            }
        }
            break;
        case CShape::Rectangle_s:
        {//CRectangle_s
            if(this->rectangle_s && perm){
                this->rectangle_s->endPoint = event->pos();
            }
        }
            break;
        case CShape::Circle:
        {
            if(this->circle && perm){
                this->circle->endPoint = event->pos();
            }
        }
            break;
        case CShape::Ellipse:
        {
            if(this->ellipse && perm){
                this->ellipse->endPoint = event->pos();
            }
        }
            break;
        case CShape::Triangle:
        {
            if(this->triangle && perm){
                this->triangle->endPoint = event->pos ();
                this->triangle->centralPoint = QPoint(
                            2 * this->triangle->startPoint.x() -
                            event->pos ().x (),event->pos ().y ());
            }
        }
            break;
        case CShape::BezierCurve:
        {
            if(this->bezierCurve && perm){
                this->bezierCurve->endPoint = event->pos();
                this->bezierCurve->intermediatePointRight = QPoint(
                            event->pos().x() - 20,event->pos().y() - 20);
            }
        }
            break;
        default:
            break;
        }
    }
    else{
        /// line
        for(int i = 0; i < this->lineVector.size();i++){
            if(this->lineVector.at(i)->moveCenter){
                int x = event->pos().x() - this->lineVector.at(i)->startPoint.x();
                int y = event->pos().y() - this->lineVector.at(i)->startPoint.y();

                this->lineVector.at(i)->startPoint = event->pos();
                this->lineVector.at(i)->endPoint.setX(this->lineVector.at(i)->endPoint.x() + x);
                this->lineVector.at(i)->endPoint.setY(this->lineVector.at(i)->endPoint.y() + y);
                update();
                break;
            }
            else if(this->lineVector.at(i)->change){
                this->lineVector.at(i)->endPoint = event->pos();
            }
        }

        /// rectangleVector
        for(int i = 0;i < this->rectangleVector.size();i++){
            if(this->rectangleVector.at(i)->moveCenter){
                int x = event->pos().x() - this->rectangleVector.at(i)->startPoint.x();
                int y = event->pos().y() - this->rectangleVector.at(i)->startPoint.y();

                this->rectangleVector.at(i)->startPoint = event->pos();
                this->rectangleVector.at(i)->endPoint.setX(this->rectangleVector.at(i)->endPoint.x() + x);
                this->rectangleVector.at(i)->endPoint.setY(this->rectangleVector.at(i)->endPoint.y() + y);
                update();
                break;
            }
            else if(this->rectangleVector.at(i)->change){
                this->rectangleVector.at(i)->endPoint = event->pos();
            }
        }

        /// rectangle_sVector
        for(int i = 0;i < this->rectangle_sVector.size();i++){
            if(this->rectangle_sVector.at(i)->moveCenter){
                int x = event->pos().x() - this->rectangle_sVector.at(i)->startPoint.x();
                int y = event->pos().y() - this->rectangle_sVector.at(i)->startPoint.y();

                this->rectangle_sVector.at(i)->startPoint = event->pos();
                this->rectangle_sVector.at(i)->endPoint.setX(this->rectangle_sVector.at(i)->endPoint.x() + x);
                this->rectangle_sVector.at(i)->endPoint.setY(this->rectangle_sVector.at(i)->endPoint.y() + y);
                update();
                break;
            }
            else if(this->rectangle_sVector.at(i)->change){
                this->rectangle_sVector.at(i)->endPoint = event->pos();
            }
        }

        /// circleVector
        for(int i = 0;i < this->circleVector.size();i++){
            if(this->circleVector.at(i)->moveCenter){
                int x = event->pos().x() - this->circleVector.at(i)->startPoint.x();
                int y = event->pos().y() - this->circleVector.at(i)->startPoint.y();

                this->circleVector.at(i)->startPoint = event->pos();
                this->circleVector.at(i)->endPoint.setX(this->circleVector.at(i)->endPoint.x() + x);
                this->circleVector.at(i)->endPoint.setY(this->circleVector.at(i)->endPoint.y() + y);
                update();
                break;
            }
            else if(this->circleVector.at(i)->change){
                this->circleVector.at(i)->endPoint = event->pos();
            }
        }

        /// ellipseVector
        for(int i = 0;i < this->ellipseVector.size();i++){
            if(this->ellipseVector.at(i)->moveCenter){
                int x = event->pos().x() - this->ellipseVector.at(i)->startPoint.x();
                int y = event->pos().y() - this->ellipseVector.at(i)->startPoint.y();

                this->ellipseVector.at(i)->startPoint = event->pos();
                this->ellipseVector.at(i)->endPoint.setX(this->ellipseVector.at(i)->endPoint.x() + x);
                this->ellipseVector.at(i)->endPoint.setY(this->ellipseVector.at(i)->endPoint.y() + y);
                update();
                break;
            }
            else if(this->ellipseVector.at(i)->change){
                this->ellipseVector.at(i)->endPoint = event->pos();
            }
        }

        /// triangleVector
        for(int i = 0;i < this->triangleVector.size();i++){
            if(this->triangleVector.at(i)->moveCenter){
                int x = event->pos().x() - this->triangleVector.at(i)->startPoint.x();
                int y = event->pos().y() - this->triangleVector.at(i)->startPoint.y();

                this->triangleVector.at(i)->startPoint = event->pos();
                this->triangleVector.at(i)->endPoint.setX(this->triangleVector.at(i)->endPoint.x() + x);
                this->triangleVector.at(i)->endPoint.setY(this->triangleVector.at(i)->endPoint.y() + y);
                this->triangleVector.at(i)->centralPoint.setX(this->triangleVector.at(i)->centralPoint.x() + x);
                this->triangleVector.at(i)->centralPoint.setY(this->triangleVector.at(i)->centralPoint.y() + y);
                update();
                break;
            }
            else if(this->triangleVector.at(i)->changeRight){
                this->triangleVector.at(i)->endPoint = event->pos();
            }
            else if(this->triangleVector.at(i)->changeLeft){
                this->triangleVector.at (i)->centralPoint = event->pos ();
            }
        }

        /// bezierCurveVector
        for(int i = 0; i < this->bezierCurveVector.size();i++){
            if(this->bezierCurveVector.at(i)->moveCenter){
                int x = event->pos().x() - this->bezierCurveVector.at(i)->startPoint.x();
                int y = event->pos().y() - this->bezierCurveVector.at(i)->startPoint.y();

                this->bezierCurveVector.at(i)->startPoint = event->pos();

                this->bezierCurveVector.at(i)->endPoint.setX(this->bezierCurveVector.at(i)->endPoint.x() + x);
                this->bezierCurveVector.at(i)->endPoint.setY(this->bezierCurveVector.at(i)->endPoint.y() + y);

                this->bezierCurveVector.at(i)->intermediatePointLeft.setX(
                            this->bezierCurveVector.at(i)->intermediatePointLeft.x() + x);
                this->bezierCurveVector.at(i)->intermediatePointLeft.setY(
                            this->bezierCurveVector.at(i)->intermediatePointLeft.y() + y);

                this->bezierCurveVector.at(i)->intermediatePointRight.setX(
                            this->bezierCurveVector.at(i)->intermediatePointRight.x() + x);
                this->bezierCurveVector.at(i)->intermediatePointRight.setY(
                            this->bezierCurveVector.at(i)->intermediatePointRight.y() + y);

                update();
                break;
            }
            else if(this->bezierCurveVector.at(i)->changeEnd){
                this->bezierCurveVector.at(i)->endPoint = event->pos();
            }
            else if(this->bezierCurveVector.at(i)->changeLeft){
                this->bezierCurveVector.at(i)->intermediatePointLeft = event->pos();
            }
            else if(this->bezierCurveVector.at(i)->changRight){
                this->bezierCurveVector.at(i)->intermediatePointRight = event->pos();
            }
        }
    }
    update();
}


void CanvasWidget::mouseReleaseEvent(QMouseEvent *){
    if(!this->controlMode){
        if(this->shapeName != CShape::Control){
            perm = false;
        }
    }
    else{
        for(int i = 0; i < this->lineVector.size();i++){
            if(this->lineVector.at(i)->moveCenter)
                this->lineVector.at(i)->moveCenter = false;
            else if(this->lineVector.at(i)->change)
                this->lineVector.at(i)->change = false;
        }
        for(int i = 0; i < this->rectangleVector.size();i++){
            if(this->rectangleVector.at(i)->moveCenter)
                this->rectangleVector.at(i)->moveCenter = false;
            else if(this->rectangleVector.at(i)->change)
                this->rectangleVector.at(i)->change = false;
        }
        for(int i = 0; i < this->rectangle_sVector.size();i++){
            if(this->rectangle_sVector.at(i)->moveCenter)
                this->rectangle_sVector.at(i)->moveCenter = false;
            else if(this->rectangle_sVector.at(i)->change)
                this->rectangle_sVector.at(i)->change = false;
        }
        for(int i = 0; i < this->circleVector.size();i++){
            if(this->circleVector.at(i)->moveCenter)
                this->circleVector.at(i)->moveCenter = false;
            else if(this->circleVector.at(i)->change)
                this->circleVector.at(i)->change = false;
        }
        for(int i = 0; i < this->ellipseVector.size();i++){
            if(this->ellipseVector.at(i)->moveCenter)
                this->ellipseVector.at(i)->moveCenter = false;
            else if(this->ellipseVector.at(i)->change)
                this->ellipseVector.at(i)->change = false;
        }
        for(int i = 0; i < this->triangleVector.size();i++){
            if(this->triangleVector.at(i)->moveCenter)
                this->triangleVector.at(i)->moveCenter = false;
            else if(this->triangleVector.at(i)->changeLeft)
                this->triangleVector.at(i)->changeLeft = false;
            else if(this->triangleVector.at (i)->changeRight)
                this->triangleVector.at (i)->changeRight = false;
        }
        for(int i = 0; i < this->bezierCurveVector.size();i++){
            if(this->bezierCurveVector.at(i)->changeEnd)
                this->bezierCurveVector.at(i)->changeEnd = false;
            else if(this->bezierCurveVector.at(i)->moveCenter)
                this->bezierCurveVector.at(i)->moveCenter = false;
            else if(this->bezierCurveVector.at(i)->changeLeft)
                this->bezierCurveVector.at(i)->changeLeft = false;
            else if(this->bezierCurveVector.at(i)->changRight)
                this->bezierCurveVector.at(i)->changRight = false;
        }
    }
}
