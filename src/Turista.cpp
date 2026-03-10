#include <string>

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