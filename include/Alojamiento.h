#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "Experiencia.h"

enum TipoRegimen {
    AllInclusive = 1,
    MediaPension = 2
};

class Alojamiento: public Experiencia {
    private:
        std::string hotel;
        TipoRegimen regimen;
        int cantNoches;
    public:
        Alojamiento(std::string, std::string, int, DTFecha*, std::string, TipoRegimen, int);
        ~Alojamiento();

        std::string getHotel();
        TipoRegimen getRegimen();
        int getCantNoches();

        void setHotel(std::string);
        void setRegimen(TipoRegimen);
        void setCantNoches(int);

        float calcularCosto();
};

#endif
