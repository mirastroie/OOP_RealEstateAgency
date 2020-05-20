#include <bits/stdc++.h>
#include "Casa.h"
#include "MyException.h"

Casa::Casa():area(0),numarEtaje(1),pretCurte(0),suprafataCurte(0){}
Casa::Casa(std::string numeClient, double suprafata,int discount, double pret, double suprafataCurte, int numarEtaje,
double areaValue,double pretCurte):Locuinta(numeClient,suprafata,discount,pret),
suprafataCurte(suprafataCurte),numarEtaje(numarEtaje),pretCurte(pretCurte)
{

     for(int i=0;i<numarEtaje;i++)
        area.push_back(areaValue); ///setam suprafetele tuturor etajelor ca fiind egale cu areaValue

}

Casa::Casa(std::string numeClient, double suprafata,int discount, double pret,
           double suprafataCurte, int numarEtaje, std::vector<double> areaVector,double pretCurte):Locuinta(numeClient,suprafata,discount,pret),
suprafataCurte(suprafataCurte),numarEtaje(numarEtaje),area(areaVector),pretCurte(pretCurte){}

///avand in vedere ca vectorul e de double-uri, e okay sa folosim CC si operatorul de = date de clasa vector
Casa::Casa(const Casa&old):Locuinta(old),suprafataCurte(old.suprafataCurte),numarEtaje(old.numarEtaje),area(old.area),pretCurte(old.pretCurte){}
Casa& Casa::operator=(const Casa&old)
{

    if(this==&old)return *this;
    Locuinta::operator=(old);
    suprafataCurte=old.suprafataCurte;
    numarEtaje=old.numarEtaje;
    pretCurte=old.pretCurte;
    area=old.area;
    area.shrink_to_fit();
    return *this;

}
std::istream&operator>>(std::istream&in, Casa&old)
{
    in>>static_cast<Locuinta&>(old);
    std::cout<<"Introduceti suprafata curtii:\n";
    in>>old.suprafataCurte;
    std::cout<<"Introduceti pretul curtii:\n";
    in>>old.pretCurte;
    std::cout<<"Introduceti numarul de etaje al casei: \n";
    in>>old.numarEtaje;
    std::cout<<"Introduceti suprafata utila a fiecarui etaj: \n";
    old.area.resize(old.numarEtaje);
    double sum=0;
    for(int i=0;i<old.numarEtaje;i++)
       {

        in>>old.area[i];sum+=old.area[i];
       }
    if(sum!=old.suprafata)
        throw(MyException("Suprafata utila a etajelor nu corespunde cu suprafata utila totala",4));
    return in;
}
std::ostream&operator<<(std::ostream&out, const Casa&old)
{

    out<<static_cast<const Locuinta&>(old);
    std::cout<<"Curtea are o suprafata de";
    out<<old.suprafataCurte;
     std::cout<<", avand pretul de ";
    out<<old.pretCurte;
    std::cout<<". Sunt";
    out<<old.numarEtaje;
    std::cout<<"etaje si fiecare etaj are suprafata utila de ";
    std::vector<double>::const_iterator it;
    for(it=old.area.begin();it!=old.area.end();it++)
        out<<*it<<" ";
    std::cout<<"Pretul total este: ";
        out<<old.pretFinal();
    std::cout<<"\n";
    return out;
}

double Casa::pretFinal()const
{
    double pretPartial=pret*suprafata*((100-static_cast<double>(discount))/100);
    pretPartial+=pretCurte*suprafataCurte;
    return pretPartial;
}
void Casa::afisare()
{
    std::cout<<"Numele clientului este: ";
    std::cout<<numeClient;
    std::cout<<", avand suprafata locuintei de: ";
    std::cout<<suprafata;
    std::cout<<" . Clientul beneficiaza de un discount de: ";
    std::cout<<discount;
    std::cout<<" si pretul pe m2 este";
    std::cout<<pret<<".\n";
    std::cout<<"Curtea are o suprafata de";
    std::cout<<suprafataCurte;
    std::cout<<", avand pretul pe m2 de ";
    std::cout<<pretCurte;
    std::cout<<". Sunt";
    std::cout<<numarEtaje;
    std::cout<<"etaje si fiecare etaj are suprafata utila de ";
    std::vector<double>::const_iterator it;
    for(it=area.begin();it!=area.end();it++)
        std::cout<<*it<<" ";
    std::cout<<" . Pretul total final este: ";
    std::cout<<pretFinal();
    std::cout<<"\n";
}
Casa::~Casa()
{
    std::cout<<"Destructor called for Home\n";
    area.clear();
    area.shrink_to_fit();
}
