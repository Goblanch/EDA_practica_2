#include "GestorSolicitudes.h"

void GestorSolicitudes::cargarSolicitudes(const std::vector<Solicitud> &solicitudes_iniciales, GenericStack<Solicitud> &stack) {
    for (int i = 0; i < solicitudes_iniciales.size(); ++i) {
        stack.push(solicitudes_iniciales[i]);
    }
}
