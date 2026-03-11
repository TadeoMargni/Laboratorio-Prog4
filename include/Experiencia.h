#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <string>
#include <set>
#include <list>
#include "DTFecha.h"
#include "DTExpe.h"

// Lo movi y renombre porque creo que encaja mas con la clase Experiencia que con el datatype DTExpe, que hasta donde vi
// su unica funcion era ser el tipo de retorno de la operacion getDT() en Experiencia

class Turista;
// para no tener dependecia circular

class Experiencia{
    private:
        std::string codigoReserva;
        std::string descripcion;
        DTFecha fecha;
        int precioBase;
        // falto precio base
        // es lista no set, no nos importa el orden
        std::list<Turista*> turistas; //no se si podemos usar set o tenemos que alterar turista para poderlos manipluar en una lista dinamica, para preguntar
    public:
        Experiencia(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha);

        virtual ~Experiencia();

        std::string getCodigoReserva();

        DTFecha* getFecha();
        int getPrecioBase();
        std::list<Turista*> getTuristas();

        DTExpe* getDT();

        virtual float calcularCosto() = 0; // Operacion abstracta para que la clase Experencia sea abstracta
        // agrego funciones que faltan
        void agregarTurista(Turista* t);
        void eliminarTurista(Turista* t);
};

#endif
