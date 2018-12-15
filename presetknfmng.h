#ifndef PRESETKNFMNG_H
#define PRESETKNFMNG_H

#include <QDialog>

namespace Ui {
class PreSetKnfMng;
}

class PreSetKnfMng : public QDialog
{
    Q_OBJECT

public:
    explicit PreSetKnfMng(QWidget *parent = nullptr);
    ~PreSetKnfMng();

private:
    Ui::PreSetKnfMng *ui;
};

#endif // PRESETKNFMNG_H
