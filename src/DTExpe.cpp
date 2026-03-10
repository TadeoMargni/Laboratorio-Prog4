#include <string>
#include <set>
#include <DTFecha.cpp>

using namespace std; 

class DTExpe{
    private:
        string codigoReserva;
        string descripcion;
        DTFecha fecha;
        set<string> turista; //no se si podemos usar set o tenemos que alterar turista para poderlos manipluar en una lista dinamica, para preguntar
    public:
        DTExpe(string codigoReserva, string descripcion, DTFecha fecha, set<string>){
            this->codigoReserva=codigoReserva;
            this->descripcion=descripcion;
            this->fecha=fecha;
            this->turista=turista;
        }  
    
        ~DTExpe();

        string getCodigoReserva(DTExpe A){
            return A.codigoReserva;
        }

        string getDescripcion(DTExpe A){
            return A.descripcion;
        }

        DTFecha getFecha(DTExpe A){
            return getFecha(A);
        }

        set<string> getTruistas(DTExpe A){
            return A.turista;
        }
    


};