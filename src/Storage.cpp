#include "helpers.h"
#include "Storage.h"

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
    delimiter("*", 75);
    std::cout << "Genero del almacen: " << genero << std::endl;
    std::cout << "Espacio Disponible: " << maximum_capacity - valve.size() << std::endl;
    // OJITO AQUI QUE ESOTY MOSTRANDO TODOS LOS LIBROS SIEMPRE
    showBooks();

}