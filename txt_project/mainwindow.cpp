#include "mainwindow.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    label = new QLabel(this);
    layout->addWidget(label);

    QString fileName = "anun.txt";

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "Hayk\n";
        out << "Vahagn\n";
        out << "Arman\n";
        file.close();
    } else {
        qDebug() << "Failed to open file for writing:" << file.errorString();
    }

    QString content;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            content += in.readLine() + "\n";
        }
        file.close();
    } else {
        qDebug() << "Failed to open file for reading:" << file.errorString();
    }

    label->setText(content);
}

MainWindow::~MainWindow()
{
}
