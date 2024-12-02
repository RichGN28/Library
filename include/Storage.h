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
        // CONSTRUCTORES
        Storage(std::string genero);

        // GETTERS AND SETTERS
        std::vector<Book> & getValve();
        const std::string getGenero();
    
        // METODOS
        void emptyStorage();
        void showValve();
        void showBooks();
        void addBookToValve(Book book);

};

#endif
