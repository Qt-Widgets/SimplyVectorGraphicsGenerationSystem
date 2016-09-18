///=============================================
/// 源文件main.cpp
///
/// 说明：简易矢量图形生成系统应用程序入口.
///
/// 创建日期：2012-02-28
///=============================================

#include <QApplication>
#include <QTextCodec>
#include <QFont>
#include <QtWidgets>

#include "mainwindow.h"

int main(int argc,char *argv[]){
    QApplication app(argc,argv);

//    QTextCodec *codec = QTextCodec::codecForName("system");        //获取系统编码
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
