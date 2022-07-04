#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED
#include "Turno.h"



void MenuAgenda();//
void TurnosDelDia();//
void TurnosProx7Dias();
void TurnosMes();
void TurnosPaciente();
void TurnosDispDia();
void HorariosDisponiblesDelDia(Fecha f);
void TurnosDispProx7Dias();
void TurnosDispPorProf(Fecha f, int LegProf);
void DiaProf();
void TurnosDispProx7Prof();

#endif // AGENDA_H_INCLUDED
