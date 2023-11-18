#ifndef GEACA
#define GEACA

#include "Haina.hpp"

// acest lucru va permite accesul atributelor public si protected din Haina
class Geaca : public Haina // si vor ramane cu acelasi statut si in Geaca
{
    private:
        int marime;
        char * brand;
    public:
        Geaca(float pret = 0.0, const char * material = NULL, int marime = 0, const char * brand = NULL);
        //mai intai atributele clasei/lor parinte in ordinea derivarii
        Geaca(const Geaca &);
        Geaca & operator = (const Geaca &);
        float getPret() const; // putem accesa direct pret pentru ca este protected
        bool operator > (const Geaca &) const;
        ~Geaca();
        friend std::ostream & operator << (std::ostream &, const Geaca &);
        friend bool operator < (const float, const Geaca &);
};
#endif // GEACA
