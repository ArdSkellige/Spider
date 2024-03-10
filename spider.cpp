#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QPalette>
#include <QColor>
#include <QBrush>
#include <QGuiApplication>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>
#include <QString>

#include "spider.h"


Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << this->windowFlags();
    Qt::WindowFlags flags = Qt::Widget;
    flags |= Qt::CustomizeWindowHint;
    flags |= Qt::WindowTitleHint;
    flags |= Qt::WindowSystemMenuHint;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowMaximizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::WindowStaysOnTopHint;
    this->setWindowFlags(flags);
    qDebug() << this->windowFlags();

    Qt::WindowState state = Qt::WindowActive;
    this->setWindowState(state);

    setWindowTitle(tr("Spider"));

    QIcon icon("Images_lab1/icon1.ico");
    this->setWindowIcon(icon);

    // ⦁	Задаем цвет фона окна в активном состоянии
    QPalette palette;
    palette.setColor(QPalette::Active, QPalette::Window, QColor(0, 52, 52));

    // ⦁	Задаем картинку в качестве фона окна (для неактивного состояния)
    QPixmap pix;
    bool b = pix.load("Images_lab1/Water lilies.jpg");
    if(b)
    {
        QBrush brush(pix);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
    }
    else
    {
        palette.setColor(QPalette::Inactive, QPalette::Window, QColor("#F0E68C"));
    }
    //this->setPalette(palette);

    // ⦁	Задаем степень прозрачности окна
    if(b)
    {
        this->setWindowOpacity(0.85);
    }

    // ⦁	Задаем размеры и расположение окна
    this->setMinimumSize(400, 300);
    this->resize(500, 400);
    this->move(100,200);

    // Указатель на виджет экрана
    QScreen * screen = QGuiApplication::primaryScreen();

    // ⦁	Задаем вид курсора
    QCursor cursor;
    QPixmap pix2;
    bool b2 = pix2.load("Images_lab1/cursor1.cur");
    if(b2)
    {
        pix2.setMask(QBitmap("Images_lab1/cursor1.cur"));
        cursor = pix2;
    }
    else
    {
        cursor = Qt::CrossCursor;
    }
    this->setCursor(cursor);

    // ⦁	Задаем диалоговые окна
    QColorDialog colDia;
    QColor col = colDia.getColor();
    bool b3 = col.isValid();
    if(b3)
    {
        palette.setColor(QPalette::Active, QPalette::Window, col);
    }

    QFileDialog fDia;
    QString fStr = fDia.getOpenFileName();
    bool b4 = fStr.isEmpty();
    if(!b4)
    {
        if(pix.load(fStr))
        {
            QBrush brush(pix);
            palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        }
    }
    this->setPalette(palette);

    // ⦁	Задаем max размер окна
    this->setMaximumSize(pix.size());
}

Spider::~Spider()
{
}

