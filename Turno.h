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
    int _EstadoTurno;//1- activo; 2- Falta; 3-Cancelacion con 2 dias de anticipacion.-
    Fecha _FechaTurno;
    Hora _HoraTurno;
    int _LegajoPaciente;
    int _LegajoProfesional;
    char _Motivo[100];
public:
    void setId(int id);
    void setEstadoTurno(int EstadoTurno);
    void setFechaTurno(Fecha FechaTurno);
    void setHoraTurno(Hora HoraTurno);
    void setLegajoPaciente(int LegajoPaciente);
    void setLegajoProfesional(int LegajoProfesional);
    void setMotivo (string Motivo);
    int getId();
    int getEstadoTurno();
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
