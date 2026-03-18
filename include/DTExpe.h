
#ifndef DTEXPE_H
#define DTEXPE_H

#include <string>
#include <set>
#include "DTFecha.h"
#include <iostream>

class DTExpe {
private:
    std::string codigoReserva;
    std::string descripcion;
    DTFecha* fecha;
    std::set<std::string> turistas; //faltaba set d turistas
public:
    DTExpe(std::string codigoReserva, std::string descripcion, DTFecha* fecha, std::set<std::string> turistas);
    ~DTExpe();

friend std::ostream& operator<<(std::ostream& os, const DTExpe& expe);
//por letra pide usar ostream para sobrecargar << asi q no necesitamos los getters pq los imprime directo con cout
// friend sirve para q la funcion acceda a los atributos privados de dtexpe
};

#endif
