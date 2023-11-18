#include "Haina.hpp"
#include "Geaca.hpp"

void creare(Geaca *& geci)
{
     const char * materiale[] = {"catifea", "bumbac", "matase", "piele", "lana"};
     const char * branduri[] = {"Prada", "Gucci", "Hermes", "Armani", "Burberry"};
     int preturi[] = {500, 700, 400, 1000, 600};
     int marimi[] = {50, 85, 40, 45, 35};
     geci = new Geaca[5];
     for(int i = 0; i < 5; i++)
        geci[i] = Geaca(preturi[i], materiale[i], marimi[i], branduri[i]);
}

void interschimbare(Geaca & a, Geaca & b)
{
    Geaca temp(a);
    a = b;
    b = temp;
}

void sortare(Geaca *& geci)
{
    bool sortat = true;
    while(sortat)
    {
        sortat = false;
        for(int i = 0; i < 4; i++)
            if(geci[i] > geci[i + 1]) // am supradefinit operatorul > in clasa Geaca
            {
                interschimbare(geci[i], geci[i + 1]);
                sortat = true;
            }
    }
}

void celMaiMarePret(Geaca *& geci)
{
    float pret = -9999;
    for(int i = 0; i < 5; i++)
        if(pret < geci[i]) // inca un operator, dar pentru un pret si un obiect Geaca
            pret = geci[i].getPret();
    std::cout << "Cel mai mare pret este : " << pret << "$" << std::endl;
}

void afisare(Geaca *& geci)
{
    for(int i = 0; i < 5; i++)
        std::cout << geci[i] << std::endl;
}

int main()
{
   Geaca * geci;
   creare(geci);
   std::cout << "       INAINTE DE SORTARE\n\n";
   afisare(geci);
   sortare(geci);
   std::cout << "       DUPA SORTARE\n\n";
   afisare(geci);
   celMaiMarePret(geci);
   delete[] geci;
}
