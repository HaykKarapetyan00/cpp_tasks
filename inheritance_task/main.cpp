#include <QApplication>
#include <QLabel>
#include "shape.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    QLabel label;
    label.setText("Area of circle: " + QString::number(circle.calculateArea()) + "\n"
                  + "Area of rectangle: " + QString::number(rectangle.calculateArea()));
    label.resize(150,150);
    label.show();

    return app.exec();
}
