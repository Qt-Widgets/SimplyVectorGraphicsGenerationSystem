#include "colormanagedialog.h"
#include "ui_colormanagedialog.h"

ColorManageDialog::ColorManageDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ColorManageDialog)
{
    ui->setupUi(this);
    //this->setWindowTitle(tr("填充颜色与画笔管理"));

    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(245, 255, 255));
    setPalette(pal);


    //Brush
    this->ui->redBrushSpinBox->setRange(0,255);
    this->ui->redBrushHorizontalSlider->setRange(0,255);
    this->ui->redBrushSpinBox->setValue(255);

    this->ui->greenBrushSpinBox->setRange(0,255);
    this->ui->greenBrushHorizontalSlider->setRange(0,255);
    this->ui->greenBrushSpinBox->setValue(255);

    this->ui->blueBrushSpinBox->setRange(0,255);
    this->ui->blueBrushHorizontalSlider->setRange(0,255);
    this->ui->blueBrushSpinBox->setValue(255);

    //Pen
    this->ui->redPenSpinBox->setRange(0,255);
    this->ui->redPenHorizontalSlider->setRange(0,255);
    this->ui->redPenSpinBox->setValue(0);

    this->ui->greenPenSpinBox->setRange(0,255);
    this->ui->greenPenHorizontalSlider->setRange(0,255);
    this->ui->greenPenSpinBox->setValue(0);

    this->ui->bluePenSpinBox->setRange(0,255);
    this->ui->bluePenHorizontalSlider->setRange(0,255);
    this->ui->bluePenSpinBox->setValue(0);

    this->ui->thickPenSpinBox->setRange(1,5);
    this->ui->thickPenHorizontalSlider->setRange(1,5);
    this->ui->thickPenSpinBox->setValue(2);


    connect(this->ui->acquiescencePushButton,SIGNAL(clicked()),
            this,SLOT(on_acquiescencePushButton_clicked()));

}

ColorManageDialog::~ColorManageDialog()
{
    delete ui;
}


//恢复默认设置
void ColorManageDialog::on_acquiescencePushButton_clicked()
{
    this->ui->redBrushSpinBox->setValue(255);
    this->ui->greenBrushSpinBox->setValue(255);
    this->ui->blueBrushSpinBox->setValue(255);

    this->ui->redPenSpinBox->setValue(0);
    this->ui->greenPenSpinBox->setValue(0);
    this->ui->bluePenSpinBox->setValue(0);
    this->ui->thickPenSpinBox->setValue(2);
}

QColor ColorManageDialog::getBrushColor()const{
    return QColor(this->ui->redBrushSpinBox->value(),
                  this->ui->greenBrushSpinBox->value(),
                  this->ui->blueBrushSpinBox->value());
}

QColor ColorManageDialog::getPenColor()const{
    return QColor(this->ui->redPenSpinBox->value(),
                  this->ui->greenPenSpinBox->value(),
                  this->ui->bluePenSpinBox->value());
}

int ColorManageDialog::getThick()const{
    return this->ui->thickPenSpinBox->value();
}

void ColorManageDialog::on_okPushButton_clicked()
{
    emit catchClicked();
}
