#include "Book.h"

Book::Book() : price(0), stock(0) {}

void Book::input() {
    std::cin.ignore(); // To ignore the leftover newline character from the previous input
    std::cout << "Enter title: ";
    std::getline(std::cin, title);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);
    std::cout << "Enter publisher: ";
    std::getline(std::cin, publisher);
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter stock: ";
    std::cin >> stock;
    std::cin.ignore(); // To consume the newline character left in the input buffer
}

void Book::display() const {
    std::cout << "Title: " << title << "\nAuthor: " << author
              << "\nPublisher: " << publisher << "\nPrice: " << price
              << "\nStock: " << stock << std::endl;
}
