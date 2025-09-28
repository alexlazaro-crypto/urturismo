#include "turista.h"
#include <iostream>
#include <string>

using namespace std;

string Fecha::toString() const {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
}

void Turista::mostrarInfo() const {
    cout << "\n--- INFORMACION DEL TURISTA ---" << endl;
    cout << "CI: " << ci << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;
    cout << "Fecha llegada: " << fecha_llegada.toString() << endl;
    cout << "Fecha salida: " << fecha_salida.toString() << endl;
    cout << "Habitación: " << numero_habitacion << endl;
    cout << "Comida: " << comida << endl;
}
