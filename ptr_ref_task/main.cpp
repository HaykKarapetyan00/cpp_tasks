#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    int number = 10;

    int* pointer = &number;

    int& reference = number;

    std::cout << "Initial value of 'number': " << number << std::endl;

    *pointer = 20;

    std::cout << "Value of 'number' after using pointer: " << number << std::endl;

    reference = 30;

    std::cout << "Value of 'number' after using reference: " << number << std::endl;

    return a.exec();
}
