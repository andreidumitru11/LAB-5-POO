#include "Geaca.hpp"

Geaca::Geaca(float pret, const char * material, int marime, const char * brand) : Haina(pret, material), marime(marime)
{
    this->brand = NULL;
    if(brand)
        this->brand = alocare_copiere(brand);
}

Geaca::Geaca(const Geaca & other) : Haina(other), marime(other.marime)
{
    this->brand = NULL;
    if(other.brand)
        this->brand = alocare_copiere(other.brand);
}
Geaca & Geaca::operator = (const Geaca & other)
{
    if(this != &other)
    {
        Haina::operator=(other);
        this->marime = other.marime;
        if(this->brand)
            delete[] this->brand;
        this->brand = NULL;
        if(other.brand)
            this->brand = alocare_copiere(other.brand);
    }
    return *this;
}

float Geaca::getPret() const
{
    return pret;
}

bool Geaca::operator > (const Geaca & other) const
{
    return (this->marime > other.marime);
}

Geaca::~Geaca()
{
    if(brand)
        delete[] brand;
    brand = NULL;
}

std::ostream & operator << (std::ostream & COUT, const Geaca & obj)
{
    COUT << (Haina&)obj;
    std::cout << "Marimea este " << obj.marime << " ";
    if(obj.brand)
    {
        std::cout << "si brand-ul este " << obj.brand << std::endl;
        return COUT;
    }
    std::cout << "si brand-ul este necunoscut\n";
    return COUT;
}

bool operator < (const float pret, const Geaca & other)
{
    return (pret < other.pret);
}
