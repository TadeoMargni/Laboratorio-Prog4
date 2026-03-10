// Codigo p2

#ifndef DTFECHA_H
#define DTFECHA_H

#include <string>
using namespace std;

class DTFecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        DTFecha();
        string toString();
        bool esMayorQue(DTFecha fecha);
        DTFecha(int dia, int mes, int anio);
};

#endif
