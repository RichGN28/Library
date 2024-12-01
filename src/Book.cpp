#include "Book.h"

Book::Book() {
    pages = 1;
    price = 0.0;
    title = "Demo";
    genero = "Muestra";
    autor = "Sin autor";
}

Book::Book(int pages, float price, std::string title, std::string genero, std::string autor) {
    this->pages = pages;
    this->price = price;
    this->title = title;
    this->genero = genero;
    this->autor = autor;
    
}

void Book::showBook() {
    std::cout << "--------- " << title << " ---------" << std::endl;
    std::cout << "Genero: " << genero << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "Paginas: " << pages << std::endl;
    std::cout << "Precio: $" << price << " MX" << std::endl;
}
void Book::readBook() {
    std::cout << "You are reading " << title << std::endl;
}

// GETTERS AND SETTERS
float Book::getPrice() {
    return price;
}

std::string Book::getTitle() {
    return title;
}
