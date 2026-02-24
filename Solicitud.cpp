//
// Created by gonza on 24/02/2026.
//

#include "Solicitud.h"
#include <stdexcept>
#include <iostream>

Solicitud::Solicitud(const int& id_producto, const std::string& fecha, const char& estado, const double& reembolso) {
    this->id_producto = id_producto;
    this->fecha_solicitud = fecha;
    setCodigo();
    this->estado = estado;
    this->reembolso = reembolso;

}

std::string Solicitud::getCodigo() const{
    return codigo;
}

char Solicitud::getEstado() const {
    return estado;
}

double Solicitud::getReembolso() const {
    return reembolso;
}

void Solicitud::setCodigo() {
    codigo = std::to_string(this->id_producto) + "_" + this->fecha_solicitud;
}

void Solicitud::setEstado(const char estado) {
    if (!estadoValido(estado)) {
        throw std::invalid_argument("Estado no valido. (P, A o R");
    }
    this->estado = estado;
}

void Solicitud::setReembolso(const double reembolso) {
    this->reembolso = reembolso;
}

bool Solicitud::estadoValido(const char& e) const {
    return e == 'P' || e == 'A' || e == 'R';
}

void Solicitud::mostrar() const {
    std::cout << "Codigo: " << codigo
                  << " | Estado: " << estado
                  << " | Reembolso: " << reembolso << "\n";
}
