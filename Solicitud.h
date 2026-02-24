#pragma once
#include <string>

class Solicitud {
public:
    Solicitud(const int& id_producto, const std::string& fecha, const std::string& codigo, const char& estado, const double& reembolso);

    // Getters
    std::string getCodigo() const;
    char getEstado() const;
    double getReembolso() const;

    // Setters
    void setCodigo(const std::string& codigo);
    void setEstado(const char estado);
    void setReembolso(const double reembolso);

    void mostrar() const;

    bool estadoValido(const char& e) const;
private:
    int id_producto;
    std::string fecha_solicitud;
    std::string codigo;
    char estado;
    double reembolso;

};

