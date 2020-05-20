#include <iostream>
#include "Locuinta.h"
#include "Casa.h"
#include "Apartament.h"
#include "Gestiune.h"
#include "MyException.h"
#include <memory>
using namespace std;

void prelucrare()
{

    unique_ptr<Gestiune<Apartament>> A(Gestiune<Apartament>::getHandle());
    unique_ptr<Gestiune<Casa>> C(Gestiune<Casa>::getHandle());
    int n,x;
    cout<<"Cate obiecte vrei sa introduci?\n";
    cin>>n;
    try
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Apartament(1) sau Casa(2)?\n";
            cin>>x;
            if(x!=1 &&x!=2)
                throw(MyException("Input gresit",0));
            cin.get();
            switch(x)
            {
            case 1:
            {

                Apartament B;
                cout<<"Introdu apartamentul\n";
                try{
                cin>>B;
                }
                catch(MyException &e)
                {
                    throw;
                }
                *A+=B;

            }
            break;
            case 2:
            {
                Casa D;
                cout<<"Introdu casa\n";
                cin>>D;
                *C+=D;

            }
            break;

            }
        }

    }
    catch(MyException &e)
    {
        cout<<e.what()<<"\n";
    }

   cout<<"\n\n Confrom datelor introduse, rezultatul este: \n\n";
   A->afisare();
   Gestiune<Casa>::getPretFinalCase();
   C->afisare();
   cout<<"Numarul de apartamente este " <<Gestiune<Apartament>::getIndexLocuinta()<<" si numarul de case este ";
   cout<<Gestiune<Casa>::getNrCase();
   cout<<"\n";

}
int main()
{
//    Casa A1,B1("Courtney Cox",12.24,3,23.1,21.2,2,2.2,7),UC("Megan Fox",920,10,23.1,21.2,2,2.9,90);
//    vector <double> v{80,22};
//    Casa R1("Green Green",102,3,30.2,70,2,v,20.75);
//    Apartament C1,D1("David Beckham",123.2,3,231.2,3),UA("Adam Lambert",34.2,0,321.1,6);
//    B1.afisare();
//    D1.afisare();
//    R1.afisare();
//
//    Casa TC(B1);
//    Apartament TA(D1);
//    cout<<TC<<"\n";
//    cout<<TA<<"\n";
//    TC=UC;
//    TA=UA;
//    cout<<TC<<"\n";
//    cout<<TA<<"\n";

   prelucrare();

   ///se apeleaza destructorul pentru gestiune; se dezaloca memoria atat pentru obiectele pointate de catre pointeri din set, cat
   /// si pentru setul propriu-zis.
    return 0;
}
