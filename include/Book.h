#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
#include <map>



class Book {
    private:
        int pages;
        float price;
        std::string title;
        std::string genero;
        std::string autor;

    
    public:
        Book();
        Book(int pages, float price, std::string title, std::string genero, 
             std::string autor);


        void showBook();
        void readBook();

        // GETTERS AND SETTERS
        float getPrice();
        std::string getTitle();
};

#endif
