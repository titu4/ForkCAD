#include <QtWidgets>
#include "displaywidget.h"
#include "Bike/wheel.h"

DisplayWidget::DisplayWidget(QWidget *parent)
    : QWidget(parent)
{
//Front Wheel
    bike.fWheel.setDiam(622);
    bike.fWheel.setWide(23);
    bike.fWheel.setX(0);
    bike.fWheel.setY(0);
//Fork
    bike.fork.leg.setA(0,0);
    bike.fork.leg.setB(bike.fWheel.getX(),bike.fWheel.getY());
}

DisplayWidget::DisplayWidget()
{

}

DisplayWidget::~DisplayWidget()
{

}

void DisplayWidget::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    paint(painter);
    painter.end();
}

void DisplayWidget::paint(QPainter &painter)
{
    painter.setClipRect(QRect(0, 0, 1000, 1334));
    QPen pen;
    painter.scale(0.5,0.5);
    painter.translate(600,600);
//Base Line
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(QPoint(-600,bike.fWheel.getRealRadius()),QPoint(1334,334));
//Wheels
    pen.setWidth(0);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawEllipse(QPointF(bike.fWheel.getX(),bike.fWheel.getY()), bike.fWheel.getRealRadius(), bike.fWheel.getRealRadius());
//Frame
    pen.setColor(Qt::black);
    painter.setPen(pen);
    //HT
    int htAx,htAy,htBx,htBy;
    bike.frame.ht.getA(htAx,htAy);
    bike.frame.ht.getB(htBx,htBy);
    painter.drawLine(QPoint(htAx,htAy),QPoint(htBx,htBy));
//Fork
    int flAx,flAy,flBx,flBy;
    bike.fork.leg.getA(flAx,flAy);
    bike.fork.leg.getB(flBx,flBy);
    painter.drawLine(QPoint(flAx,flAy),QPoint(flBx,flBy));
}

void DisplayWidget::setFWheel(int x, int y){
    /*
    fWheel.setX(x);
    fWheel.setY(y);
    fWheel.setDiam(100);
    this->update();
*/
}
