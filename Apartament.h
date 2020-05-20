#ifndef APARTAMENT_H_INCLUDED
#define APARTAMENT_H_INCLUDED
#include "Locuinta.h"

class Apartament: public Locuinta
{

    int Etaj;
    const int maxEtaje=100;
public:
    Apartament();
    Apartament(std::string, double, int , double, int);
    Apartament(const Apartament&);
    double pretFinal()const;
    Apartament& operator=(const Apartament&);
    friend std::istream &operator>>(std::istream&, Apartament&);
    friend std::ostream &operator<<(std::ostream&, const Apartament&);

    void afisare();
    ~Apartament();
};


#endif // APARTAMENT_H_INCLUDED
