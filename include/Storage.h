#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "Book.h"

class Storage {
    private:
        int maximum_capacity;
        std::vector<Book> valve;
        std::string genero;
    public:
        Storage(std::string genero);
        void emptyStorage();
        const std::vector<Book> & getValve();
        const std::string getGenero();
        void showValve();
        void showBooks();
        void addBookToValve(Book book);

};

#endif
