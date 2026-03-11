#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "Experiencia.h"
#include "DTFecha.h"
#include <string>
#include <set>
using namespace std;

enum TipoRegimen {
    AllInclusive,
    MediaPension
};

class Alojamiento: public Experiencia {
    private:
        string hotel;
        TipoRegimen regimen;
        int cantNoches;
    public:
        // falto constructor
        Alojamiento(string codigoReserva, string descripcion, int precioBase, DTFecha* fecha, string hotel, TipoRegimen regimen, int cantNoches);
        float calcularCosto();
};

#endif
