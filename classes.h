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
        Book() {
            pages = 1;
            price = 0.0;
            title = "Demo";
            genero = "Muestra";
            autor = "Sin autor";
        }
        Book(int pages, float price, std::string title, std::string genero, std::string autor) {
            this->pages = pages;
            this->price = price;
            this->title = title;
            this->genero = genero;
            this->autor = autor;
            
        }

        void showBook() {
            std::cout << "--------- " << title << " ---------" << std::endl;
            std::cout << "Genero: " << genero << std::endl;
            std::cout << "Autor: " << autor << std::endl;
            std::cout << "Paginas: " << pages << std::endl;
            std::cout << "Precio: $" << price << " MX" << std::endl;
        }
        void readBook() {
            std::cout << "You are reading " << title << std::endl;
        }

        // GETTERS AND SETTERS
        float getPrice() {
            return price;
        }

        std::string getTitle() {
            return title;
        }
};

class Cart {
    private:
        int total;
        std::vector<Book> books;

    public:
        Cart() {
            total = 0;
        }

        void showCart() {
            int size = books.size();
            if (size == 0) {
                std::cout << "Your cart is empty!!!" << std::endl;
                std::cout << "Add some books" << std::endl;
                return;
            }
            std::cout << "******** " << "Mostrando tu carrito de compras" << " *********" << std::endl;
            std::cout << "Tienes " << size << " Libros en tu carrito \n";
            for (int i = 0; i < size; i++) {
                books[i].showBook();
            }
        }
        // METHODS
        void addItem(Book book) {
            books.push_back(book);
            // add the total to the cart while adding it
            // To avoid the user to buy free books
            total += book.getPrice();
        }

        void removeItem() {
            std::cout << "Escoge un libro para eliminar de tu carrito: " 
            << std::endl;
            std::string remove;
            std::getline(std::cin, remove);

            for (auto it = books.begin(); it != books.end(); it++) {
                if (it->getTitle() == remove) {
                    books.erase(it);
                    std::cout << "Libro borrado satisfactoriamente del carrito" 
                    << std::endl;
                    return;
                }
            }
            std::cout << "Libro no encontrado" << std::endl;
        }

        void empty() {
            books.clear();
            total = 0;
        }


        // GETTERS SETTERS
        const std::vector<Book>& getCart() {
            return books;
        }

        const int & getTotal() {
            return total;
        }

};

class Cliente {
    private:
        std::string username;
        std::string password;
        double balance;
        Cart cart;
        std::vector<Book> owned;

    public:
        Cliente(std::string username, std::string password) {
            this->username = username;
            this->password = password;
            this->balance = 0;
        }

        void showCliente() {
            std::cout << "hola\n";
        }

        void buyBooks() {
            int total = cart.getTotal();
            if (balance < total) {
                std::cout << "Insuficiente fondos" << std::endl;
                return;
            }
            const std::vector<Book> ref = cart.getCart();
            for (auto it = ref.begin(); it != ref.end(); it++) {
                owned.push_back(*it);
            }
            balance -= total;
            cart.empty();
        }

        void showBooksOwned() {
            for (auto it = owned.begin(); it != owned.end(); it++) {
                it->showBook();
            }
        }

};

class Storage {
    private:
        int maximum_capacity = 100;
        std::map<Book, int> valve;
        std::string genero;
    public:
        Storage(std::string genero, int maximum_capacity = 100) {
            this->genero = genero;
            this->maximum_capacity = maximum_capacity;
        }
        void emptyStorage() {
            valve.clear();
        }
        const std::map<Book, int> & getValve() {
            return valve;
        }
        const std::string getGenero() {
            return genero;
        }
};

class Store {
    private:
    //Think about a store method
        std::string name;
        std::vector<Storage> almacen;
        std::vector<Cliente> clientes;
    public:
        Store() {
            name = "Libreria de libros";
        }
        
        void createClient(std::string username, std::string password) {
            Cliente(username, password);
        }

        const std::vector<Cliente> & getClients() {
            return this->clientes;
        }

};

#endif