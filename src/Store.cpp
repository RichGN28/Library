#include <vector>
#include <iostream>

#include "helpers.h"
#include "Store.h"


// STORE
Store::Store() {
    name = "Libreria de libros";
}


void Store::setAdminPassword() {
    std::string check, newPass, newPassCheck;
    std::cout << "\nAntigua Contrasena: ";
    std::cin >> check;
    if (check != adminPassword) {
        std::cout << "\nContraseña incorrecta\n";
        return;
    }
    std::cout << "\nNueva Contraseña: ";
    std::cin >> newPass;

    std::cout << "\nReescribe la contraseña Contraseña: ";
    std::cin >> newPassCheck;
    if (newPass != newPassCheck) {
        std::cout << "\nLas constrasenas no coinciden\n";
    }
    this->adminPassword = newPass;
    std::cout << "Constraseña de administrador cambiada satisfactoriamente" << std::endl;
    delimiter("-", 60);
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



bool Store::verifyLogin(std::string username, std::string password) {
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

Cliente & Store::getCliente(std::string username, std::string password) {
    int index = 0;
    for (int i = 0, size = clientes.size(); i < size; i++) {
    if (clientes[i].getUsername() == username) {
        if(clientes[i].validatePassword(password)) {
            index = i;
            break;
        }
    }
}
return clientes[index];
}

std::string Store::getAdminPassword() {
    return this->adminPassword;
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



void Store::expandInventory() {
    // This method adds a new book to the desire valve
    int almacen_size = almacen.size();
    if (almacen_size) {
        Book book = createBook();
        
        showEntireAlmacen();
        std::cout << "Escoge un almacen para guardar tu libro (por el nombre del genero): ";
        std::string generoChoose;
        std::cin >> generoChoose;

        bool correctAdd = false;
        for (int i = 0; i < almacen_size; i++) {
            if (almacen[i].getGenero() == generoChoose) {
                almacen[i].addBookToValve(book);
                correctAdd = true;
                break;
            }
        }
        correctAdd ? std::cout << "Libro agregado satisfactoriamente" << std::endl : 
        std::cout << "No existe una estanteria con ese nombre" << std::endl;
    }
    else {
        std::cout << "No hay ninguna estanteria disponible" << std::endl;
        delimiter("-", 70);
    }


}


void Store::createNewValve() {
    std::string bodega;
    std::cout << "Escoge el genero de tu bodega: ";
    std::cin >> bodega;
    Storage valve(bodega);
    almacen.push_back(valve);
    std::cout << "Bogeda Creada Satisfactoriamente" << std::endl;
}

const std::vector<Storage> & Store::getStorage() {
    return this->almacen;
}

void Store::showEntireAlmacen() {
    std::cout << "*-*-*-*-*-*-*-*-*-" << "MOSTRANDO EL ALMACEN" << "*-*-*-*-*-*-*-*-*-" << std::endl;
    int almcenSize = almacen.size();
    for (int i = 0; i < almcenSize; i++) {
        almacen[i].showValve();
    }
}