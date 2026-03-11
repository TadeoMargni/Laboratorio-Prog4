#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include <list>
#include "DTFecha.h"
using namespace std;

class Experiencia; 
// para no tener dependecia circular

class Turista{
    private:
        string ci;
        string nombre;
        string email;
        list<Experiencia*> experiencias;
    public:
        Turista(string ci, string nombre, string email);

        ~Turista();

        string toString();

        string getCi();
        string getNombre();
        void agregarExperiencia(Experiencia* e);
        void eliminarExperiencia(Experiencia* e);
        set<string> listarExperiencias(DTFecha* desde, float min, float max);
};

#endif
