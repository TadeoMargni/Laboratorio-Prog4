#include "DTExpe.h"
#include <ostream>

DTExpe::DTExpe(std::string codigoReserva, std::string descripcion, DTFecha* fecha, std::set<std::string> turistas) {
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->fecha = fecha;
    this->turistas = turistas;
}

DTExpe::~DTExpe() {} //agrego dest

// std::string DTExpe::getTitulo() {
//     return this->titulo;
// }

// std::string DTExpe::getDescripcion() {
//     return this->descripcion;
// }

// DTFecha DTExpe::getFecha() {
//     return this->fecha;
// }

// std::string DTExpe::toString() {
//     return titulo + " - " + descripcion + " - " + fecha.toString();
// }

std::ostream& operator<<(std::ostream& os, const DTExpe& expe) {
    os << expe.codigoReserva << "->" << expe.descripcion << "(" << expe.fecha->toString() << ")/";
    std::set<std::string>::const_iterator it = expe.turistas.begin();
    while (it != expe.turistas.end()) {
        os << *it;
        ++it;
        if (it != expe.turistas.end())
            os << ",";     //si quedan mas turistas pone , y sigue
    }
    return os;
}