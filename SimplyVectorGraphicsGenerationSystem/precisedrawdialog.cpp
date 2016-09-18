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
    if( str == "ֱ��"){
        return CShape::Line_s;
    }
    else if(str == "����"){
        return CShape::Rectangle_s;
    }
    else if(str == "����(�����)"){
          return CShape::Rectangle;
    }
    else if(str == "��׼Բ"){
          return CShape::Circle;
    }
    else if(str == "��Բ"){
          return CShape::Ellipse;
    }
    else if(str == "������"){
          return CShape::Triangle;
    }
    else if(str == "����(������)"){
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
