#include "Cliente.h"
#include "Storage.h"
#include "helpers.h"

#define ESPACIADO 70

Cliente::Cliente(std::string username, std::string password) {
    this->username = username;
    this->password = password;
    this->balance = 0;
}

const std::string& Cliente::getUsername() {
    return username;
}
bool Cliente::validatePassword(std::string pass) {
    return pass == password;
}



void Cliente::showCliente() {
    std::cout << "Usuario: " << username << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    delimiter("-", ESPACIADO);

}

void Cliente::buyBooks(std::vector<Storage> & almacen) {
    int total = cart.getTotal();
    if (balance < total) {
        std::cout << "Insuficiente fondos" << std::endl;
        return;
    }
    const std::vector<Book> &carrito = cart.getCart();
    for (int k = 0, sizeCarrito = carrito.size(); k <sizeCarrito; k++) {
        // Agregar a comprados
        Book book = carrito[k];
        owned.push_back(book);
        for (int i = 0, size = almacen.size(); i < size; i++) {
            std::vector<Book>&estanteria = almacen[i].getValve();
            for (int j = 0, sizeEstanteria = estanteria.size(); j < sizeEstanteria; j++) {
                if (estanteria[j].getTitle() == book.getTitle()) {
                    estanteria.erase(estanteria.begin() + j);
                    break;
                }
            }
        }

    }
    balance -= total;
    cart.empty();
    std::cout << "Libros comprados satisfactoriamente" << std::endl;
}

void Cliente::showBooksOwned() {
    int size = owned.size();
    if (!size) {
        std::cout << "No books owned, buy some books!!" << std::endl;
        return;
    }
    for (auto it = owned.begin(); it != owned.end(); it++) {
        it->showBook();
    }
}

void Cliente::setBalance() {
    std::cout << "Cuanto dinero quieres depositar: ";
    double newBalance;
    std::cin >> newBalance;
    this->balance = newBalance;
    std::cout << "$" << newBalance << " Anadidos" << std::endl;
    delimiter("-", ESPACIADO);
}

Cart & Cliente::getCart() {
    return this->cart;
}