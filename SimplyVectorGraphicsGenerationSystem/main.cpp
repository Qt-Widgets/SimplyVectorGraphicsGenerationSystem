///=============================================
/// Դ�ļ�main.cpp
///
/// ˵��������ʸ��ͼ������ϵͳӦ�ó������.
///
/// �������ڣ�2012-02-28
///=============================================

#include <QApplication>
#include <QTextCodec>
#include <QFont>
#include <QtWidgets>

#include "mainwindow.h"

int main(int argc,char *argv[]){
    QApplication app(argc,argv);

//    QTextCodec *codec = QTextCodec::codecForName("system");        //��ȡϵͳ����
//    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(codec);
//    QTextCodec::setCodecForTr(codec);

    QFont font = app.font();
    font.setPointSize(10);
    app.setFont(font);

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
