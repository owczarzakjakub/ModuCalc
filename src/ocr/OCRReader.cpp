#include "OCRReader.h"
#include <QProcess>
#include <QFileInfo>
#include <QTemporaryFile>
#include <QDebug>
#include <QString>
#include <QCoreApplication>

OCRReader::OCRReader(QObject *parent) : QObject(parent)
{
    QString appDir = QCoreApplication::applicationDirPath();
    tesseractPath = appDir + "/tesseract/tesseract.exe";
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

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

    QString appDir = QCoreApplication::applicationDirPath();
    env.insert("TESSDATA_PREFIX", appDir + "/tesseract/tessdata");

    process.setProcessEnvironment(env);

    process.start(tesseractPath, args);

    if (!process.waitForStarted(3000)) {
        qWarning() << "Nie udało się uruchomić Tesseracta";
        return "";
    }

    process.waitForFinished(-1);

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
