#ifndef CART_H
#define CART_H


#include <iostream>
#include <vector>

#include "Book.h"


class Cart {
    private:
        int total;
        std::vector<Book> books;

    public:
        Cart();
        
        // GETTERS SETTERS
        const std::vector<Book>& getCart();
        const int & getTotal();

        // METHODS
        void showCart();
        void addItem(Book book);
        void removeItem();
        void empty();



};

#endif