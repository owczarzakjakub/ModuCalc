#pragma once

#include <QString>
#include <QObject>

class OCRReader : public QObject
{
    Q_OBJECT
public:
    explicit OCRReader(QObject *parent = nullptr);

    QString readEquation(const QString &imagePath);

    void setTesseractPath(const QString &path);

private:
    QString tesseractPath;
};

