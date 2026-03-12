#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include "Experiencia.h"
#include <string>
#include <set>
#include "DTFecha.h"

class TourGuiado: public Experiencia {
    private:
        string agencia;
        std::set<std::string> lugaresVisitados;
    public:
        // falto constructor
        TourGuiado(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string agencia, std::set<std::string> lugaresVisitados);
        float calcularCosto();


};

#endif
