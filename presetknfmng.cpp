#include "presetknfmng.h"
#include "ui_presetknfmng.h"

PreSetKnfMng::PreSetKnfMng(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreSetKnfMng)
{
    ui->setupUi(this);
}

PreSetKnfMng::~PreSetKnfMng()
{
    delete ui;
}
