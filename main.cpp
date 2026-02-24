#include "Solicitud.h"
#include "GenericStack.h"
#include "GestorSolicitudes.h"
#include <iostream>
#include <vector>

int main() {

    GenericStack<Solicitud> stack;
    GestorSolicitudes gestor;

    std::vector<Solicitud> solicitudes = {
        Solicitud(101, "24022026", 'P', 25.50),
        Solicitud(412, "22022016", 'R', 15.25),
        Solicitud(202, "23022026", 'A', 70.00),
        Solicitud(303, "22022026", 'R', 10.25),
        Solicitud(404, "21022026", 'P', 99.99),
        Solicitud(505, "20022026", 'A', 12.75)
    };

    gestor.cargarSolicitudes(solicitudes, stack);
    std::cout << "\t#### PILA INICIAL: ####\n";
    stack.print();

    double ahorrado = 0.0;
    GenericStack<Solicitud> pilaSinR = gestor.procesarSolicitudesRechazadas(stack, ahorrado);

    std::cout << "\t#### PILA PURGADA: ####\n";
    pilaSinR.print();

    return 0;
}