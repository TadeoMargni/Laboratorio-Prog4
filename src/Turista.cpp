
#include "../include/Turista.h"

Turista::Turista(string ci, string nombre, string email){
    this->ci=ci;
    this->nombre=nombre;
    this->email=email;
};

Turista::~Turista();

string Turista::toString(string ci, string nombre, string email){
    string info =ci + "->" + nombre + "/" + email;
    return info;
}
