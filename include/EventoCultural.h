#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include "Experiencia.h"
#include <string>
#include <set>
#include "DTFecha.h"
using namespace std;

class EventoCultural: public Experiencia {
    private:
        string ubicacion;
        bool usoCupon;
    public:
        // falto constructor
        EventoCultural(string codigoReserva, string descripcion, int precioBase, DTFecha* fecha, string ubicacion, bool usoCupon);
        float calcularCosto();


};

#endif
