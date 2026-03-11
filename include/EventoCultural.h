#ifndef EVENTOCULTURAL
#define EVENTOCULTURAL

#include "Experiencia.h"
#include <string>


class EventoCultural: public Experiencia {
    private:
        std::string ubicacion;
        bool usoCupon;
    public:
        float CalcularCosto();


};

#endif
