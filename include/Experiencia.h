#ifndef EXPERIENCIA
#define EXPERIENCIA

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTExpe.h"

using namespace std;

// Lo movi y renombre porque creo que encaja mas con la clase Experiencia que con el datatype DTExpe, que hasta donde vi
// su unica funcion era ser el tipo de retorno de la operacion getDT() en Experiencia

class Experiencia{
    private:
        string codigoReserva;
        string descripcion;
        DTFecha fecha;
        set<string> turista; //no se si podemos usar set o tenemos que alterar turista para poderlos manipluar en una lista dinamica, para preguntar
    public:
        Experiencia(string codigoReserva, string descripcion, DTFecha fecha, set<string>);

        ~Experiencia();

        string getCodigoReserva();

        string getDescripcion();

        DTFecha getFecha();

        set<string> getTruistas();

        DTExpe getDT();

        virtual float calcularCosto() = 0; // Operacion abstracta para que la clase Experencia sea abstracta
};

#endif
