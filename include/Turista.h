#ifndef TURISTA_H
#define TURISTA_H

#include <string>
#include <set>
#include <list>
#include "DTFecha.h"

class Experiencia; 
// para no tener dependecia circular

class Turista{
    private:
        std::string ci;
        std::string nombre;
        std::string email;
        std::list<Experiencia*> experiencias;
    public:
        Turista(std::string ci, std::string nombre, std::string email);

        ~Turista();

        std::string toString();

        std::string getCi();
        std::string getNombre();
        void agregarExperiencia(Experiencia* e);
        void eliminarExperiencia(Experiencia* e);
        std::list<Experiencia*> getExperiencias();
        std::set<std::string> listarExperiencias(DTFecha* desde, float min, float max);
};

#endif
