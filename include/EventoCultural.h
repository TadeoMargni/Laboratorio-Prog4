#ifndef EVENTOCULTURAL_H
#define EVENTOCULTURAL_H

#include "Experiencia.h"

class EventoCultural: public Experiencia {
    private:
        std::string ubicacion;
        bool usoCupon;
    public:
        EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string ubicacion, bool usoCupon);
        ~EventoCultural();

        std::string getUbicacion();
        bool getUsoCupon();

        void setUbicacion(std::string);
        void setUsoCupon(bool);

        float calcularCosto();
};

#endif
