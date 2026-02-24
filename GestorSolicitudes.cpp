#include "GestorSolicitudes.h"

void GestorSolicitudes::cargarSolicitudes(const std::vector<Solicitud> &solicitudes_iniciales, GenericStack<Solicitud> &stack) {
    for (int i = 0; i < solicitudes_iniciales.size(); ++i) {
        stack.push(solicitudes_iniciales[i]);
    }
}

GenericStack<Solicitud> GestorSolicitudes::procesarSolicitudesRechazadas(const GenericStack<Solicitud> &stack, double& totalAhorrado) {
    if (stack.empty()) {
        throw std::runtime_error("Stack is empty");
    }
    totalAhorrado = 0.0;

    // 1) Copia de la pila original (gracias al constructor de copia)
    GenericStack<Solicitud> copia(stack);

    // 2) Pilas auxiliares para mantener orden
    GenericStack<Solicitud> aux;
    GenericStack<Solicitud> resultado;

    // 3) Recorremos la copia
    while (!copia.empty()) {
        Solicitud actual = copia.top();
        copia.pop();

        if (actual.getEstado() == 'R') {
            totalAhorrado += actual.getReembolso();
        } else {
            aux.push(actual); // se invierte
        }
    }

    // 4) Restauramos el orden original
    while (!aux.empty()) {
        resultado.push(aux.top());
        aux.pop();
    }

    std::cout << "\n\t#### Proceso de purga. Creditos ahorrados: " << totalAhorrado << " ####\n\n";
    return resultado;
}
