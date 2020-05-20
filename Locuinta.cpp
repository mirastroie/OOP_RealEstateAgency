#include <bits/stdc++.h>
#include "Locuinta.h"

#include "MyException.h"


Locuinta::Locuinta()
{
    numeClient="Mr. X";
    suprafata=0;
    discount=0;
    pret=0;
}
Locuinta::Locuinta(std::string s, double sp, int d,double p):numeClient(s),suprafata(sp),pret(p) {
   if(d<0 || d>maxDiscount)
       throw(MyException("Discountul trebuie sa fie intre 0 si 10",2));
   discount=d;
}
Locuinta::Locuinta(const Locuinta&old):discount(old.discount),suprafata(old.suprafata),numeClient(old.numeClient),pret(old.pret) {}
Locuinta& Locuinta::operator=(const Locuinta&old)
{
    if(this==&old)
        return *this;
    numeClient=old.numeClient;
    suprafata=old.suprafata;
    discount=old.discount;
    pret=old.pret;
    return *this;
}
std::istream& operator>>(std::istream &in,Locuinta &old)
{
    std::cout<<"Introdu numele clientului\n";
    std::getline(in,old.numeClient);
    std::cout<<"Introdu suprafata\n";
    in>>old.suprafata;

    std::cout<<"Introdu discountul (intre 0-10 %)\n";
    in>>old.discount;
    if(old.discount<0 || old.discount>old.maxDiscount)
       throw(MyException("Discountul trebuie sa fie intre 0 si 10",2));
    std::cout<<"Introdu pretul:\n";
    in>>old.pret;
    return in;
}
std::ostream& operator<<(std::ostream &out,const Locuinta&old)
{
    std::cout<<"Numele clientului este: ";
    out<<old.numeClient;
    std::cout<<", avand suprafata locuintei de: ";
    out<<old.suprafata;
    std::cout<<" .Clientul beneficiaza de un discount de: ";
    out<<old.discount;
    std::cout<<" ,pretul pe m2 este ";
    out<<old.pret<<".\n";
    return out;
}
void Locuinta::afisare()
{
    std::cout<<"Numele clientului este: ";
    std::cout<<numeClient;
    std::cout<<", avand suprafata locuintei de: ";
    std::cout<<suprafata;
    std::cout<<" .Avand in vedere discountul de: ";
    std::cout<<discount;
    std::cout<<" ,pretul final aferent este ";
    std::cout<<pret<<".\n";
}
bool Locuinta::operator<(const Locuinta&old)const
{
    if(suprafata<old.suprafata)
        return true;
    return false;
}

Locuinta::~Locuinta()
{
    std::cout<<"Destructor for locuinta called\n";
}
