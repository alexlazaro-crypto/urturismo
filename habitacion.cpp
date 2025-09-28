#include "habitacion.h"
#include <iostream>
#include <string>

using namespace std;

void Habitacion::mostrarInfo() const {
    cout << "Habitación #" << numero_habitacion;
    cout << " - " << tipo;
    cout << " - $" << tarifa;
    cout << " - " << estado << endl;
}
