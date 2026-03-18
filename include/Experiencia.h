#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include "DTFecha.h"
#include "DTExpe.h"
#include "Turista.h"
#include <string>
#include <set>
#include <list>


class Turista;

class Experiencia
{
    private:
        std::string codigoReserva;
        std::string descripcion;
        DTFecha* fecha;
        int precioBase;
        std::list<Turista*> turistas;
    public:
        Experiencia(std::string, std::string, int, DTFecha*);
        virtual ~Experiencia();
        
        std::string getCodigoReserva();
        std::string getDescripcion();
        DTFecha* getFecha();
        int getPrecioBase();
        std::list<Turista*> getTuristas();

        void setCodigoReserva(std::string);        
        void setDescripcion(std::string);
        void setFecha(DTFecha*);
        void setPrecioBase(int);
        void agregarTurista(Turista*);
        void eliminarTurista(Turista*);
        
        DTExpe* getDT();
        virtual float calcularCosto() = 0;
};

#endif
