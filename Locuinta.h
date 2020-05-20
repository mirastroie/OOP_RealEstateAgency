#ifndef LOCUINTA_H_INCLUDED
#define LOCUINTA_H_INCLUDED
#include <string>

class Locuinta
{
  protected:
    std::string numeClient;
    double suprafata;
    const int maxDiscount=10;
    int discount;
    double pret;
public:
    Locuinta();
    Locuinta(std::string,double, int, double);
    Locuinta(const Locuinta&);
    Locuinta& operator=(const Locuinta&);
    virtual ~Locuinta();

    friend std::istream &operator>>(std::istream&,Locuinta&);
    friend std::ostream &operator<<(std::ostream&,const Locuinta&);
    virtual void afisare();
    virtual double pretFinal()const=0;
    bool operator<(const Locuinta&)const;

};
#endif // LOCUINTA_H_INCLUDED
