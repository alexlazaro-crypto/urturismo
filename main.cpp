
 #include <iostream>
#include <vector>
#include <limits>
#include "turista.h"
#include "habitacion.h"
#include "tour.h"

using namespace std;


void mostrarMenuPrincipal();
void registrarTurista(vector<Turista>& turistas, const vector<Habitacion>& habitaciones);
void mostrarTuristas(const vector<Turista>& turistas);
void gestionarHabitaciones(vector<Habitacion>& habitaciones);
void gestionarTours(vector<Tour>& tours);
void asignarTourTurista(vector<Turista>& turistas, const vector<Tour>& tours);
int leerEntero(const string& mensaje);
string leerString(const string& mensaje);
bool habitacionExiste(const vector<Habitacion>& habitaciones, int numero);
bool tourExiste(const vector<Tour>& tours, int id);

int main() {
    vector<Turista> turistas;
    vector<Habitacion> habitaciones;
    vector<Tour> tours;

    // Datos de ejemplo más completos
    habitaciones.push_back({101, 50.0, "Individual", "Disponible"});
    habitaciones.push_back({102, 75.0, "Doble", "Disponible"});
    habitaciones.push_back({103, 100.0, "Matrimonial", "Mantenimiento"});

    tours.push_back({1, "Tour Museo UrusAndino", 25.0, "Carlos Perez"});
    tours.push_back({2, "Tour Mamanica", 35.0, "Ana Gomez"});
    tours.push_back({3, "Tour Ayparavi", 45.0, "Luis Rodriguez"});

    int opcion;

    cout << "=========================================" << endl;
    cout << "       SISTEMA DE GESTION TURISTICA "      << endl;
    cout << "=========================================" << endl;

    do {
        mostrarMenuPrincipal();
        cout << "Seleccione una opcion (1 al 6): ";
        opcion = leerEntero("");

        switch(opcion) {
            case 1:
                registrarTurista(turistas, habitaciones);
                break;
            case 2:
                mostrarTuristas(turistas);
                break;
            case 3:
                gestionarHabitaciones(habitaciones);
                break;
            case 4:
                gestionarTours(tours);
                break;
            case 5:
                asignarTourTurista(turistas, tours);
                break;
            case 6:
                cout << "Saliendo del sistema......" << endl;
                break;
            default:
                cout << " Opcion no válida. Intente con 1-6." << endl;
        }

        cout << endl;
        system("pause");

    } while (opcion != 6);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1.  Registrar nuevo turista" << endl;
    cout << "2.  Mostrar lista de turistas" << endl;
    cout << "3.  Gestionar habitaciones" << endl;
    cout << "4.  Gestionar tours" << endl;
    cout << "5.  Asignar tour a turista" << endl;
    cout << "6.  Salir del sistema" << endl;
    cout << "=======================" << endl;
}

void registrarTurista(vector<Turista>& turistas, const vector<Habitacion>& habitaciones) {
    Turista nuevo;

    cout << "\n--- REGISTRAR NUEVO TURISTA ---" << endl;

    nuevo.ci = leerString("Cedula de identidad: ");
    nuevo.nombre = leerString("Nombre completo: ");
    nuevo.nacionalidad = leerString("Nacionalidad: ");

    cout << "FECHA DE LLEGADA:" << endl;
    nuevo.fecha_llegada.dia = leerEntero("Dia: ");
    nuevo.fecha_llegada.mes = leerEntero("Mes: ");
    nuevo.fecha_llegada.ano = leerEntero("Anio: ");

    cout << "FECHA DE SALIDA:" << endl;
    nuevo.fecha_salida.dia = leerEntero("Dia: ");
    nuevo.fecha_salida.mes = leerEntero("Mes: ");
    nuevo.fecha_salida.ano = leerEntero("Anio: ");

    ////// habitaciones disponibles
    cout << "\nHabitaciones registradas:" << endl;
    for (const auto& hab : habitaciones) {
        hab.mostrarInfo();
    }

    nuevo.numero_habitacion = leerEntero("Numero de habitacion: ");

    //// Validacion
    if (!habitacionExiste(habitaciones, nuevo.numero_habitacion)) {
        cout << " Advertencia: La habitacion no existe en el sistema." << endl;
    }

    nuevo.comida = leerString("menu de comida: ");

    turistas.push_back(nuevo);
    cout << " Turista registrado exitosamente!" << endl;
    cout << "Total de turistas registrados: " << turistas.size() << endl;
}

void mostrarTuristas(const vector<Turista>& turistas) {
    if (turistas.empty()) {
        cout << " No hay turistas registrados en el sistema." << endl;
        return;
    }

    cout << "\n--- LISTA DE TURISTAS (" << turistas.size() << ") ---" << endl;
    for (size_t i = 0; i < turistas.size(); i++) {
        cout << "[" << i + 1 << "] ";
        turistas[i].mostrarInfo();
        cout << "------------------------" << endl;
    }
}

void gestionarHabitaciones(vector<Habitacion>& habitaciones) {
    int opcion;
    do {
        cout << "\n--- GESTION DE HABITACIONES ---" << endl;
        cout << "1. Ver todas las habitaciones" << endl;
        cout << "2. Agregar nueva habitacion" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Seleccione: ";
        opcion = leerEntero("");

        if (opcion == 1) {
            cout << "\n--- HABITACIONES REGISTRADAS ---" << endl;
            for (const auto& hab : habitaciones) {
                hab.mostrarInfo();
            }
        } else if (opcion == 2) {
            Habitacion nueva;
            nueva.numero_habitacion = leerEntero("Numero de habitacion: ");
            cout << "Tarifa: ";
            cin >> nueva.tarifa;
            cin.ignore();
            nueva.tipo = leerString("Tipo de habitacion: ");
            nueva.estado = "Disponible";

            habitaciones.push_back(nueva);
            cout << " Habitacion agregada!" << endl;
        }
    } while (opcion != 3);
}

void gestionarTours(vector<Tour>& tours) {
    int opcion;
    do {
        cout << "\n--- GESTION DE TOURS ---" << endl;
        cout << "1. Ver todos los tours" << endl;
        cout << "2. Agregar nuevo tour" << endl;
        cout << "3. Volver al menu principal" << endl;
        cout << "Seleccione: ";
        opcion = leerEntero("");

        if (opcion == 1) {
            cout << "\n--- TOURS DISPONIBLES ---" << endl;
            for (const auto& tour : tours) {
                tour.mostrarInfo();
            }
        } else if (opcion == 2) {
            Tour nuevo;
            nuevo.numero_tours = leerEntero("Nro del tour: ");
            nuevo.destino = leerString("Destino: ");
            cout << "Costo: ";
            cin >> nuevo.costo;
            cin.ignore();
            nuevo.guia = leerString("Nombre del guia: ");

            tours.push_back(nuevo);
            cout << " Tour agregado!" << endl;
        }
    } while (opcion != 3);
}

// Funciones aux...vhgcgf
int leerEntero(const string& mensaje) {
    int valor;
    if (!mensaje.empty()) cout << mensaje;
    while (!(cin >> valor)) {
        cout << " Error: Ingrese un numero valido: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    cin.ignore();
    return valor;
}

string leerString(const string& mensaje) {
    string valor;
    cout << mensaje;
    getline(cin, valor);
    return valor;
}

bool habitacionExiste(const vector<Habitacion>& habitaciones, int numero) {
    for (const auto& hab : habitaciones) {
        if (hab.numero_habitacion == numero) {
            return true;
        }
    }
    return false;
}

bool tourExiste(const vector<Tour>& tours, int id) {
    for (const auto& tour : tours) {
        if (tour.numero_tours == id) {
            return true;
        }
    }
    return false;
}















void asignarTourTurista(vector<Turista>& turistas, const vector<Tour>& tours) {
    int id_turista, id_tour;

    cout << "\n--- ASIGNAR TOUR A TURISTA ---" << endl;

    if (turistas.empty()) {
        cout << " No hay turistas registrados." << endl;
        return;
    }
    if (tours.empty()) {
        cout << " No hay tours registrados." << endl;
        return;
    }


    cout << "\n--- Turistas Disponibles ---" << endl;
    for (size_t i = 0; i < turistas.size(); ++i) {
        cout << "INDICE [" << i + 1 << "] - CI: " << turistas[i].ci << ", Nombre: " << turistas[i].nombre << endl;
    }

    int indice_turista = leerEntero("Ingrese el INDICE del turista a asignar: ") - 1;

    if (indice_turista < 0 || indice_turista >= turistas.size()) {
        cout << " Indice de turista no valido." << endl;
        return;
    }

    Turista& turista_seleccionado = turistas[indice_turista];
    cout << " Turista seleccionado: " << turista_seleccionado.nombre << endl;


    cout << "\n--- Tours Disponibles ---" << endl;

    for (const auto& tour : tours) {
        tour.mostrarInfo();
    }

    id_tour = leerEntero("Ingrese el Nro del tour que desea asignar: ");


    if (!tourExiste(tours, id_tour)) {
        cout << " El Nro del tour (" << id_tour << ") no existe en el sistema." << endl;
        return;
    }


    turista_seleccionado.tours_asignados.push_back(id_tour);

    cout << "\n Tour (Nro: " << id_tour << ") asignado exitosamente a " << turista_seleccionado.nombre << "." << endl;
    cout << "Total de tours de este turista: " << turista_seleccionado.tours_asignados.size() << endl;
}
