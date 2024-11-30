#include <vector>
#include <iostream>

#include "helpers.h"
#include "classes.h"


// BOOK
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


// CART
Cart::Cart() {
    total = 0;
}

void Cart::showCart() {
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
void Cart::addItem(Book book) {
    books.push_back(book);
    // add the total to the cart while adding it
    // To avoid the user to buy free books
    total += book.getPrice();
}

void Cart::removeItem() {
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

void Cart::empty() {
    books.clear();
    total = 0;
}


// GETTERS SETTERS
const std::vector<Book>& Cart::getCart() {
    return books;
}

const int & Cart::getTotal() {
    return total;
}

// CLIENTE
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
    showBooksOwned();
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


// STORAGE
Storage::Storage(std::string genero) {
    this->genero = genero;
    this->maximum_capacity = 15;
}
void Storage::emptyStorage() {
    valve.clear();
}
const std::map<Book, int> & Storage::getValve() {
    return valve;
}
const std::string Storage::getGenero() {
    return genero;
}


// STORE
        Store::Store() {
            name = "Libreria de libros";
        }
        
        bool Store::registrarse() {
            std::vector<std::string> credentials;
            credentials = getCredentials();
            std::cout << "Escribe tu contraseña nuevamente" << std::endl;
            
            std::string password2;
            std::cin >> password2;
            
            if (password2 != credentials[1]) {
                std::cout << "Las contrasenas no coinciden" << std::endl;
                std::cout << "Registro invalido" << std::endl;
                delimiter("-", 50);
                return false;
            }
            Cliente user(credentials[0], credentials[1]);
            clientes.push_back(user);
            std::cout << "Registrado Correctamente" << std::endl;
            delimiter("-", 50);
            return true;
        }

        bool Store::login(std::string username, std::string password) {
            // Check if my vector contains the inputs
            int index = 0;
            for (int i = 0, size = clientes.size(); i < size; i++) {
                if (clientes[i].getUsername() == username) {
                    if(clientes[i].validatePassword(password)) {
                        std::cout << "Login satisfactorio" << std::endl;
                        delimiter("-", 50);
                        return true;
                    }
                }
            }
            std::cout << "No se encontro el perfil" << std::endl;
            delimiter("-", 50);
            return false;
        }

        const std::vector<Cliente> & Store::getClients() {
            return this->clientes;
        }
        void Store::showClients() {
            int size = clientes.size();
            if (!size) {
                std::cout << "No hay clientes actualmente :(" << std::endl;
                return;
            }
            std::cout << "***** CLIENTES ACTUALES *****" << std::endl;
            for (int i = 0; i < size; i++) {
                clientes[i].showCliente();
                delimiter("-*", 50);
            }
        }
