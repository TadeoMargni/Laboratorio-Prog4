
class DTFecha{
    private:
        int dia;
        int mes;
        int año;

    public:
        DTFecha(){
            this->año=año;
            this->dia=dia;
            this->mes=mes;
        }

        ~DTFecha();

        DTFecha getFecha(DTFecha A){return A;}
    
};