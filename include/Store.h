#ifndef STORE_H
#define STORE_H

#include "Storage.h"
#include "Cliente.h"

class Store {
    private:

        std::string name;
        std::vector<Storage> almacen;
        std::vector<Cliente> clientes;
        std::string adminPassword = "admin123";

    public:
        Store();

        std::string getAdminPassword();
        
        bool registrarse();

        void createNewValve();

        void createStorage();

        bool verifyLogin(std::string username, std::string password);
        const std::vector<Cliente> & getClients();
        void showClients();

        void showEntireAlmacen();

        void expandInventory();
        
        const std::vector<Storage> & getStorage();

        Cliente & getCliente(std::string username, std::string password);

};
#endif