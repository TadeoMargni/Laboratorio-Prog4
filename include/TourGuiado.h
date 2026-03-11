#ifndef TOURGUIADO
#define TOURGUIADO

#include "Experiencia.h"
#include <string>
#include <set>

class TourGuiado: public Experiencia {
    private:
        std::string agencia;
        std::set<std::string> lugaresVisitados;
    public:
        float CalcularCosto();


};

#endif
