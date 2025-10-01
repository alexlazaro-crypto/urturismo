#include "habitacion.h"
#include <iostream>
#include <string>

using namespace std;

void Habitacion::mostrarInfo() const {
    cout << "Habitacion #" << numero_habitacion;
    cout << " - " << tipo;
    cout << " - Bs" << tarifa;
    cout << " - " << estado << endl;
}
