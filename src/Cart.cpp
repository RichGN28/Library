#include "Cart.h"
#include "helpers.h"
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
    if (!books.size()) {
        std::cout << "Carrito Vacio" << std::endl;
        return;
    }
    clearBuffer();

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