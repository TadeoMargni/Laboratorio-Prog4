#include "Alojamiento.h"

Alojamiento::Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string hotel, TipoRegimen regimen, int cantNoches)
: Experiencia(codigoReserva, descripcion, precioBase, fecha)
{
    this->hotel = hotel;
    this->regimen = regimen;
    this->cantNoches = cantNoches;
}
Alojamiento::~Alojamiento()
{
    ~Experiencia();
}
std::string Alojamiento::getHotel()
{
    return this->hotel;
}
TipoRegimen Alojamiento::getRegimen()
{
    return this->regimen;
}
int Alojamiento::getCantNoches()
{
    return this->cantNoches;
}
void Alojamiento::setHotel(std::string h)
{
    this->hotel = h;
}
void Alojamiento::setRegimen(TipoRegimen r)
{
    this->regimen = r;
}
void Alojamiento::setCantNoches(int n)
{
    this->cantNoches = n;
}
float Alojamiento::calcularCosto()
{
    float costo = getPrecioBase() * cantNoches;
    if (regimen == AllInclusive)
        costo += 10 * cantNoches;
    return costo;
}