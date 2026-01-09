#include "OCRReader.h"
#include <QProcess>
#include <QFileInfo>
#include <QTemporaryFile>
#include <QDebug>

OCRReader::OCRReader(QObject *parent) : QObject(parent)
{
    tesseractPath = "tesseract";
}

void OCRReader::setTesseractPath(const QString &path)
{
    tesseractPath = path;
}

QString OCRReader::readEquation(const QString &imagePath)
{
    QFileInfo checkFile(imagePath);
    if (!checkFile.exists() || !checkFile.isFile()) {
        qWarning() << "Plik obrazu nie istnieje:" << imagePath;
        return "";
    }

    QTemporaryFile outFile;
    outFile.setAutoRemove(false);
    if (!outFile.open()) {
        qWarning() << "Nie można utworzyć tymczasowego pliku OCR";
        return "";
    }
    QString outPath = outFile.fileName();
    outFile.close();

    QStringList args;
    args << imagePath << outPath << "-l" << "eng";

    QProcess process;
    process.start(tesseractPath, args);
    if (!process.waitForFinished(10000)) {
        qWarning() << "Tesseract nie odpowiedział w czasie";
        return "";
    }

    QFile resultFile(outPath + ".txt");
    if (!resultFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Nie można odczytać wyniku OCR";
        return "";
    }

    QString text = QString::fromUtf8(resultFile.readAll());
    resultFile.close();

    resultFile.remove();

    return text.trimmed();
}
