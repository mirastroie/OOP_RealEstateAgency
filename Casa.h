#ifndef CASA_H_INCLUDED
#define CASA_H_INCLUDED
#include "Locuinta.h"
#include <vector>


class Casa: public Locuinta
{
    const int numarEtajeMax=20;
    double suprafataCurte;
    int numarEtaje;
    double pretCurte;
    std::vector <double> area;
public:
    Casa();
    Casa(std::string, double,int, double, double, int, double,double);
    Casa(std::string, double,int, double, double, int, std::vector<double>,double);
    Casa(const Casa&);
    Casa& operator=(const Casa&);
    friend std::istream& operator>>(std::istream&,Casa&);
    friend std::ostream&operator<<(std::ostream &,const Casa&);
    void afisare();
    double pretFinal()const;
    ~Casa();
};

#endif // CASA_H_INCLUDED
