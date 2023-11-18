#ifndef HAINA
#define HAINA

#include <iostream>
#include <cstring>

char * alocare_copiere(const char *);

class Haina
{
    protected:
        float pret;
        char * material;
    public:
        Haina(float pret = 0.0, const char * material = NULL);
        Haina(const Haina &);
        Haina & operator = (const Haina &);
        ~Haina();
        friend std::ostream & operator << (std::ostream &, const Haina &);
};
#endif // HAINA
