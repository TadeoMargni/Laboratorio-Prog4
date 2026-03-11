#include "../include/DTExpe.h"

DTExpe::DTExpe(std::string titulo, std::string descripcion, DTFecha fecha) {
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->fecha = fecha;
}

std::string DTExpe::getTitulo() {
    return this->titulo;
}

std::string DTExpe::getDescripcion() {
    return this->descripcion;
}

DTFecha DTExpe::getFecha() {
    return this->fecha;
}

std::string DTExpe::toString() {
    return titulo + " - " + descripcion + " - " + fecha.toString();
}