#include <iostream>
#include <list>
#include <map>
#include <string>
#include <set>

using namespace std; 

class turista{
    private:
        string ci;
        string nombre;
        string email;

    turista(string ci, string nombre, string email){
        this->ci=ci;
        this->nombre=nombre;
        this->email=email;
    }

    ~turista();

    string toString(string ci, string nombre, string email){
        string info =ci + "->" + nombre + "/" + email;
        return info; 
    }

    
 
};

class DTFecha{
    private:
        int dia;
        int mes;
        int año;

    public:
        DTFecha(){
            this->año=año;
            this->dia=dia;
            this->mes=mes;
        }

        ~DTFecha();

        DTFecha getFecha(DTFecha A){return A;}
    
};


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