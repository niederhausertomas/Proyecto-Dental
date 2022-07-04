#ifndef PROFESIONAL_H_INCLUDED
#define PROFESIONAL_H_INCLUDED
#include "Persona.h"

class Profesional: public Persona
{
protected:
    int _legajo;
    int _matricula;
    bool _estadoProfesional;
public:
    void setLegajo(int legajo);
    void setMatricula(int matricula);
    void setEstadoProfesional(bool estadoProfesional);
    int getLegajo();
    int getMatricula();
    bool getEstadoProfesional();
    void cargarProfesional();
    void mostrarProfesional();
    bool leerDeDisco(int nroRegistro);
    bool guardarEnDisco();
    bool guardarEnDisco(int nroRegistro);
};

void menuProfesionales();
void listarProfesionalesActivos();
void listarProfesionalesInactivos();
void listarProfesionales();
int BuscarProfesionalPorLegajo();
int cantidadRegistrosProfesionales();
void EditarProfesional();

#endif // PROFESIONAL_H_INCLUDED
