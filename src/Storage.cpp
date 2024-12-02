#include "helpers.h"
#include "Storage.h"

#define ESPACIADO 70

Storage::Storage(std::string genero) {
    this->genero = genero;
    this->maximum_capacity = 15;
}
void Storage::emptyStorage() {
    valve.clear();
}
std::vector<Book> & Storage::getValve() {
    return valve;
}
const std::string Storage::getGenero() {
    return genero;
}

void Storage::showBooks() {
    for (auto it = valve.begin(); it != valve.end(); it++) {
        it->showBook();
    }
}

void Storage::addBookToValve(Book book) {
    valve.push_back(book);
}

void Storage::showValve() {
    std::cout << "Genero del almacen: " << genero << std::endl;
    std::cout << "Espacio Disponible: " << maximum_capacity - valve.size() << std::endl;

    showBooks();
    delimiter("*", ESPACIADO);
}