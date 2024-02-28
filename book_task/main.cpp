#include <QApplication>
#include <QLabel>
#include "book.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Book book;

    book.setTitle("C++ OOAD");
    book.setAuthor("Booch");
    book.setISBN("47129");

    Book book1;

    book1.setTitle("shunn u katun");
    book1.setAuthor("Tumanyan");
    book1.setISBN("31884");

    QString labelText = "Title: " + book.getTitle() + "\n"
                        + "Author: " + book.getAuthor() + "\n"
                        + "ISBN: " + book.getISBN() + "\n"
                        + "Title: " + book1.getTitle() + "\n"
                        + "Author: " + book1.getAuthor() + "\n"
                        + "ISBN: " + book1.getISBN();

    QLabel label;
    label.setText(labelText);
    label.show();

    return app.exec();
}
