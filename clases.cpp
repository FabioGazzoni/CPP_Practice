#include <iostream>
// #include <stdlib.h>

using namespace std;

class Persona
{
private:
    int edad;
    string nombre;

public:
    Persona(int, string);
    ~Persona();
    void leer();
    void correr();
};

Persona::Persona(int edad, string nombre)
{
    this->edad = edad;
    this->nombre = nombre;
}

Persona::~Persona()
{
    cout << "La persona " << nombre << " edad "<< edad << " se destruira"<<endl;
}

void Persona::leer()
{
    cout << "Soy " << nombre << " y voy a leer el siguiente cuento" << endl;
}

void Persona::correr()
{
    cout << "Estoy corriendo y tengo " << edad << " Años" << endl;
}

int main()
{
    Persona *p1 = new Persona(15, "franco");
    Persona p2= Persona(20, "Fabio");

    p1->leer();
    Persona *p_p2 = &p2;
    p_p2->leer();
    delete p1;
    return 0;
}