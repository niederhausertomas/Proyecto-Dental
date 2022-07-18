#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED
#include "Hora.h"
#include "Fecha.h"

int ValidarDia(int Dia);
int ValidarMes(int Mes);
int ValidarAnio(int Anio);
int ValidarLegajoProfesional(int Leg);
int ValidarHora();
int ValidarMinutos();
Hora ValidarHorario();
Hora ValidarHorarioConLegJornada(Hora HoraTurno, int LegajoProfesional,Fecha FechaTurno);
int ValidarLegajoPaciente(int Leg);
bool ValidarFechaPasado(Fecha f);
Fecha ValidarFecha(Fecha f);
int ValidarDni(int DNI);
int ValidarDniExistente(int DNI);
void ValidarEstado(bool estado);
int ProfParaTurno(Fecha FechaTurno, int Leg);

#endif // VALIDAR_H_INCLUDED
