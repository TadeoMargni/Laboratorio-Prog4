
#include "Turista.h"
#include "Experiencia.h"

Turista::Turista(std::string ci, std::string nombre, std::string email){
    this->ci=ci;
    this->nombre=nombre;
    this->email=email;
};

Turista::~Turista() {}

std::string Turista::toString() {
    return ci + "->" + nombre + "/" + email;
}

std::string Turista::getCi() {
    return ci;
}

std::string Turista::getNombre() {
    return nombre;
}

void Turista::agregarExperiencia(Experiencia* e) {
    experiencias.push_back(e);
}

void Turista::eliminarExperiencia(Experiencia* e) {
    experiencias.remove(e);
}