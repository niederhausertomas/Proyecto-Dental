#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include <string>
#include "Persona.h"
#include "Fecha.h"

class Paciente: public Persona
{
protected:
    int _legajo, _inasistencias, _nroObraSocial;
    bool _estadoPaciente;
public:
    void setLegajo(int legajo);
    void setInasistencias(int inasistencias);
    void setNroObraSocial(int nroObraSocial);
    void setEstadoPaciente(bool estadoPaciente);
    int getLegajo();
    int getInasistencias();
    int getNroObraSocial();
    bool getEstadoPaciente();
    void Cargar();
    void Mostrar();
    bool leerDeDisco(int nroRegistro);
    bool guardarEnDisco();
    bool guardarEnDisco(int nroRegistro);

};

//--------------------------------------------------------------------------------------

void menuPacientes();
void listarPacientesActivos();
void listarPacientesInactivos();
void listarPacientes();
int BuscarPacientePorLegajo();
int cantidadRegistrosPacientes();
void EditarPaciente();


#endif // PACIENTE_H_INCLUDED
