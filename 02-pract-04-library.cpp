#include <iostream>
#include <cstring>
#include <print>

#pragma warning (disable:4996)

namespace Constants {
    constexpr int MaxTitleLength = 50;
    constexpr int MaxAuthorLength = 50;
	constexpr int BooksCount = 3;
}

enum Genre {
    Scifi,
    Historical,
    Drama,
    Other
};

const char* GenreToString(Genre genre) {
    switch (genre) {
        case Genre::Scifi: return "Sci-Fi";
        case Genre::Historical: return "Historical";
        case Genre::Drama: return "Drama";
        case Genre::Other: return "Other";
        default: return "Unknown";
    }
}

struct Book {
private:
    char title[Constants::MaxTitleLength];
    char author[Constants::MaxAuthorLength];
    int availability;
	Genre genre;

public:
    const char* getTitle() const {
        return title;
	}

    void setTitle(const char* title) {
		if (!title) return;
        strcpy(this->title, title);
    }

    const char* getAuthor() const {
        return author;
    }

    void setAuthor(const char* author) {
        if (!author) return;
        strcpy(this->author, author);
    }

    int getAvailability() const {
        return availability;
    }

    void setAvailability(int availability) {
        if (availability < 0) return;
        this->availability = availability;
    }

    Genre getGenre() const {
        return genre;
    }

    void setGenre(Genre genre) {
        this->genre = genre;
	}

    void setAll(const char* title, const char* author, int availability, Genre genre) {
        setTitle(title);
        setAuthor(author);
        setAvailability(availability);
        setGenre(genre);
	}

    void print() const {
		std::println("Title: {}, Author: {}, Availability: {}, Genre: {}", title, author, availability, GenreToString(genre));
	}
};

struct Library {
private:
    Book books[Constants::BooksCount];
	int booksCount = 0;

    int getBookIndex(const char* title) const {
        for (int i = 0; i < booksCount; i++) {
            if (strcmp(books[i].getTitle(), title) == 0) {
                return i;
            }
        }

        return -1;
	}

public:
    const Book* getBooks() const {
        return books;
    }

    int getBooksCount() const {
        return booksCount;
    }

    void addBook(const Book& book) {
        if (booksCount >= Constants::BooksCount) {
            std::cout << "Cannot add more books. Maximum capacity reached.\n";
            return;
        }

        books[booksCount++] = book;
	}

    void borrowBook(const char* title) {
        int index = getBookIndex(title);

        if (index == -1) {
            std::cout << "Book not found.\n";
            return;
        }

        if (books[index].getAvailability() <= 0) {
            std::cout << "Book is not available.\n";
            return;
        }

		books[index].setAvailability(books[index].getAvailability() - 1);
	}

    void returnBook(const char* title) {
        int index = getBookIndex(title);

        if (index == -1) {
            std::cout << "Book not found.\n";
            return;
        }

        books[index].setAvailability(books[index].getAvailability() + 1);
	}

    void print() const {
        std::println("Library currently contains:");
        for (int i = 0; i < booksCount; i++) {
            books[i].print();
		}
    }
};

int main()
{
    Book book1;
	book1.setAll("The Great Gatsby", "F. Scott Fitzgerald", 5, Genre::Drama);

	Book book2;
	book2.setAll("Dune", "Frank Herbert", 3, Genre::Scifi);

	Book book3;
	book3.setAll("The Great", "F. Scott Fitzgerald", 2, Genre::Historical);

	Library library;
	library.addBook(book1);
	library.addBook(book2);
	library.addBook(book3);

    library.print();
	std::println();

	library.borrowBook("Dune");
	library.borrowBook("Dune");
	library.borrowBook("The Great");
    library.borrowBook("The Great");
    library.borrowBook("The Great");

    library.print();
    std::println();

	library.returnBook("Dune");
	library.returnBook("The Great");

	library.print();
}