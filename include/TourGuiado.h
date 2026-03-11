#ifndef TOURGUIADO_H
#define TOURGUIADO_H

#include "Experiencia.h"
#include <string>
#include <set>
#include "DTFecha.h"
using namespace std;

class TourGuiado: public Experiencia {
    private:
        string agencia;
        set<string> lugaresVisitados;
    public:
        // falto constructor
        TourGuiado(string codigoReserva, string descripcion, int precioBase, DTFecha* fecha, string agencia, set<string> lugaresVisitados);
        float CalcularCosto();


};

#endif
