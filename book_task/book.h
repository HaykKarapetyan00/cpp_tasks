#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book {
private:
    QString title;
    QString author;
    QString isbn;

public:
    Book(const QString& title = "", const QString& author = "", const QString& isbn = "");

    void setTitle(const QString& newTitle);
    void setAuthor(const QString& newAuthor);
    void setISBN(const QString& newISBN);

    QString getTitle() const;
    QString getAuthor() const;
    QString getISBN() const;
};

#endif // BOOK_H
