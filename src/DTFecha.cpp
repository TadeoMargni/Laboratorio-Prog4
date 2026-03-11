// codigo p2
#include "DTFecha.h"
#include <sstream>

DTFecha::DTFecha(){
    this->dia=0;
    this->mes=0;
    this->anio=0;
    }

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

std::string DTFecha::toString() {
    ostringstream oss;
    oss << dia << "/" << mes << "/" << anio;
    return oss.str();
}

bool DTFecha::esMayorQue(DTFecha f)
{
    return ((this->anio > f.anio) ||
        ((this->anio == f.anio) && (this->mes > f.mes)) ||
        ((this->anio == f.anio) && (this->mes == f.mes) && (this->dia > f.dia)));
}

