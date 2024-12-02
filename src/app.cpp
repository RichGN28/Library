#include <iostream>

#include "helpers.h"
#include "Store.h"
#include "functions.h"

// Inicializar la instancia de la tienda
Store store;

int main(void) {
    int option;
    bienvenida();

    while(true) {
        std::vector<std::string> text = {"Login", "Register"};
        showText(text);
        int option = choose();
        std::vector <std::string> credentials;
        switch (option)
        {
        case -1:
            std::cout << "No puedes regresar en este menu\n";
            break;
        case 1:
            // INICIAR SESION
            credentials = getCredentials();
            if (store.verifyLogin(credentials[0], credentials[1])) {
                Cliente &actual_user = store.getCliente(credentials[0], credentials[1]);
                // Iniciar el programa
                MainApp(actual_user);
            }
            break;
        case 2:
            // REGIRTRARSE
            store.registrarse();
            break;
        
        default:
            std::cout << "Invalido" << std::endl;
            break;
        }
    }

}
