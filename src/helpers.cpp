#include <iostream>
#include "helpers.h"

#include "Store.h"

void clearBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Book createBook() {
    std::cout << std::endl << "************" << " CREANDO NUEVO LIBRO " << "************" << std::endl;
    int pages;
    float price;
    std::string title, genero, autor;
    // clearBuffer();
    std::cout << "Titulo del libro: ";

    std::getline(std::cin, title);

    std::cout << "Paginas: ";
    std::cin >> pages;

    std::cout << "Precio: ";
    std::cin >> price;

    clearBuffer();

    std::cout << "Genero: ";
    
    std::getline(std::cin, genero);

    std::cout << "Autor: ";
    std::getline(std::cin, autor);
    Book book(pages, price, title, genero, autor);

    return book;
}

void delimiter(std::string _, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << _;
    }
    std::cout << std::endl;
}

int choose() {
    delimiter("*-", 50);
    std::cout << "Que desea hacer: ";
    int option;
    std::cin >> option; 
    delimiter("*-", 50);
    std::cin.ignore();
    return option;
}

void bienvenida() {
    std::cout << std::endl << "******** " <<"Bienvenido a la libreria de libros!" << " ********" << std::endl;
    std::cout << "Donde solo vendemos libros y mas libros y otros cuantos libros" << std::endl;
    delimiter("-", 75);
    std::cout << "Para interactuar con el menu, simplemente escrbe el numero del menu al que quieres acceder" << std::endl;
    std::cout << "Escribe -1 para volver a la interfaz anterior" << std::endl;
    delimiter(".", 70);
}


void showText(std::vector<std::string> text) {
    for (int i = 0, size = text.size(); i < size; i++) {
        std::cout << i + 1 << ". " << text[i] << std::endl;
    }
    
}

std::vector<std::string> getCredentials() {
    std::vector<std::string> credentials;
    std::string username;
    std::string password;
    std::cout << "Escribe tu nombre de usuario: ";
    std::cin >> username;
    std::cout << "\nEscribe tu contraseña: " << std::endl;
    std::cin >> password;
    credentials.push_back(username);
    credentials.push_back(password);
    return credentials;
}

void opcionesMain() {
    std::vector<std::string> text = {"Iniciar Sesion"};
    showText(text);
}

void opcionesCarrito() {
    std::vector<std::string> text = {"Mostrar articulos en carrito", 
    "Ver subtotal", "Ver libros comprados", "Logout"};
    showText(text);
}


