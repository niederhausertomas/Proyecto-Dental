#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED
#include "Fecha.h"
#include "Hora.h"
#include "Paciente.h"
#include "Profesional.h"
#include <string>
#include "Jornada.h"

class Turno
{
private:
    int _Id;
    bool _EstadoTurno;
    Fecha _FechaTurno;
    Hora _HoraTurno;
    int _LegajoPaciente;
    int _LegajoProfesional;
    char _Motivo[100];
public:
    void setId(int id);
    void setEstadoTurno(bool EstadoTurno);
    void setFechaTurno(Fecha FechaTurno);
    void setHoraTurno(Hora HoraTurno);
    void setLegajoPaciente(int LegajoPaciente);
    void setLegajoProfesional(int LegajoProfesional);
    void setMotivo (string Motivo);
    int getId();
    bool getEstadoTurno();
    Fecha getFechaTurno();
    Hora getHoraTurno();
    int getLegajoPaciente();
    int getLegajoProfesional ();
    string getMotivo();
    void Cargar();
    void Mostrar();
    bool GuardarEnDisco();
    bool GuardarEnDisco(int nroRegistro);
    bool LeerDeDisco(int nroRegistro);
    int GenerarIdTurno();
};

void MenuTurnos();
void EditarTurno();
int CantidadRegistrosTurnos();
void ListarTurnos();

#endif // TURNO_H_INCLUDED
