#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include "classes.h"

void bienvenida() {
    std::cout << "******** " <<"Bienvenido a la libreria de libros!" << " ********" << std::endl;
    std::cout << "Donde solo vendemos libros y mas libros y otros cuantos libros" << std::endl;
    std::cout << "---------------------------------------------------------------------------------\n";
    std::cout << "Para interactuar con el menu, simplemente escrbe el numero del menu al que quieres acceder" << std::endl;
}


void showText(std::vector<std::string> text) {
    for (int i = 0, size = text.size(); i < size; i++) {
        std::cout << i + 1 << ". " << text[i] << std::endl;
    }
}

// std::vector<std::string> getCredentials() {
//     std::vector<std::string> credentials;
//     std::string username;
//     std::string password;
//     std::cout << "Escribe tu nombre de usuario: ";
//     std::cin >> username;
//     std::cout << "\nEscribe tu contraseña: " << std::endl;
//     std::cin >> password;
//     credentials.push_back(username);
//     credentials.push_back(password);
//     return credentials;
// }

void opcionesMain() {
    std::vector<std::string> text = {"Iniciar Sesion"};
    showText(text);
}

void opcionesCarrito() {
    std::vector<std::string> text = {"Mostrar articulos en carrito", 
    "Ver subtotal", "Ver libros comprados", "Logout"};
    showText(text);
}

#endif