#include <QApplication>
#include <QLabel>
#include "shape.h"

float count_area(Shape* shp){
    return shp->calculateArea();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    Shape* shape_ptr = &circle;

    QLabel label;
    label.setText("Area of circle: " + QString::number(circle.calculateArea()) + "\n"
                  + "Area of rectangle: " + QString::number(rectangle.calculateArea()) + "\n"
                  + "Area calculation with shape pointer: " + QString::number(count_area(shape_ptr)));
    label.resize(300,150);
    label.show();

    return app.exec();
}
