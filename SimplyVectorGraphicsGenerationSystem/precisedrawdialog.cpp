#include "precisedrawdialog.h"
#include "ui_precisedrawdialog.h"

PreciseDrawDialog::PreciseDrawDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreciseDrawDialog)
{
    ui->setupUi(this);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(245, 255, 255));
    setPalette(pal);
}

PreciseDrawDialog::~PreciseDrawDialog()
{
    delete ui;
}

void PreciseDrawDialog::on_pushButton_clicked()
{
    emit catchClicked();
}

CShape::ShapeName PreciseDrawDialog::getShapeName()const{
    QString str = this->ui->shapeTypeComboBox->currentText();
    if( str == "直线"){
        return CShape::Line_s;
    }
    else if(str == "矩形"){
        return CShape::Rectangle_s;
    }
    else if(str == "矩形(可填充)"){
          return CShape::Rectangle;
    }
    else if(str == "标准圆"){
          return CShape::Circle;
    }
    else if(str == "椭圆"){
          return CShape::Ellipse;
    }
    else if(str == "三角形"){
          return CShape::Triangle;
    }
    else if(str == "曲线(贝塞尔)"){
          return CShape::BezierCurve;
    }
    else{
         return CShape::Line_s;
    }
}

QPoint PreciseDrawDialog::getStart()const{
    return QPoint(this->ui->startXSpinBox->value(),
                  this->ui->startYSpinBox->value());
}

QPoint PreciseDrawDialog::getEnd()const{
    return QPoint(this->ui->endXSpinBox->value(),
                  this->ui->endYSpinBox->value());
}

QPoint PreciseDrawDialog::getContralA()const{
    return QPoint(this->ui->cAXSpinBox->value(),
                  this->ui->cAYSpinBox->value());
}

QPoint PreciseDrawDialog::getContralB()const{
    return  QPoint(this->ui->cBXSpinBox->value(),
                   this->ui->cBYSpinBox->value());
}
