#ifndef ALOJAMIENTO
#define ALOJAMIENTO

#include "Experiencia.h"
#include <string>

enum TipoRegimen {
    AllInclusive,
    MediaPension

};

class Alojamiento: public Experiencia {
    private:
        std::string hotel;
        enum TipoRegimen regimen;
        int cantNoches;
    public:
        float CalcularCosto();
};

#endif
