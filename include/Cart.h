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

        // METHODS
        void showCart();
        void addItem(Book book);
        void removeItem();
        void empty();


        // GETTERS SETTERS
        const std::vector<Book>& getCart();
        const int & getTotal();

};

#endif