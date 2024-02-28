#include "book.h"

Book::Book(const QString& title, const QString& author, const QString& isbn)
    : title(title), author(author), isbn(isbn) {}

void Book::setTitle(const QString& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const QString& newAuthor) {
    author = newAuthor;
}

void Book::setISBN(const QString& newISBN) {
    isbn = newISBN;
}

QString Book::getTitle() const {
    return title;
}

QString Book::getAuthor() const {
    return author;
}

QString Book::getISBN() const {
    return isbn;
}
