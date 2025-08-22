#include <iostream>

using namespace std;

class Persona
{
private:
    int edad;
    string nombre;

public:
    Persona(int, string);
    void leer();
};

class Alumno:public Persona{
    private: //Solo accede esta clase --- protected: solo accede esta clase y sus hijas
        string codigo;
        float nota_final;

    public:
        Alumno(int, string, string, float);
        void presentar();
};

Persona::Persona(int edad, string nombre)
{
    this->edad = edad;
    this->nombre = nombre;
}

void Persona::leer()
{
    cout << "Soy " << nombre << " y voy a leer el siguiente cuento" << endl;
}

Alumno::Alumno(int edad, string nombre, string codigo, float nota_final):Persona(edad, nombre){
    this->codigo = codigo;
    this->nota_final = nota_final;
}

void Alumno::presentar(){
    leer();
    cout<<"Soy un alumno con la nota "<< nota_final<<endl;
}

int main()
{
    Persona *p1 = new Persona(15, "franco");
    Alumno a1 = Alumno(10, "Roberto", "A756", 8.1);
    a1.presentar();
    delete p1;
    return 0;
}