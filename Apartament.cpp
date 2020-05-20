#include <bits/stdc++.h>
#include "Apartament.h"
#include "MyException.h"


    Apartament::Apartament():Etaj(0){}
    Apartament::Apartament(std::string numeClient, double suprafata, int discount, double pret, int Etaj):Locuinta(numeClient,suprafata,discount,pret){
       if(Etaj>maxEtaje)
           throw(MyException("Prea multe etaje!",5));
       this->Etaj=Etaj;
    }
    Apartament::Apartament(const Apartament&old):Locuinta(old),Etaj(old.Etaj){}
   Apartament&  Apartament::operator=(const Apartament&old)
    {
        if(this==&old)return *this;
        Locuinta::operator=(old);
        Etaj=old.Etaj;
        return *this;
    }
    double Apartament::pretFinal()const
{

    return pret*suprafata*((100-static_cast<double>(discount))/100);

}
    std::istream &operator>>(std::istream&in, Apartament&old)
    {
        in>>static_cast<Locuinta&>(old);
        std::cout<<"Introdu etajul:\n";

        in>>old.Etaj;
        if(old.Etaj>old.maxEtaje)
           throw(MyException("Prea multe etaje!",5));
        return in;
    }
    std::ostream &operator<<(std::ostream&out, const Apartament&old)
    {
        out<<static_cast<const Locuinta&>(old);
        std::cout<<"Apartamentul se afla la etajul ";
        out<<old.Etaj;
        std::cout<<"Pretul total este: ";
        out<<old.pretFinal()<<"\n";
        return out;

    }

void Apartament::afisare()
    {
    std::cout<<"Numele clientului este: ";
    std::cout<<numeClient;
    std::cout<<", avand suprafata locuintei de: ";
    std::cout<<suprafata;
    std::cout<<" . Clientul beneficiaza de un discount de: ";
    std::cout<<discount;
    std::cout<<" si pretul pe m2 este";
    std::cout<<pret<<".\n";
    std::cout<<"Apartamentul se afla la etajul ";
    std::cout<<Etaj;
    std::cout<<" ,iar pretul final total este "<<pretFinal()<<"\n";

    }
    Apartament::~Apartament()
    {
        std::cout<<"Destructor called for Apartment\n";
    }
