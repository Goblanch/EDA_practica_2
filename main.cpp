#include "Solicitud.h"
#include "GenericStack.h"
#include "GestorSolicitudes.h"
#include <iostream>
#include <vector>

int main() {

    GenericStack<Solicitud> stack;
    GestorSolicitudes gestor;

    std::vector<Solicitud> solicitudes = {
        Solicitud(101, "24022026", "10124022026", 'P', 25.50),
        Solicitud(202, "23022026", "20223022026", 'A', 70.00),
        Solicitud(303, "22022026", "30322022026", 'R', 10.25),
        Solicitud(404, "21022026", "40421022026", 'P', 99.99),
        Solicitud(505, "20022026", "50520022026", 'A', 12.75)
    };

    gestor.cargarSolicitudes(solicitudes, stack);

    stack.print();

    return 0;
}