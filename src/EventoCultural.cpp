#include "EventoCultural.h"

EventoCultural::EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string ubicacion, bool usoCupon)
: Experiencia(codigoReserva, descripcion, precioBase, fecha)
{
    this->ubicacion = ubicacion;
    this->usoCupon = usoCupon;
}
EventoCultural::~EventoCultural()
{
    ~Experiencia();
}
std::string EventoCultural::getUbicacion()
{
    return this->ubicacion;
}
bool EventoCultural::getUsoCupon()
{
    return this->usoCupon;
}
void EventoCultural::setUbicacion(std::string u)
{
    this->ubicacion = u;
}
void EventoCultural::setUsoCupon(bool uC)
{
    this->usoCupon = uC;
}
float EventoCultural::calcularCosto()
{
    int cantTuristas = getTuristas().size();
    float costo = getPrecioBase() * cantTuristas;
    if (usoCupon)
        costo -= 5 * cantTuristas;
    return costo;
}