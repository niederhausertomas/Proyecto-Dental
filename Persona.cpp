#ifndef PERSONA_CPP_INCLUDED
#define PERSONA_CPP_INCLUDED
#include<iostream>
using namespace std;
#include "Persona.h"
#include <string>

void Persona::setDni(int Dni)
{
    _Dni=Dni;
}

void Persona::setNombre(string Nombre)
{
    strcpy(_Nombre, Nombre.c_str());
}
void Persona::setApellido(string Apellido)
{
    strcpy(_Apellido, Apellido.c_str());
}
void Persona::setFechaNacimiento(Fecha FechaNacimiento)
{
    _FechaNacimiento = FechaNacimiento;
}
void Persona::setEmail(string Email)
{
    strcpy(_Email, Email.c_str());
}
void Persona::setDomicilio(string Domicilio)
{
    strcpy(_Domicilio, Domicilio.c_str());
}
void Persona::setTelefono(string Telefono)
{
    strcpy(_Telefono, Telefono.c_str());
}


int Persona::getDni()
{
    return _Dni;
}

string Persona::getNombre()
{
    string Nombre;
    Nombre = _Nombre;
    return Nombre;
}
string Persona::getApellido()
{
    string Apellido;
    Apellido = _Apellido;
    return Apellido;
}
Fecha Persona::getFechaNacimiento()
{
    return _FechaNacimiento;
}
string Persona::getEmail()
{
    string Email;
    Email=_Email;
    return Email;
}
string Persona::getDomicilio()
{
    string Domicilio;
    Domicilio=_Domicilio;
    return Domicilio;
}
string Persona::getTelefono()
{
    string Telefono;
    Telefono=_Telefono;
    return Telefono;
}

#endif // PERSONA_CPP_INCLUDED
