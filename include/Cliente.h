#ifndef CLIENTE_U
#define CLIENTE_U


#include <vector>
#include "Book.h"
#include "Cart.h"

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
        // Setters
        void setBalance();
};

#endif
