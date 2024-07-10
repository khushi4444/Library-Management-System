#include "Bookshop.h"

Bookshop::Bookshop() {
    loadBooks();
}

Bookshop::~Bookshop() {
    saveBooks();
}

void Bookshop::loadBooks() {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        books.clear();
        Book book;
        while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            books.push_back(book);
        }
        file.close();
    } else {
        std::cout << "Could not open file for reading.\n";
    }
}

void Bookshop::saveBooks() {
    std::ofstream file(filename, std::ios::binary | std::ios::trunc);
    if (file.is_open()) {
        for (const auto& book : books) {
            file.write(reinterpret_cast<const char*>(&book), sizeof(Book));
        }
        file.close();
    } else {
        std::cout << "Could not open file for writing.\n";
    }
}

void Bookshop::addBook() {
    Book book;
    book.input();
    books.push_back(book);
    std::cout << "Book added successfully!\n";
}

void Bookshop::displayBooks() const {
    if (books.empty()) {
        std::cout << "No books available.\n";
    } else {
        for (const auto& book : books) {
            book.display();
            std::cout << "-------------------\n";
        }
    }
}

void Bookshop::searchBook(const std::string& title) const {
    for (const auto& book : books) {
        if (book.title == title) {
            book.display();
            return;
        }
    }
    std::cout << "Book not found!\n";
}

void Bookshop::deleteBook(const std::string& title) {
    auto it = std::remove_if(books.begin(), books.end(), [&title](const Book& book) {
        return book.title == title;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        std::cout << "Book deleted successfully!\n";
    } else {
        std::cout << "Book not found!\n";
    }
}

void Bookshop::menu() {
    int choice;
    std::string title;
    while (true) {
        std::cout << "\nBookshop Management System\n";
        std::cout << "1. Add Book\n2. Display All Books\n3. Search Book\n4. Delete Book\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore leftover newline character
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                std::cout << "Enter title to search: ";
                std::getline(std::cin, title);
                searchBook(title);
                break;
            case 4:
                std::cout << "Enter title to delete: ";
                std::getline(std::cin, title);
                deleteBook(title);
                break;
            case 5:
                std::cout << "Exiting the system...\n";
                return;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
}
