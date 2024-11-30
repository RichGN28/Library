#ifndef CLASSES_H
#define CLASSES_H

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

class Cliente {
    private:
        std::string username;
        std::string password;
        double balance;
        Cart cart;
        std::vector<Book> owned;

    public:
        Cliente(std::string username, std::string password);

        // METHODS
        bool validatePassword(std::string pass);
        void showCliente();
        void buyBooks();
        void showBooksOwned();

        // GETTERS
        const std::string & getUsername();
};


class Storage {
    private:
        int maximum_capacity;
        std::map<Book, int> valve;
        std::string genero;
    public:
        Storage(std::string genero);
        void emptyStorage();
        const std::map<Book, int> & getValve();
        const std::string getGenero();

};

class Store {
    private:
    //Think about a store method
        std::string name;
        std::vector<Storage> almacen;
        std::vector<Cliente> clientes;
    public:
        Store();
        
        bool registrarse();

        bool login(std::string username, std::string password);
        const std::vector<Cliente> & getClients();
        void showClients();

};
#endif