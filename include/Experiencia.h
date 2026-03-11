#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTExpe.h"

using namespace std;

// Lo movi y renombre porque creo que encaja mas con la clase Experiencia que con el datatype DTExpe, que hasta donde vi
// su unica funcion era ser el tipo de retorno de la operacion getDT() en Experiencia

class Turista;
// para no tener dependecia circular

class Experiencia{
    private:
        string codigoReserva;
        string descripcion;
        DTFecha fecha;
        int precioBase;
        // falto precio base
        // es lista no set, no nos importa el orden
        list<Turista*> turistas; //no se si podemos usar set o tenemos que alterar turista para poderlos manipluar en una lista dinamica, para preguntar
    public:
        Experiencia(string codigoReserva, string descripcion, int precioBase, DTFecha* fecha);

        virtual ~Experiencia();

        string getCodigoReserva();

        DTFecha* getFecha();
        int getPrecioBase();
        list<Turista*> getTruistas();

        DTExpe* getDT();

        virtual float calcularCosto() = 0; // Operacion abstracta para que la clase Experencia sea abstracta

        void agregarTurista(Turista* t);
        void eliminarTurista(Turista* t);
};

#endif
