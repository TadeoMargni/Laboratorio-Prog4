
#include "../include/Experiencia.h"


Experiencia::Experiencia(string codigoReserva, string descripcion, DTFecha fecha, set<string>){ // Se podria recibir un unico parametro de tipo DTExpe?
    this->codigoReserva=codigoReserva;
    this->descripcion=descripcion;
    this->fecha=fecha;
    this->turista=turista;
}

Experiencia::~Experiencia();

string Experiencia::getCodigoReserva(){ // Accedo al objeto implicito porque esto se va a llamar directamente desde un objeto de la clase experiencia, no hace falta pasarle otro por parametro
    return this->codigoReserva;
}

string Experiencia::getDescripcion(){
    return this->descripcion;
}

DTFecha Experiencia::getFecha(){
    return this->fecha;
}

set<string> Experiencia::getTruistas(){
    return this->turista;
}

DTExpe Experiencia::getDT();

set<string> Experiencia::getTruistas(){
    return this->turista;
}
