#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    std::string author;
    std::string publisher;
    int price;
    int stock;

    Book();
    void input();
    void display() const;
};

#endif // BOOK_H
