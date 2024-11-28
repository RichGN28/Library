#include <iostream>
#include "functions.h"

#include "classes.h"

int main(void) {
    
    Cliente user = iniciarSesion();

    bienvenida();
    opcionesMain();

    bool running = true;
    while (running) {
    int option;
    std::cin >> option;
    switch (option) {
            case 1:
                std::cout << "Opcion 1\n";
                user.showCliente();
                break;
            case 2:
                // searchBooks();
                break;
            case 3:
                opcionesCarrito();
                break;
            case 4:
                user.showBooksOwned();
                break;
            case 5:
                running = false;
        }
    }
}