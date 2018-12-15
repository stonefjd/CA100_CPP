#ifndef PAINTFRAME_H
#define PAINTFRAME_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QtMath>
#include <QColor>

class PaintFrame : public QWidget
{
    Q_OBJECT
public:
    explicit PaintFrame(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:

public slots:
    void receiveFileSplit(QStringList data);
private:
    QStringList pointStrList;
    bool getPointInString(QString str,QPointF *p);
};

#endif // PAINTFRAME_H
