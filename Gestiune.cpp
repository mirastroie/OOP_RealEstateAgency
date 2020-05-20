#include <bits/stdc++.h>

#include "Gestiune.h"

template<class tip> Gestiune<tip>::~Gestiune()
{

    tip *ptr=nullptr,*ptr2=nullptr;
    for(auto it=objects->begin(); it!=objects->end();)
    {

        ptr=it->second;
        ptr2=dynamic_cast<tip*>(it->first);
        objects->erase(it++); ///scot elementul din set

        delete ptr2;  ///eliberez memoria retinuta de obiectul pointat de catre ptr2 si ptr


        ptr2=nullptr;
        ptr=nullptr;

    }
    delete objects;
}
///adaugarea locuintelor in structura de date
template<class tip>  Gestiune<tip>& Gestiune<tip>::operator+=(tip&old)
{
    indexLocuinta++;
    std::pair<Locuinta*,tip*> add;
    tip *j=new tip(old);
    add.second=j;

    add.first=dynamic_cast<Locuinta*>(j);

    objects->insert(add);
    return *this;
}
///afisarea obiectelor din structura de date
template<class tip>  void Gestiune<tip>::afisare()
{
    if(!objects->size())
    {
        std::cout<<"Nu exista obiecte de tipul "<<typeid(tip).name()<<"\n";
        return;
    }
    std::cout<<"Obiectele de tipul "<<typeid(tip).name()<<" sunt: \n";
    for(auto it=objects->begin(); it!=objects->end(); it++)
    {
        if(Casa*c=dynamic_cast<Casa*>(it->first))
            std::cout<<*c<<"\n";
        else if(Apartament*a=dynamic_cast<Apartament*>(it->first))
            std::cout<<*a<<"\n";
    }
}
///Pentru specializare:

Gestiune<Casa>:: ~Gestiune()
{

    Casa *ptr=nullptr,*ptr2=nullptr;
    for(auto it=objects->begin(); it!=objects->end();)
    {

        ptr=it->second;
        ptr2=dynamic_cast<Casa*>(it->first);
        objects->erase(it++);

        delete ptr2;
        ptr2=nullptr;
        ptr=nullptr;

    }
    delete objects;

}
Gestiune<Casa>& Gestiune<Casa>::operator+=(Casa&old)
{
    std::pair<Locuinta*,Casa*> add;
    Casa *j=new Casa(old);
    add.second=j;
    add.first=dynamic_cast<Locuinta*>(j);
    nrCase++;

    pretFinalCase+=old.pretFinal();
    objects->insert(add);
    return *this;
}
void Gestiune<Casa>::afisare()
{
    if(!objects->size())
    {
        std::cout<<"Nu exista case.\n";
        return;
    }
    std::cout<<"Casele sunt: \n";
    for(auto it=objects->begin(); it!=objects->end(); it++)
    {
        if(Casa*c=dynamic_cast<Casa*>(it->first))
            std::cout<<*c<<"\n";
    }
}
///instantierea explicita a template-ului
///necesara pentru despartirea declaratiei si a implementarii
///in fisiere .cpp si .h
template class Gestiune<Apartament>;
template class Gestiune<Casa>;


template <class tip> int Gestiune<tip>::indexLocuinta=0;
Gestiune<Casa>* Gestiune<Casa>::instance=nullptr;
int Gestiune<Casa>::nrCase=0;
double  Gestiune<Casa>::pretFinalCase=0;
template<class tip> Gestiune<tip>*   Gestiune<tip>:: instance = nullptr;
