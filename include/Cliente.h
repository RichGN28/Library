#ifndef CLIENTE_U
#define CLIENTE_U


#include <vector>
#include "Book.h"
#include "Cart.h"

class Storage;

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
        void buyBooks(std::vector<Storage> & almacen);
        void showBooksOwned();

        // GETTERS
        const std::string & getUsername();
        Cart & getCart();
        // Setters
        void setBalance();
};

#endif
