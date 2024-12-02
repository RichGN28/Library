#include <iostream>

#include "helpers.h"
#include "Store.h"

void userApp(Cliente & user);
void MainApp(Cliente & user);
void adminApp(Cliente & user);
void addBooksToCart(Cliente & user);
void carritoApp(Cliente & user);

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
        case 1:
            credentials = getCredentials();
            if (store.verifyLogin(credentials[0], credentials[1])) {
                Cliente &actual_user = store.getCliente(credentials[0], credentials[1]);
                // Iniciar el programa
                MainApp(actual_user);
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

/*
Esta función va a contener la opcion para entrar al perfil del usuario
asi como para agregar nuevos libros, solo si tienes la contrasena
*/
void MainApp(Cliente & user) {
   while (true) {
        std::vector<std::string> text = {"Ver Perfil", "Entrar a interfaz de admin"};
        showText(text);
        int option = choose();

        std::string pass;
        switch (option) {
            case 1:
                userApp(user);
                break;
            case 2:
                std::cout << "Escribe la contraseña de administrador: ";
                std::cin >> pass;
                if (pass == store.getAdminPassword()) {
                    adminApp(user);
                }
                else {
                    std::cout << "Contraseña incorrecta" << std::endl;
                }
                break;
            default:
                std::cout << "Input no valido \nIntenta de nuevo " << std::endl;
                break;
        }
   }
}

void adminApp(Cliente & user) {
    delimiter("-", 60);
    while (true) {
            std::vector<std::string> text = {"Agregar Libros", "Crear nueva bodega", "Mostrar Estanterias", "Mostrar Clientes",
             "Cambiar contraseña de admin"};
            showText(text);
            int option = choose();
            switch (option)
            {
            case -1:
                return;
            case 1:
                // Agregar libros
                store.expandInventory();
                break;
            case 2:
                store.createNewValve();
                break;
            case 3:
                store.showEntireAlmacen();
                break;
            case 4:
                store.showClients();
                break;
            case 5:
                store.setAdminPassword();
                break;
            default:
                std::cout << "Opcion no valida, inenta de nuevo" << std::endl;
                break;
            }
    }
}

/*
Aqui voy a poner todo lo que este relacionado con el interfaz
del cliente y su información
*/
void userApp(Cliente & user) {
    while (true) {
        std::vector<std::string> text = {"Mostrar Perfil", "Anadir fondos",
        "Mostar Libros Comprados", "Agregar Libros Al Carrito","Ir a carrito"};
        showText(text);
        int option = choose();

        switch (option)
        {
        case -1:
            return;
        case 1:
            delimiter("-", 75);
            user.showCliente();
            break;
        case 2:
            delimiter("-", 75);
            user.setBalance();
            break;
        case 3:
            user.showBooksOwned();
            break;
        case 4:
            addBooksToCart(user);
            break;
        case 5:
            // Ir a carrito
            carritoApp(user);
            break;
        default:
            
            break;
        }
        

    }

}

void addBooksToCart(Cliente & user) {
    Cart &cart = user.getCart();
    store.showEntireAlmacen();
    std::cout << "Que libro desea agregar al carrito: ";
    std::string bookToAdd;
    clearBuffer();
    std::getline(std::cin, bookToAdd);
    
    std::vector<Storage> &almacen = store.getStorage();

    for (int i = 0, size = almacen.size(); i < size; i++) {
        std::vector<Book> &estanteria = almacen[i].getValve();
        for (int j = 0,sizeEstanteria = estanteria.size(); j < sizeEstanteria; j++) {
            // Si encuentra el libro haz esto
            if (estanteria[j].getTitle() == bookToAdd) {
                cart.addItem(estanteria[j]);
                return;
            }
        }
    }
}

void carritoApp(Cliente & user) {
    while (true) {
        std::vector<std::string> text = {"Comprar Libros","Mostrar Carrito", "Borrar Item", 
        "Vaciar Carrito"};
        Cart &cart = user.getCart();
        showText(text);
        int option = choose();

        switch (option)
        {
        case -1:
            return;
        case 1:
            //Comprar libros
            user.buyBooks(store.getStorage());
            break;
        case 2:
            cart.showCart();
            break;
        case 3:
            cart.removeItem();
            break;
        case 4:
            cart.empty();
        default:
            break;
        }

    }   
}

