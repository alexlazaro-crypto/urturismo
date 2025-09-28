#ifndef TOUR_H_INCLUDED
#define TOUR_H_INCLUDED



#include <string>
#include <iostream>

class Tour {
public:
    int numero_tours;
    std::string destino;
    float costo;
    std::string guia;

    void mostrarInfo() const;
};

#endif // TOUR_H_INCLUDED
