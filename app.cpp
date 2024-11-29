#include <iostream>

#include "functions.h"
#include "classes.h"

int main(void) {
    bool running = true;
    int option;
    Store store;
    bienvenida();

    while(true) {
        std::vector<std::string> text = {"Login", "Register"};
        showText(text);
        std::cin >> option;
        std::vector <std::string> credentials;
        switch (option)
        {
        case 1:
            credentials = getCredentials();
            if (store.login(credentials[0], credentials[1])) {
                // Iniciar el programa
                std::cout << "Logeado correctamente" << std::endl;
            }
            break;
        case 2:
            store.registrarse() ? std::cout << "Registrado Correctamente" : 
            std::cout << "Registro invalido" << std::endl;

            break;
        
        default:
            std::cout << "Invalido" << std::endl;
            break;
        }
    }

    // while(running) {
    //     opcionesMain();
    //     std::cout << "Type -1 to quit" << std::endl;
    //     std::cin >> option;
    //     switch (option) {
    //     case -1:
    //         running = false;
    //         break;
    //     case 1:
    //         break;
        
    //     default:
    //         std::cout << "Not valid" << std::endl;
    //         break;
    //     }
        

    // }
    // store.showClients();
}