#ifndef TURISTA
#define TURISTA

#include <string>

using namespace std;

class Turista{
    private:
        string ci;
        string nombre;
        string email;
    public:
        turista(string ci, string nombre, string email);

        ~turista();

        string toString(string ci, string nombre, string email);
};

#endif
