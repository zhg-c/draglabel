#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_bMove(true)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if(ui->label->geometry().contains(e->pos()))
    {
        m_bMove = true;
        m_Distance = e->pos() - ui->label->geometry().topLeft();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *e)
{
    if(m_bMove)
    {
        ui->label->move(e->pos() - m_Distance);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    m_bMove = false;
}
