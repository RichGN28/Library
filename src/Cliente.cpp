#include "Cliente.h"

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
}

void Cliente::buyBooks() {
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
    std::cout << "$" << newBalance << "Anadidos" << std::endl;
}