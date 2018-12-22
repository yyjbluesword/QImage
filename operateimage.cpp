#include "operateimage.h"
//#include <QPixmap>
#include <QImage>
#include <QDebug>

OperateImage::OperateImage(QObject *parent) : QObject(parent)
{
}

// check Resolution
void OperateImage::checkResolution(QString fileUrl){
    QImage image;
    image.load(fileUrl);
    qDebug()<<image.width()<<"*"<<image.height();
    if(image.width()!=1024 && image.height() != 768){
        qDebug()<<"File Format Error.";
        return;
    }
}

// save new Image
void OperateImage::saveNewImage(QString fileUrl){
    QImage image;
    image.load(fileUrl);
    if(image.width() != 1024 && image.height() != 768){
        qDebug()<<"File Format error.";
        return;
    }
    QImage image2 = image.convertToFormat(QImage::Format_ARGB8565_Premultiplied);
    image2.save("test.bmp","bmp",-1);
}
