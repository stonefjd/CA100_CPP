#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QDebug>
#include <QPainter>
#include <QtMath>
#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include <QApplication>
#include <QSettings>

#include "presetknfmng.h"

#pragma execution_character_set("utf-8")

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actChinese_triggered();

    void on_actEnglish_triggered();

    void on_actGerman_triggered();

    void on_actItalian_triggered();

    void on_pushButton_clicked();
    void on_actPreSettingsKnifeMng_triggered();

signals:
    void sendFileSplit(QStringList);   //用来传递数据的信号
private:
    Ui::MainWindow *ui;
    PreSetKnfMng preSetKnfMng;

    QStringList pathList;
    QString pathSettingFile;

    void settings_FileInit(QString strPath);
    void settings_Language(QString strPath,QString strL);

    void init_Language(QString *str);
    void init_Failed();

};

#endif // MAINWINDOW_H
