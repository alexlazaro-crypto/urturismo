#ifndef TURISTA_H_INCLUDED
#define TURISTA_H_INCLUDED

#include <string>
#include <iostream>
#include <vector>

struct Fecha {
    int dia, mes, ano;
    std::string toString() const;
};

class Turista {
public:
    std::string ci;
    std::string nombre;
    std::string nacionalidad;
    Fecha fecha_llegada;
    Fecha fecha_salida;
    int numero_habitacion;
    std::string comida;





    std::vector<int> tours_asignados;

    void mostrarInfo() const;

};


#endif
