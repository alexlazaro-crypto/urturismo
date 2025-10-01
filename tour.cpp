#include "tour.h"
#include <iostream>
#include <string>

using namespace std;

void Tour::mostrarInfo() const {
    cout << "Tour #" << numero_tours;
    cout << " - " << destino;
    cout << " - Bs" << costo;
    cout << " - Guia: " << guia << endl;
}
