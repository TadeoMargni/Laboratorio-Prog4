#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include "Experiencia.h"

class TourGuiado: public Experiencia {
    private:
        std::string agencia;
        std::set<std::string> lugaresVisitados;
    public:
        TourGuiado(std::string, std::string, int, DTFecha*, std::string, std::set<std::string>);
        ~TourGuiado();

        std::string getAgencia();
        std::set<std::string> getLugaresVisitados();

        void setAgencia(std::string);
        void addLugarVisitado(std::string);
        void removeLugarVisitado(std::string);

        float calcularCosto();
};

#endif
