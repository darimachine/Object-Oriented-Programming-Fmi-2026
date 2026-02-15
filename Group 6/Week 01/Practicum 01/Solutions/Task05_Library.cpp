#include <iostream>

namespace Constants {
    const int MAX_LENGTH = 50;
    const int BOOKS_CAPACITY = 3;
}

enum class Genre {
    Novel,
    Historic,
    Poetry,
    Other
};

using namespace Constants;

struct Book {
    char title[MAX_LENGTH] = "";
    char author[MAX_LENGTH] = "";
    Genre genre = Genre::Other;
    bool available = false;
};

struct Library {
    unsigned booksAmount = 0;
    Book books[BOOKS_CAPACITY];
};

Genre initGenre(int num) {
    switch (num) {
        case 0: return Genre::Novel;
        case 1: return Genre::Historic;
        case 2: return Genre::Poetry;
        default: return Genre::Other;
    }
}

const char* getGenreString(const Genre& genre) {
    switch (genre) {
        case Genre::Novel: return "Novel";
        case Genre::Historic: return "Historic";
        case Genre::Poetry: return "Poetry";
        case Genre::Other: return "Other";
    }
}

void printBook(const Book& book) {
    std::cout << book.title << ", "
        << book.author << ", "
        << getGenreString(book.genre) << ", "
        << (book.available ? "available" : "not available")
        << std::endl;
}

void initBook(Book& book) {
    int genreNum;
    std::cin >> book.title >> book.author >> genreNum >> book.available;
    book.genre = initGenre(genreNum);
}

void addBookToLibrary(Library& library, const Book& book) {
    if (library.booksAmount == BOOKS_CAPACITY) {
        std::cout << "Max books capacity is reached!";
        return;
    }

    library.books[library.booksAmount++] = book;
}

const Book& getBookByTitle(const char* title, const Library& library) {
    for (unsigned i = 0; i < library.booksAmount; i++) {
        if (strcmp(library.books[i].title, title) == 0) {
            return library.books[i];
        }
    }
}

void printBooksInfo(const Library& library) {
    for (unsigned i = 0; i < library.booksAmount; i++) {
        printBook(library.books[i]);
    }
}

int main () {
    // ...
}
