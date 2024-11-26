#include <iostream>
#include <vector>

class Book {
    private:
        int pages;
        float price;
        std::string title;
        std::string genero;
        std::string autor;

    
    public:
        Book() {
            pages = 1;
            price = 0.0;
            title = "Demo";
            genero = "Muestra";
            autor = "Sin autor";
        }
        Book(int pages, float price, std::string title, std::string genero, std::string autor) {
            this->pages = pages;
            this->price = price;
            this->title = title;
            this->genero = genero;
            this->autor = autor;
            
        }

        void showBook() {
            std::cout << "--------- " << title << " ---------" << std::endl;
            std::cout << "Genero: " << genero << std::endl;
            std::cout << "Autor: " << autor << std::endl;
            std::cout << "Paginas: " << pages << std::endl;
            std::cout << "Precio: $" << price << " MX" << std::endl;
        }
        void readBook() {
            std::cout << "You are reading " << title << std::endl;
        }

        // GETTERS AND SETTERS
        float getPrice() {
            return price;
        }

        std::string getTitle() {
            return title;
        }
};

class Cart {
    private:
        int total;
        std::vector<Book> books;

    public:
        Cart() {
            total = 0;
        }

        void showCart() {
            int size = books.size();
            if (size == 0) {
                std::cout << "Your cart is empty!!!" << std::endl;
                std::cout << "Add some books" << std::endl;
                return;
            }
            std::cout << "******** " << "Mostrando tu carrito de compras" << " *********" << std::endl;
            std::cout << "Tienes " << size << " Libros en tu carrito \n";
            for (int i = 0; i < size; i++) {
                books[i].showBook();
            }
        }
        // METHODS
        void addItem(Book book) {
            books.push_back(book);
            // add the total to the cart while adding it
            // To avoid the user to buy free books
            total += book.getPrice();
        }

        void removeItem() {
            std::cout << "Escoge un libro para eliminar de tu carrito: " 
            << std::endl;
            std::string remove;
            std::getline(std::cin, remove);

            for (auto it = books.begin(); it != books.end(); it++) {
                if (it->getTitle() == remove) {
                    books.erase(it);
                    std::cout << "Libro borrado satisfactoriamente del carrito" 
                    << std::endl;
                    return;
                }
            }
            std::cout << "Libro no encontrado" << std::endl;
        }

        void empty() {
            books.clear();
            total = 0;
        }


        // GETTERS SETTERS
        const std::vector<Book>& getCart() {
            return books;
        }

        const int & getTotal() {
            return total;
        }

};

class Cliente {
    private:
        std::string username;
        std::string password;
        double balance;
        Cart cart;
        std::vector<Book> owned;

    public:
        Cliente(std::string username, std::string password) {
            this->username = username;
            this->password = password;
            this->balance = 0;
        }

        void buyBooks() {
            int total = cart.getTotal();
            if (balance < total) {
                std::cout << "Insuficiente fondos" << std::endl;
                return;
            }
            const std::vector<Book> ref = cart.getCart();
            for (auto it = ref.begin(); it != ref.end(); it++) {
                owned.push_back(*it);
            }
            balance -= total;
            cart.empty();
        }

        void showBooksOwned() {
            for (auto it = owned.begin(); it != owned.end(); it++) {
                it->showBook();
            }
        }

};

void bienvenida() {
    std::cout << "******** " <<"Bienvenido a la libreria de libros!" << " ********" << std::endl;
    std::cout << "Donde solo vendemos libros y mas libros y otros cuantos libros" << std::endl;
    std::cout << "---------------------------------------------------------------------------------\n";
    std::cout << "Para interactuar con el menu, simplemente escrbe el numero del menu al que quieres acceder" << std::endl;
}

void iniciarSesion() {
    std::string username;
    std::string password;
    std::cout << "Escribe tu nombre de usuario: ";
    std::cin >> username;
    std::cout << "\nEscribe tu contraseña: ";
    std::cin >> password;
    std::cout << std::endl;
}

void registrarse() {

}

void opciones() {
    std::cout << "1. ";
}

int main(void) {
    bienvenida();
}