#pragma once

#include <vector>
#include "Solicitud.h"
#include "GenericStack.h"

class GestorSolicitudes {
public:
    GestorSolicitudes() = default;
    ~GestorSolicitudes() = default;

    void cargarSolicitudes(const std::vector<Solicitud> &solicitudes_iniciales, GenericStack<Solicitud> &stack);
    GenericStack<Solicitud> procesarSolicitudesRechazadas(const GenericStack<Solicitud> &stack, double& totalAhorrado);
};
