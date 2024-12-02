#ifndef STORE_H
#define STORE_H

#include "Storage.h"
#include "Cliente.h"

#include <string>

class Store {
    private:
        std::string name;
        std::vector<Storage> almacen;
        std::vector<Cliente> clientes;
        std::string adminPassword = "admin123";

    public:
        Store();

        // GETTERS
        Cliente & getCliente(std::string username, std::string password);
        std::vector<Storage> & getStorage();
        std::string getAdminPassword();
        const std::vector<Cliente> & getClients();
        
        // SETTERS
        void setAdminPassword();
        
        // METHODS
        bool registrarse();
        void createNewValve();
        bool verifyLogin(std::string username, std::string password);
        void showClients();
        void showEntireAlmacen();
        void expandInventory();
        
        

        

};
#endif