#ifndef COLORMANAGEDIALOG_H
#define COLORMANAGEDIALOG_H

#include <QDialog>
#include <QColor>
#include <QPalette>

namespace Ui {
    class ColorManageDialog;
}

class ColorManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ColorManageDialog(QWidget *parent = NULL);
    ~ColorManageDialog();

private:
    Ui::ColorManageDialog *ui;

signals:
    void catchClicked();

public slots:
    void on_acquiescencePushButton_clicked();

    void on_okPushButton_clicked();

public:
    QColor getBrushColor()const;
    QColor getPenColor()const;
    int getThick()const;
};

#endif // COLORMANAGEDIALOG_H
