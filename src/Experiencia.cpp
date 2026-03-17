#include "Experiencia.h"


Experiencia::Experiencia(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha* fecha)
{
    this->codigoReserva = codigoReserva;                                              
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
}
Experiencia::~Experiencia()
{
    std::list<Turista*>::iterator it = this->turistas.begin();
    while (it != this->turistas.end())
    {
        Turista* a_borrar = *it;
        ++it;
        eliminarTurista(a_borrar);
    }
}
std::string Experiencia::getCodigoReserva()
{
    return this->codigoReserva;
}
std::string Experiencia::getDescripcion()
{
    return this->descripcion;
}
DTFecha* Experiencia::getFecha()
{
    return this->fecha;
}
int Experiencia::getPrecioBase()
{
    return this->precioBase;
}
std::list<Turista*> Experiencia::getTuristas()
{
    return this->turistas;
}
void Experiencia::setCodigoReserva(std::string c)
{
    this->codigoReserva = c;
}
void Experiencia::setDescripcion(std::string d)
{
    this->descripcion = d;
}
void Experiencia::setFecha(DTFecha* f)
{
    this->fecha = f;
}
void Experiencia::setPrecioBase(int p)
{
    this->precioBase = p;
}
void Experiencia::agregarTurista(Turista* t)
{
    this->turistas.push_back(t);
}
void Experiencia::eliminarTurista(Turista* t)
{
    this->turistas.remove(t);
}
DTExpe* Experiencia::getDT()
{
    std::set<std::string> nombres;
    std::list<Turista*>::iterator it = this->turistas.begin();
    while (it != this->turistas.end())
    {
        nombres.insert((*it)->getNombre());
        ++it;
    }
    DTExpe* retorno = new DTExpe(this->codigoReserva, this->descripcion, this->fecha, nombres);
    return retorno;
}

