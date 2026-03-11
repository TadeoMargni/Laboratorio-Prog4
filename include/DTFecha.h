// Codigo p2

#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>

class DTFecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        DTFecha();
        std::string toString();
        bool esMayorQue(DTFecha fecha);
        DTFecha(int dia, int mes, int anio);
};

#endif
