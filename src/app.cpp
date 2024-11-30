#include <iostream>

#include "helpers.h"
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
            store.registrarse();

            break;
        
        default:
            std::cout << "Invalido" << std::endl;
            break;
        }
    }

}