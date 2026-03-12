#include "Alojamiento.h"

Alojamiento::Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string hotel, TipoRegimen regimen, int cantNoches)
: Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantNoches = cantNoches;
}

float Alojamiento::calcularCosto() {
    float costo = getPrecioBase() * cantNoches;
    if (regimen == AllInclusive)
        costo += 10 * cantNoches;
    return costo;
}