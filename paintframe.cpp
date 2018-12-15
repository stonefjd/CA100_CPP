#include "paintframe.h"



PaintFrame::PaintFrame(QWidget *parent) : QWidget(parent)
{

}


void PaintFrame::receiveFileSplit(QStringList data)
{

    this->pointStrList = data;
}
void PaintFrame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    QPen pen;
    const QColor penColor(255,0,0,255);//penColor.setRgbF(0.5,0.5,0.5,0)
    pen.setColor(penColor);
    pen.setStyle(Qt::CustomDashLine);
    pen.setWidthF(0);// line for only one pixel

    painter.setPen(pen);

    painter.setViewport(0,0,this->width(),this->height());//set the real area
//    painter.setWindow(-this->width()/2, this->height()/2, this->width(), -this->height()); //(-10, 2)(10, -2)
    painter.setWindow(0,0, 10*this->width(), 10*this->height()); //set the ratio size
    painter.fillRect(0, 0, 10*this->width(), 10*this->height(), Qt::black);
//    painter.drawLine(QPointF(0, 0), QPointF(100, 100));
//    painter.drawLine(QPointF(100, 100), QPointF(100, 200));

    QPointF startPoint(0,0);
    QPointF endPoint(0,0);


    if(!this->pointStrList.isEmpty())
    {
        int i=0;
        while(this->pointStrList[i]!= nullptr)
        {
            startPoint = endPoint;
            if(getPointInString(this->pointStrList[i],&endPoint))
            {
                painter.drawLine(startPoint, endPoint);
            }
            i++;
        }
    }


//    for(double x=0; x<10; x+=0.01)
//    {
//        double y = 50*qSin(x/10);
//        painter.drawPoint(QPointF(x ,y));
//    }
}

//--This function only used for the string in OutFile----------//
bool PaintFrame::getPointInString(QString str,QPointF *p)
{
    QStringList list;
    if(str.contains('X',Qt::CaseSensitive)&&str.contains('Y',Qt::CaseSensitive))
    {
        str.remove(0,1);
        list = str.split('Y');
        p->setX(list[0].toInt());
        p->setY(list[1].toInt());
        return true;
    }
    else
        return false;
}
