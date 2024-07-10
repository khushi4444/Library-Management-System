#ifndef BOOKSHOP_H
#define BOOKSHOP_H

#include "Book.h"
#include <vector>
#include <fstream>
#include <algorithm>

class Bookshop {
private:
    std::vector<Book> books;
    const std::string filename = "books.dat";

    void loadBooks();
    void saveBooks();

public:
    Bookshop();
    ~Bookshop();
    void addBook();
    void displayBooks() const;
    void searchBook(const std::string& title) const;
    void deleteBook(const std::string& title);
    void menu();
};

#endif // BOOKSHOP_H
