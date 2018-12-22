#ifndef OPERATEIMAGE_H
#define OPERATEIMAGE_H

#include <QObject>

class OperateImage : public QObject
{
    Q_OBJECT
public:
    explicit OperateImage(QObject *parent = nullptr);
    Q_INVOKABLE void checkResolution(QString fileUrl);
    Q_INVOKABLE void saveNewImage(QString fileUrl);

signals:

public slots:
};

#endif // OPERATEIMAGE_H
