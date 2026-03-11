
#include "Experiencia.h"
#include "Turista.h"

Experiencia::Experiencia(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha){ // Se podria recibir un unico parametro de tipo DTExpe?
    this->codigoReserva=codigoReserva;                                              // en los constructores no va set ni list ni map
    this->descripcion=descripcion;
    this->precioBase=precioBase;
    this->fecha=fecha;
}

Experiencia::~Experiencia() {}

std::string Experiencia::getCodigoReserva(){ // Accedo al objeto implicito porque esto se va a llamar directamente desde un objeto de la clase experiencia, no hace falta pasarle otro por parametro
    return codigoReserva;
}

// getDT debe devolver la descripcion

DTFecha Experiencia::getFecha(){
    return fecha;
}

std::list<Turista*> Experiencia::getTuristas() {
    return turistas;
}

int Experiencia::getPrecioBase() {
    return precioBase;
}

void Experiencia::agregarTurista(Turista* t) {
    turistas.push_back(t);
}

void Experiencia::eliminarTurista(Turista* t) {
    turistas.remove(t);
}

// DTExpe Experiencia::getDT(); falta .h


