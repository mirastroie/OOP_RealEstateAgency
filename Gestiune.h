#ifndef GESTIUNE_H_INCLUDED
#define GESTIUNE_H_INCLUDED

#include <set>
#include <utility>
#include <typeinfo>
#include "Apartament.h"
#include "Casa.h"



///Implementam Singleton, ne asiguram ca
///exista o singura instanta a acelei clase si prin urmare CC si op = trebuie stersi.

///Prin intermediul destructorului dezalocam toata memoria alocata - atat a obiectelor de tip
///apartament sau casa, cat si a set-ul in sine.

template <class tip>
class Gestiune
{
    static Gestiune<tip>* instance;
    static int indexLocuinta;
    std::set <std::pair<Locuinta*,tip*>> *objects;
    Gestiune()
    {
        objects=new std::set<std::pair<Locuinta*,tip*>>;
    }
public:
    ~Gestiune();
    Gestiune(const Gestiune&)=delete;
    Gestiune<tip>& operator=(const Gestiune<tip>&)=delete;

    static Gestiune<tip>* getHandle()
    {
        if(!instance)
            instance = new Gestiune<tip>;
        return instance;
    }

    static int getIndexLocuinta()
    {
        return indexLocuinta;
    }
    Gestiune& operator+=(tip&old);
    void afisare();
};



///specializarea
template <>
class Gestiune<Casa>
{
    static Gestiune<Casa>* instance;
    std::set <std::pair<Locuinta*,Casa*>> *objects;
    static int nrCase;
    static double pretFinalCase;
    Gestiune()
    {
        objects=new std::set<std::pair<Locuinta*,Casa*>>;
    }

public:
    ~Gestiune();
    Gestiune(const Gestiune&)=delete;
    Gestiune<Casa>& operator=(const Gestiune<Casa>&)=delete;

    static Gestiune<Casa>*getHandle()
    {
        if(!instance)
            instance = new Gestiune<Casa>;
        return instance;
    }

    static int getNrCase()
    {
        return nrCase;
    }
    Gestiune& operator+=(Casa&old);
    void afisare();
    static void getPretFinalCase()
    {
        std::cout<<"Totalul obtinut de agentie de pe urma caselor este: "<<pretFinalCase<<"\n";

    }
};
#endif // GESTIUNE_H_INCLUDED
