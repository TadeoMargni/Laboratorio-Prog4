#include "TourGuiado.h"

TourGuiado::TourGuiado(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha, std::string agencia, std::set<std::string> lugaresVisitados)
: Experiencia(codigoReserva, descripcion, precioBase, fecha)
{
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
}
TourGuiado::~TourGuiado() {}
std::string TourGuiado::getAgencia()
{
    return this->agencia;
}
std::set<std::string> TourGuiado::getLugaresVisitados()
{
    return this->lugaresVisitados;
}
void TourGuiado::setAgencia(std::string a)
{
    this->agencia = a;
}
void TourGuiado::addLugarVisitado(std::string l)
{
    this->lugaresVisitados.insert(l);
}
void TourGuiado::removeLugarVisitado(std::string l)
{
    this->lugaresVisitados.erase(l);
}
float TourGuiado::calcularCosto()
{
    int cantLugares = lugaresVisitados.size();
    int cantTuristas = getTuristas().size();
    return getPrecioBase() + 2 * cantLugares * cantTuristas;
}