#include <iostream>

#include "functions.h"
#include "classes.h"

int main(void) {
    bool running = true;
    int option = 0;
    Store store;
    bienvenida();
    while(running) {
        opcionesMain();
        std::cout << "Type -1 to quit" << std::endl;
        std::cin >> option;
        switch (option) {
        case -1:
            running = false;
            break;
        case 1:
            store.addClient();
            break;
        
        default:
            std::cout << "Not valid" << std::endl;
            break;
        }
        

    }
    store.showClients();
}