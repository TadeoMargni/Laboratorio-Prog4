
#ifndef DTEXPE_H
#define DTEXPE_H

#include <string>
#include "DTFecha.h"

class DTExpe {
private:
    std::string titulo;
    std::string descripcion;
    DTFecha fecha;

public:
    DTExpe(std::string titulo, std::string descripcion, DTFecha fecha);

    std::string getTitulo();
    std::string getDescripcion();
    DTFecha getFecha();

    std::string toString();
};

#endif
