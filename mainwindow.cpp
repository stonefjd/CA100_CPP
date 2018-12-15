#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //--connect singal and solt
    connect(this,SIGNAL(sendFileSplit(QStringList)),ui->paintMainWedget,SLOT(receiveFileSplit(QStringList)));

    //--check cfg files
    this->pathSettingFile = "Settings\\settings.ini";
    QFile file(this->pathSettingFile);
    QMessageBox settingFileMsgBox;
    QSettings settingsCfg(this->pathSettingFile,QSettings::IniFormat);

    if(!file.exists())
    {
        //remind for init files
        QMessageBox::information(this,QObject::tr("提示"),QObject::tr("初始化文件已缺失，\n重新初始化文件设置"),QObject::tr("确定"));//setText(QObject::tr("软件配置文件不存在，以默认文件进行创建"))

        //initial write files
        settings_FileInit(this->pathSettingFile);
    }

    //-----read files for init
    //--language init
    QString strLanguage;
    strLanguage = settingsCfg.value("Language").toString();
    init_Language(&strLanguage);

}
void MainWindow::init_Language(QString *str)
{
    if(!str->compare("Chinese"))
    {
        on_actChinese_triggered();
    }
    else if(!str->compare("English"))
    {
        on_actEnglish_triggered();
    }
    else if(!str->compare("German"))
    {

    }
    else if(!str->compare("Italian"))
    {

    }
    else
        init_Failed();
}
void MainWindow::settings_Language(QString strPath,QString strL)
{
    QSettings settingsCfg(strPath,QSettings::IniFormat);
    settingsCfg.setValue("hh/dd/Language",strL);
}
void MainWindow::init_Failed()
{
    qDebug()<<"Init_Failed";
}
void MainWindow::settings_FileInit(QString strPath)
{
    settings_Language(strPath,"Chinese");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actChinese_triggered()
{
    QTranslator translation(qApp);
    qApp->removeTranslator(&translation);
    ui->retranslateUi(this);
    settings_Language(this->pathSettingFile,"Chinese");
}

void MainWindow::on_actEnglish_triggered()
{
    QTranslator translation(qApp);
    translation.load("PGM_en.qm"); //加载翻译的文件
    qApp->installTranslator(&translation);
    ui->retranslateUi(this);
    settings_Language(this->pathSettingFile,"English");
}

void MainWindow::on_actGerman_triggered()
{

}

void MainWindow::on_actItalian_triggered()
{

}
void MainWindow::on_actPreSettingsKnifeMng_triggered()
{
    this->preSetKnfMng.exec();
}
void MainWindow::on_pushButton_clicked()
{
    QString line;
    QFile file("Gfile");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug()<<"error";

    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readLine();
        //qDebug()<<line;
    }
    this->pathList = line.split('*');
//    qDebug()<<this->pathList;
    //发出信号
    emit sendFileSplit(this->pathList);
    ui->paintMainWedget->update();
}





