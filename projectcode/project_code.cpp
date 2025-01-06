#include <iostream>
#include <vector>
#include <string>

struct Book {
    int id;
    std::string title;
    std::string author;
    double price;
};

std::vector<Book> books;

void displayMenu() {
    std::cout << "\nBookshop Management System\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Delete Book\n";
    std::cout << "3. Update Book\n";
    std::cout << "4. Display Books\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void addBook() {
    Book book;
    std::cout << "Enter Book ID: ";
    std::cin >> book.id;
    std::cout << "Enter Title: ";
    std::cin.ignore();
    std::getline(std::cin, book.title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, book.author);
    std::cout << "Enter Price: ";
    std::cin >> book.price;
    books.push_back(book);
    std::cout << "Book added successfully!\n";
}

void deleteBook() {
    int id;
    std::cout << "Enter Book ID to delete: ";
    std::cin >> id;

    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            std::cout << "Book deleted successfully!\n";
            return;
        }
    }

    std::cout << "Book not found!\n";
}

void updateBook() {
    int id;
    std::cout << "Enter Book ID to update: ";
    std::cin >> id;

    for (auto& book : books) {
        if (book.id == id) {
            std::cout << "Enter new Title: ";
            std::cin.ignore();
            std::getline(std::cin, book.title);
            std::cout << "Enter new Author: ";
            std::getline(std::cin, book.author);
            std::cout << "Enter new Price: ";
            std::cin >> book.price;
            std::cout << "Book updated successfully!\n";
            return;
        }
    }

    std::cout << "Book not found!\n";
}

void displayBooks() {
    if (books.empty()) {
        std::cout << "No books in the inventory.\n";
        return;
    }

    std::cout << "\nBooks in the inventory:\n";
    for (const Book& book : books) {
        std::cout << "ID: " << book.id << " | Title: " << book.title << " | Author: " << book.author << " | Price: " << book.price << "\n";
    }
}

int main() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
