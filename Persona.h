#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <cstring>
#include "Fecha.h"
#include <string>

class Persona
{
protected:
    int _Dni;
    char _Nombre[50];
    char _Apellido[50];
    Fecha _FechaNacimiento;
    char _Email[50];
    char _Domicilio[50];
    char _Telefono[50];
public:
    void setDni(int Dni);
    void setNombre(string Nombre);
    void setApellido(string Apellido);
    void setFechaNacimiento(Fecha FechaNacimiento);
    void setEmail(string Email);
    void setDomicilio (string Domicilio);
    void setTelefono (string Telefono);
    int getDni();
    Fecha getFechaNacimiento();
    string getNombre();
    string getApellido();
    string getEmail();
    string getDomicilio();
    string getTelefono();
};

#endif // PERSONA_H_INCLUDED
