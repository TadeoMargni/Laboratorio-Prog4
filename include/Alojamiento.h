#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "Experiencia.h"
#include "DTFecha.h"
#include <string>
#include <set>

enum TipoRegimen {
    AllInclusive,
    MediaPension
};

class Alojamiento: public Experiencia {
    private:
        std::string hotel;
        TipoRegimen regimen;
        int cantNoches;
    public:
        // falto constructor
        Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string hotel, TipoRegimen regimen, int cantNoches);
        float calcularCosto();
};

#endif
