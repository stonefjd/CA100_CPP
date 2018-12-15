#include "cuttingwindow.h"
#include "ui_cuttingwindow.h"

CuttingWindow::CuttingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CuttingWindow)
{
    ui->setupUi(this);
}

CuttingWindow::~CuttingWindow()
{
    delete ui;
}
