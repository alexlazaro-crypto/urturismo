#ifndef HABITACION_H_INCLUDED
#define HABITACION_H_INCLUDED

#include <string>
#include <iostream>

class Habitacion {
public:
    int numero_habitacion;
    float tarifa;
    std::string tipo;
    std::string estado;

    void mostrarInfo() const;
};

#endif // HABITACION_H_INCLUDED
