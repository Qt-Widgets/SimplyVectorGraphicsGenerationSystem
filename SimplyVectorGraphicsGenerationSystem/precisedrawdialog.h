#ifndef PRECISEDRAWDIALOG_H
#define PRECISEDRAWDIALOG_H

#include <QtWidgets>
#include "cshape.h"

namespace Ui {
    class PreciseDrawDialog;
}

class PreciseDrawDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreciseDrawDialog(QWidget *parent = NULL);
    ~PreciseDrawDialog();

signals:
    void catchClicked();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PreciseDrawDialog *ui;


public:
    CShape::ShapeName getShapeName()const;
    QPoint getStart()const;
    QPoint getEnd()const;
    QPoint getContralA()const;
    QPoint getContralB()const;

};

#endif // PRECISEDRAWDIALOG_H
