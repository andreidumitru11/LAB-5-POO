#include "Haina.hpp"

char * alocare_copiere(const char * buffer)
{
    return (strcpy(new char[strlen(buffer) + 1], buffer));
}

Haina::Haina(float pret, const char * material) : pret(pret)
{
    this->material = NULL;
    if(material)
        this->material = alocare_copiere(material);
}

Haina::Haina(const Haina & other) : pret(other.pret)
{
    this->material = NULL;
    if(other.material)
        this->material = alocare_copiere(other.material);
}

Haina & Haina::operator = (const Haina & other)
{
    if(this != &other)
    {
        this->pret = other.pret;
        if(this->material)
            delete[] this->material;
        this->material = NULL;       // aceasta linie este pusa aici deoarece in urmatoarea instructiune
                                     // verificam oricum daca other.material are informatie utila
                                     // daca nu, vom da skip la copiere si this->material va ramane NULL
                                     // ceea ce si vrem
        if(other.material)
            this->material = alocare_copiere(other.material);
    }
    return *this;
}

Haina::~Haina()
{
    if(material)
        delete[] material;
    material = NULL;
}

std::ostream & operator << (std::ostream & COUT, const Haina & obj)
{
    std::cout << "Pretul este " << obj.pret << " ";
    if(obj.material)
    {
        std::cout << "si materialul este " << obj.material << std::endl;
        return COUT;
    }
    std::cout << "si materialul este necunoscut" << std::endl; // aceasta linie este in cazul in care obj.material este NULL
                                                            // si nu s-ar mai executa acel return COUT din blocul IF
    return COUT;
}
