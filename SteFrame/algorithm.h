#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QImage>
#include <QRgb>
#include <string>
#include <iostream>
#include <fstream>

using namespace  std;

class Algorithm
{
public:
    Algorithm();
    Algorithm(QImage &img);
    ~Algorithm();

    void EmbedText(QString &text);
    void ExtractText();

public:
    QImage img;
    QString resultSte;
};

#endif // ALGORITHM_H
