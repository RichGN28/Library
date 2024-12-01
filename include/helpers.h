#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>

void delimiter(std::string _, int len);

std::vector<std::string> getCredentials();
void bienvenida();

void showText(std::vector<std::string> text);

void opcionesMain();

void opcionesCarrito();

int choose();
#endif