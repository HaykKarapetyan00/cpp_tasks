#include <QApplication>
#include <QLabel>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int myInt = 10;
    char myChar = 'A';
    bool myBool = true;
    QString myString = "Hello, World!";

    QString intText = "Integer: " + QString::number(myInt);
    QString charText = "Char: ";
    charText.append(QChar(myChar));
    QString boolText;
    if (myBool) {
        boolText = "Bool: true";
    } else {
        boolText = "Bool: false";
    }

    QString labelText = intText + "\n" + charText + "\n" + boolText + "\n" + myString;

    QLabel label;
    label.setText(labelText);
    label.show();

    return app.exec();
}
