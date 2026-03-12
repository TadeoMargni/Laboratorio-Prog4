#include "TourGuiado.h"

TourGuiado::TourGuiado(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string agencia, std::set<std::string> lugaresVisitados)
: Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
}

float TourGuiado::calcularCosto() {
    int cantLugares = lugaresVisitados.size();
    int cantTuristas = getTuristas().size();
    return getPrecioBase() + 2 * cantLugares * cantTuristas;
}