#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include "Experiencia.h"
#include <string>
#include <set>
#include "DTFecha.h"

class EventoCultural: public Experiencia {
    private:
        std::string ubicacion;
        bool usoCupon;
    public:
        // falto constructor
        EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string ubicacion, bool usoCupon);
        float calcularCosto();


};

#endif
